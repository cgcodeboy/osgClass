QT += core
QT -= gui

TARGET = demo10
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

CONFIG+=debug_and_release
INCLUDEPATH += D:\osg\win7\OpenSceneGraph-3.2.1-rc3\include
CONFIG(debug, debug|release) {
    LIBS+=-LD:\osg\win7\OpenSceneGraph-3.2.1-rc3\lib -lOpenThreadsd -losgd -losgDBd -losgUtild -losgGAd -losgViewerd -losgTextd -losgOceanD -losgQtd -losgParticled
} else {
    LIBS+=-LD:\osg\win7\OpenSceneGraph-3.2.1-rc3\lib -lOpenThreads -losg -losgDB -losgUtil -losgGA -losgViewer -losgText -losgOcean -losgQt -losgParticle
}
