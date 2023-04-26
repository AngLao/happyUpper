/********************************************************************************
** Form generated from reading UI file 'SerialConf.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALCONF_H
#define UI_SERIALCONF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <SerialPortBase.h>

QT_BEGIN_NAMESPACE

class Ui_SerialPortBase
{
public:
    QHBoxLayout *horizontalLayout_11;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout;
    QTextEdit *RxDataTextEdit;
    QTextEdit *TxDataTextEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    MyComboBox *SerialPortChooseComboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *BaudRateComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *PortStopBitsComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *PortDataBitsComboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *PortParityComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QPushButton *OpenSerialPortPushButton;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *RxDataForHexCheckBox;
    QCheckBox *RxDataWithTimeCheckBox;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *RxDataSavePushButton;
    QPushButton *RxDataTextClearPushButton;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *SendDataTextClearPushButton;
    QPushButton *SendDataPushButton;
    QCheckBox *SendDataPeriodCheckBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *SendDataPeriodLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *SendDataForHexCheckBox;
    QCheckBox *SendDataWithEnterCheckBox;

    void setupUi(QWidget *SerialPortBase)
    {
        if (SerialPortBase->objectName().isEmpty())
            SerialPortBase->setObjectName(QString::fromUtf8("SerialPortBase"));
        SerialPortBase->resize(953, 518);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SerialPortBase->sizePolicy().hasHeightForWidth());
        SerialPortBase->setSizePolicy(sizePolicy);
        SerialPortBase->setSizeIncrement(QSize(0, 0));
        SerialPortBase->setBaseSize(QSize(0, 0));
        SerialPortBase->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_11 = new QHBoxLayout(SerialPortBase);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(SerialPortBase);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_12 = new QHBoxLayout(frame);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(6, 6, 6, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RxDataTextEdit = new QTextEdit(frame);
        RxDataTextEdit->setObjectName(QString::fromUtf8("RxDataTextEdit"));
        RxDataTextEdit->setAutoFillBackground(false);
        RxDataTextEdit->setStyleSheet(QString::fromUtf8(" font:12pt \"\346\245\267\344\275\223\";"));
        RxDataTextEdit->setAutoFormatting(QTextEdit::AutoBulletList);
        RxDataTextEdit->setUndoRedoEnabled(false);
        RxDataTextEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        RxDataTextEdit->setLineWrapColumnOrWidth(1888);
        RxDataTextEdit->setTabStopDistance(40.000000000000000);

        verticalLayout->addWidget(RxDataTextEdit);

        TxDataTextEdit = new QTextEdit(frame);
        TxDataTextEdit->setObjectName(QString::fromUtf8("TxDataTextEdit"));
        TxDataTextEdit->setMinimumSize(QSize(400, 110));
        TxDataTextEdit->setMaximumSize(QSize(9999, 9999));

        verticalLayout->addWidget(TxDataTextEdit);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(1, 1);

        horizontalLayout_12->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(165, 22));
        label->setMaximumSize(QSize(999, 999));
        label->setBaseSize(QSize(0, 0));

        verticalLayout_2->addWidget(label);

        SerialPortChooseComboBox = new MyComboBox(frame);
        SerialPortChooseComboBox->setObjectName(QString::fromUtf8("SerialPortChooseComboBox"));
        SerialPortChooseComboBox->setMinimumSize(QSize(172, 22));
        SerialPortChooseComboBox->setMaximumSize(QSize(999, 999));

        verticalLayout_2->addWidget(SerialPortChooseComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 22));
        label_2->setMaximumSize(QSize(80, 22));

        horizontalLayout->addWidget(label_2);

        BaudRateComboBox = new QComboBox(frame);
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->addItem(QString());
        BaudRateComboBox->setObjectName(QString::fromUtf8("BaudRateComboBox"));
        BaudRateComboBox->setMinimumSize(QSize(80, 22));
        BaudRateComboBox->setMaximumSize(QSize(80, 22));
        BaudRateComboBox->setEditable(true);

        horizontalLayout->addWidget(BaudRateComboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 22));
        label_4->setMaximumSize(QSize(80, 22));

        horizontalLayout_2->addWidget(label_4);

        PortStopBitsComboBox = new QComboBox(frame);
        PortStopBitsComboBox->addItem(QString());
        PortStopBitsComboBox->addItem(QString());
        PortStopBitsComboBox->addItem(QString());
        PortStopBitsComboBox->setObjectName(QString::fromUtf8("PortStopBitsComboBox"));
        PortStopBitsComboBox->setMinimumSize(QSize(80, 22));
        PortStopBitsComboBox->setMaximumSize(QSize(80, 22));

        horizontalLayout_2->addWidget(PortStopBitsComboBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(80, 22));
        label_5->setMaximumSize(QSize(80, 22));

        horizontalLayout_3->addWidget(label_5);

        PortDataBitsComboBox = new QComboBox(frame);
        PortDataBitsComboBox->addItem(QString());
        PortDataBitsComboBox->addItem(QString());
        PortDataBitsComboBox->addItem(QString());
        PortDataBitsComboBox->addItem(QString());
        PortDataBitsComboBox->setObjectName(QString::fromUtf8("PortDataBitsComboBox"));
        PortDataBitsComboBox->setMinimumSize(QSize(80, 22));
        PortDataBitsComboBox->setMaximumSize(QSize(80, 22));

        horizontalLayout_3->addWidget(PortDataBitsComboBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 22));
        label_3->setMaximumSize(QSize(80, 22));

        horizontalLayout_4->addWidget(label_3);

        PortParityComboBox = new QComboBox(frame);
        PortParityComboBox->addItem(QString());
        PortParityComboBox->addItem(QString());
        PortParityComboBox->addItem(QString());
        PortParityComboBox->addItem(QString());
        PortParityComboBox->addItem(QString());
        PortParityComboBox->setObjectName(QString::fromUtf8("PortParityComboBox"));
        PortParityComboBox->setMinimumSize(QSize(80, 22));
        PortParityComboBox->setMaximumSize(QSize(80, 22));

        horizontalLayout_4->addWidget(PortParityComboBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(80, 22));
        label_6->setMaximumSize(QSize(80, 22));

        horizontalLayout_5->addWidget(label_6);

        OpenSerialPortPushButton = new QPushButton(frame);
        OpenSerialPortPushButton->setObjectName(QString::fromUtf8("OpenSerialPortPushButton"));
        OpenSerialPortPushButton->setMinimumSize(QSize(80, 25));
        OpenSerialPortPushButton->setMaximumSize(QSize(80, 25));

        horizontalLayout_5->addWidget(OpenSerialPortPushButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        RxDataForHexCheckBox = new QCheckBox(frame);
        RxDataForHexCheckBox->setObjectName(QString::fromUtf8("RxDataForHexCheckBox"));
        RxDataForHexCheckBox->setMinimumSize(QSize(80, 20));
        RxDataForHexCheckBox->setMaximumSize(QSize(80, 20));
        RxDataForHexCheckBox->setChecked(true);
        RxDataForHexCheckBox->setTristate(false);

        horizontalLayout_6->addWidget(RxDataForHexCheckBox);

        RxDataWithTimeCheckBox = new QCheckBox(frame);
        RxDataWithTimeCheckBox->setObjectName(QString::fromUtf8("RxDataWithTimeCheckBox"));
        RxDataWithTimeCheckBox->setMinimumSize(QSize(80, 20));
        RxDataWithTimeCheckBox->setMaximumSize(QSize(80, 20));

        horizontalLayout_6->addWidget(RxDataWithTimeCheckBox);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        RxDataSavePushButton = new QPushButton(frame);
        RxDataSavePushButton->setObjectName(QString::fromUtf8("RxDataSavePushButton"));
        RxDataSavePushButton->setMinimumSize(QSize(80, 25));
        RxDataSavePushButton->setMaximumSize(QSize(80, 25));

        horizontalLayout_7->addWidget(RxDataSavePushButton);

        RxDataTextClearPushButton = new QPushButton(frame);
        RxDataTextClearPushButton->setObjectName(QString::fromUtf8("RxDataTextClearPushButton"));
        RxDataTextClearPushButton->setMinimumSize(QSize(80, 25));
        RxDataTextClearPushButton->setMaximumSize(QSize(80, 25));

        horizontalLayout_7->addWidget(RxDataTextClearPushButton);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        SendDataTextClearPushButton = new QPushButton(frame);
        SendDataTextClearPushButton->setObjectName(QString::fromUtf8("SendDataTextClearPushButton"));
        SendDataTextClearPushButton->setMinimumSize(QSize(80, 25));
        SendDataTextClearPushButton->setMaximumSize(QSize(80, 25));

        horizontalLayout_8->addWidget(SendDataTextClearPushButton);

        SendDataPushButton = new QPushButton(frame);
        SendDataPushButton->setObjectName(QString::fromUtf8("SendDataPushButton"));
        SendDataPushButton->setMinimumSize(QSize(80, 25));
        SendDataPushButton->setMaximumSize(QSize(80, 25));

        horizontalLayout_8->addWidget(SendDataPushButton);


        verticalLayout_2->addLayout(horizontalLayout_8);

        SendDataPeriodCheckBox = new QCheckBox(frame);
        SendDataPeriodCheckBox->setObjectName(QString::fromUtf8("SendDataPeriodCheckBox"));
        SendDataPeriodCheckBox->setEnabled(false);
        SendDataPeriodCheckBox->setMinimumSize(QSize(165, 25));
        SendDataPeriodCheckBox->setMaximumSize(QSize(999, 999));

        verticalLayout_2->addWidget(SendDataPeriodCheckBox);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);

        SendDataPeriodLineEdit = new QLineEdit(frame);
        SendDataPeriodLineEdit->setObjectName(QString::fromUtf8("SendDataPeriodLineEdit"));
        SendDataPeriodLineEdit->setMinimumSize(QSize(80, 22));
        SendDataPeriodLineEdit->setMaximumSize(QSize(80, 22));

        horizontalLayout_9->addWidget(SendDataPeriodLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        SendDataForHexCheckBox = new QCheckBox(frame);
        SendDataForHexCheckBox->setObjectName(QString::fromUtf8("SendDataForHexCheckBox"));
        SendDataForHexCheckBox->setEnabled(false);
        SendDataForHexCheckBox->setMinimumSize(QSize(80, 22));
        SendDataForHexCheckBox->setChecked(true);

        horizontalLayout_10->addWidget(SendDataForHexCheckBox);

        SendDataWithEnterCheckBox = new QCheckBox(frame);
        SendDataWithEnterCheckBox->setObjectName(QString::fromUtf8("SendDataWithEnterCheckBox"));
        SendDataWithEnterCheckBox->setEnabled(false);
        SendDataWithEnterCheckBox->setMinimumSize(QSize(80, 22));
        SendDataWithEnterCheckBox->setMaximumSize(QSize(80, 22));

        horizontalLayout_10->addWidget(SendDataWithEnterCheckBox);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout_12->addLayout(verticalLayout_2);

        horizontalLayout_12->setStretch(0, 4);
        horizontalLayout_12->setStretch(1, 1);

        horizontalLayout_11->addWidget(frame);


        retranslateUi(SerialPortBase);

        BaudRateComboBox->setCurrentIndex(13);


        QMetaObject::connectSlotsByName(SerialPortBase);
    } // setupUi

    void retranslateUi(QWidget *SerialPortBase)
    {
        SerialPortBase->setWindowTitle(QCoreApplication::translate("SerialPortBase", "Form", nullptr));
        label->setText(QCoreApplication::translate("SerialPortBase", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\344\270\262\345\217\243\351\200\211\346\213\251</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SerialPortBase", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\263\242\347\211\271\347\216\207</span></p></body></html>", nullptr));
        BaudRateComboBox->setItemText(0, QCoreApplication::translate("SerialPortBase", "110", nullptr));
        BaudRateComboBox->setItemText(1, QCoreApplication::translate("SerialPortBase", "300", nullptr));
        BaudRateComboBox->setItemText(2, QCoreApplication::translate("SerialPortBase", "600", nullptr));
        BaudRateComboBox->setItemText(3, QCoreApplication::translate("SerialPortBase", "1200", nullptr));
        BaudRateComboBox->setItemText(4, QCoreApplication::translate("SerialPortBase", "2400", nullptr));
        BaudRateComboBox->setItemText(5, QCoreApplication::translate("SerialPortBase", "4800", nullptr));
        BaudRateComboBox->setItemText(6, QCoreApplication::translate("SerialPortBase", "9600", nullptr));
        BaudRateComboBox->setItemText(7, QCoreApplication::translate("SerialPortBase", "14400", nullptr));
        BaudRateComboBox->setItemText(8, QCoreApplication::translate("SerialPortBase", "19200", nullptr));
        BaudRateComboBox->setItemText(9, QCoreApplication::translate("SerialPortBase", "38400", nullptr));
        BaudRateComboBox->setItemText(10, QCoreApplication::translate("SerialPortBase", "43000", nullptr));
        BaudRateComboBox->setItemText(11, QCoreApplication::translate("SerialPortBase", "57600", nullptr));
        BaudRateComboBox->setItemText(12, QCoreApplication::translate("SerialPortBase", "76800", nullptr));
        BaudRateComboBox->setItemText(13, QCoreApplication::translate("SerialPortBase", "115200", nullptr));
        BaudRateComboBox->setItemText(14, QCoreApplication::translate("SerialPortBase", "460800", nullptr));
        BaudRateComboBox->setItemText(15, QCoreApplication::translate("SerialPortBase", "921600", nullptr));

        label_4->setText(QCoreApplication::translate("SerialPortBase", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\201\234\346\255\242\344\275\215</span></p></body></html>", nullptr));
        PortStopBitsComboBox->setItemText(0, QCoreApplication::translate("SerialPortBase", "1", nullptr));
        PortStopBitsComboBox->setItemText(1, QCoreApplication::translate("SerialPortBase", "2", nullptr));
        PortStopBitsComboBox->setItemText(2, QCoreApplication::translate("SerialPortBase", "1.5", nullptr));

        label_5->setText(QCoreApplication::translate("SerialPortBase", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\225\260\346\215\256\344\275\215</span></p></body></html>", nullptr));
        PortDataBitsComboBox->setItemText(0, QCoreApplication::translate("SerialPortBase", "8", nullptr));
        PortDataBitsComboBox->setItemText(1, QCoreApplication::translate("SerialPortBase", "7", nullptr));
        PortDataBitsComboBox->setItemText(2, QCoreApplication::translate("SerialPortBase", "6", nullptr));
        PortDataBitsComboBox->setItemText(3, QCoreApplication::translate("SerialPortBase", "5", nullptr));

        label_3->setText(QCoreApplication::translate("SerialPortBase", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\240\241\351\252\214\344\275\215</span></p></body></html>", nullptr));
        PortParityComboBox->setItemText(0, QCoreApplication::translate("SerialPortBase", "\346\227\240\346\240\241\351\252\214", nullptr));
        PortParityComboBox->setItemText(1, QCoreApplication::translate("SerialPortBase", "EvenParity ", nullptr));
        PortParityComboBox->setItemText(2, QCoreApplication::translate("SerialPortBase", "OddParity ", nullptr));
        PortParityComboBox->setItemText(3, QCoreApplication::translate("SerialPortBase", "SpaceParity ", nullptr));
        PortParityComboBox->setItemText(4, QCoreApplication::translate("SerialPortBase", "MarkParity ", nullptr));

        label_6->setText(QCoreApplication::translate("SerialPortBase", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\344\270\262\345\217\243\346\223\215\344\275\234</span></p></body></html>", nullptr));
        OpenSerialPortPushButton->setText(QCoreApplication::translate("SerialPortBase", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        RxDataForHexCheckBox->setText(QCoreApplication::translate("SerialPortBase", "Hex\346\230\276\347\244\272", nullptr));
        RxDataWithTimeCheckBox->setText(QCoreApplication::translate("SerialPortBase", "\346\227\266\351\227\264\346\210\263", nullptr));
        RxDataSavePushButton->setText(QCoreApplication::translate("SerialPortBase", "\344\277\235\345\255\230\344\270\262\345\217\243", nullptr));
        RxDataTextClearPushButton->setText(QCoreApplication::translate("SerialPortBase", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        SendDataTextClearPushButton->setText(QCoreApplication::translate("SerialPortBase", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        SendDataPushButton->setText(QCoreApplication::translate("SerialPortBase", "\345\217\221\351\200\201", nullptr));
        SendDataPeriodCheckBox->setText(QCoreApplication::translate("SerialPortBase", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        label_7->setText(QCoreApplication::translate("SerialPortBase", "\345\217\221\351\200\201\345\221\250\346\234\237(ms)\357\274\232", nullptr));
        SendDataPeriodLineEdit->setText(QCoreApplication::translate("SerialPortBase", "100", nullptr));
        SendDataForHexCheckBox->setText(QCoreApplication::translate("SerialPortBase", "Hex\345\217\221\351\200\201", nullptr));
        SendDataWithEnterCheckBox->setText(QCoreApplication::translate("SerialPortBase", "\345\217\221\351\200\201\345\233\236\350\275\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialPortBase: public Ui_SerialPortBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALCONF_H
