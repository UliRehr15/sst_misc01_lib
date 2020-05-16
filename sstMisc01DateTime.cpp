/**********************************************************************
 *
 * sstMiscLib - cpp miscellaneous library for sst
 * Hosted on github
 *
 * Copyright (C) 2020 Uli Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/
// sstMisc01DateTime.cpp    15.05.20  Re.    15.05.20  Re.
//
// Date and Time Handler Class

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>
#include <list>

#include <sstStr01Lib.h>
#include <sstMath01Lib.h>
#include <sstMisc01Lib.h>

#include "sstMisc01LibInt.h"

//=============================================================================
sstMisc01DateTimeIntCls::sstMisc01DateTimeIntCls ()
//-----------------------------------------------------------------------------
{
}
//=============================================================================
std::string sstMisc01DateTimeIntCls::getActualDate ()
//-----------------------------------------------------------------------------
{
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y%m%d.%X", &tstruct);
  std::string oTmpDate = buf;
  return oTmpDate.substr(0,8);
}
//=============================================================================
std::string sstMisc01DateTimeIntCls::getActualTime ()
//-----------------------------------------------------------------------------
{
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y%m%d.%X", &tstruct);
  std::string oTmpTime = buf;
  return oTmpTime.substr(9,8);
}
//=============================================================================
