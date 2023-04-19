#include "water.h"
#include "ui_water.h"
#include "SerialConf.h"
water::water(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::water)
{
    ui->setupUi(this);


}

water::~water()
{
    delete ui;
}


void water::go(){
    qDebug()<<"go";
}

void water::back()
{
    qDebug()<<"asd";
}

void water::left()
{

}

void water::right()
{

}

void water::up()
{

}

void water::down()
{

}

void water::stop()
{

}

void water::unlock()
{

}
//W A S D ↑ ↓
void water::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key()) {
    case Qt::Key_W:
        go();
        return;
    case Qt::Key_A:

        return;
    case Qt::Key_S:

        return;
    case Qt::Key_D:

        return;
    case Qt::Key_Up:

        return;
    case Qt::Key_Down:

        return;
    }

    //    QWidget::keyPressEvent(ev);
}

//W A S D ↑ ↓
void water::keyReleaseEvent(QKeyEvent *ev)
{

    switch (ev->key()) {
    case Qt::Key_W:
        back();
        return;
    case Qt::Key_A:

        return;
    case Qt::Key_S:

        return;
    case Qt::Key_D:

        return;
    case Qt::Key_Up:

        return;
    case Qt::Key_Down:

        return;
    }


    //    QWidget::keyReleaseEvent(ev);
}

