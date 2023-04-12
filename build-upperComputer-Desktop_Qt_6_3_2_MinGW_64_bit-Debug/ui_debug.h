/********************************************************************************
** Form generated from reading UI file 'debug.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUG_H
#define UI_DEBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEdit_7;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(867, 513);
        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 40, 171, 119));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        widget1 = new QWidget(Form);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(240, 50, 520, 63));
        horizontalLayout_10 = new QHBoxLayout(widget1);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);


        horizontalLayout_9->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_5 = new QLineEdit(widget1);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_5->addWidget(lineEdit_5);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        spinBox = new QSpinBox(widget1);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_6->addWidget(spinBox);


        horizontalLayout_9->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalSlider = new QSlider(widget1);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::NoTicks);
        horizontalSlider->setTickInterval(10);

        verticalLayout_3->addWidget(horizontalSlider);


        horizontalLayout_10->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_6 = new QLineEdit(widget1);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_7->addWidget(lineEdit_6);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(widget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEdit_7 = new QLineEdit(widget1);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_8->addWidget(lineEdit_7);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_10->addLayout(verticalLayout_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "header", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "checkmodel", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "name", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "\346\255\245\350\277\233", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "\345\200\274", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "MAX", nullptr));
        label_8->setText(QCoreApplication::translate("Form", "MIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUG_H
