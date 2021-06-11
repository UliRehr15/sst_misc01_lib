TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows

# CONFIG    -= debug  # RELEASE is active
CONFIG    -= release  # DEBUG is active

CONFIG    += staticlib

INCLUDEPATH += ./Header
INCLUDEPATH += ../sst_str01_lib/Header
INCLUDEPATH += ../sstMath01Lib/Header

HEADERS		+= ./Header/sstMisc01Lib.h
HEADERS		+= sstMisc01LibInt.h

SOURCES		+= sstMisc01Lib.cpp \
    sstMisc01AscFil.cpp \
    sstMisc01AscRow.cpp \
    sstMisc01CfgSet.cpp \
    sstMisc01CfgFil.cpp \
    sstMisc01PrgBar.cpp \
    sstMisc01PrtFil.cpp \
    sstMisc01PrtMsg.cpp \
    sstMisc01FilNam.cpp \
    sstMisc01DateTime.cpp

OTHER_FILES += README.md

debug{
  TARGET		= sst_misc01_lib_d
}
release{
  TARGET		= sst_misc01_lib_r
}

DESTDIR     = ../libs

