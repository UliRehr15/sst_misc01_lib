TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows

# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

CONFIG    += staticlib

INCLUDEPATH = ./Header

# SOURCES		+= str1_lib1.cpp
HEADERS		+= ./Header/sstMisc01Lib.h
HEADERS		+= sstMisc01LibInt.h

SOURCES		+= sstMisc01Lib.cpp \
    sstMisc01AscFil.cpp \
    sstMisc01AscRow.cpp
SOURCES		+=

OTHER_FILES += README.md

debug{
  TARGET		= sst_misc01_lib_d
}
release{
  TARGET		= sst_misc01_lib_r
}

DESTDIR     = ../libs

