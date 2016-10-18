QT += core
QT -= gui

CONFIG += c++11

TARGET = lab6
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    book.cpp \
    library.cpp \
    Sorter.cpp

HEADERS += \
    book.h \
    library.h \
    Sorter.h
