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
// sstMisc01LibTest.cpp    15.02.16  Re.    16.12.15  Re.
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
  int iStat = 0;

  printf("Test Misc01Lib Start. \n");

  iStat = Test_FileNameCls ( 0);
  assert (iStat >= 0);

  iStat = Test_AscFile ( 0);
  assert (iStat >= 0);

  iStat = Test_LogSystem ( 0);
  assert (iStat >= 0);

  iStat = Test_ConfigSystem ( 0);
  assert (iStat >= 0);

  iStat = Test_ProgressBar ( 0);
  assert (iStat >= 0);

  printf("Test Misc01Lib Success. \n");
}
//=============================================================================
int Test_AscFile (int iKey) // v  -> For the moment 0
//-----------------------------------------------------------------------------
{
  sstMisc01AscRowCls oAscRow1;
  sstMisc01AscFilCls oAscFil1;
  sstMisc01AscFilCls oAscFil2;
  std::string oFilNam1 = "Test.asc";
  std::string oFilNam2 = "TestCompare.asc";
  std::string oStr;

  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = oAscFil1.fopenWr(0,(char*) oFilNam1.c_str());
  assert (iStat >= 0);

  oStr = "Row1: Test";
  iStat = oAscRow1.Str1_toLine(0, &oStr);
  assert (iStat >= 0);

  iStat = oAscFil1.wr_line(0,&oAscRow1);
  assert (iStat >= 0);

  iStat = oAscFil1.Wr_String(0,"TestString");
  assert (iStat >= 0);

  iStat = oAscFil1.fcloseFil(0);
  assert (iStat >= 0);

  iStat = oAscFil2.fopenWr(0,(char*) oFilNam2.c_str());
  assert (iStat >= 0);

  iStat = oAscFil2.Wr_String(0,"Row1: Test");
  assert (iStat >= 0);
  iStat = oAscFil2.Wr_String(0,"TestString");
  assert (iStat >= 0);

  iStat = oAscFil2.fcloseFil(0);
  assert (iStat >= 0);

  unsigned long ulRowNo = 0;
  iStat = sstMisc01FileCompare(0,oFilNam1,oFilNam2,&ulRowNo);

  iStat = oAscFil1.fopenRd(0, (char*)"Test.asc");
  assert (iStat >= 0);

  oStr.clear();
  iStat = oAscFil1.Rd_StrDS1( 0, &oStr);
  assert(oStr == "Row1: Test");

  oStr.clear();
  iStat = oAscFil1.Rd_StrDS1( 0, &oStr);
  assert(oStr == "TestString");

  iStat = oAscFil1.fcloseFil(0);
  assert (iStat >= 0);

  // Fatal Errors goes to an assert

  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_LogSystem (int iKey) // v  -> For the moment 0
//-----------------------------------------------------------------------------
{
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  sstMisc01PrtFilCls oSstPrt;

  // Open Protocol
  iStat = oSstPrt.SST_PrtAuf ( 0, (char*) "TestPrt");
  assert(iStat == 0);

  // Close Protocol
  iStat = oSstPrt.SST_PrtZu ( 0);
  assert(iStat == 0);

  return iStat;
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

  // Open existing config file and test contents
  iStat = oAscFil.fopenRd(0,(char*)"CfgFileTest.cfg");
  sstMisc01CfgSetCls oCfgSet;
  sstMisc01CfgFilRowTyp_enum eCfgType;
  std::string oResultStr1;
  std::string oResultStr2;
  std::string oErrStr;

  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  oCfgSet.GetCfgIniRowType(0,&oAscRow, &eCfgType);
  assert (eCfgType == esstMisc01CfgRowSetEmpty);
  assert (oAscRow.compare("") == 0);

  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  oCfgSet.GetCfgIniRowType(0,&oAscRow, &eCfgType);
  assert (eCfgType == esstMisc01CfgRowSetSection);
  assert (oAscRow.compare("[Basics]") == 0);
  oResultStr1 = oCfgSet.GetSection();
  assert (oResultStr1.compare("[Basics]") == 0);

  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (oAscRow.compare("Param2=AAA") == 0);
  oCfgSet.GetCfgIniRowType(0,&oAscRow, &eCfgType);
  assert (eCfgType == esstMisc01CfgRowSetSetting);
  // read parameter and value from cfg file row to cfgset object
  if (eCfgType == esstMisc01CfgRowSetSetting)
    iStat = oCfgSet.FindSetSettings(0,&oAscRow,&oErrStr);
  oResultStr1 = oCfgSet.GetParameter();
  oResultStr2 = oCfgSet.GetValue();
  assert (oResultStr1.compare("Param2") == 0);
  assert (oResultStr2.compare("AAA") == 0);

  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  oCfgSet.GetCfgIniRowType(0,&oAscRow, &eCfgType);
  assert (eCfgType == esstMisc01CfgRowSetEmpty);
  assert (oAscRow.compare("") == 0);

  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  oCfgSet.GetCfgIniRowType(0,&oAscRow, &eCfgType);
  assert (eCfgType == esstMisc01CfgRowSetSection);
  assert (oAscRow.compare("[Settings]") == 0);

  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  oCfgSet.GetCfgIniRowType(0,&oAscRow, &eCfgType);
  assert (eCfgType == esstMisc01CfgRowSetSetting);
  assert (oAscRow.compare("Param1=10.0") == 0);

  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  oCfgSet.GetCfgIniRowType(0,&oAscRow, &eCfgType);
  assert (eCfgType == esstMisc01CfgRowSetSetting);
  assert (oAscRow.compare("Param3=333") == 0);

  iStat = oAscFil.Rd_StrDS1( 2, &oAscRow);
  assert (iStat = -1);  // End of file

  iStat = oAscFil.fcloseFil(0);




  return iStat;
}
//=============================================================================
int Test_ProgressBar (int iKey) // v  -> For the moment 0
//-----------------------------------------------------------------------------
{
  sstMisc01ConPrgBarCls oPrgBar;

  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // open progress bar on console with 10 calls per point
  iStat = oPrgBar.Open ( 0, (char*) "Reading Start", 10);
  assert(iStat == 0);

  for (int ii=0; ii<100; ii++)
  {
    // write tick/call on progress bar
    oPrgBar.Tick ();
  }

  // close progress bar on console
  iStat = oPrgBar.Close ( 0, (char*) "Reading Stop");
  assert(iStat == 0);

  return iStat;
}
//=============================================================================
int Test_FileNameCls (int iKey)
//-----------------------------------------------------------------------------
{
  sstMisc01FilNamCls oSstFilNam;

  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  {
    std::string FilNamEnding="dxf";
    std::string FilNamWith="test.dXf";
    std::string FilNamWithout;
    // remove given ending from filename
    iStat = oSstFilNam.RemoveExtension( 0, FilNamEnding, FilNamWith, &FilNamWithout);
    assert (iStat >= 0);
    assert (FilNamWithout.compare("test") == 0);
  }

  {
    std::string FilNam="testtttt";
    unsigned int PntPos=0;
  // Find point char in filename
  iStat = oSstFilNam.GetPntPos( iKey, &FilNam, &PntPos);
  assert (iStat == 0);
  assert (PntPos == 0);
}
  {
    std::string FilNam="test.ttt";
    unsigned int PntPos=0;
  // Find point char in filename
  iStat = oSstFilNam.GetPntPos( iKey, &FilNam, &PntPos);
  assert (iStat == 1);
  assert (PntPos == 5);
}

  {
    std::string FilNamEnd="dxXf";
    std::string FilNamOld="test.csv";
    std::string FilNamNew;
  // exchange ending in filename with new ending
  iStat = oSstFilNam.ReplaceExtension( 0, &FilNamOld, &FilNamEnd, &FilNamNew);
  assert (iStat >= 0);
  assert (FilNamNew.compare("test.dxXf") == 0);
}

  {
    std::string FilNamEnd="dxfdxf";
    std::string FilNamOld="testtesttesttest.csv";
    std::string FilNamNew;
  // exchange ending in filename with new ending
  iStat = oSstFilNam.ReplaceExtension( 0, &FilNamOld, &FilNamEnd, &FilNamNew);
  assert (iStat >= 0);
  assert (FilNamNew.compare("testtesttesttest.dxfdxf") == 0);
}

  {
    std::string FilNamEnd="test.dxf";
    std::string FilEnd;
    std::string FilNam;
  // Split filenamestring to name and ending
  iStat = oSstFilNam.SplitExtension( iKey, &FilNamEnd, &FilEnd, &FilNam);
  assert (iStat >= 0);
  assert (FilEnd.compare("dxf") == 0);
  assert (FilNam.compare("test") == 0);
}

  return iStat;
}
//=============================================================================

