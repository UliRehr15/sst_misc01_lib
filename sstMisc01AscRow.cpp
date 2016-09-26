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
// sstMisc01AscRow.cpp    16.12.15  Re.    16.12.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <list>
#include <string>

#include <sstStr01Lib.h>

#include "sstMisc01Lib.h"
#include "sstMisc01LibInt.h"

//=============================================================================
sstMisc01AscRowIntCls::sstMisc01AscRowIntCls ()
//-----------------------------------------------------------------------------
{
  // int istat;
//.............................................................................
  // if (iKey != 0) return -1;
  // istat = 0;

  memset(this->Txt, 0, dCASC2_TEXTLEN);
  this->Len = 0;

  // return istat;
}
//==============================================================================
/**
* @brief StringDatensatz 2 an StringDatensatz 1 anfügen
*/
//------------------------------------------------------------------------------
int sstMisc01AscRowIntCls::CatLine ( int            iKey,
                             sstMisc01AscRowIntCls *DatZeil2)
//------------------------------------------------------------------------------
{

  int iRet;
  // int iStat;
//.............................................................................
  if ( iKey != 0) return -1;
  iRet = 0;

  if ( this->Len + DatZeil2->Len > dCASC2_TEXTLEN)
  {
    return -1;
  }

  strncat( this->Txt, DatZeil2->Txt, dCASC2_TEXTLEN);
  this->Len = strlen( this->Txt);

  if (iRet < 0)
  {
    assert (iRet >= 0);  // Assert, wenn Ausdruck in Klammmern nicht erfüllt
  }
  return iRet;
}
//=============================================================================
int sstMisc01AscRowIntCls::LineAppendLong (int   iKey,
                                   unsigned long  lValue)
//-----------------------------------------------------------------------------
{
  sstMisc01AscRowIntCls sLineTmp;
  sstStr01Cls oCsvStr;
  std::string oTmpStr;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Int4 in einen String konvertieren und in Zeilenbereich kopieren
  iStat = oCsvStr.Csv_UInt4_2String(0,lValue,&oTmpStr);

  // sLineTmp.Line_toStr1(0,&oTmpStr);
  sLineTmp.Str1_toLine(0, &oTmpStr);

  // Append second row to object
  iStat = this->CatLine ( 0,  &sLineTmp);

  // Heavy Errors goes to an assert
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
int sstMisc01AscRowIntCls::Line_toStr1 (int             iKey,
                                std::string    *Str1)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // if (strlen(this->Txt) <= 0)
  if (strlen(this->Txt) <= 0)
  {
    return -2;
  }

  Str1->clear();

  *Str1 = this->Txt;

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
int sstMisc01AscRowIntCls::Str1_toLine (int          iKey,
                                std::string *Str1)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  strncpy( this->Txt, Str1->c_str(), dCASC2_TEXTLEN-1);
  this->Len = strlen(this->Txt);

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
