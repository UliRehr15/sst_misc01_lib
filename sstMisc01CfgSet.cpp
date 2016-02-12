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

#include <string>

#include <sstStr01Lib.h>
#include <sstRec04Lib.h>

#include <sstMisc01Lib.h>
#include "sstMisc01LibInt.h"

//=============================================================================
sstCfgSetIntCls::sstCfgSetIntCls()
{
  memset(&this->cSection,0,dSST_CFG_SECTION_TXTLEN);
  memset(&this->cParameter,0,dSST_CFG_PARAMETER_TXTLEN);
  memset(&this->cValue,0,dSST_CFG_VALUE_TXTLEN);
  memset(&this->cCfgSort,0,dSST_CFG_SECTION_TXTLEN + dSST_CFG_PARAMETER_TXTLEN);
}
//=============================================================================
int sstCfgSetIntCls::FindSetSettings (int           iKey,
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
int sstCfgSetIntCls::GetTonIniRowType(int                    iKey,
                                   std::string           *sTmpFilRow,
                                   sstCfgFilRowTyp_enum *eTONSetTyp)
{
  std::string           sTmpSection;
  sstStr01Cls oRowStr;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  *eTONSetTyp = eCfgRowSetError;

  if ( iKey != 0) return -1;

  // iStat = Str1Cpy( 0, &this->sFilRow, sTmpFilRow->Txt);
  if (sTmpFilRow->length() <= 0)
  {
    *eTONSetTyp = eCfgRowSetEmpty;
    return 0;
  }

  // Find comment >;
  if (sTmpFilRow->at(0) == 59)  // 59 = ";"
  {
    *eTONSetTyp = eCfgRowSetComment;
    return 0;
  }

  // Find section
  if (sTmpFilRow->at(0) == 91)  // 91 = "["
  {
    // Return from next informationstring contents inside of brakes.
    // long lStrPos=0;
    // iStat = Str1_GetNextBrakeInfo ( 1, sTmpFilRow, &lStrPos, (char*)"[",(char*) "]", &sTmpSection);
    oRowStr.SetBracket(0,(char*)"[]");
    oRowStr.GetNextBrakeInfo(0,sTmpFilRow,&sTmpSection);
    strncpy( this->cSection, sTmpSection.c_str(), dSST_CFG_SECTION_TXTLEN);

    *eTONSetTyp = eCfgRowSetSection;
    return 0;
  }

  // All other are TON Settings rows
  *eTONSetTyp = eCfgRowSetSetting;

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
void sstCfgSetIntCls::SetSection(std::string oTmpSection)
{
  strncpy( this->cSection, oTmpSection.c_str(), dSST_CFG_SECTION_TXTLEN);
}
//=============================================================================
void sstCfgSetIntCls::SetParameter(std::string oTmpParameter)
{
  strncpy( this->cParameter, oTmpParameter.c_str(), dSST_CFG_PARAMETER_TXTLEN);
}
//=============================================================================
void sstCfgSetIntCls::SetValue(std::string oTmpValue)
{
  strncpy( this->cValue, oTmpValue.c_str(), dSST_CFG_VALUE_TXTLEN);
}
//=============================================================================
void sstCfgSetIntCls::SetCfgSort(std::string oTmpSection, std::string oTmpParameter)
{
  strncpy( this->cCfgSort, oTmpSection.c_str(), dSST_CFG_SECTION_TXTLEN);
  strncat( this->cCfgSort, oTmpParameter.c_str(), dSST_CFG_PARAMETER_TXTLEN);
}
//=============================================================================
char* sstCfgSetIntCls::GetSection()
{
  return this->cSection;
}
//=============================================================================
char* sstCfgSetIntCls::GetParameter()
{
  return this->cParameter;
}
//=============================================================================
char* sstCfgSetIntCls::GetValue()
{
  return this->cValue;
}
//=============================================================================
char* sstCfgSetIntCls::GetCfgSortAdr()
{
  return this->cCfgSort;
}
//=============================================================================
unsigned int sstCfgSetIntCls::GetCfgSortSize()
{
  return sizeof(this->cCfgSort);
}
//=============================================================================
int sstCfgSetIntCls::WritFileSection(int iKey,sstMisc01AscFilCls *oExpFil)
{
  sstMisc01AscRowCls oExpRow;
  std::string sFilRow;

  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // write empty row to file
  iStat = oExpFil->wr_line( 1, &oExpRow);

  // write section to row
//  iStat = Str1Cpy(0,&sFilRow, (char*) "[");
//  iStat = Str1Cat(0,&sFilRow, this->sSection.Txt);
//  iStat = Str1Cat(0,&sFilRow, (char*)"]");
  // Str1_Init(0,&sFilRow);
  sFilRow.clear();
//  strncpy(sFilRow.Txt, (char*) "[", dSTR1_TEXTLEN);
//  strncat(sFilRow.Txt, this->cSection, dSTR1_TEXTLEN);
//  strncat(sFilRow.Txt, (char*)"]", dSTR1_TEXTLEN);
  sFilRow =  "[";
  sFilRow = sFilRow +  this->cSection;
  sFilRow = sFilRow + "]";

  // write row to file
  iStat = oExpRow.Str1_toLine(0,&sFilRow);
  iStat = oExpFil->wr_line( 0, &oExpRow);

  return iStat;
}
//=============================================================================
int sstCfgSetIntCls::WritFileParameterValue(int iKey,sstMisc01AscFilCls *oExpFil)
{
  sstMisc01AscRowCls oExpRow;
  std::string sFilRow;

  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Str1_Init(0,&sFilRow);
  sFilRow.clear();
  // write parameter to row
  // iStat = Str1Cpy(0,&sFilRow, this->sParameter.Txt);
  // strncpy(sFilRow.Txt, this->cParameter, dSTR1_TEXTLEN);
  sFilRow = this->cParameter;

  // write value to row
//  iStat = Str1Cat(0,&sFilRow, (char*) "=");
//  iStat = Str1Cat(0,&sFilRow, this->sValue.Txt);
//  strncat(sFilRow.Txt, (char*) "=", dSTR1_TEXTLEN);
//  strncat(sFilRow.Txt, this->cValue, dSTR1_TEXTLEN);
  sFilRow = sFilRow + "=";
  sFilRow = sFilRow + this->cValue;

  iStat = oExpRow.Str1_toLine(0,&sFilRow);
  iStat = oExpFil->wr_line( 0, &oExpRow);

  return iStat;
}
//=============================================================================
