# -------------------------------------------------
# Project created by QtCreator 2010-05-18T22:13:23
# -------------------------------------------------
QT += testlib
TARGET = sistema_nebuloso
TEMPLATE = app
INCLUDEPATH += include
SOURCES += src/gui/main.cpp \
    src/gui/mainwindow.cpp \
    src/gui/car_gui.cpp \
    src/gui/car_gui_handler.cpp \
    src/model/fuzzy_set.cpp \
    src/model/fuzzy_driver.cpp \
    src/model/neural_driver.cpp \
    src/model/network.cpp \
    src/model/layer.cpp
HEADERS += include/gui/mainwindow.h \
    include/gui/car_gui.h \
    include/gui/car_gui_handler.h \
    include/model/fuzzy_set.h \
    include/model/fuzzy_driver.h \
    include/gui/window_size.h \
    include/model/neural_driver.h \
    include/model/network.h \
    include/model/layer.h
FORMS += src/gui/mainwindow.ui
