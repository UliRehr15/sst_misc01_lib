/**********************************************************************
 *
 * sstMiscLib - cpp miscellaneous library for sst
 * Hosted on github
 *
 * Copyright (C) 2015 Uli Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/
// sstMisc01Lib.cpp    16.12.15  Re.    16.12.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <sstMisc01Lib.h>

#include "sstMisc01LibTest.h"

//=============================================================================
int main (int argc, char *argv [])
//=============================================================================
{
  sstMisc01AscRowCls oAscRow;
  sstMisc01AscFilCls oAscFil;
  std::string oStr;

  int iStat = 0;

  printf("Test Misc01Lib Start. \n");

  iStat = oAscFil.fopenWr(0,(char*)"Test.asc");
  assert (iStat >= 0);

  oStr = "Row1: Test";
  iStat = oAscRow.Str1_toLine(0, &oStr);
  assert (iStat >= 0);

  iStat = oAscFil.wr_line(0,&oAscRow);
  assert (iStat >= 0);

  iStat = oAscFil.fcloseFil(0);
  assert (iStat >= 0);

  printf("Test Misc01Lib Success. \n");
}
//=============================================================================

