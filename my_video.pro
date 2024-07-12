QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11



win32 {
LIBS += -L$$PWD/lib/SDL2 \
    -L$$PWD/lib/ffmpeg/lib \
    -lSDL2 \
    -lavcodec \
    -lavdevice \
    -lavfilter \
    -lavformat \
    -lavutil \
    -lswresample \
    -lswscale

INCLUDEPATH += lib \
    lib/ffmpeg/include
}


###cmd install lib
#sudo apt-get install ffmpeg
#sudo apt-get install libavformat-dev
#sudo apt-get install libavutil-dev
#sudo apt-get install libavcodec-dev
#sudo apt-get install libswscale-dev
#sudo apt-get install libsdl2-dev
###
unix {
LIBS += \
    -lSDL2 \
    -lavcodec \
    -lavdevice \
    -lavfilter \
    -lavformat \
    -lavutil \
    -lswresample \
    -lswscale
}

macx {
    INCLUDEPATH += /usr/local/Cellar/sdl2/2.24.1/include
    LIBS += -L/usr/local/Cellar/sdl2/2.24.1/lib -lSDL2
    INCLUDEPATH += /usr/local/Cellar/ffmpeg@5.1.1/5.1.1_1/include
    LIBS += -L/usr/local/Cellar/ffmpeg@5.1.1/5.1.1_1/lib -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lswresample -lswscale
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    globalhelper.cpp \
    title.cpp \
    about.cpp \
    playlist.cpp \
#    ctrlbar.cpp \
#    show.cpp \
#    videoctl.cpp \
#    CustomSlider.cpp \
    medialist.cpp \

HEADERS += \
    mainwindow.h \
    globalhelper.h \
    title.h \
    about.h \
    playlist.h \
#    ctrlbar.h \
#    show.h \
#    videoctl.h \
#    CustomSlider.h \
    medialist.h \
#    datactl.h \

FORMS += \
    mainwindow.ui \
    title.ui \
    about.ui \
    playlist.ui \
    ctrlbar.ui \
    show.ui \


RESOURCES += mainwid.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
