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

#include <list>
#include <string>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>

#include "sstMisc01LibInt.h"

//=============================================================================
sstMisc01PrtMsgIntCls::sstMisc01PrtMsgIntCls()
{
  this->Ik = 0;                       /**< Fehlertyp 0= hochzählbar */
  this->Nr = 0;                       /**< Fehlernummer */
  this->Typ = 0;                      /**< Fehlerklasse 5=fatal => Abbruch */
  memset(this->Txt,0,dMISC01_PRTMELDLEN);  /**< Meldungstext ASCIZ */

}
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

  strncpy( this->Txt, cText, dMISC01_PRTMELDLEN);
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
  oTmpStr.Csv_Int4_2String( 0, lValue, &oString);

  strncpy ( sLine.Txt, this->Txt, dMISC01_PRTMELDLEN);
  sLine.Len = strlen ( sLine.Txt);
  iStat = sLine.Str1_toLine(0,&oString);

  if (sLine.Len < dMISC01_PRTMELDLEN )
  {
   strncpy( this->Txt, sLine.Txt, dMISC01_PRTMELDLEN);
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
