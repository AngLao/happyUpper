#include "SerialPortBase.h"
#include "ui_SerialConf.h"

SerialPortBase::SerialPortBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialPortBase)
{
    ui->setupUi(this);

    //提升端口选择下拉框，使其具备点击响应,点击时进行一次搜寻串口操作
    auto FineSerialPort = [&](){
        QStringList SerialPortNameList;/*保存搜索到的串口，存入列表中*/
        ui->RxDataTextEdit->clear();
        ui->RxDataTextEdit->append("存在的串口：");
        foreach (const QSerialPortInfo &SerialPortInfo, QSerialPortInfo::availablePorts()) /*遍历可使用的串口*/
        {
            SerialPortNameList.append(SerialPortInfo.portName());/*把搜索到的串口存入列表中*/
            ui->RxDataTextEdit->append(SerialPortInfo.portName() + " " + SerialPortInfo.description());
        }
        ui->SerialPortChooseComboBox->clear();
        ui->SerialPortChooseComboBox->addItems(SerialPortNameList);/*将搜索到的串口显示到UI界面上*/
    };
    connect( ui->SerialPortChooseComboBox, &MyComboBox::clicked, this,FineSerialPort);

    //连接按钮信号和槽
    connect( ui->OpenSerialPortPushButton,&QPushButton::clicked,this, &SerialPortBase::OpenSerialPort );


    //清除接收框消息
    connect( ui->RxDataTextClearPushButton,&QPushButton::clicked,this,[&](){
        ui->RxDataTextEdit->clear();
    });

    //清除发送框消息
    connect( ui->SendDataTextClearPushButton,&QPushButton::clicked,this,[&](){
        ui->TxDataTextEdit->clear();
    });

    //发送输入框消息
    connect( ui->SendDataPushButton,&QPushButton::clicked,this,[&](){
        QByteArray GetHexShowArray(ui->TxDataTextEdit->toPlainText().toLocal8Bit());

        sendCount+=GetHexShowArray.size();

        if(ui->SendDataForHexCheckBox->isChecked() == true){
            SerialPort->write(QByteArray::fromHex(GetHexShowArray));/*发送16进制文本*/
        }else{
            SerialPort->write(GetHexShowArray);/*发送文本*/
        }

        if(ui->SendDataWithEnterCheckBox->isChecked() == true){
            SerialPort->write("\r\n");/*发送回车*/
        }
    });

    //定时发送消息
    connect( ui->SendDataPeriodCheckBox,&QCheckBox::stateChanged,this,[&](){
        if(ui->SendDataPeriodLineEdit->text().isEmpty())
        {
            /*设置的发送时间为空，不启动发送*/
            ui->SendDataPeriodCheckBox->setCheckState(Qt::Unchecked);
            QMessageBox::information(this,"提示","请检查发送时间设置是否正确！");
            return;
        }
        static QTimer*  Timer1 ;
        if(ui->SendDataPeriodCheckBox->isChecked() == true)
        {
            Timer1 = new QTimer();
            Timer1->setInterval(ui->SendDataPeriodLineEdit->text().toInt());/*设置定时时间*/
            Timer1->setTimerType(Qt::PreciseTimer);/*定时器定时精度*/
            Timer1->start();/*开启定时器*/
        }else{
            if(Timer1 != nullptr){
                Timer1->stop();/*停止定时器*/
                delete Timer1;
                Timer1 = nullptr;
            }
        }
    });

    SerialPort = new QSerialPort();

    ui->RxDataTextEdit->document()->setMaximumBlockCount(500);
    FineSerialPort();
}

void SerialPortBase::sendsingleData(const char *data)
{
    if(SerialPort->isOpen()){
        SerialPort->write(data,1);/*发送数据*/
        sendCount+=1;
    }else{
        qDebug()<<"SerialPort error";
    }
}

void SerialPortBase::OpenSerialPort()
{
    if(ui->OpenSerialPortPushButton->text() == "打开串口")
    {
        /*设置选中的COM口*/
        SerialPort->setPortName(ui->SerialPortChooseComboBox->currentText());

        /*设置串口的波特率*/
        SerialPort->setBaudRate(ui->BaudRateComboBox->currentText().toInt());

        /*设置数据位数*/
        SerialPort->setDataBits( QSerialPort::DataBits(ui->PortDataBitsComboBox->currentText().toInt()) );

        /*设置奇偶校验,NoParit无校验*/
        int index = ui->PortParityComboBox->currentIndex();
        QSerialPort::Parity PortParityBits = (index == 0) ? (QSerialPort::NoParity) :QSerialPort::Parity(index+1);
        SerialPort->setParity(PortParityBits);

        /*设置停止位，OneStop一个停止位*/
        SerialPort->setStopBits( QSerialPort::StopBits((ui->PortStopBitsComboBox->currentIndex()+1)) );

        /*设置流控制，NoFlowControl无流控制*/
        SerialPort->setFlowControl( QSerialPort::NoFlowControl );

        /*ReadWrite设置的是可读可写的属性*/
        if(SerialPort->open(QIODevice::ReadWrite) == true){
            ui->RxDataTextEdit->append(ui->SerialPortChooseComboBox->currentText() + "已连接");

            ui->SendDataPushButton->setEnabled(true);/*使能串口发送按键*/
            ui->SendDataPeriodCheckBox->setEnabled(true);  /*打开串口后可以设置自动发送*/
            ui->SendDataPeriodLineEdit->setEnabled(true);  /*打开串口后可以设置自动发送时间*/

            ui->BaudRateComboBox->setEnabled(false);
            ui->PortStopBitsComboBox->setEnabled(false);
            ui->PortDataBitsComboBox->setEnabled(false);
            ui->PortParityComboBox->setEnabled(false);/*连接成功后设置ComboBox不可选择*/
            ui->SerialPortChooseComboBox->setEnabled(false);/*列表框无效*/

            /*打开串口成功，连接信号和槽*/
            connect(SerialPort,&QSerialPort::readyRead,this,&SerialPortBase::DisplayData);
            ui->OpenSerialPortPushButton->setText("关闭串口");
        }else{
            ui->RxDataTextEdit->append(ui->SerialPortChooseComboBox->currentText() + "连接失败");
        }
    }else{

        SerialPort->close();/*关闭串口*/
        disconnect(SerialPort,&QSerialPort::readyRead,this,&SerialPortBase::DisplayData);

        ui->RxDataTextEdit->append(ui->SerialPortChooseComboBox->currentText() + "已关闭");

        ui->SerialPortChooseComboBox->setEnabled(true);/*列表框有效*/
        ui->OpenSerialPortPushButton->setText("打开串口");
        ui->SendDataPushButton->setEnabled(false);/*失能串口发送按键*/

        ui->BaudRateComboBox->setEnabled(true);
        ui->PortStopBitsComboBox->setEnabled(true);
        ui->PortDataBitsComboBox->setEnabled(true);
        ui->PortParityComboBox->setEnabled(true);/*关闭连接后设置ComboBox选择*/

        ui->SendDataPeriodCheckBox->setEnabled(false);  /*未打开串口前不能设置自动发送*/
        ui->SendDataPeriodLineEdit->setEnabled(false);  /*未打开串口前不能设置自动发送时间*/
    }
}


void SerialPortBase::DisplayData()
{
    static QByteArray SerialPortDataBuf ;
    SerialPortDataBuf = SerialPort->readAll();
    //刷新接收计数
    recCount+=SerialPortDataBuf.size();

    if(ui->RxDataForHexCheckBox->checkState() == 0)
    {
        if(ui->RxDataWithTimeCheckBox->isChecked() == true)/*显示时间戳*/
        {
            QDateTime NowTime = QDateTime::currentDateTime();
            ui->RxDataTextEdit->append("["+NowTime.toString("hh:mm:ss:zzz")+"]:");/*正常显示文本*/
            ui->RxDataTextEdit->append(SerialPortDataBuf.toHex(' ').toUpper() );/*正常显示文本*/
        }
    }else{
        ui->RxDataTextEdit->append(SerialPortDataBuf.toHex(' ').toUpper());
    }

    //计数显示刷新
    static QLabel* recCountLabel = this->parent()->findChild<QLabel*>("串口接收计数值");
    static QLabel* sendCountLabel = this->parent()->findChild<QLabel*>("串口发送计数值");

    if(recCountLabel != nullptr || sendCountLabel != nullptr){
        recCountLabel->setText(QString::number(recCount));
        sendCountLabel->setText(QString::number(sendCount));
    }

    //保持编辑器光标在最后一行
    ui->RxDataTextEdit->moveCursor(QTextCursor::End);
    //防止积累太多数据内存占用过高
    if(ui->RxDataTextEdit->toPlainText().size()>(1024*10)){
        ui->RxDataTextEdit->clear();
    }

    //发送可以解析信号
    emit DataReady(SerialPortDataBuf);
}


//给combobox添加点击事件
void MyComboBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();  //触发clicked信号
    }

    QComboBox::mousePressEvent(event);  //将该事件传给父类处理，这句话很重要，如果没有，父类无法处理本来的点击事件
}


