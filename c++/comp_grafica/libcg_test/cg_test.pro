# -------------------------------------------------
# Project created by QtCreator 2010-03-04T11:21:47
# -------------------------------------------------
QT += testlib
QT -= gui
TARGET = cg_test
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
LIBS += -L../libcg \
    -lcg
INCLUDEPATH = ./include \
    ../libcg/include
SOURCES += ./src/main.cpp \
    ./src/wire_test.cpp \
    ./src/wireframe_test.cpp \
    ./src/point_test.cpp \
    ./src/window_test.cpp \
    ./src/viewport_2d_test.cpp \
    ./src/matrix_test.cpp \
    ./src/transform_test.cpp \
    ./src/window_ppc_test.cpp \
    ./src/colored_geometric_shape_test.cpp \
    ./src/window_ppc_clipped_test.cpp \
    ./src/curve_hermite_test.cpp
HEADERS += ./include/wire_test.h \
    ./include/wireframe_test.h \
    ./include/point_test.h \
    ./include/window_test.h \
    ./include/viewport_2d_test.h \
    ./include/matrix_test.h \
    ./include/transform_test.h \
    ./include/window_ppc_test.h \
    ./include/colored_geometric_shape_test.h \
    ./include/window_ppc_clipped_test.h \
    ./include/curve_hermite_test.h
