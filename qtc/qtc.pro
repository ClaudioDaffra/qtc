
TARGET = qtc


QT += core gui widgets


CONFIG += c++11 console


TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += WIN32 MINGW32

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0




SOURCES += ../main.cpp \
    ../picoc/picoc.c \
    ../picoc/table.c \
    ../picoc/lex.c \
    ../picoc/parse.c \
    ../picoc/expression.c \
    ../picoc/heap.c \
    ../picoc/type.c \
    ../picoc/variable.c \
    ../picoc/clibrary.c \
    ../picoc/platform.c \
    ../picoc/QtLib/qString.cpp \
    ../picoc/include.c \
    ../picoc/debug.c \
    ../picoc/platform/platform_msvc.c \
    ../picoc/platform/library_msvc.c \
    ../picoc/cstdlib/stdio.c \
    ../picoc/cstdlib/math.c \
    ../picoc/cstdlib/string.c \
    ../picoc/cstdlib/stdlib.c \
    ../picoc/cstdlib/time.c \
    ../picoc/cstdlib/errno.c \
    ../picoc/cstdlib/ctype.c \
    ../picoc/cstdlib/stdbool.c \
    ../picoc/cstdlib/limits.c \
    ../picoc/cstdlib/stdint.c \
    ../picoc/QtLib/qWidget.cpp \
    ../picoc/QtLib/qWidgetConst.c \
    ../picoc/QtLib/qPaint.cpp \
    ../picoc/QtLib/qPaintConst.c \
    ../picoc/QtLib/qComplex.cpp \
    ../picoc/QtLib/qComplexConst.c





HEADERS += \
    ../picoc/picoc.h \
    ../picoc/platform.h \
    ../picoc/interpreter.h \
    ../main.h \
    ../picoc/QtLib/qPaint.h \
    ../picoc/QtLib/qComplex.h

