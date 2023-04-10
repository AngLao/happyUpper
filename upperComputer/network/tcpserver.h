#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QString>
#include <QList>
#include <QLabel>
#include <QTcpServer>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>


class tcpserver : public QWidget
{
    Q_OBJECT
public:
    explicit tcpserver(QWidget *parent = nullptr);

    QTcpServer* mTcpServer ;
    QList<QTcpSocket*> QTcpSocketList;
    void initServer();
    void initNewConnect(QTcpSocket *newSocket);
private:
    //ui
    QPushButton* sendButton = new QPushButton();
    QPushButton* connectButton = new QPushButton();

    QTextEdit* sendTextEdit = new QTextEdit();
    QTextEdit* recTextEdit = new QTextEdit();

    QLabel* ipLabel = new QLabel();
    QLineEdit* portEdit = new QLineEdit();
};

#endif // TCPSERVER_H
