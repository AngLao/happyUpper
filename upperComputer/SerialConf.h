#ifndef SERIALCONF_H
#define SERIALCONF_H

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
class win1;
}

class win1 : public QWidget
{
    Q_OBJECT

public:
    explicit win1(QWidget *parent = nullptr);
    ~win1();
    Ui::win1 *ui;

    QSerialPort *SerialPort;
    QTimer *Timer1;

    QString data;
    long long int recCount = 0;
    long long int sendCount = 0;

    void sendsingleData(const char *data);
private slots:
    void findSerialPort();
    void OpenSerialPortSlot();
    void RxDataSaveSlot();
    void RxDataTextClearSlot();
    void DataReadyReadSlot();/*串口数据接收槽函数*/
    void SendDataSlot();
    void SendDataTextClearSlot();
    //    void RxDataForHexSlot();
    //    void SendDataForHexSlot();
    void SendDataPeriodSlot();


private:

signals:
    void DatatoCRC_signal(QByteArray& SendData);
};

class MyComboBox : public QComboBox
{
    Q_OBJECT    //只有加入Q_OBJECT，才能使用信号signal和槽slot的机制
public:
    explicit MyComboBox(QWidget *parent = 0){};
    ~MyComboBox(){};
protected:
    virtual void mousePressEvent(QMouseEvent *e);  //添加鼠标点击事件

signals:
    void clicked();  //自定义点击信号，在mousePressEvent事件发生时触发
};


#endif // SERIALCONF_H
