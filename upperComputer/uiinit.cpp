#include "uiinit.h"
#include "extend/EasyPact.h".h"
#include "extend/panelwidget.h"
#include "qcombobox.h"
#include <QCheckBox>
#include <QGroupBox>
#include <QTextEdit>

#include "qcustomplot.h"

//#include "opencv2/opencv.hpp"
/*---------------------------dataView-----------------------------------
 *  dataView数据面板类ui实现
-----------------------------------------------------------------------*/
dataView::dataView()
{
    /*-----------------------------------------------------------------------
     *  根据QStringList需求创建一个用户数据标签
     *  每个标签由多个垂直分布的label组成
     *  第一个标签下和最后一个标签上有分割线条
     *  @parame mQStringlis 根据列表情况生成标签
    -----------------------------------------------------------------------*/
    auto newFrmDevice = [](QStringList* mQStringlis){
        QWidget* frmDeviceWidget = new QWidget();
        //设置QWidget名称，要改变标签板内数据是通过查找名称改变
        frmDeviceWidget->setObjectName(mQStringlis->at(0));
        //数据显示框为垂直布局,提升该布局为frame类，使其带边框
        QFrame* layoutFrame = new QFrame();
        QVBoxLayout* thisLayout = new QVBoxLayout(layoutFrame);

        //根据需求创建数据标签
        for(int i=0; i < mQStringlis->size() ; i++)
        {
            QLabel *Label = new QLabel(layoutFrame);
            //设置名称，方便查找 可单独修改标签值
            if(i != mQStringlis->size()-1){
                Label->setObjectName(mQStringlis->at(i));
            }else{//最后标签名称XX频率
                Label->setObjectName(mQStringlis->at(0)+mQStringlis->at(i));
                //qDebug()<<Label->objectName();
            }
            Label->setText(mQStringlis->at(i));
            thisLayout->addWidget(Label);
            //加分割线
            if(i==0 || i == mQStringlis->size()-2 ){
                QFrame* line = new QFrame();
                line->setMaximumSize(QSize(16777215, 1));
                line->setFrameShape(QFrame::HLine);
                thisLayout->addWidget(line);
            }
        }
        //创建一个布局显示提升为frame的布局类
        QVBoxLayout* mainLayout = new QVBoxLayout();
        mainLayout->setContentsMargins(0,0,0,0);
        mainLayout->setSpacing(0);
        mainLayout->addWidget(layoutFrame);
        frmDeviceWidget->setLayout(mainLayout);

        return frmDeviceWidget;
    };
    /*-----------------------------------------------------------------------*/

    /*-----------------------------------------------------------------------
     * 根据widget List生成带滑动条的widget阵列
    -----------------------------------------------------------------------*/
    auto newPanelWidget = [](QList<QWidget *>* frms){
        PanelWidget* newWidget = new PanelWidget();
        newWidget->setMargin(1);
        newWidget->setSpacing(12);
        newWidget->setWidget(*frms, 4);
        return newWidget;
    };
    /*-----------------------------------------------------------------------*/

    QStringListInit();
    //内置数据类型面板
    QList<QWidget *>* flyFrms = new QList<QWidget *>();
    for (int i = 0; i < flyList.size(); i++) {
        flyFrms->append(newFrmDevice(flyList.at(i)) );
    }

    //自定义数据类型面板
    QList<QWidget *>* userFrms = new QList<QWidget *>();    //创建飞行数据面板
    for (int i = 0; i < userList.size(); i++) {
        userFrms->append(newFrmDevice(userList.at(i)) );
    }
    //dataViwe不同功能块数据面板用Tab widget装载
    dataViewTabWidget = new QTabWidget();
    dataViewTabWidget->setTabShape(QTabWidget::Triangular  );
    dataViewTabWidget->addTab(newPanelWidget(flyFrms),"内置数据");
    dataViewTabWidget->addTab(newPanelWidget(userFrms),"用户数据");

}

//返回此ui widget句柄
QWidget *dataView::widget()
{
    return dataViewTabWidget;
}

//设置一个标签的值
void dataView::setLabelValue(QString labelName , double value){
    QLabel* thisLabel = dataViewTabWidget->findChild<QLabel*>(labelName);
    if(thisLabel == nullptr){
        qDebug()<< "cant find thisLabel"<<Qt::endl;
    }else{
        thisLabel->setText(thisLabel->objectName()+" = "+QString::number(value));
    }
}

//刷新用户数据面板槽函数
void dataView::refreshUserView(int i, double value)
{
    auto getUserLabelList = [=](){
        QList<QLabel*> userLabelList;
        for (int var = 0; var < 20; ++var) {
            QLabel* thisLabel = dataViewTabWidget->findChild<QLabel*>("value"+QString::number(var+1));
            qDebug()<<thisLabel;
            userLabelList.append(thisLabel);
        }
        return userLabelList;
    };

    static QList<QLabel*> userLabelList = getUserLabelList() ;

    //先找到面板位置
    userLabelList[i]->setText(userLabelList[i]->objectName()+" = "+QString::number(value));
    //    setLabelValue("value"+QString::number(i+1) ,value );
}

//设置一个面板中的所有数据
void dataView::setViewData(QString frmDeviceWidgetName ,QStringList* mQStringlis)
{
    //按名称寻找对应数据板块
    QWidget* findResult = dataViewTabWidget->findChild<QWidget*>(frmDeviceWidgetName);
    if(findResult != nullptr){
        //获取板块中label列表
        QList<QLabel*> thisLabelList  =  findResult->findChildren<QLabel*>();
        //         qDebug()<<thisLabelList.size()<<Qt::endl;
        for (int var = 0; var < thisLabelList.size(); ++var) {
            //            qDebug()<<thisLabelList.at(var)->text()<<Qt::endl;
            //修改显示值
            thisLabelList.at(var)->setText(mQStringlis->at(var));
        }

    }else{
        qDebug()<< "cant find"<<Qt::endl;
    }
}

//初始化各个面板显示数据名称
void dataView::QStringListInit(){
    //-----------------FLYDATA------------------
    static QStringList Id0x01 ;
    Id0x01<<"Id : 0x01"\
         <<"accX"<<"accY"<<"accZ"<<"gyrX"<<"gyrY"<<"gyrZ"<<"sta_shock" \
        <<"频率";
    flyList.append( &Id0x01) ;

    static QStringList Id0x02 ;
    Id0x02<<"Id : 0x02"\
         <<"magX"<<"magY"<<"magZ"<<"AltBar"<<"tmp"<<"staBar"<<"staMag"\
        <<"频率";
    flyList.append( &Id0x02) ;

    static QStringList Id0x03 ;
    Id0x03<<"Id : 0x03"\
         <<"roll"<<"pit"<<"yaw"<<"sta_fusion"\
        <<"频率";
    flyList.append( &Id0x03) ;

    static QStringList Id0x04 ;
    Id0x04<<"Id : 0x04"\
         <<"attV0"<<"attV1"<<"attV2"<<"attV3"\
        <<"频率";
    flyList.append( &Id0x04) ;

    //-----------------USERDATA------------------

    static QStringList USERDATA1 ;
    USERDATA1<<"USERDATA1"<<"value1"<<"频率";
    userList.append( &USERDATA1) ;

    static QStringList USERDATA2 ;
    USERDATA2<<"USERDATA2"<<"value2"<<"频率";
    userList.append( &USERDATA2) ;

    static QStringList USERDATA3 ;
    USERDATA3<<"USERDATA3"<<"value3"<<"频率";
    userList.append( &USERDATA3) ;

    static QStringList USERDATA4 ;
    USERDATA4<<"USERDATA4"<<"value4"<<"频率";
    userList.append( &USERDATA4) ;

    static QStringList USERDATA5 ;
    USERDATA5<<"USERDATA5"<<"value5"<<"频率";
    userList.append( &USERDATA5) ;

    static QStringList USERDATA6 ;
    USERDATA6<<"USERDATA6"<<"value6"<<"频率";
    userList.append( &USERDATA6) ;

    static QStringList USERDATA7 ;
    USERDATA7<<"USERDATA7"<<"value7"<<"频率";
    userList.append( &USERDATA7) ;

    static QStringList USERDATA8 ;
    USERDATA8<<"USERDATA8"<<"value8"<<"频率";
    userList.append( &USERDATA8) ;

    static QStringList USERDATA9 ;
    USERDATA9<<"USERDATA9"<<"value9"<<"频率";
    userList.append( &USERDATA9) ;

    static QStringList USERDATA10 ;
    USERDATA10<<"USERDATA10"<<"value10"<<"频率";
    userList.append( &USERDATA10) ;

    static QStringList USERDATA11 ;
    USERDATA11<<"USERDATA11"<<"value11"<<"频率";
    userList.append( &USERDATA11) ;

    static QStringList USERDATA12 ;
    USERDATA12<<"USERDATA12"<<"value12"<<"频率";
    userList.append( &USERDATA12) ;

    static QStringList USERDATA13 ;
    USERDATA13<<"USERDATA13"<<"value13"<<"频率";
    userList.append( &USERDATA13) ;

    static QStringList USERDATA14 ;
    USERDATA14<<"USERDATA14"<<"value14"<<"频率";
    userList.append( &USERDATA14) ;

    static QStringList USERDATA15 ;
    USERDATA15<<"USERDATA15"<<"value15"<<"频率";
    userList.append( &USERDATA15) ;

    static QStringList USERDATA16 ;
    USERDATA16<<"USERDATA16"<<"value16"<<"频率";
    userList.append( &USERDATA16) ;

    static QStringList USERDATA17 ;
    USERDATA17<<"USERDATA17"<<"value17"<<"频率";
    userList.append( &USERDATA17) ;

    static QStringList USERDATA18 ;
    USERDATA18<<"USERDATA18"<<"value18"<<"频率";
    userList.append( &USERDATA18) ;

    static QStringList USERDATA19 ;
    USERDATA19<<"USERDATA19"<<"value19"<<"频率";
    userList.append( &USERDATA19) ;

    static QStringList USERDATA20 ;
    USERDATA20<<"USERDATA20"<<"value20"<<"频率";
    userList.append( &USERDATA20) ;
}


/*--------------------------frameView------------------------------------
 *  frameView接收到的帧数据面板类ui实现
-----------------------------------------------------------------------*/
frameView::frameView()
{

    frameViewWidget = new QWidget();
    QTableWidget* frameView = new QTableWidget();

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(2);
    mainLayout->addWidget(frameView);
    frameViewWidget->setLayout(mainLayout);

    QStringList tableHeaderList;
    tableHeaderList<<"HEAD"<<"ADRE"<<"  ID  "<<" LEN "
                  <<"DATA1"<<"DATA2"<<"DATA3"<<"DATA4"<<"DATA5"
                 <<"DATA6"<<"DATA7"<<"DATA8"<<"DATA9"<<"DATA10"
                <<"  SC  "<<"  AC  ";
    //表头列文本设置
    frameView->setColumnCount(tableHeaderList.size());
    for (int i=0;i<tableHeaderList.size();i++) {
        frameView->setHorizontalHeaderItem(i,new QTableWidgetItem(tableHeaderList.at(i)));
        frameView->setColumnWidth(i,frameView->width());
    }
    //    frameView->horizontalHeader()->setStretchLastSection(true);
    frameView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //    frameView->verticalHeader()->setMinimumSectionSize(15);

    frameView->setSelectionBehavior(QAbstractItemView::SelectRows);//行选中
    frameView->setShowGrid(false);//不显示网格
    //    frameView->setFocusPolicy(Qt::NoFocus); //去除选中虚线框
    frameView->verticalHeader()->setVisible(false); //设置垂直头不可见
    frameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//去掉水平滚动条
    frameView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能编写
    //    frameView->setSelectionMode(QAbstractItemView::SingleSelection);//只能单次选中


}

QWidget *frameView::widget()
{
    return frameViewWidget;
}

void frameView::addItem(finalFrame *pResult , int len)
{
    //获取数据容器配置窗口句柄
    static QTableWidget* frameView = this->widget()->findChild<QTableWidget*>();
    static int RowCont = 0;
    frameView->insertRow(RowCont);//增加一行

    //    static QVector<QTableWidgetItem*> itemVector;
    //    itemVector.append(new QTableWidgetItem( QString::number(pResult->head , 16).toUpper()) );
    //    itemVector.append(new QTableWidgetItem( QString::number(pResult->addr , 16).toUpper()) );
    //    itemVector.append(new QTableWidgetItem( QString::number(pResult->id , 16).toUpper()) );
    //    itemVector.append(new QTableWidgetItem( QString::number(len , 16).toUpper()) );
    //    itemVector.append(new QTableWidgetItem( QString::number(pResult->sc , 16).toUpper()) );
    //    itemVector.append(new QTableWidgetItem( QString::number(pResult->ac , 16).toUpper()) );
    //    //插入元素
    //    for (int var = 0; var < pResult->len; ++var) {
    //        itemVector.append(new QTableWidgetItem( QString::number(pResult->data[var].Uint32 , 16).toUpper() ));
    //    }
    //插入元素
    //    frameView->setItem(RowCont,0,new QTableWidgetItem( QString::number(pResult->head , 16).toUpper() ));
    //    frameView->setItem(RowCont,1,new QTableWidgetItem( QString::number(pResult->addr , 16).toUpper() ));
    //    frameView->setItem(RowCont,2,new QTableWidgetItem( QString::number(pResult->id , 16).toUpper() ));
    //    frameView->setItem(RowCont,3,new QTableWidgetItem( QString::number(i , 16).toUpper() ));
    //    for (int var = 0; var < pResult->len; ++var) {
    //        frameView->setItem(RowCont,4+var,new QTableWidgetItem( QString::number(pResult->data[var].Uint32 , 16).toUpper() ));
    //    }
    //    frameView->setItem(RowCont,14,new QTableWidgetItem( QString::number(pResult->sc , 16).toUpper() ));
    //    frameView->setItem(RowCont,15,new QTableWidgetItem( QString::number(pResult->ac , 16).toUpper() ));
    RowCont++;
    frameView->scrollToBottom();
}


/*--------------------------userConfView--------------------------------
 *  userConfView 自定义协议解析类ui实现
-----------------------------------------------------------------------*/

userConfView::userConfView(QWidget *parent)
{
    userConfViewWidger = new QWidget(parent);
    //垂直布局装两GroupBox
    QFrame* layoutFrame = new QFrame();
    QVBoxLayout* groupLayout = new QVBoxLayout(layoutFrame);

    QTreeWidget* frameconfTreeWidget = new QTreeWidget();
    setUserConfView(frameconfTreeWidget);

    QGroupBox* frameconfBox = new QGroupBox(layoutFrame);
    frameconfBox->setTitle("自定义用户帧配置");
    QVBoxLayout* frameconfBoxLayout = new QVBoxLayout();
    frameconfBoxLayout->addWidget(frameconfTreeWidget);
    frameconfBox->setLayout(frameconfBoxLayout);

    QTableWidget* dataconfTreeWidget = new QTableWidget(frameconfBox);
    setDataConfView(dataconfTreeWidget);

    QGroupBox* dataconfBox = new QGroupBox(layoutFrame);
    dataconfBox->setTitle("数据容器配置");
    QVBoxLayout* dataconfBoxLayout = new QVBoxLayout();
    dataconfBoxLayout->addWidget(dataconfTreeWidget);
    dataconfBox->setLayout(dataconfBoxLayout);

    groupLayout->addWidget(frameconfBox);
    groupLayout->addWidget(dataconfBox);
    groupLayout->setContentsMargins(0,0,0,0);
    groupLayout->setSpacing(0);
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(2);
    mainLayout->addWidget(layoutFrame);
    userConfViewWidger->setLayout(mainLayout);

    if(parent!=nullptr){
        userConfViewWidger->resize(parent->size());
    }
}
//返回窗口句柄
QWidget *userConfView::widget()
{
    return userConfViewWidger;
}

//配置自定义数据帧界面
void userConfView::setUserConfView(QTreeWidget*  frameconf)
{
    //绘制自定义用户帧表
    QList<QTreeWidgetItem *> items;
    frameconf->setColumnCount(4);
    frameconf->setHeaderLabels(QStringList()<<"用户帧"<<"数据位"<<"数据类型"<<"传输缩放");

    for(int i =1   ; i<=10 ; i++)
    {
        if(i<10){
            //父节点设置
            QTreeWidgetItem * item=new QTreeWidgetItem(QStringList()<<"F"+QString::number(i));
            frameconf->addTopLevelItem(item);
            //使能选择框设置
            item->setCheckState(1, Qt::Unchecked);
            item->setText(1,  "使能该帧");
            //子节点设置
            for(int x =0 ; x<10 ; x++)
            {
                QTreeWidgetItem * childitem=new QTreeWidgetItem(QStringList()<<"F"+QString::number(i));
                item->addChild(childitem);

                childitem->setText(1,QString::number(x+1));

                //设置数据类型下拉框控件
                QComboBox *frameBox = new QComboBox;
                frameBox->addItem("Uint8" );
                frameBox->addItem("Uint16" );
                frameBox->addItem("Int16" );
                frameBox->addItem("Int32" );
                frameBox->addItem("Uint32" );
                frameconf->setItemWidget(childitem, 2, frameBox);

                //设置传输缩放下拉框控件
                QComboBox *frameBox1 = new QComboBox;
                for(int y=0;y<10;y++)
                    frameBox1->addItem("1.0E+" + QString::number(y) );
                frameconf->setItemWidget(childitem, 3, frameBox1);
            }
        }else{
            //父节点设置
            QTreeWidgetItem * item=new QTreeWidgetItem(QStringList()<<"FA" );
            frameconf->addTopLevelItem(item);
            //使能选择框设置
            item->setCheckState(1, Qt::Unchecked);
            item->setText(1,  "使能该帧");

            //子节点设置
            for(int x =0 ; x<10 ; x++)
            {
                QTreeWidgetItem * childitem=new QTreeWidgetItem(QStringList()<<"FA");
                item->addChild(childitem);

                childitem->setText(1,QString::number(x+1));

                //设置数据类型下拉框控件
                QComboBox *frameBox = new QComboBox;
                frameBox->addItem("Uint8" );
                frameBox->addItem("Uint16" );
                frameBox->addItem("Int16" );
                frameBox->addItem("Int32" );
                frameBox->addItem("Uint32" );
                frameconf->setItemWidget(childitem, 2, frameBox);

                //设置传输缩放下拉框控件
                QComboBox *frameBox1 = new QComboBox;
                for(int y=0;y<10;y++)
                    frameBox1->addItem("1.0E+" + QString::number(y) );
                frameconf->setItemWidget(childitem, 3, frameBox1);
            }
        }
    }
}
//配置数据容器界面
void userConfView::setDataConfView(QTableWidget* dataconf)
{
    //绘制容器表格
    QStringList tableHeaderList;
    tableHeaderList<<tr("容器")<<tr("用户帧")<<tr("数据位")<<tr("数据值");
    dataconf->setRowCount(20);
    dataconf->setColumnCount(tableHeaderList.size());          //表头列文本设置
    for (int i=0;i<tableHeaderList.size();i++) {
        dataconf->setHorizontalHeaderItem(i,new QTableWidgetItem(tableHeaderList.at(i)));
        dataconf->setColumnWidth(i,dataconf->width());
    }
    dataconf->horizontalHeader()->setStretchLastSection(true);
    dataconf->verticalHeader()->setMinimumSectionSize(35);
    dataconf->resizeRowsToContents();
    dataconf->setSelectionBehavior(QAbstractItemView::SelectRows);//行选中
    dataconf->setShowGrid(false);//不显示网格
    dataconf->setAlternatingRowColors(true);
    dataconf->setFocusPolicy(Qt::NoFocus); //去除选中虚线框
    dataconf->verticalHeader()->setVisible(false); //设置垂直头不可见
    //   dataconf->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//去掉水平滚动条
    dataconf->setEditTriggers(QAbstractItemView::NoEditTriggers);//不能编写
    dataconf->setSelectionMode(QAbstractItemView::SingleSelection);//只能单次选中
    //容器名
    for(int x=0 , y=0 ; x<20 ; x++)
    {
        QString num = QString::number(x+1);
        dataconf->setItem(x,y, new QTableWidgetItem("userData"+num));
        dataconf->item(x,y)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }

    //用户帧下拉框设置
    for(int i =0   ; i<20 ; i++)
    {    //用户帧下拉框内容
        QComboBox *frameBox = new QComboBox;
        for(int i =1   ; i<=9 ; i++)
        {
            frameBox->addItem("F"+QString::number(i) );
            if(i==9)
                frameBox->addItem("FA"  );
        }
        //放在哪个地方
        dataconf->setCellWidget(i,1,frameBox);
        //默认选择
        frameBox->setCurrentText("F1");
    }

    //数据位下拉框位置
    for(int i =0   ; i<20 ; i++)
    {    //数据位下拉框内容
        QComboBox *dataLenBox = new QComboBox;
        for(int i =0   ; i<10 ; i++)
        {
            dataLenBox->addItem(QString::number(i+1));
        }
        dataconf->setCellWidget(i,2,dataLenBox);
        //默认选择
        dataLenBox->setCurrentText("1");
    }

    //默认数据值
    for(int i =0   ; i<20 ; i++)
    {
        dataconf->setItem(i,3, new QTableWidgetItem("0"));
    }
}
//读取自定义数据帧配置
void userConfView::readUserConf()
{
    qDebug()<<"readUserConf()";
    //获取用户自定义帧配置窗口句柄
    static QTreeWidget* pQTreeWidget = this->widget()->findChild<QTreeWidget*>();
    //保存用户自定义帧数据类型
    for(int x=0  ; x<10 ; x++){
        //判断此帧是否为选中启用状态
        userConf[x].check_sta = pQTreeWidget->topLevelItem(x)->checkState(1);
        //        qDebug("check_sta = %d",userConf[x].check_sta);
        //保存一帧配置
        for(int y=0 ; y<10 ; y++ ){
            //找到节枝点
            QTreeWidgetItem* pQTreeWidgetItem = pQTreeWidget->topLevelItem(x)->child(y);
            //读取数据类型下拉框
            QString udt=dynamic_cast<QComboBox *>(pQTreeWidget->itemWidget(pQTreeWidgetItem, 2))->currentText();
            if(udt == "Uint8"){
                userConf[x].bit[y].udt = Uint8; //保存数据类型
            }else if(udt == "Uint16"){
                userConf[x].bit[y].udt = Uint16;
            }else if(udt == "Int16"){
                userConf[x].bit[y].udt = Int16;
            }else if(udt == "Int32"){
                userConf[x].bit[y].udt = Int32;
            }else if(udt == "Uint32"){
                userConf[x].bit[y].udt = Uint32;
            }

            //读取传输缩放下拉框
            QString ts=dynamic_cast<QComboBox *>(pQTreeWidget->itemWidget(pQTreeWidgetItem, 3))->currentText();
            if(ts == "1.0E+0"){
                userConf[x].bit[y].ts = M1; //保存传输缩放
            }else if(ts == "1.0E+1"){
                userConf[x].bit[y].ts = M2;
            }else if(ts == "1.0E+2"){
                userConf[x].bit[y].ts = M3;
            }else if(ts == "1.0E+3"){
                userConf[x].bit[y].ts = M4;
            }else if(ts == "1.0E+4"){
                userConf[x].bit[y].ts = M5;
            }else if(ts == "1.0E+5"){
                userConf[x].bit[y].ts = M6;
            }else if(ts == "1.0E+6"){
                userConf[x].bit[y].ts = M7;
            }else if(ts == "1.0E+7"){
                userConf[x].bit[y].ts = M8;
            }else if(ts == "1.0E+8"){
                userConf[x].bit[y].ts = M9;
            }else if(ts == "1.0E+9"){
                userConf[x].bit[y].ts = M10;
            }
            //            qDebug("udt = %s    ,  ts = %s",qPrintable( udt ) ,qPrintable( ts ));
            //            qDebug("x = %d    ,  y = %d",x ,y);
        }

    }
}
//读取数据容器配置
void userConfView::readDataConf()
{
    qDebug()<<"readDataConf()";
    /*表格中下拉框获取选中值*/
    //QString strValue=dynamic_cast<QComboBox *>(ui->tableWidget->cellWidget(0,2))->currentText();

    //获取数据容器配置窗口句柄
    static QTableWidget* pQTableWidget = this->widget()->findChild<QTableWidget*>();

    //保存数据容器对应哪个帧
    for(int i = 0 ; i< 20 ; i++){
        QString strValue=dynamic_cast<QComboBox *>(pQTableWidget->cellWidget(i,1))->currentText();
        if(strValue == QString("F1")){
            dataConf[i].frameNum = F1;
        }else if(strValue == QString("F2")){
            dataConf[i].frameNum = F2;
        }else if(strValue == QString("F3")){
            dataConf[i].frameNum = F3;
        }else if(strValue == QString("F4")){
            dataConf[i].frameNum = F4;
        }else if(strValue == QString("F5")){
            dataConf[i].frameNum = F5;
        }else if(strValue == QString("F6")){
            dataConf[i].frameNum = F6;
        }else if(strValue == QString("F7")){
            dataConf[i].frameNum = F7;
        }else if(strValue == QString("F8")){
            dataConf[i].frameNum = F8;
        }else if(strValue == QString("F9")){
            dataConf[i].frameNum = F9;
        }else if(strValue == QString("FA")){
            dataConf[i].frameNum = FA;
        }
    }

    //保存数据容器对应哪个数据位
    for(int i = 0 ; i< 20 ; i++){
        QString strValue=dynamic_cast<QComboBox *>(pQTableWidget->cellWidget(i,2))->currentText();
        if(strValue == QString("1")){
            dataConf[i].bitNum = B1;
        }else if(strValue == QString("2")){
            dataConf[i].bitNum = B2;
        }else if(strValue == QString("3")){
            dataConf[i].bitNum = B3;
        }else if(strValue == QString("4")){
            dataConf[i].bitNum = B4;
        }else if(strValue == QString("5")){
            dataConf[i].bitNum = B5;
        }else if(strValue == QString("6")){
            dataConf[i].bitNum = B6;
        }else if(strValue == QString("7")){
            dataConf[i].bitNum = B7;
        }else if(strValue == QString("8")){
            dataConf[i].bitNum = B8;
        }else if(strValue == QString("9")){
            dataConf[i].bitNum = B9;
        }else if(strValue == QString("10")){
            dataConf[i].bitNum = B10;
        }
    }

}

//用户自定义帧解析方法组合数据
void userConfView::combinationUserData(void *mframe)
{
    qDebug()<<"combinationUserData()";

    //定义字节组合函数
    auto getUInt8  =  [](unsigned char *pData, unsigned int *i){
        unsigned  char result = 0;
        result = (unsigned  char)pData[*i];
        *i += 1 ;
        return result ;
    };
    auto getUInt16 =  [](unsigned char *pData, unsigned int *i){
        unsigned  short result = 0;
        result = (unsigned  short)pData[*i];
        *i += 1 ;
        result += (unsigned  short)(pData[*i]<<8);
        *i += 1 ;
        return result ;
    };
    auto getInt16  =  [](unsigned char* pData, unsigned int* i){
        short result = 0;
        result = (short)pData[*i];
        *i += 1 ;
        result += (short)(pData[*i]<<8);
        *i += 1 ;
        return result ;
    };
    auto getUInt32 =  [](unsigned char *pData, unsigned int *i){
        unsigned  int result = 0;
        result = (int)pData[*i];
        *i += 1 ;
        result += (int)(pData[*i]<<8);
        *i += 1 ;
        result += (int)(pData[*i]<<16);
        *i += 1 ;
        result += (int)(pData[*i]<<24);
        *i += 1 ;
        return result ;
    };
    auto getInt32  =  [](unsigned char *pData, unsigned int *i){
        int result = 0;
        result = (int)pData[*i];
        *i += 1 ;
        result += (int)(pData[*i]<<8);
        *i += 1 ;
        result += (int)(pData[*i]<<16);
        *i += 1 ;
        result += (int)(pData[*i]<<24);
        *i += 1 ;
        return result ;
    };
    //是否为用户自定义数据帧?
//    if(mframe.Id()<0xF0){
//        return ;
//    }

    //保存帧描述
    uesrFinalFrame.head=0;
    uesrFinalFrame.addr=0;
    uesrFinalFrame.id=0;

    uesrFinalFrame.ac=0;
    uesrFinalFrame.sc=0;

    int lenindex = 0;
    unsigned char* pBuf ;

//    uesrFinalFrame.head=mframe.Head();
//    uesrFinalFrame.addr=mframe.Addr();
//    uesrFinalFrame.id=mframe.Id();

//    uesrFinalFrame.ac=mframe.Ac();
//    uesrFinalFrame.sc=mframe.Sc();

//    int lenindex = mframe.Len() ;
//    unsigned char* pBuf = mframe.DataPoint() ;
    //根据配置解析数据
    unsigned char idindex = uesrFinalFrame.id-0xF1; //对应的功能帧索引
    qDebug("idindex res:%d", idindex);
    unsigned int bufIndex = 0 ;

    for(int i = 0 ; i<10 ; i++){
        //数据归零
        uesrFinalFrame.data[i].Uint32 = 0;
    }
    //读取配置数据
    readUserConf();
    readDataConf();
    //根据配置的数据类型组合数据
    for (uesrFinalFrame.len=0; uesrFinalFrame.len<10 && lenindex > 0 ; uesrFinalFrame.len++) {
        switch (userConf[idindex].bit[uesrFinalFrame.len].udt) {
        case Uint8 :
            lenindex-=1; //读取一字节
            uesrFinalFrame.data[uesrFinalFrame.len].Uint8  =  getUInt8( pBuf , &bufIndex) ;
            qDebug("Uint8 res:%d", uesrFinalFrame.data[uesrFinalFrame.len].Uint8);
            break;
        case Int16 :
            lenindex-=2; //读取二字节
            uesrFinalFrame.data[uesrFinalFrame.len].Int16  =  getInt16( pBuf , &bufIndex) ;
            qDebug("Int16 res:%d", uesrFinalFrame.data[uesrFinalFrame.len].Int16);
            break;
        case Uint16 :
            lenindex-=2; //读取二字节
            uesrFinalFrame.data[uesrFinalFrame.len].Uint16 =  getUInt16( pBuf , &bufIndex) ;
            qDebug("Uint16 res:%d", uesrFinalFrame.data[uesrFinalFrame.len].Uint16);
            break;
        case Int32  :
            lenindex-=4; //读取四字节
            uesrFinalFrame.data[uesrFinalFrame.len].Int32  =  getInt32( pBuf , &bufIndex) ;
            qDebug("Int32 res:%d", uesrFinalFrame.data[uesrFinalFrame.len].Int32);
            break;
        case Uint32 :
            lenindex-=4; //读取四字节
            uesrFinalFrame.data[uesrFinalFrame.len].Uint32  =  getUInt32( pBuf , &bufIndex) ;
            qDebug("Uint32 res:%d", uesrFinalFrame.data[uesrFinalFrame.len].Uint32);
            break;
        }
    }

    //最终解析帧转成通过信号发送到tablewifget显示
    emit showframe(&uesrFinalFrame, 0);
    //刷新UI显示值
    refreshView();

}


//刷新UI显示值
void userConfView::refreshView()
{
    static long int frameCount = 0;//统计接收的总数据包数(由不同的帧组合)
    frameCount++;
    //------------------------------------------------------------------------------------
    //获取数据容器配置窗口句柄
    static QTableWidget* pQTableWidget = this->widget()->findChild<QTableWidget*>();

    //遍历数据容器
    for(int i = 0 ; i<20 ;i++){
        //遍历用户帧配置
        for(int x=0 ; x<10 ; x++){
            //判断当前帧的id与要显示的帧id是否相符                    //如果用户帧使能
            if(uesrFinalFrame.id-0xF1 == dataConf[i].frameNum && userConf[x].check_sta==2){
                //读取哪个数据位
                int dataNum = dataConf[i].bitNum;
                //缩放比例
                int howBig = pow(10,userConf[x].bit[dataNum].ts);
                //根据缩放比例换算结果
                double res = static_cast<double>(uesrFinalFrame.data[dataNum].Uint32)/howBig;
                //刷新表格数据
                pQTableWidget->item(i,3)->setText(QString::number(res));
                //刷新数据面板用户自定义数据显示
                emit refreshDataView(i,res);
                //发送显示数据波形
                emit refreshPrint(frameCount , res , i );

                break;
            }
        }
    }


    //------------------------------------------------------------------------------------


}


/*--------------------------waveformView--------------------------------
 *  waveFormView 波形显示类ui实现
-----------------------------------------------------------------------*/
waveformView::waveformView()
{
    //水平布局装一个tabwidget和一个widget
    QFrame* toplayoutFrame = new QFrame();
    QHBoxLayout* topLayout = new QHBoxLayout(toplayoutFrame);
    topLayout->setContentsMargins(5,3,5,3);
    topLayout->setSpacing(3);

    //定义颜色
    userColorStrList<<"paleturquoise"<<"skyblue"<<"darkturquoise"<<"darkcyan"<<"steelblue"<<"deepskyblue"
                   <<"darkslateblue"<<"brown"<<"maroon"<<"madiumaquamarine"<<"forestgreen"
                  <<"darkslategray"<<"darkkhaki"<<"gold"<<"darkorange"<<"orangered"<<"violet"
                 <<"darkviolet"<<"darkgoldenrod"<<"deeppink";

    //添加checkbox
    QList<QWidget *>* checkList = new QList<QWidget *>() ;
    for (int var = 0; var < 20; ++var) {
        QCheckBox* newCheckBox = new QCheckBox();
        newCheckBox->setObjectName("USERDATA"+QString::number(var+1));
        newCheckBox->setText("USERDATA"+QString::number(var+1));
        QString StyleSheetStr = "QCheckBox{background-color:" ;
        StyleSheetStr+= userColorStrList.at(var);
        StyleSheetStr+= "}" ;
        newCheckBox->setStyleSheet(StyleSheetStr);
        checkList->append(newCheckBox);
        //链接信号和槽根据选择状态决定是否显示波形
        connect(newCheckBox, &QCheckBox::stateChanged , this , [=](){
            pQCustomPlot->graph(var)->setVisible(newCheckBox->isChecked());
            pQCustomPlot->replot(); //刷新
        });
    }

    //checkbox装不完添加滑动条
    //用户自定义数据checkbox
    PanelWidget* newWidget = new PanelWidget();
    newWidget->setObjectName("用户数据");
    newWidget->setMargin(2);
    newWidget->setWidget(*checkList, 1);

    QTabWidget* checkWidget = new QTabWidget();
    checkWidget->addTab(newWidget, "用户数据");

    //提升widget类为QCustomPlot类
    pQCustomPlot = new QCustomPlot();
    //设置波形显示背景
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor("#20B2AA"));
    plotGradient.setColorAt(1, QColor("#FFFACD"));
    pQCustomPlot->setBackground(plotGradient);

    topLayout->addWidget(checkWidget);
    topLayout->addWidget(pQCustomPlot);
    topLayout->setStretch(0,1);
    topLayout->setStretch(1,10);
    //底部水平布局装控制按钮
    QFrame* bottomLayoutFrame = new QFrame();
    QHBoxLayout* bottomLayout = new QHBoxLayout(bottomLayoutFrame);
    bottomLayout->setContentsMargins(2,2,2,2);
    bottomLayout->setSpacing(2);
    //配置按钮
    //开始显示按钮
    QPushButton* startWaveformButton = new QPushButton();
    startWaveformButton->setText("开始显示");
    connect(startWaveformButton,&QPushButton::clicked,pQCustomPlot,[=](){
        if(startWaveformButton->text() == "开始显示"){
            startWaveformButton->setText("暂停显示");
            startFlag = true;
        }else{
            startWaveformButton->setText("开始显示");
            startFlag = false;
        }
    });
    //清空波形按钮
    bottomLayout->addWidget(startWaveformButton);
    QPushButton* clearWaveformButton = new QPushButton();
    clearWaveformButton->setText("清空波形");
    connect(clearWaveformButton,&QPushButton::clicked,pQCustomPlot,[=](){
        int count=pQCustomPlot->graphCount();//获取曲线条数
        for(int i=0;i<count;++i)
        {
            pQCustomPlot->graph(i)->data().data()->clear();
        }
        pQCustomPlot->replot();
    });
    bottomLayout->addWidget(clearWaveformButton);
    //动态显示按钮
    QPushButton* dynamicDisplayButton = new QPushButton();
    dynamicDisplayButton->setText("停止跟随");
    connect(dynamicDisplayButton,&QPushButton::clicked,pQCustomPlot,[=](){
        if(dynamicDisplayButton->text() == "动态显示"){
            dynamicDisplayButton->setText("停止跟随");
            dynamicDisplayFlag = true;
        }else{
            dynamicDisplayButton->setText("动态显示");
            dynamicDisplayFlag = false;
        }
    });
    bottomLayout->addWidget(dynamicDisplayButton);
    //全显波形按钮
    QPushButton* seeAllLineButton = new QPushButton();
    seeAllLineButton->setText("波形全显");
    connect(seeAllLineButton,&QPushButton::clicked,pQCustomPlot,[=](){
        dynamicDisplayButton->setText("动态显示");
        dynamicDisplayFlag = false;
        pQCustomPlot->xAxis->rescale(true);//调整X轴的范围，使之能显示出所有的曲线的X值
        pQCustomPlot->yAxis->rescale(true);//调整Y轴的范围，使之能显示出所有的曲线的Y值
        pQCustomPlot->replot();  // 刷新
    });
    bottomLayout->addWidget(seeAllLineButton);

    //主布局设置
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(2,0,2,0);
    mainLayout->setSpacing(2);
    mainLayout->addWidget(toplayoutFrame);
    mainLayout->addWidget(bottomLayoutFrame);

    waveformViewWidget = new QWidget();
    waveformViewWidget->setLayout(mainLayout);

    //波形线条初始化
    lineInit();
}

QWidget* waveformView::widget()
{
    return waveformViewWidget;
}

void waveformView::lineInit(){
    //新增20条用户数据波形

    for (int var = 0; var < 20; ++var) {
        QPen pen;
        pen.setWidth(1);//设置线宽
        pen.setStyle(Qt::PenStyle::SolidLine);//设置为实线
        pen.setColor(QColor(userColorStrList.at(var)));//设置线条颜色

        pQCustomPlot->addGraph();
        pQCustomPlot->graph(var)->setPen(pen);
        pQCustomPlot->graph(var)->setVisible(false);
    }

    //显示图例
    //    pQCustomPlot->legend->setVisible(true);
    //允许拖拽
    pQCustomPlot->setInteraction( QCP::iRangeDrag , true);
    //允许缩放
    pQCustomPlot->setInteraction( QCP::iRangeZoom , true);

}

void waveformView::paintUserData(double x ,double y , int num)
{
    //获取checkbox控件句柄
    static QList<QCheckBox*>  CheckBoxList = this->widget()->findChildren<QCheckBox*>();

    static bool isChange = false;
    if(startFlag){
        //添加数据
        y = sin(x)*20*(num+1);
        pQCustomPlot->graph(num)->addData(x,y);
        isChange=true;
    }
    if(dynamicDisplayFlag){
        //刷新数据的时候才动态显示
        if(isChange){
            //动态x轴
            pQCustomPlot->xAxis->setRange(x-20, 300, Qt::AlignRight);
            //设置y轴范围
            QCPRange a = pQCustomPlot->yAxis->range();
            if(y < a.lower){
                pQCustomPlot->yAxis->setRange(y,a.upper);
            }
            if(y > a.upper){
                pQCustomPlot->yAxis->setRange(a.lower,y);
            }

        }
    }

    static QTimer* thisTimer = new QTimer();
    thisTimer->setTimerType(Qt::PreciseTimer);
    connect(thisTimer , &QTimer::timeout , this , [=](){
        if(isChange){
            pQCustomPlot->replot(QCustomPlot::rpQueuedReplot); //刷新
            isChange=false;
        }
    });
    thisTimer->start(1);

}


/*--------------------------debugView--------------------------------
 *  waveFormView 波形显示类ui实现
-----------------------------------------------------------------------*/

debugView::debugView()
{
    QVBoxLayout* ctrLayout = new QVBoxLayout();
    QList< QWidget*> ctrblockList ;
    for (int var = 0; var < 6; ++var) {

        ctrblockList.append(addCtrBlock());
        ctrLayout->addWidget(ctrblockList.at(var));
    }

    QWidget* confBlock = addConfBlock();
    //主布局设置
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(2,0,2,0);
    mainLayout->setSpacing(2);
    mainLayout->addWidget(confBlock,2);
    mainLayout->addLayout(ctrLayout,8);
    debugViewWidget = new QWidget();
    debugViewWidget->setLayout(mainLayout);
}

QWidget* debugView::widget()
{
    return debugViewWidget;
}

QWidget* debugView::addCtrBlock()
{
    //显示名称控件配置
    QLabel *labname = new QLabel("地址ID:");
    QLabel *lab_set = new QLabel("值:");
    QLabel *lab_zoom = new QLabel("缩放:");
    QLabel *lab_step = new QLabel("步进:");
    QLabel *lab_min = new QLabel("min:");
    QLabel *lab_max = new QLabel("max:");

    //数值编辑控件配置
    QSpinBox *sb_set = new QSpinBox();  //设置数值
    QLineEdit *le_name = new QLineEdit("00");//目标地址和id
    QLineEdit *le_zoom = new QLineEdit(QString::number(1));//传输缩放
    QLineEdit *le_step = new QLineEdit(QString::number(1));//微调步进
    QLineEdit *le_min = new QLineEdit(QString::number(0));//可传输最大值
    QLineEdit *le_max = new QLineEdit(QString::number(500));//可传输最小值

    //带符号32位数值,规范QLineEdit输入格式
    le_name->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9]+")));
    le_zoom->setValidator(new QIntValidator(-500, 500));
    le_step->setValidator(new QIntValidator(-500, 500));
    le_min->setValidator(new QIntValidator(-2147483647, 2147483647));
    le_max->setValidator(new QIntValidator(-2147483647, 2147483647));


    sb_set->setMinimum(le_min->text().toInt());
    sb_set->setMaximum(le_max->text().toInt());
    sb_set->setSingleStep(le_step->text().toInt());
    sb_set->setValue(0);

    //滑杆控件配置
    QSlider *hs_set = new QSlider();
    hs_set->setOrientation(Qt::Horizontal);
    hs_set->setMinimum(le_min->text().toInt());
    hs_set->setMaximum(le_max->text().toInt());
    hs_set->setValue(0);

    //----------槽函数链接----------
    //滑杆操作响应
    connect(hs_set, &QSlider::sliderReleased,this,[=](){
        sb_set->setValue(hs_set->value());
    });

    //设定值改变时响应
    connect(sb_set, &QSpinBox::valueChanged,this,[=](){
        hs_set->setValue(sb_set->value());
        //发送数据
        auto text = le_name->text().toUtf8();
        uint32_t data = sb_set->text().toUInt();

        static frame_t senbuf;
        easy_set_header(&senbuf, 0xAA);
        easy_set_address(&senbuf, int(text.at(0)));
        easy_set_id(&senbuf, int(text.at(1)));

        easy_wipe_data(&senbuf);
        easy_add_data(&senbuf, data, 4);
        easy_add_data(&senbuf, data, 2);
        easy_add_check(&senbuf);
        //发送帧数据
        uint8_t len = easy_return_buflen(&senbuf);
        qDebug()<<len;
        qDebug()<<data;

        emit sendPackData((char*)&senbuf ,easy_return_buflen(&senbuf));
    });

    //地址ID改变时响应
    connect(le_name, &QLineEdit::editingFinished,this,[=](){
        auto text = le_name->text() ;
        if(text.length()!=2)
            le_name->setText("00");
    });

    //步进值改变时响应
    connect(le_step, &QLineEdit::editingFinished,this,[=](){
        sb_set->setSingleStep(le_step->text().toInt());
    });

    //最大最小值编辑结束时响应
    connect(le_max, &QLineEdit::editingFinished,this,[=](){
        int changvalue = le_max->text().toInt();
        int thisvalue = sb_set->value();
        sb_set->setMaximum(changvalue);
        hs_set->setMaximum(changvalue);
        sb_set->setValue(thisvalue);
        hs_set->setValue(thisvalue);

    });
    connect(le_min, &QLineEdit::editingFinished,this,[=](){
        int changvalue = le_min->text().toInt();
        int thisvalue = sb_set->value();
        sb_set->setMinimum(changvalue);
        hs_set->setMinimum(changvalue);
        sb_set->setValue(thisvalue);
        hs_set->setValue(thisvalue);

    });


    //开始布局
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(labname);
    topLayout->addWidget(le_name,1);
    topLayout->addWidget(lab_set);
    topLayout->addWidget(sb_set,1);
    topLayout->addWidget(lab_zoom);
    topLayout->addWidget(le_zoom,1);
    topLayout->addWidget(lab_step);
    topLayout->addWidget(le_step,1);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(hs_set,6);
    bottomLayout->addWidget(lab_min);
    bottomLayout->addWidget(le_min,1);
    bottomLayout->addWidget(lab_max);
    bottomLayout->addWidget(le_max,1);

    //主布局设置
    QFrame *mainFrame = new QFrame();
    QVBoxLayout* mainLayout = new QVBoxLayout(mainFrame);
    mainLayout->setContentsMargins(2,0,2,0);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);

    return mainFrame;
}

QWidget* debugView::addConfBlock()
{
    QLabel *lab_header = new QLabel("header:");
    QLabel *lab_checkmodel = new QLabel("checkmodel:");

    QLineEdit *le_header = new QLineEdit(QString::number(REC_HEADER));
    le_header->setDisabled(true);
    QLineEdit *le_checkmodel = new QLineEdit(QString::number(check_model));
    le_checkmodel->setDisabled(true);



    QHBoxLayout *headerLayout = new QHBoxLayout();
    headerLayout->addWidget(lab_header);
    headerLayout->addWidget(le_header);
    QHBoxLayout *checkmodelLayout = new QHBoxLayout();
    checkmodelLayout->addWidget(lab_checkmodel);
    checkmodelLayout->addWidget(le_checkmodel);

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *readConfButton = new QPushButton();
    readConfButton->setSizePolicy(sizePolicy);
    readConfButton->setText("读取配置");
    QPushButton *saveConfButton = new QPushButton();
    saveConfButton->setSizePolicy(sizePolicy);
    saveConfButton->setText("保存配置");
    QPushButton *sendConfButton = new QPushButton();
    sendConfButton->setSizePolicy(sizePolicy);
    sendConfButton->setText("全部发送");

    //功能未完善
    readConfButton->setDisabled(true);
    saveConfButton->setDisabled(true);
    sendConfButton->setDisabled(true);
    //主布局设置
    QFrame *mainFrame = new QFrame();
    QVBoxLayout* mainLayout = new QVBoxLayout(mainFrame);
    mainLayout->setContentsMargins(2,2,2,2);
    mainLayout->addLayout(headerLayout);
    mainLayout->addLayout(checkmodelLayout);
    mainLayout->addWidget(readConfButton);
    mainLayout->addWidget(saveConfButton);
    mainLayout->addWidget(sendConfButton);


    return mainFrame;
}

/*--------------------------networkView--------------------------------
 *  networkView 网络通讯类ui实现
-----------------------------------------------------------------------*/
networkView::networkView()
{
    //几个QGroupBox装按钮,点击后新建立窗口来进行通讯控制

    //水平布局装 QGroupBox
    QFrame* layoutFrame = new QFrame();
    QHBoxLayout* Layout = new QHBoxLayout(layoutFrame);

    Layout->setContentsMargins(5,3,5,3);
    Layout->setSpacing(3);
    //TCP QGroupBox
    QGroupBox* tcpGroupBox = new QGroupBox(layoutFrame);
    tcpGroupBox->setTitle("TCP");
    Layout->addWidget(tcpGroupBox);
    //垂直布局加入控制按钮
    QVBoxLayout* tcpGroupBoxLayout = new QVBoxLayout();
    tcpGroupBox->setLayout(tcpGroupBoxLayout);
    QPushButton* tcpserverButton = new QPushButton();
    tcpserverButton->setText("TCP服务器");
    connect(tcpserverButton,&QPushButton::clicked,this,[=](){
    });
    tcpGroupBoxLayout->addWidget(tcpserverButton);
    QPushButton* tcpsocketButton = new QPushButton();
    tcpsocketButton->setText("TCP客户端");
    connect(tcpsocketButton,&QPushButton::clicked,this,[=](){
    });
    tcpGroupBoxLayout->addWidget(tcpsocketButton);
    //UDP QGroupBox
    QGroupBox* udpGroupBox = new QGroupBox(layoutFrame);
    udpGroupBox->setTitle("UDP");
    Layout->addWidget(udpGroupBox);
    //垂直布局加入控制按钮
    QVBoxLayout* udpGroupBoxLayout = new QVBoxLayout();
    udpGroupBox->setLayout(udpGroupBoxLayout);
    QPushButton* udpserverButton = new QPushButton();
    udpserverButton->setText("UDP服务器");
    connect(udpserverButton,&QPushButton::clicked,this,[](){

    });
    udpGroupBoxLayout->addWidget(udpserverButton);
    QPushButton* udpsocketButton = new QPushButton();
    udpsocketButton->setText("UDP客户端");
    connect(udpsocketButton,&QPushButton::clicked,this,[](){

    });
    udpGroupBoxLayout->addWidget(udpsocketButton);


    networkViewWidget = new QWidget();
    networkViewWidget->setLayout(Layout);
}

QWidget *networkView::widget()
{
    return networkViewWidget;
}

//QWidget* networkView::tcpServerWidget(){
//    //TCP Server
//    QTcpServer* mTcpServer = new QTcpServer(this);    //tcp服务端
//    QNetworkProxyFactory::setUseSystemConfiguration(false);
//    QList<QTcpSocket*>* QTcpSocketList = new QList<QTcpSocket*>();
//    //垂直布局
//    QFrame* layoutFrame = new QFrame();
//    QVBoxLayout* Layout = new QVBoxLayout(layoutFrame);
//    //连接控制控件布局
//    QHBoxLayout* connectLayout = new QHBoxLayout();
//    QLabel* ipLabel = new QLabel();
//    ipLabel->setText("监听Ip:");
//    QLineEdit* ipEdit = new QLineEdit();
//    ipEdit->setText("192.168.0.22");
//    QLabel* portLabel = new QLabel();
//    QLineEdit* portEdit = new QLineEdit();
//    portEdit->setText("8080");
//    portLabel->setText("监听端口:");
//    connectLayout->addWidget(ipLabel);
//    connectLayout->addWidget(ipEdit);
//    connectLayout->addWidget(portLabel);
//    connectLayout->addWidget(portEdit);
//    //接收显示textedit
//    QLabel* recLabel = new QLabel();
//    recLabel->setText("接收数据:");
//    QTextEdit* recTextEdit = new QTextEdit();
//    recTextEdit->setReadOnly(true);
//    //发送数据textedit
//    QLabel* sendLabel = new QLabel();
//    sendLabel->setText("发送文本:");
//    QTextEdit* sendTextEdit = new QTextEdit();
//    //发送按钮
//    QPushButton* sendButton = new QPushButton();
//    sendButton->setText("发送数据");
//    //链接按钮
//    QPushButton* connectButton = new QPushButton();
//    connectButton->setText("开启监听");
//    connect(connectButton,&QPushButton::clicked,this,[=](){
//        if(connectButton->text() == "开启监听"){
//            QHostAddress ip;
//            if(ipEdit->text() == "-1"){
//                //-1 监听所有地址
//                ip= QHostAddress::Any;
//            }else{
//                ip = QHostAddress(ipEdit->text());
//            }
//            if(mTcpServer->listen(ip, portEdit->text().toUShort() ) ){
//                //监听开启成功
//                connectButton->setText("关闭监听");
//                recTextEdit->append("监听IP:"+ ip.toString());
//                recTextEdit->append("监听端口:"+ portEdit->text());
//                connect(mTcpServer,&QTcpServer::newConnection,this,[=](){
//                    //获取客户端连接
//                    QTcpSocket* newTcpSocket = mTcpServer->nextPendingConnection();
//                    recTextEdit->append("新客户连接:" );
//                    QTcpSocketList->append(newTcpSocket);
//                    //客户端发送数据过来就会触发readyRead信号
//                    connect(newTcpSocket, &QTcpSocket::readyRead, this, [=](){
//                        recTextEdit->append(newTcpSocket->readAll()) ;
//                    });
//                    //客户端断开连接触发disconnected信号
//                    connect(newTcpSocket, &QTcpSocket::disconnected, this, [=](){
//                        newTcpSocket->close();
//                    });
//                });
//            }else{
//                recTextEdit->append("无法打开监听");
//            }
//        }else{
//            for(int i=0; i<QTcpSocketList->length(); i++)//断开所有连接
//            {
//                QTcpSocketList->at(i)->disconnectFromHost();
//                if(QTcpSocketList->at(i)->waitForDisconnected(1000))
//                {
//                    // 处理异常
//                }
//                QTcpSocketList->removeAt(i);  //从保存的客户端列表中取去除
//            }
//            mTcpServer->close();     //不再监听端口
//            connectButton->setText("开启监听");
//            recTextEdit->append("已关闭监听");
//        }
//    });
//    Layout->addLayout(connectLayout);
//    Layout->addWidget(connectButton);
//    Layout->addWidget(recLabel);
//    Layout->addWidget(recTextEdit);
//    Layout->addWidget(sendLabel);
//    Layout->addWidget(sendTextEdit);
//    Layout->addWidget(sendButton);

//    QWidget* newtcpServerWidget = new QWidget();
//    newtcpServerWidget->setWindowTitle("TcpServer");
//    newtcpServerWidget->setLayout(Layout);
//    return newtcpServerWidget;
//}

//QWidget* networkView::tcpClientWidget(){
//    //TCP Server
//    QTcpSocket* mQTcpSocket = new QTcpSocket();    //tcp客户端
//    mQTcpSocket->abort();                 //取消原有连接
//    //垂直布局
//    QFrame* layoutFrame = new QFrame();
//    QVBoxLayout* Layout = new QVBoxLayout(layoutFrame);
//    //连接控制控件布局
//    QHBoxLayout* connectLayout = new QHBoxLayout();
//    QLabel* ipLabel = new QLabel();
//    ipLabel->setText("主机Ip:");
//    QLineEdit* ipEdit = new QLineEdit();
//    ipEdit->setText("192.168.0.12");
//    QLabel* portLabel = new QLabel();
//    portLabel->setText("应用端口:");
//    QLineEdit* portEdit = new QLineEdit();
//    portEdit->setText("8080");
//    connectLayout->addWidget(ipLabel);
//    connectLayout->addWidget(ipEdit);
//    connectLayout->addWidget(portLabel);
//    connectLayout->addWidget(portEdit);
//    //接收显示textedit
//    QLabel* recLabel = new QLabel();
//    recLabel->setText("接收数据:");
//    QTextEdit* recTextEdit = new QTextEdit();
//    recTextEdit->setReadOnly(true);
//    //发送数据textedit
//    QLabel* sendLabel = new QLabel();
//    sendLabel->setText("发送文本:");
//    QTextEdit* sendTextEdit = new QTextEdit();
//    //发送按钮
//    QPushButton* sendButton = new QPushButton();
//    sendButton->setText("发送数据");
//    connect(sendButton,&QPushButton::clicked,this,[=](){

//        char* data = "asdasd";
//        mQTcpSocket->write(data,sizeof(data));

//    });
//    //链接按钮
//    QPushButton* connectButton = new QPushButton();
//    connectButton->setText("请求链接");
//    connect(connectButton,&QPushButton::clicked,this,[=](){
//        if(connectButton->text() == "请求链接"){
//            mQTcpSocket->connectToHost(ipEdit->text(), portEdit->text().toUShort());
//            if (mQTcpSocket->waitForConnected(500))  // 连接成功则进入if{}
//            {
//                recTextEdit->append("链接成功");
//                connectButton->setText("断开链接");
//                connect(mQTcpSocket, &QTcpSocket::readyRead, this, [=](){
//                    QByteArray buffer = mQTcpSocket->readAll();
//                    if(!buffer.isEmpty())
//                    {
//                        recTextEdit->append(buffer);
//                    }
//                });
//            }else{
//                recTextEdit->append("链接失败");
//            }

//        }else{
//            mQTcpSocket->disconnectFromHost();
//            if (mQTcpSocket->state() == QAbstractSocket::UnconnectedState \
//                    || mQTcpSocket->waitForDisconnected(1000))  //已断开连接则进入if{}
//            {
//                connectButton->setText("请求链接");
//                recTextEdit->append("已断开链接");
//            }

//        }
//    });
//    Layout->addLayout(connectLayout);
//    Layout->addWidget(connectButton);
//    Layout->addWidget(recLabel);
//    Layout->addWidget(recTextEdit);
//    Layout->addWidget(sendLabel);
//    Layout->addWidget(sendTextEdit);
//    Layout->addWidget(sendButton);

//    QWidget* newtcpServerWidget = new QWidget();
//    newtcpServerWidget->setWindowTitle("TcpClient");
//    newtcpServerWidget->setLayout(Layout);
//    return newtcpServerWidget;
//}
