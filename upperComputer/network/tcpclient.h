#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QString>
#include <QList>
#include <QLabel>
#include <QTcpServer>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QTcpSocket>

class tcpclient : public QWidget
{
    Q_OBJECT
public:
    explicit tcpclient(QWidget *parent = nullptr);


    QTcpSocket *tcpSocket = new QTcpSocket(this);
    QDataStream in;
    void hostComboReset();
    void initTcpSocket();
private:
    //ui
    QPushButton* sendButton = new QPushButton();
    QPushButton* connectButton = new QPushButton();

    QTextEdit* sendTextEdit = new QTextEdit();
    QTextEdit* recTextEdit = new QTextEdit();

    QLabel* hostLabel = new QLabel();
    QComboBox *hostCombo = new QComboBox();
    QLabel* portLabel = new QLabel();
    QLineEdit* portEdit = new QLineEdit();
signals:

};

#endif // TCPCLIENT_H
