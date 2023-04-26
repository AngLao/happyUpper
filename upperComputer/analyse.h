#ifndef ANALYSE_H
#define ANALYSE_H

#include <QObject>



class analyse
{
    Q_OBJECT
public:
    explicit analyse();

    ~analyse(){};


signals:
    void DataReady(QByteArray& ReceiveData);
};





#endif // ANALYSE_H
