QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle.cpp \
    drawcircle.cpp \
    drawline.cpp \
    drawrectangle.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    search.cpp \
    shape.cpp \
    sort.cpp

HEADERS += \
    circle.h \
    drawcircle.h \
    drawline.h \
    drawrectangle.h \
    line.h \
    mainwindow.h \
    rectangle.h \
    search.h \
    shape.h \
    sort.h

FORMS += \
    drawcircle.ui \
    drawline.ui \
    drawrectangle.ui \
    mainwindow.ui \
    search.ui \
    sort.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
