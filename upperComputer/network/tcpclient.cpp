#include "tcpclient.h"

#include <QHBoxLayout>
#include <QtNetwork>
#include <QMessageBox>>

tcpclient::tcpclient(QWidget *parent)
    : QWidget{parent}
{
    //连接控制控件布局
    hostLabel->setText("连接Ip:");

    initTcpSocket();
    hostComboReset();

    QHBoxLayout* hostLayout = new QHBoxLayout();
    hostLayout->addWidget(hostLabel);
    hostLayout->addWidget(hostCombo);

    QHBoxLayout* portLayout = new QHBoxLayout();
    portLabel->setText("连接端口:");
    portEdit->setText("6666");
    portLayout->addWidget(portLabel);
    portLayout->addWidget(portEdit);

    connectButton->setText("请求连接");
    connect(connectButton , &QPushButton::clicked , this , [this](){
        if(connectButton->text() == "请求连接"){
            connectButton->setDisabled(true);
            tcpSocket->connectToHost(hostCombo->currentText(),
                                     portEdit->text().toInt());
            recTextEdit->append("等待主机响应...");

        }else{
            connectButton->setDisabled(true);
            recTextEdit->append("正在断开连接...");
            tcpSocket->disconnectFromHost();
        }
    });
    //接收显示textedit
    QLabel* recLabel = new QLabel();
    recLabel->setText("接收数据:");
    recTextEdit->setReadOnly(true);
    //发送数据textedit
    QLabel* sendLabel = new QLabel();
    sendLabel->setText("发送文本:");

    sendButton->setText("发送");
    connect(sendButton, &QPushButton::clicked,this,[=](){
            QByteArray block;
            QDataStream out(&block, QIODevice::ReadWrite);
            out.setVersion(QDataStream::Qt_5_10);
            out << "hello";
            tcpSocket->write(block);
    });

    //总体布局
    QVBoxLayout* Layout = new QVBoxLayout();
    Layout->addLayout(hostLayout);
    Layout->addLayout(portLayout);
    Layout->addWidget(connectButton);
    Layout->addWidget(recLabel);
    Layout->addWidget(recTextEdit);
    Layout->addWidget(sendLabel);
    Layout->addWidget(sendTextEdit);
    Layout->addWidget(sendButton);

    this->setWindowTitle("TcpClient");
    this->setLayout(Layout);

}

void tcpclient::hostComboReset(void){
    hostCombo->setEditable(true);
    hostCombo->clear();
    // 找出这台机器的名称
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty()) {
        hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QLatin1String("localhost"))
        hostCombo->addItem(QString("localhost"));
    // 查找此计算机的IP地址
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // 添加非本地主机地址
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }
    // 添加本地主机地址
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

}

void tcpclient::initTcpSocket(void){
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_5_10);

    //新消息响应
    auto readData = [this](){
        in.startTransaction();

        QByteArray data;
        in >> data;
        recTextEdit->append(data);

    };

    connect(tcpSocket, &QIODevice::readyRead, this, readData);
    //错误处理响应
    auto displayError = [this](QAbstractSocket::SocketError socketError){
        QString ErrorStr;
        switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        case QAbstractSocket::HostNotFoundError:
            ErrorStr = tr("找不到主机。请检查主机名和端口设置");
            break;
        case QAbstractSocket::ConnectionRefusedError:
            ErrorStr = tr("对方拒绝连接.确保服务器正在运行并检查主机名和端口设置正确。");
            break;
        default:
            ErrorStr = tr("发生以下错误: %1.")
                    .arg(tcpSocket->errorString());
        }
        recTextEdit->append(ErrorStr);
        connectButton->setDisabled(false);

    };

    connect(tcpSocket, &QAbstractSocket::errorOccurred,  this,  displayError);

    //连接主机成功时响应
    connect(tcpSocket, &QAbstractSocket::connected, this, [=](){
        connectButton->setDisabled(false);
        recTextEdit->append("连接成功!");
        connectButton->setText("断开连接");
    });


    //断开连接成功时响应
    connect(tcpSocket, &QAbstractSocket::disconnected, this, [=](){
        connectButton->setDisabled(false);
        recTextEdit->append("与主机连接已断开");
        connectButton->setText("请求连接");
    });
}
