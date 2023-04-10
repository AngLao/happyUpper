#include "widget.h"
#include "SerialConf.h"
#include "ui_SerialConf.h"
#include "uiinit.h"
#include "module.h"
#include <QApplication>
#include <QTextEdit>
#include <QToolButton>

#include "network/networkHeader.h"

//主函数入口
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    //    //test
    //    tcpserver server ;
    //    server.show();
    //    tcpclient client ;
    //    client.show();

    return a.exec();
}


/*---------------------------------------------------------
 * 封装！
 * 在uiinit类里面实现控件放置与布局
 * 在module类里面实现功能
 * 将槽函数尽量用lambda表达式减少耦合
 * 加入Json解析
 *
 * 22/10/2
 * 从数据流中解析数据的速度太慢,10ms一帧基本吃满单线程 （串口配置界面textedit文本堆积导致刷新缓慢?）
 *                                               (加上时间戳线程占用大大降低)
 *                                               原因是insertPlainText函数会将之前积累的文本再次刷新,
 *                                               更换成append解决问题,修改后1ms1帧刚好占满单线程
 * 增加串口数据显示textedit到一点大小时清空内存功能
 * 问：单次发送数据过多会导致内存积累？（关闭串口后清空）(问题初步定位：串口定时器)
 *                                                (原因串口缓冲区未清除读取速度跟不上写速度,等待内存会释放)
 *                                                (虚拟串口助手取消精确波特率模拟即可快速读写,电脑读取缓存速度远大于自定义这些波特率)
 * 22/10/3
 * 串口接收数据刷新textedit耗时间过长,1000帧占满线程占用cpu13%,同比匿名cpu占用1%
 * 关闭textedit显示后cpu占用不足0.5%
 *
 * 优化dataview刷新方式,1000帧/s下cpu占用从2.5%降至1%
 *
 * 22/10/4frameView显示数据方式由Textedit改为tabelwidget
 * 匿名上位机数据帧显示错误? 44332211显示为11223344
 *
 * 22/10/5
 * 加入定时器定时刷新显示数据
 * 解决波形刷新卡顿问题，完善波形控制按钮 1000帧20条波形不卡顿
 * 未解决问题Tabelwidget刷新太慢，占用太高，内置数据解析和显示未添加
---------------------------------------------------------*/
Widget::Widget(QWidget *parent) : QWidget(parent)
{
    this->resize(940, 450);
    QMetaObject::connectSlotsByName(this);
    //设置无边框
    //this->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);

    //主窗口初始化
    startWindowInit();
    //生成解析串口数据流方法类
    pqAgreement = new qAgreement();
    //添加自定义界面
    win1* serialConf = new win1(this);
    dataView* dataView = new class dataView();
    frameView* frameView = new class frameView();
    userConfView* userConfView = new  class userConfView();
    waveformView* waveformView = new class waveformView();
    //    networkView* networkView = new class networkView();

    m_pStackedWidget->addWidget(serialConf);
    m_pStackedWidget->addWidget(dataView->widget());
    m_pStackedWidget->addWidget(frameView->widget());
    m_pStackedWidget->addWidget(userConfView->widget());
    m_pStackedWidget->addWidget(waveformView->widget());
    //    m_pStackedWidget->addWidget(networkView->widget());

    m_pStackedWidget->setCurrentIndex(5);
    qssInit(":/qss/test.css");

    //串口读取数据通过信号发送给qAgreement类解析出原始帧数据
    connect(serialConf, &win1::DatatoCRC_signal,pqAgreement,&qAgreement::analysis);
    //原始帧数据通过信号发送给userConfView类按相应配置进行解析
    connect(pqAgreement, &qAgreement::frameQuoteSignal,userConfView,&userConfView::combinationUserData);
    //解析完成的最终结果发送到进行显示
    //    connect(userConfView, &userConfView::showframe,frameView,&frameView::addItem);
    connect(userConfView, &userConfView::refreshDataView,dataView,&dataView::refreshUserView);
    connect(userConfView, &userConfView::refreshPrint,waveformView,&waveformView::paintUserData);


}

Widget::~Widget(){}

void Widget::startWindowInit(void){
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    //设置布局边距Policy
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);

    /*添加自定义界面组件 */
    m_pStackedWidget = new QStackedWidget();
    /*底部主界面栏*/
    // 提升layout控件为frame
    QFrame* lowLayoutFrame = new QFrame(this);
    QHBoxLayout* lowLayout = new QHBoxLayout(lowLayoutFrame);
    //设置布局边距
    lowLayout->setContentsMargins(3,3,3,3);

    //加入label显示基本信息，垂直布局
    QFrame* sayLayoutFrame = new QFrame();
    QVBoxLayout* sayLayout = new QVBoxLayout(sayLayoutFrame);
    sayLayout->setContentsMargins(3,3,3,3);
    QLabel* say = new QLabel();
    say->setText("坤坤计数:");
    sayLayout->addWidget(say);
    //串口接收计数label
    QHBoxLayout* sayInLayout = new QHBoxLayout();
    QLabel* serialIn = new QLabel();
    serialIn->setText("串口接收计数:");
    QLabel* serialInValue = new QLabel();
    serialInValue->setObjectName("串口接收计数值");
    serialInValue->setText(QString::number(0));
    sayInLayout->addWidget(serialIn);
    sayInLayout->addWidget(serialInValue);
    sayInLayout->setStretch(0,1);
    sayInLayout->setStretch(1,99);
    //串口发送计数label
    QHBoxLayout* sayOutLayout = new QHBoxLayout();
    QLabel* serialOut = new QLabel();
    serialOut->setText("串口发送计数:");
    QLabel* serialOutValue = new QLabel();
    serialOutValue->setObjectName("串口发送计数值");
    serialOutValue->setText(QString::number(0));
    sayOutLayout->addWidget(serialOut);
    sayOutLayout->addWidget(serialOutValue);
    sayOutLayout->setStretch(0,1);
    sayOutLayout->setStretch(1,99);

    sayLayout->addLayout(sayInLayout);
    sayLayout->addLayout(sayOutLayout);

    lowLayout->addWidget(sayLayoutFrame);

    //配置按钮
    auto buttonInit = [=](QString name , QString iconPath){
        QToolButton* newTButton = new QToolButton(lowLayoutFrame);
        newTButton->setText(name);
        newTButton->setFocusPolicy(Qt::WheelFocus);
        QIcon icon;
        icon.addFile(iconPath, QSize(), QIcon::Normal, QIcon::Off);
        newTButton->setIcon(icon);
        newTButton->setIconSize(QSize(40, 40));
        newTButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        newTButton->setAutoRaise(true);
        lowLayout->addWidget(newTButton);
        return newTButton;
    };
    //创建按钮并绑定槽函数
    auto addTButton = [=]{
        static QToolButton* serialConf = buttonInit("串口配置",":/Icon/ser.ico");
        connect(serialConf ,&QPushButton::clicked,this,[this]() {
            m_pStackedWidget->setCurrentIndex(0);
        });
        static QToolButton* dataView = buttonInit("数据面板",":/Icon/data.ico");
        connect(dataView ,&QPushButton::clicked,this,[this]() {
            m_pStackedWidget->setCurrentIndex(1);

        });
        static QToolButton* protocolResolution = buttonInit("协议解析",":/Icon/tell.ico");
        connect(protocolResolution ,&QPushButton::clicked,this,[this]() {
            m_pStackedWidget->setCurrentIndex(2);
        });
        static QToolButton* userConf = buttonInit("用户配置",":/Icon/user.ico");
        connect(userConf ,&QPushButton::clicked,this,[this]() {
            m_pStackedWidget->setCurrentIndex(3);

        });
        static QToolButton* waveformDisplay = buttonInit("波形显示",":/Icon/bx.ico");
        connect(waveformDisplay ,&QPushButton::clicked,this,[this]() {
            m_pStackedWidget->setCurrentIndex(4);
        });
        static QToolButton* sendCmd = buttonInit("网络通讯",":/Icon/message.ico");
        connect(sendCmd ,&QPushButton::clicked,this,[this]() {
            m_pStackedWidget->setCurrentIndex(5);
        });
        static QToolButton* protocolManual = buttonInit("协议手册",":/Icon/txxy.ico");
        connect(protocolManual ,&QPushButton::clicked,this,[=]() {
            bool res = QDesktopServices::openUrl(QUrl::fromLocalFile("qrc:/sheet/ANO_XIEYI.pdf"));

            if(!res){
                QMessageBox::information(this,"waring","未找到手册文件");
            }
            //            QProcess::execute("explorer :/sheet/ANO_XIEYI.pdf");
        });
        static QToolButton* beSmall = buttonInit("隐藏窗口",":/Icon/small.ico");
        connect(beSmall ,&QPushButton::clicked,this,[=]() {
            this->setWindowState(Qt::WindowMinimized);
        });
        static QToolButton* closeSoftware = buttonInit("退出软件",":/Icon/close.ico");
        connect(closeSoftware ,&QPushButton::clicked,this,[=]() {
            this->close();
            //     delete ui;
        });

    };
    addTButton();
    //加入基础上面两个基础控件到主界面布局
    mainLayout->addWidget(m_pStackedWidget);
    mainLayout->addWidget(lowLayoutFrame);
    //设置布局排版
    mainLayout->setStretch(0,9);
    mainLayout->setStretch(1,1);
    this->setLayout(mainLayout);

}

void Widget::qssInit(QString filePath){
    //加载样式表
    if (!filePath.isEmpty()) {
        QFile file(filePath);

        if (file.open(QFile::ReadOnly)) {
            QString qss = file.readAll();
            //            QString qss = QLatin1String(file.readAll());
            this->setStyleSheet(qss);
        }
    }
}
