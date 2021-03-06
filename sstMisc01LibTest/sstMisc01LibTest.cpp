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
// sstMisc01LibTest.cpp    12.03.19  Re.    16.12.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <sstMisc01Lib.h>

#include "sstMisc01LibTest.h"

//=============================================================================
// int main (int argc, char *argv [])
int main ()
//=============================================================================
{
  int iStat = 0;

  printf("Test sstMisc01Lib Start. \n");

  sstMisc01DateTimeCls oDateTimeHdl;
  std::string oDateStr = oDateTimeHdl.getActualDate();
  std::string oTimeStr = oDateTimeHdl.getActualTime();

  std::string oFileNameStr = "tttdxfdsss.dxf";
  std::string oFileExtensionStr = "dxf";

  std::size_t found = oFileNameStr.rfind(oFileExtensionStr);
  assert(found > 0);

  // Test Frame for File Diff functions <BR>
  iStat = Test_FileDiff ( 0);
  assert (iStat >= 0);

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

  printf("Test sstMisc01Lib Success. \n");
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

//=============================================================================
  // Test with not printable chars

  iStat = oAscFil1.fopenWr(0,(char*) oFilNam1.c_str());
  assert (iStat >= 0);

  char cTest[20];

  memset(cTest,0,20);
  strncpy(cTest,"abcdefhi",19);
  cTest[4] = 3;  // set not printable char
  oStr = cTest;

  iStat = oAscFil1.Wr_String( 0, oStr);  // write string with not printable char in file
  assert (iStat >= 0);

  iStat = oAscFil1.fcloseFil(0);
  assert (iStat >= 0);

  iStat = oAscFil1.fopenRd(0, (char*)"Test.asc");
  assert (iStat >= 0);

  oStr.clear();
  iStat = oAscFil1.Rd_StrDS1( 0, &oStr);
  assert(iStat == -2);  // not printable char found

  iStat = oAscFil1.fcloseFil(0);
  assert (iStat >= 0);

  iStat = oAscFil1.fopenRd(0, (char*)"Test.asc");
  assert (iStat >= 0);

  oStr.clear();
  iStat = oAscFil1.Rd_StrDS1( 2, &oStr);
  assert(oStr.length() == 8);
  assert(iStat == 8);  // non printable char is replaced with question mark

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
  sstMisc01PrtMsgCls oMsg;

  // Open Protocol
  iStat = oSstPrt.SST_PrtAuf ( 0, (char*) "TestPrt");
  assert(iStat == 0);

  // Write Message to Console / Protocolfile
  iStat = oSstPrt.SST_PrtWrt( 1, (char*)"Test");

  // Write Message to Console / Protocolfile with char-Value
  iStat = oSstPrt.SST_PrtWrtChar( 1, (char*)"Infotext", (char*)"Message: ");

  // Write Message to Console
  iStat = oSstPrt.SST_PrtWrtConsole( 1, (char*)"Consoletext");

  // Write Message to Console / Protocolfile with Double-Value
  iStat = oSstPrt.SST_PrtWrtDbl( 1, 22.22, (char*)"DoubleValue: ");

  // Write Message to Console / Protocolfile with Unsigned long Int-Value
  iStat = oSstPrt.SST_PrtWrtInt4( 1, 555555, (char*)"UnsignedLongIntValue: ");

  // Write a Messageobject to Console / Protocolfile
  iStat = oSstPrt.SST_PrtWrtMld( 1, &oMsg);

  // Write Message to Console / Protocolfile with Row-Information
  iStat = oSstPrt.SST_PrtWrtZeil( 1, 987654, (char*)"Row Number: ");

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
  assert (iStat == -1);  // End of file Error

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
  assert (iStat == -1);  // End of file Error

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

  printf("Test ProgressBar Functions Start. \n");

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

  printf("Test ProgressBar Functions Finish OK. \n");

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
    sstMisc01FilNamCls oFilNamCnvt;

    std::string cAppDefFilNam="NisdeffApp.deff";
    std::string cCsvExpFilNam;

    iStat = oFilNamCnvt.RemoveExtension( 0, ".deff", cAppDefFilNam, &cCsvExpFilNam);
    assert(iStat == 0);

    cCsvExpFilNam = cCsvExpFilNam + "_TD";
    assert(cCsvExpFilNam == "NisdeffApp_TD");

    cCsvExpFilNam = cCsvExpFilNam + ".csv";
    assert(cCsvExpFilNam == "NisdeffApp_TD.csv");

    cCsvExpFilNam.clear();
    iStat = oFilNamCnvt.RemoveExtension( 0, ".def", cAppDefFilNam, &cCsvExpFilNam);
    assert(iStat == -3);  // string not found at end of filnam
  }

  {
    std::string FilNamEnding="dxf";
    std::string FilNamWith="testdxf.dXf";
    std::string FilNamWithout;
    // remove given ending from filename
    iStat = oSstFilNam.RemoveExtension( 0, FilNamEnding, FilNamWith, &FilNamWithout);
    assert (iStat >= 0);
    assert (FilNamWithout.compare("testdxf.") == 0);
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
int Test_FileDiff (int iKey)
//-----------------------------------------------------------------------------
{

  sstMisc01AscRowCls oAscRow1;
  sstMisc01AscFilCls oAscFil1;
  sstMisc01AscFilCls oAscFil2;
  std::string oFilNam1 = "Test.asc";
  std::string oFilNam2 = "TestCompare.asc";
  std::string oStr;

  // int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  printf("Test File Diff Functions Start. \n");

  //-----------------------------------------------------------------------------

  iStat = oAscFil1.fopenWr(0,(char*) oFilNam1.c_str());
  iStat = oAscFil2.fopenWr(0,(char*) oFilNam2.c_str());

  iStat = oAscFil1.Wr_String(0,"Row1: Test");
  iStat = oAscFil1.Wr_String(0,"TestString");

  iStat = oAscFil2.Wr_String(0,"Row1: Test");
  iStat = oAscFil2.Wr_String(0,"TestString");

  iStat = oAscFil1.fcloseFil(0);
  iStat = oAscFil2.fcloseFil(0);

  unsigned long ulRowNo = 0;
  iStat = sstMisc01FileCompare(0,oFilNam1,oFilNam2,&ulRowNo);
  assert (iStat == 0);
  assert(ulRowNo == 0);  // Files are equal

  //-----------------------------------------------------------------------------

  iStat = oAscFil1.fopenWr(0,(char*) oFilNam1.c_str());
  iStat = oAscFil2.fopenWr(0,(char*) oFilNam2.c_str());

  iStat = oAscFil1.Wr_String(0,"Row1: Test");
  iStat = oAscFil1.Wr_String(0,"TestString");

  iStat = oAscFil2.Wr_String(0,"Row1: Test");
  iStat = oAscFil2.Wr_String(0,"Testttring");  // different second row!

  iStat = oAscFil1.fcloseFil(0);
  iStat = oAscFil2.fcloseFil(0);

  ulRowNo = 0;
  iStat = sstMisc01FileCompare(0,oFilNam1,oFilNam2,&ulRowNo);
  assert (iStat == -5);   // Files are not equal
  assert (ulRowNo == 2);  // Second Row is first different

  //-----------------------------------------------------------------------------

  printf("Test File Diff Functions Finish OK. \n");

  return 0;
}
//=============================================================================
