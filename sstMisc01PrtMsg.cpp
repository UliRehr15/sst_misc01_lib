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
// sstMisc01PrtMsg.cpp    15.02.16  Re.    16.12.15  Re.
//

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include <string>

// #include <kern.h>
// #include <mathem.h>
// #include <str_lib.h>
#include <sstStr01Lib.h>
#include <sstRec04Lib.h>
#include <sstMisc01Lib.h>
// #include <sstlib2.h>
#include "sstMisc01LibInt.h"

//=============================================================================
sstMisc01PrtMsgIntCls::sstMisc01PrtMsgIntCls()
{
  this->Ik = 0;                       /**< Fehlertyp 0= hochzählbar */
  this->Nr = 0;                       /**< Fehlernummer */
  this->Typ = 0;                      /**< Fehlerklasse 5=fatal => Abbruch */
  memset(this->Txt,0,dCASC_MELDLEN);  /**< Meldungstext ASCIZ */

}
//=============================================================================
/**
* @brief Meldung initialisieren
*/
//-----------------------------------------------------------------------------
//int SST_MldIni (int iKey,
//                SST_Mld_stru *sMld)
////-----------------------------------------------------------------------------
//{
//  int iRet  = 0;
//  int iStat = 0;
////-----------------------------------------------------------------------------
//  if ( iKey != 0) return -1;

//  memset( sMld->Txt, 0, 80);
//  sMld->Ik = 0;
//  sMld->Nr = 0;
//  sMld->Typ = 0;

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
/**
* @brief Meldung setzen
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtMsgIntCls::SST_MldSet (int           iKey,
                char         *cText,
                int           iIk,
                int           iNr,
                int           Typ)

//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;
  if (strlen(cText) <=0 ) return -2;

  strncpy( this->Txt, cText,dCASC_MELDLEN);
  this->Ik =  iIk;  // Fehlertyp
  this->Nr =  iNr;  // Fehlernummer
  this->Typ = Typ;  // Fehlerklasse

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
/**
* @brief Long Int an Meldung hängen
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtMsgIntCls::SST_MldAppendLong (int           iKey,
                       long          lValue)
//-----------------------------------------------------------------------------
{
  // sstMisc01AscRowIntCls sLineTmp;
  sstMisc01AscRowIntCls sLine;
  sstStr01Cls oTmpStr;
  std::string oString;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Int4 in einen String konvertieren und in Zeilenbereich kopieren
  // iStat = casc_LineIni_c ( 0, &sLineTmp);
  // iStat = Str_Int4Zeile ( 0, 1, 12, &lValue, sLineTmp.Txt, dCASC2_TEXTLEN);
  // sLineTmp.Len = strlen ( sLineTmp.Txt);
  oTmpStr.Csv_Int4_2String( 0, lValue, &oString);

  strncpy ( sLine.Txt, this->Txt, dCASC_MELDLEN);
  sLine.Len = strlen ( sLine.Txt);
  // iStat = casc_CatLine_c ( 0, &sLine, &sLineTmp);
  // iStat = sLine.CatLine( 0, &sLineTmp);
  iStat = sLine.Str1_toLine(0,&oString);

  if (sLine.Len < dCASC_MELDLEN )
  {
   strncpy( this->Txt, sLine.Txt, dCASC_MELDLEN);
  }

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
unsigned int sstMisc01PrtMsgIntCls::GetMldLength()
{
  return strlen(this->Txt);
}
//=============================================================================
char* sstMisc01PrtMsgIntCls::GetMldText()
{
  return this->Txt;
}
//=============================================================================
