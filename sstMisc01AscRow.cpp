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
// sstMisc01LibInt.cpp    16.12.15  Re.    16.12.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

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
///**
//* @brief Append Long Int Value to Line-Structur
//*
//* More Comment
//*
//* Changed: 24.03.10  Re.
//*
//* @ingroup sstlib
//*
//* @param iKey:   [in]      For the moment 0
//* @param sLine:  [in out]  Line-Struktur
//* @param lValue: [in] Long Integer to append as string
//*
//* @return Errorstate
//*
//* @retval   = 0: OK
//* @retval   < 0: Unspecified Error
//*
//* @author Re.
//*
//* @date 24.03.10
//*/
////-----------------------------------------------------------------------------
//int sstMisc01AscRowIntCls::LineAppendLong (int   iKey,
//                                   long  lValue)
////-----------------------------------------------------------------------------
//{
//  sstMisc01AscRowIntCls sLineTmp;
//  int iRet  = 0;
//  int iStat = 0;
////-----------------------------------------------------------------------------
//  if ( iKey != 0) return -1;

//  // Int4 in einen String konvertieren und in Zeilenbereich kopieren
//  // iStat = casc_LineIni_c ( 0, &sLineTmp);
//  iStat = Str_Int4Zeile ( 0, 1, 12, &lValue, sLineTmp.Txt, dCASC2_TEXTLEN);

//  iStat = CatLine ( 0,  &sLineTmp);

//  // Heavy Errors goes to an assert
//  if (iRet < 0)
//  {
//    // Expression (iRet >= 0) has to be fullfilled
//    assert(0);
//  }

//  // Small Errors will given back
//  iRet = iStat;

//  return iRet;
//}
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
//  if (strlen(this->Txt) >= dSTR1_TEXTLEN)
//  {
//    return -3;
//  }

  // iStat = Str1_Init( 0, Str1);
  Str1->clear();

  // iStat = Str1Cpy(0, Str1, this->Txt);
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
int sstMisc01AscRowIntCls::Line_toStr2 (int             iKey,
                                std::string    *Str2)
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
//  if (strlen(this->Txt) >= dSTR1_TEXTLEN)
//  {
//    return -3;
//  }

  // iStat = StrDS2_Ini( 0, Str2);
  Str2->clear();;

  // iStat = Str2Cpy(0, Str2, this->Txt);
  *Str2 = this->Txt;

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

  strncpy( this->Txt, Str1->c_str(), dCASC2_TEXTLEN);
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
int sstMisc01AscRowIntCls::Str2_toLine (int          iKey,
                                std::string *Str2)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  strncpy( this->Txt, Str2->c_str(), dCASC2_TEXTLEN);

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
