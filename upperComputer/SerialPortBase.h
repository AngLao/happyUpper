#ifndef SERIALPORTBASE_H
#define SERIALPORTBASE_H

#include <QWidget>

#include <QMouseEvent>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QComboBox>
#include <QMouseEvent>



namespace Ui {
class SerialPortBase;
}

class SerialPortBase : public QWidget
{
    Q_OBJECT

public:
    Ui::SerialPortBase *ui;
    explicit SerialPortBase(QWidget *parent = nullptr);
    ~SerialPortBase(){delete ui;};

    void sendsingleData(const char *data);
private:
    QSerialPort *SerialPort;

    long long int recCount = 0;
    long long int sendCount = 0;

    void OpenSerialPort();
    /*串口数据接收槽函数*/
    void DisplayData();

signals:
    void DataReady(QByteArray& ReceiveData);
};

class MyComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit MyComboBox(QWidget *parent = 0){};
    ~MyComboBox(){};
protected:
    virtual void mousePressEvent(QMouseEvent *e);  //添加鼠标点击事件

signals:
    void clicked();  //自定义点击信号，在mousePressEvent事件发生时触发
};


#endif // SERIALPORTBASE_H
