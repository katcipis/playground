# -------------------------------------------------
# Project created by QtCreator 2010-03-04T10:54:25
# -------------------------------------------------
QT += xml
TARGET = cg
TEMPLATE = lib
INCLUDEPATH += ./include
DEFINES += CG_LIBRARY
SOURCES += src/wire.cpp \
    src/wireframe.cpp \
    src/point.cpp \
    src/viewport_2d.cpp \
    src/window.cpp \
    src/cg_exception.cpp \
    src/matrix.cpp \
    src/transform.cpp \
    src/window_ppc.cpp \
    src/clipper.cpp \
    src/colored_geometric_shape.cpp \
    src/curve_hermite.cpp \
    src/curve_bspline.cpp \
    src/curve.cpp \
    src/window_ortogonal.cpp \
    src/window_perspective.cpp \
    src/xml_parser.cpp \
    src/object3d.cpp \
    src/xml_object.cpp \
    src/xml_writer.cpp
HEADERS += include/wire.h \
    include/cg_global.h \
    include/wireframe.h \
    include/point.h \
    include/viewport_2d.h \
    include/window.h \
    include/cg_exception.h \
    include/matrix.h \
    include/transform.h \
    include/window_ppc.h \
    include/clipper.h \
    include/colored_geometric_shape.h \
    include/curve_hermite.h \
    include/curve_bspline.h \
    include/curve.h \
    include/window_ortogonal.h \
    include/window_perspective.h \
    include/xml_parser.h \
    include/object3d.h \
    include/xml_object.h \
    include/xml_writer.h
