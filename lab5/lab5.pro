QT += core
QT -= gui

CONFIG += c++11

TARGET = lab5
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    other.cpp \
    book.cpp

HEADERS += \
    book.h \
    other.h
