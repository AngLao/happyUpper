<<<<<<< HEAD
QT       += core gui
QT       += serialport      #加入串口模块
QT       += printsupport    #加入画图模块
QT       += network         #加入网络编程

#DEFINES += QT_NO_WARNING_OUTPUT
#DEFINES += QT_NO_DEBUG_OUTPUT
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    SerialConf.cpp \
    extend/easyProtocol.c \
    extend/panelwidget.cpp \
    module.cpp \
    network/tcpclient.cpp \
    network/tcpserver.cpp \
    uiinit.cpp \
    widget.cpp

HEADERS += \
    SerialConf.h \
    extend/easyProtocol.h \
    extend/panelwidget.h \
    module.h \
    network/networkHeader.h \
    network/tcpclient.h \
    network/tcpserver.h \
    uiinit.h \
    widget.h

FORMS += \
    SerialConf.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    main.qrc

#设置图标
RC_ICONS = favicon.ico

#波形图qcustomplot2 dll路径
LIBS += -L$$PWD/lib/ -lqcustomplot2

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

#opencv路径
#INCLUDEPATH += D:\Work\openCv\cmakeBuild\install\include
#               D:\Work\openCv\cmakeBuild\install\include\opencv2

#LIBS += -L D:\Work\openCv\cmakeBuild\lib\libopencv_*.a

DISTFILES +=
=======
QT       += core gui
QT       += serialport      #加入串口模块
QT       += printsupport    #加入画图模块
QT       += network         #加入网络编程

#DEFINES += QT_NO_WARNING_OUTPUT
#DEFINES += QT_NO_DEBUG_OUTPUT
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    SerialConf.cpp \
    extend/easyProtocol.c \
    extend/panelwidget.cpp \
    module.cpp \
    network/tcpclient.cpp \
    network/tcpserver.cpp \
    uiinit.cpp \
    widget.cpp

HEADERS += \
    SerialConf.h \
    extend/easyProtocol.h \
    extend/panelwidget.h \
    module.h \
    network/networkHeader.h \
    network/tcpclient.h \
    network/tcpserver.h \
    uiinit.h \
    widget.h

FORMS += \
    SerialConf.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    main.qrc

#设置图标
RC_ICONS = favicon.ico

#波形图qcustomplot2 dll路径
LIBS += -L$$PWD/lib/ -lqcustomplot2

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

#opencv路径
#INCLUDEPATH += D:\Work\openCv\cmakeBuild\install\include
#               D:\Work\openCv\cmakeBuild\install\include\opencv2

#LIBS += -L D:\Work\openCv\cmakeBuild\lib\libopencv_*.a

DISTFILES +=
>>>>>>> ecf0e4bf1ce90915c8f67e66537010fcda26d59f
