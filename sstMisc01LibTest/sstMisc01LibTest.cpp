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

int Test_AscFile (int iKey);
int Test_ConfigSystem (int iKey);

//=============================================================================
int main (int argc, char *argv [])
//=============================================================================
{
  int iStat = 0;

  printf("Test Misc01Lib Start. \n");

  iStat = Test_AscFile ( 0);
  assert (iStat >= 0);

  iStat = Test_ConfigSystem ( 0);
  assert (iStat >= 0);

  printf("Test Misc01Lib Success. \n");
}
//=============================================================================
int Test_AscFile (int iKey) // v  -> For the moment 0
//-----------------------------------------------------------------------------
{
  sstMisc01AscRowCls oAscRow;
  sstMisc01AscFilCls oAscFil;
  std::string oStr;

  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oAscFil.fopenWr(0,(char*)"Test.asc");
  assert (iStat >= 0);

  oStr = "Row1: Test";
  iStat = oAscRow.Str1_toLine(0, &oStr);
  assert (iStat >= 0);

  iStat = oAscFil.wr_line(0,&oAscRow);
  assert (iStat >= 0);

  iStat = oAscFil.fcloseFil(0);
  assert (iStat >= 0);

  // Fatal Errors goes to an assert

  // Pipe |
  // Smaller <
  // Greater >

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_LogSystem (int iKey) // v  -> For the moment 0
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Fatal Errors goes to an assert

  // Pipe |
  // Smaller <
  // Greater >

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_ConfigSystem (int iKey)
//-----------------------------------------------------------------------------
{

  sstMisc01CfgFilCls oCfgFil("CfgFileTest");

  sstMisc01AscFilCls oAscFil;
  std::string oAscRow;

  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oCfgFil.AddConfigSet(0,(std::string) "Settings",(std::string) "Param1",(std::string) "10.0");
  iStat = oCfgFil.AddConfigSet(0,(std::string) "Basics",(std::string) "Param2",(std::string) "AAA");
  iStat = oCfgFil.AddConfigSet(0,(std::string) "Settings",(std::string) "Param3",(std::string) "333");

  // Delete existing config file, write and close new one
  iStat = oCfgFil.DeleteWriteNewClose(0);

  /* Result should be:
(empty row)
[Basics]
Param2=AAA
(empty row)
[Settings]
Param1=10.0
Param3=333
*/

  // Open existing config file and test contents
  iStat = oAscFil.fopenRd(0,(char*)"CfgFileTest.cfg");

  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (oAscRow.compare("") == 0);
  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (oAscRow.compare("[Basics]") == 0);
  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (oAscRow.compare("Param2=AAA") == 0);
  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (oAscRow.compare("") == 0);
  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (oAscRow.compare("[Settings]") == 0);
  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (oAscRow.compare("Param1=10.0") == 0);
  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (oAscRow.compare("Param3=333") == 0);
  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (iStat = -1);  // End of file

  iStat = oAscFil.fcloseFil(0);

  return iStat;
}
//=============================================================================

