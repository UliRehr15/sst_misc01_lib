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
// sstMisc01CfgSet.cpp    12.02.16  Re.    06.01.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <list>
#include <string>

#include <sstStr01Lib.h>

#include <sstMisc01Lib.h>
#include "sstMisc01LibInt.h"

//=============================================================================
sstMisc01CfgSetIntCls::sstMisc01CfgSetIntCls()
{
  memset(&this->cSection,0,dSST_CFG_SECTION_TXTLEN);
  memset(&this->cParameter,0,dSST_CFG_PARAMETER_TXTLEN);
  memset(&this->cValue,0,dSST_CFG_VALUE_TXTLEN);
  memset(&this->cCfgSort,0,dSST_CFG_SECTION_TXTLEN + dSST_CFG_PARAMETER_TXTLEN);
}
//=============================================================================
int sstMisc01CfgSetIntCls::FindSetSettings (int           iKey,
                                   std::string  *sTmpFilRow,
                                   std::string  *sErrTxt)
//-----------------------------------------------------------------------------
{
  std::string  sTmpParameter;
  std::string  sTmpValue;
  // long lStrPos=0;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Csv ab Position in String konvertieren.
  // lStrPos = 0;
  sstStr01Cls oFrmtTyp;
  oFrmtTyp.SetSeparator(0,(char*)"=");
  iStat = oFrmtTyp.CsvString2_Str( 0, sTmpFilRow, &sTmpParameter);
  iStat = oFrmtTyp.CsvString2_Str( 0, sTmpFilRow, &sTmpValue);

  *sErrTxt = oFrmtTyp.GetErrorString();

  if (sTmpParameter.length() > dSST_CFG_PARAMETER_TXTLEN)
  {
    assert(0);
  }
  if (sTmpValue.length() > dSST_CFG_VALUE_TXTLEN)
  {
    assert(0);
  }

  strncpy(this->cParameter,sTmpParameter.c_str(),dSST_CFG_PARAMETER_TXTLEN);
  strncpy(this->cValue,sTmpValue.c_str(),dSST_CFG_VALUE_TXTLEN);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
// Return Cfg Rowtype Error, Empty, Comment, Section or Setting
// Section will be stored inside
//=============================================================================
int sstMisc01CfgSetIntCls::GetCfgIniRowType(int                    iKey,
                                   std::string           *sTmpFilRow,
                                   sstMisc01CfgFilRowTyp_enum *eCfgSetTyp)
//-----------------------------------------------------------------------------
{
  std::string           sTmpSection;
  sstStr01Cls oRowStr;
  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  *eCfgSetTyp = esstMisc01CfgRowSetError;

  if ( iKey != 0) return -1;

  // iStat = Str1Cpy( 0, &this->sFilRow, sTmpFilRow->Txt);
  if (sTmpFilRow->length() <= 0)
  {
    *eCfgSetTyp = esstMisc01CfgRowSetEmpty;
    return 0;
  }

  // Find comment >;
  if (sTmpFilRow->at(0) == 59)  // 59 = ";"
  {
    *eCfgSetTyp = esstMisc01CfgRowSetComment;
    return 0;
  }

  // Find section
  if (sTmpFilRow->at(0) == 91)  // 91 = "["
  {
    // Return from next informationstring contents inside of brakes.
    oRowStr.SetBracket(0,(char*)"[]");
    oRowStr.GetNextBrakeInfo(0,sTmpFilRow,&sTmpSection);
    strncpy( this->cSection, sTmpSection.c_str(), dSST_CFG_SECTION_TXTLEN);

    *eCfgSetTyp = esstMisc01CfgRowSetSection;
    return 0;
  }

  // All other are Config Settings rows
  *eCfgSetTyp = esstMisc01CfgRowSetSetting;

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
void sstMisc01CfgSetIntCls::SetSection(std::string oTmpSection)
{
  if (oTmpSection.length() >= dSST_CFG_SECTION_TXTLEN) assert (0);
  strncpy( this->cSection, oTmpSection.c_str(), dSST_CFG_SECTION_TXTLEN);
}
//=============================================================================
void sstMisc01CfgSetIntCls::SetParameter(std::string oTmpParameter)
{
  if (oTmpParameter.length() >= dSST_CFG_PARAMETER_TXTLEN) assert (0);
  strncpy( this->cParameter, oTmpParameter.c_str(), dSST_CFG_PARAMETER_TXTLEN);
}
//=============================================================================
void sstMisc01CfgSetIntCls::SetValue(std::string oTmpValue)
{
  if (oTmpValue.length() >= dSST_CFG_VALUE_TXTLEN) assert (0);
  strncpy( this->cValue, oTmpValue.c_str(), dSST_CFG_VALUE_TXTLEN);
}
//=============================================================================
void sstMisc01CfgSetIntCls::SetCfgSort(std::string oTmpSection, std::string oTmpParameter)
{
  strncpy( this->cCfgSort, oTmpSection.c_str(), dSST_CFG_SECTION_TXTLEN);
  strncat( this->cCfgSort, oTmpParameter.c_str(), dSST_CFG_PARAMETER_TXTLEN);
}
//=============================================================================
char* sstMisc01CfgSetIntCls::GetSection()
{
  return this->cSection;
}
//=============================================================================
char* sstMisc01CfgSetIntCls::GetParameter()
{
  return this->cParameter;
}
//=============================================================================
char* sstMisc01CfgSetIntCls::GetValue()
{
  return this->cValue;
}
//=============================================================================
char* sstMisc01CfgSetIntCls::GetCfgSortAdr()
{
  return this->cCfgSort;
}
//=============================================================================
unsigned int sstMisc01CfgSetIntCls::GetCfgSortSize()
{
  return sizeof(this->cCfgSort);
}
//=============================================================================
int sstMisc01CfgSetIntCls::WritFileSection(int iKey,sstMisc01AscFilCls *oExpFil)
{
  sstMisc01AscRowCls oExpRow;
  std::string sFilRow;

  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // write empty row to file
  iStat = oExpFil->wr_line( 1, &oExpRow);

  // write section to row
  sFilRow.clear();
  sFilRow =  "[";
  sFilRow = sFilRow +  this->cSection;
  sFilRow = sFilRow + "]";

  // write row to file
  iStat = oExpRow.Str1_toLine(0,&sFilRow);
  iStat = oExpFil->wr_line( 0, &oExpRow);

  return iStat;
}
//=============================================================================
int sstMisc01CfgSetIntCls::WritFileParameterValue(int iKey,sstMisc01AscFilCls *oExpFil)
{
  sstMisc01AscRowCls oExpRow;
  std::string sFilRow;

  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Str1_Init(0,&sFilRow);
  sFilRow.clear();
  // write parameter to row
  sFilRow = this->cParameter;

  // write value to row
  sFilRow = sFilRow + "=";
  sFilRow = sFilRow + this->cValue;

  iStat = oExpRow.Str1_toLine(0,&sFilRow);
  iStat = oExpFil->wr_line( 0, &oExpRow);

  return iStat;
}
//=============================================================================
// comparison of two sstMisc01CfgSetIntCls objects
bool compare_CfgSetInt (sstMisc01CfgSetIntCls& first, sstMisc01CfgSetIntCls& second)
{ std::string oTmpFirst;
  std::string oTmpSecond;
  oTmpFirst = first.GetCfgSortAdr();
  oTmpSecond = second.GetCfgSortAdr();
  if (oTmpFirst < oTmpSecond) return true;
  return false;
}
//=============================================================================
