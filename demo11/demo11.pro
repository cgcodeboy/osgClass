#-------------------------------------------------
#
# Project created by QtCreator 2016-11-02T13:40:04
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo11
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    viewwidget.cpp

HEADERS  += mainwindow.h \
    viewwidget.h

FORMS    += mainwindow.ui

CONFIG+=debug_and_release
INCLUDEPATH += D:\osg\win7\OpenSceneGraph-3.2.1-rc3\include
CONFIG(debug, debug|release) {
    LIBS+=-LD:\osg\win7\OpenSceneGraph-3.2.1-rc3\lib -lOpenThreadsd -losgd -losgDBd -losgUtild -losgGAd -losgViewerd -losgTextd -losgOceanD -losgQtd -losgParticled
} else {
    LIBS+=-LD:\osg\win7\OpenSceneGraph-3.2.1-rc3\lib -lOpenThreads -losg -losgDB -losgUtil -losgGA -losgViewer -losgText -losgOcean -losgQt -losgParticle
}
