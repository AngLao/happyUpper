#include "tcpserver.h"

#include <QHBoxLayout>
#include <QtNetwork>

//控件在头文件声明时便进行初始化,而在构造函数中进行布局初始化
tcpserver::tcpserver(QWidget *parent)
    : QWidget{parent}
{
    initServer();
    //连接控制控件布局
    QHBoxLayout* connectLayout = new QHBoxLayout();
    QLabel* portLabel = new QLabel();
    portLabel->setText("监听端口:");
    portEdit->setText("6666");
    connectLayout->addWidget(portLabel);
    connectLayout->addWidget(portEdit);

    connectButton->setText("监听端口");
    connect(connectButton , &QPushButton::clicked , this , [this](){
        if(connectButton->text() == "监听端口"){
            if (!mTcpServer->listen(QHostAddress::AnyIPv4, portEdit->text().toInt())) {
                recTextEdit->append("开启监听失败");
            }
            else {
                recTextEdit->append("正在监听端口:" + QString::number(mTcpServer->serverPort()));
                connectButton->setText("取消监听");
            }
        }else{
            mTcpServer->close();
            recTextEdit->append("关闭监听");
            connectButton->setText("监听端口");
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
    connect(sendButton , &QPushButton::clicked , this , [=](){
        if(!QTcpSocketList.empty()){

            QByteArray block;
            QDataStream out(&block, QIODevice::ReadWrite);
            out.setVersion(QDataStream::Qt_5_10);
            out << "hello";
            QTcpSocketList.at(0)->write(block);
        }
    });
    //总体布局
    QVBoxLayout* Layout = new QVBoxLayout();
    Layout->addWidget(ipLabel);
    Layout->addLayout(connectLayout);
    Layout->addWidget(connectButton);
    Layout->addWidget(recLabel);
    Layout->addWidget(recTextEdit);
    Layout->addWidget(sendLabel);
    Layout->addWidget(sendTextEdit);
    Layout->addWidget(sendButton);

    this->setWindowTitle("TcpServer");
    this->setLayout(Layout);
}

void tcpserver::initServer()
{
    mTcpServer = new QTcpServer(this);

    //新连接响应绑定
    connect(mTcpServer, &QTcpServer::newConnection, this, [=](){
        QTcpSocket *clientConnection = mTcpServer->nextPendingConnection();
        if(clientConnection != nullptr){
            initNewConnect(clientConnection);
        }
    });


    //读取本机IP地址,若为空着为IPv4 localhost
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        qDebug()<<ipAddressesList.at(i).toString();
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
        }
    }
    if (ipAddress.isEmpty()){
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();}
    ipLabel->setText("本机IP: "+ipAddress);
}

void tcpserver::initNewConnect(QTcpSocket * newSocket){
    QByteArray block;
    QDataStream out(&block, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_5_10);
    out << "hello";
    newSocket->write(block);

    recTextEdit->append("newSocket net");
    QTcpSocketList.append(newSocket);
    connect(newSocket, &QAbstractSocket::disconnected,newSocket, [=](){
        QTcpSocketList.removeLast();
        recTextEdit->append("Socket disconnected");
//        newSocket->deleteLater();
    });

    //新消息响应
    auto readData = [=](){
        QDataStream in ;
        in.startTransaction();

        QByteArray data;
        in >> data;
        recTextEdit->append(data);

    };

    connect(newSocket, &QIODevice::readyRead, this, readData);
}
