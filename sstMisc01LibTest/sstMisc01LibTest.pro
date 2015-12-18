TEMPLATE	= app
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows

# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

CONFIG    += staticlib

INCLUDEPATH += ../Header

debug{
  LIBS        += ../../libs/libsst_misc01_lib_d.a
}
release{

  win32-g++:QMAKE_LFLAGS += -static
  win32-g++:QMAKE_LFLAGS -= -mthreads
  win32-g++:QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
  win32-g++:QMAKE_CXXFLAGS_EXCEPTIONS_ON -= -mthreads


  LIBS        += ../../libs/libsst_misc01_lib_r.a
}


# SOURCES		+= str1_lib1.cpp
HEADERS		+= sstMisc01LibTest.h

SOURCES		+= sstMisc01LibTest.cpp


TARGET	  	= sstMisc01LibTest

