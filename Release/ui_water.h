/********************************************************************************
** Form generated from reading UI file 'water.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATER_H
#define UI_WATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_water
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *water)
    {
        if (water->objectName().isEmpty())
            water->setObjectName(QString::fromUtf8("water"));
        water->resize(1091, 460);
        pushButton = new QPushButton(water);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 60, 150, 100));
        pushButton_2 = new QPushButton(water);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 170, 150, 100));
        pushButton_3 = new QPushButton(water);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 170, 150, 100));
        pushButton_4 = new QPushButton(water);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(170, 310, 150, 100));
        pushButton_5 = new QPushButton(water);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(540, 70, 150, 100));
        pushButton_6 = new QPushButton(water);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(530, 300, 150, 100));

        retranslateUi(water);

        QMetaObject::connectSlotsByName(water);
    } // setupUi

    void retranslateUi(QWidget *water)
    {
        water->setWindowTitle(QCoreApplication::translate("water", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("water", "\345\211\215\350\277\233", nullptr));
        pushButton_2->setText(QCoreApplication::translate("water", "\345\267\246\350\275\254", nullptr));
        pushButton_3->setText(QCoreApplication::translate("water", "\345\217\263\350\275\254", nullptr));
        pushButton_4->setText(QCoreApplication::translate("water", "\345\220\216\351\200\200", nullptr));
        pushButton_5->setText(QCoreApplication::translate("water", "\344\270\212\345\215\207", nullptr));
        pushButton_6->setText(QCoreApplication::translate("water", "\344\270\213\351\231\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class water: public Ui_water {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATER_H
