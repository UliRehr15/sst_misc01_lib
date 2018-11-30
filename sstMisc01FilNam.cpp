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
// sstMisc01FilNam.cpp    02.03.16  Re.    02.03.16  Re.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <algorithm>
#include <string>
#include <list>

//#include <kern.h>
//#include <mathem.h>
//#include <str_lib.h>
#include <sstMisc01Lib.h>

#include "sstMisc01LibInt.h"

//=============================================================================
sstMisc01FilNamIntCls::sstMisc01FilNamIntCls()
{

}
//=============================================================================
int sstMisc01FilNamIntCls::RemoveExtension ( int          iKey,
                                             std::string  DatEnd,
                                             std::string  DatNamMit,
                                             std::string *DatNamOhn)
//-----------------------------------------------------------------------------
{
  std::string oTmpDatEnd;
  std::string oTmpDatNamMit;
//-----------------------------------------------------------------------------
  if (iKey != 0) return -1;

  oTmpDatEnd    = DatEnd;
  oTmpDatNamMit = DatNamMit;
  std::size_t oDatEndLen = oTmpDatEnd.length();
  std::size_t oDatNamMitLen = oTmpDatNamMit.length();
  if (oDatEndLen >= oDatNamMitLen) return -2;

  // transform both strings to upper
  std::transform(oTmpDatEnd.begin(), oTmpDatEnd.end(),oTmpDatEnd.begin(), ::toupper);
  std::transform(oTmpDatNamMit.begin(), oTmpDatNamMit.end(),oTmpDatNamMit.begin(), ::toupper);

  unsigned int uiPos =  oTmpDatNamMit.find(oTmpDatEnd);
  if (uiPos == (oDatNamMitLen - oDatEndLen))
  {
    // end string is at end of datnamstring
    DatNamOhn->clear();
    *DatNamOhn = DatNamMit.substr(0,uiPos);
  }
  else return -3;

  return 0;
}
//=============================================================================
int sstMisc01FilNamIntCls::GetPntPos ( int           Key,
                                       std::string  *DatNam,
                                       unsigned int *PktPos)
//-----------------------------------------------------------------------------
{
  unsigned int NamLen;
  // unsigned int ii;
  int iRet;
  // Cint2 iStat;
//-----------------------------------------------------------------------------
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;
  *PktPos = 0;

  // Länge des Dateinamen feststellen
  // Dateiname darf nicht länger 8+4 sein
  // NamLen = strlen ( DatNam);
  NamLen = DatNam->length();
  if ( NamLen > MAX_PFAD-2 || NamLen <= 0)
  //   if ( NamLen > dFINFO_NAM_LENZ-2 || NamLen <= 0) 
  {
    iRet = -1;
    return iRet;
  }

//  // Zeichen -Punkt- von hinten in Dateinamen suchen
//  for (ii=NamLen; ii>=1; ii--)
//  {
//    if ( DatNam[ii-1] == '.')
//    {
//      *PktPos = ii;  // Zeichen -Punkt- gefunden
//      iRet = 1;
//      break;
//    }
//  }
  *PktPos = DatNam->find_last_of(".");
  
  if ( *PktPos < NamLen)
  {
    // Zeichen Punkt gefunden
    iRet = 1;
    // Der Stamm von DOS-Dateinamen darf nicht länger 8 Zeichen sein
    if ( *PktPos >= NamLen || *PktPos < 1)
    {
      *PktPos = 0;
      iRet = -1;
    }
    *PktPos = *PktPos + 1;  // Position is 1 - n
  }
  else
  {
    // Zeichen Punkt nicht gefunden
    *PktPos = 0;
    iRet = 0;
  }
  
  if (iRet < 0)
  {
    // _ASSERT_MSG( iRet >= 0,  "Fehler");
  }
  return iRet;
}
//=============================================================================
int sstMisc01FilNamIntCls::ReplaceExtension ( int          iKey,
                                              std::string *DatNamAlt,
                                              std::string *FilNamSplitExtension,
                                              std::string *FilNamReplaceExtension)
//-----------------------------------------------------------------------------
{

  unsigned int PktPos;     // Die Position des Punktes im String
  unsigned int LenDat;

  int iRet;
  int iStat;
//-----------------------------------------------------------------------------
  if (iKey != 0) return -1;
  iRet = 0;
  iStat = 0;

  // LenDat = strlen ( DatNamAlt);
  LenDat = DatNamAlt->length();

  if ( LenDat > MAX_PFAD || LenDat <= 0)
  {
    return -1;
  }

  // strcpy( FilNamReplaceExtension, "\0");  // Ergebnis vorbesetzen
  FilNamReplaceExtension->clear(); // , "\0");  // Ergebnis vorbesetzen

  // In Dateinamen letztes Zeichen -Punkt- suchen
  // Dateinamen ohne Zeichen Punkt liefert Fehler
  iStat = this->GetPntPos ( 0, DatNamAlt, &PktPos);
  if (iStat <= 0)
  {
    iRet = -1;
  }


  if (iStat == 1) 
  {
    //  Neuen Dateiname zusammensetzen
    // strcpy( FilNamReplaceExtension, DatNamAlt);  // Dateiname umkopieren
    // *FilNamReplaceExtension = *DatNamAlt;  // Dateiname umkopieren
    *FilNamReplaceExtension = DatNamAlt->substr(0,PktPos); // = 0;          // Alte Endung raus
    // strcat( FilNamReplaceExtension, FilNamSplitExtension);  // Neue Endung rein
    *FilNamReplaceExtension = *FilNamReplaceExtension + *FilNamSplitExtension;  // Neue Endung rein
  }
  else if (iStat == 0)
  {
    //  Endung anhängen
    // strcat ( FilNamReplaceExtension, FilNamSplitExtension);
    *FilNamReplaceExtension = *FilNamReplaceExtension + *FilNamSplitExtension;
  }
  else
  {
    iRet =  -1;
  }

  return iRet;
}
//=============================================================================
int sstMisc01FilNamIntCls::SplitExtension (int          iKey,
                                           std::string *cFilNamEnd,
                                           std::string *cFilEnd,
                                           std::string *cFilNam)
//-----------------------------------------------------------------------------
{
  unsigned int iPktPos = 0;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // In String "Dateinamen" den Dezimalpunkt suchen.
  iStat = this->GetPntPos ( 0, cFilNamEnd, &iPktPos);

  if (iPktPos > 0)
  {

    // strncpy(cFilNam,cFilNamEnd,iFilNamLen);
    // *cFilNam = *cFilNamEnd;  // ,iFilNamLen);
  *cFilNam = cFilNamEnd->substr(0,iPktPos-1);  // -1] = 0;

    // strncpy(cFilEnd,&cFilNamEnd[iPktPos],iFilNamLen);
    *cFilEnd = cFilNamEnd->substr(iPktPos);  // ],iFilNamLen);
  }

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

