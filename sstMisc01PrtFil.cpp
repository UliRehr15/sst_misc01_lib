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
// sstMisc01PrtFil.cpp    15.02.16  Re.    16.12.15  Re.
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
/**
* @brief Open Protocol
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtFilIntCls::SST_PrtAuf ( int          Key,
                               char        *FilNam)
//.............................................................................
{
  sstMisc01AscRowIntCls CLine;

  int iRet;
  int iStat;
//.............................................................................
  if (Key < 0 || Key > 1) return -1;
  iRet = 0;

  // Ascii-Datei öffnen zum Schreiben
  // iStat = casc_fopenWr_c ( 0, &Prt->Fil, FilNam);
  iStat = this->Fil.fopenWr( 0, FilNam);

  if(iStat >= 0)
  { // Protokolldatei geöffnet

    strcpy(CLine.Txt,"Protokolldatei geöffnet: ");
    strcat(CLine.Txt, FilNam);
    CLine.Len = strlen(CLine.Txt);

    // Write in Message in Protocolfile
    // iStat = SST_PrtWrt ( Key, Prt, CLine.Txt);
    iStat = SST_PrtWrt ( Key, CLine.Txt);
  }
  else
  { // Protokolldatei konnte nicht geöffnet werden
    strcpy(CLine.Txt," Protokolldatei konnte nicht geöffnet werden");
    // Write in Message in Protocolfile
    iStat = SST_PrtWrt ( Key, CLine.Txt);
    iRet = -2;
  }
  return iRet;
}
//=============================================================================
/**
* @brief Write in Message in Protocolfile
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtFilIntCls::SST_PrtWrt ( int         Key,
                   char        *Mld)
//.............................................................................
{
  sstMisc01AscRowIntCls CLine;

  int iRet;
  int iStat;
//.............................................................................
  if (Key < 0 || Key > 1) return -1;
  iRet = 0;

  iStat = strlen( Mld);
  if ( iStat < dCASC2_TEXTLEN)
  {
    strcpy( CLine.Txt, Mld);
    CLine.Len = iStat;
  }
  else
  {
    return -1;
  }
  // Eine Zeile in Ascii-Datei schreiben
  // iStat = casc_wr_line_c ( 0, &Prt->Fil, &CLine);
  iStat = this->Fil.wr_line( 0, &CLine);
  if(Key ==1)
    fprintf(stdout," %s \n", CLine.Txt);

  return iRet;
}
//=============================================================================
/**
* @brief Write in Message in Protocolfile
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtFilIntCls::SST_PrtWrtMld ( int           iKey,
                    sstMisc01PrtMsgIntCls *sMld)
//.............................................................................
{
  sstMisc01AscRowIntCls CLine;

  int iRet;
  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;
  iRet = 0;

  // iStat = strlen( sMld->Txt);
  iStat = sMld->GetMldLength();
  if ( iStat < dCASC2_TEXTLEN)
  {
    // strcpy( CLine.Txt, sMld->Txt);
    strncpy( CLine.Txt, sMld->GetMldText(), dCASC_MELDLEN);
    CLine.Len = iStat;
  }
  else
  {
    return -1;
  }
  // Eine Zeile in Ascii-Datei schreiben
  // iStat = casc_wr_line_c ( 0, &Prt->Fil, &CLine);
  iStat = this->Fil.wr_line( 0, &CLine);
  if(iKey == 1)
    fprintf(stdout," %s \n", CLine.Txt);

  return iRet;
}
//=============================================================================
/**
* @brief Write Message in Protocolfile with Row-Information
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtFilIntCls::SST_PrtWrtZeil ( int               Key,
                                   unsigned long     ulZeil,
                                   char             *Mld)
//.............................................................................
{
  sstMisc01AscRowIntCls CLine;
  sstStr01Cls oCsvStr;
  std::string oTmpStr;

  int iRet;
  int iStat;
//.............................................................................
  if (Key < 0 || Key > 1) return -1;
  iRet = 0;

  // strcpy( CLine.Txt, "Fehlerzeile: ");
  oTmpStr = "Fehlerzeile: ";

  // Int4 in einen String konvertieren und in Zeilenbereich kopieren
  // iStat = Str_Int4Zeile ( 0, 14, 20, &Zeil, CLine.Txt, dCASC2_TEXTLEN);
  iStat = oCsvStr.Csv_UInt4_2String( 0, ulZeil, &oTmpStr);

  // Eine Zeile in Ascii-Datei schreiben
  // iStat = casc_wr_line_c ( 0, &Prt->Fil, &CLine);
  // iStat = this->Fil.wr_line( 0, &CLine);
  iStat = this->Fil.Wr_StrDS1(0,&oTmpStr);
  if(Key ==1)
    fprintf(stdout," %s \n", oTmpStr.c_str());

  iStat = strlen( Mld);
  if ( iStat < dCASC2_TEXTLEN-7)
  {
    strncpy( CLine.Txt, "Grund: ",dCASC2_TEXTLEN);
    strncat( CLine.Txt, Mld,dCASC2_TEXTLEN);
    CLine.Len = iStat;
  }
  else
  {
    return -1;
  }

  // Eine Zeile in Ascii-Datei schreiben
  // iStat = casc_wr_line_c ( 0, &Prt->Fil, &CLine);
  iStat = this->Fil.wr_line( 0, &CLine);
  if(Key ==1)
    fprintf(stdout," %s \n", CLine.Txt);

  return iRet;
}
//=============================================================================
/**
* @brief Write Message to Protocolfile with Integer-Value
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtFilIntCls::SST_PrtWrtInt4 ( int            iKey,
                      unsigned long          IntVal,
                      char         *Mld)
//.............................................................................
{
  sstMisc01AscRowIntCls cLineOut;
  // sstMisc01AscRowIntCls cLineInt;

  // int iRet;
  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;
  // iRet = 0;

//  // Int4 in einen String konvertieren und in Zeilenbereich kopieren
//  strcpy(cLineInt.Txt, "      ");
//  iStat = Str_Int4Zeile ( 0, 1, 12, &IntVal, cLineInt.Txt, dCASC_TEXTLEN);
//  strcat(cLineOut.Txt, cLineInt.Txt);  // Long Int anhängen

  strcpy(cLineOut.Txt, Mld);  // Meldung in Ausgabezeile schreiben

  // Append Long Int Value to Line-Structur
  // iStat = casc_LineAppendLong ( 0, &cLineOut, IntVal);
  iStat = cLineOut.LineAppendLong ( 0, IntVal);

  // Eine Zeile in Ascii-Datei schreiben
  // iStat = casc_wr_line_c ( 0, &Prt->Fil, &cLineOut);
  iStat = this->Fil.wr_line( 0, &cLineOut);

  if (iKey == 1)
    iStat = SST_PrtWrtConsole ( 0, cLineOut.Txt);
    // fprintf(stdout," %s \n", cLineOut.Txt);

  return iStat;
}
//=============================================================================
/**
* @brief Write Message to Protocolfile with Double-Value
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtFilIntCls::SST_PrtWrtDbl ( int           Key,
                                  double        DblVal,
                                  char         *Mld)
//.............................................................................
{
  sstMisc01AscRowIntCls cLineOut;
  sstMisc01AscRowIntCls cLineDbl;
  sstStr01Cls oCsvStr;
  std::string oTmpStr;

  // int iRet;
  int iStat;
//.............................................................................
  if (Key < 0 || Key > 1) return -1;
  // iRet = 0;

  // Int4 in einen String konvertieren und in Zeilenbereich kopieren
  // strcpy(cLineDbl.Txt, "        ");
  // iStat = Str_Dbl2Zeile ( 0, 1, 8, DblVal, 2, cLineDbl.Txt, dCASC2_TEXTLEN);
  iStat = oCsvStr.Csv_Dbl_2String( 0, DblVal, &oTmpStr);

  strcpy(cLineOut.Txt, Mld);  // Meldung in Ausgabezeile schreiben

  strcat(cLineOut.Txt, cLineDbl.Txt);  // Long Int anhängen

  // Eine Zeile in Ascii-Datei schreiben
  // iStat = casc_wr_line_c ( 0, &Prt->Fil, &cLineOut);
  iStat = this->Fil.wr_line( 0, &cLineOut);

  if(Key ==1)
    iStat = SST_PrtWrtConsole ( 0, cLineOut.Txt);
    // fprintf(stdout," %s \n", cLineOut.Txt);

  return iStat;
}
//=============================================================================
///**
//* @brief Write Message to Protocolfile with MinMax
//*/
////.............................................................................
//int sstMisc01PrtFilIntCls::SST_PrtWrtMinMax ( int           Key,
//                       MIMA_3D      *rMinMax)
//                       // char         *Mld)
////.............................................................................
//{
//  // sstMisc01AscRowIntCls cLineOut;
//  sstMisc01AscRowIntCls cLineDbl;

//  // int iRet;
//  int iStat;
////.............................................................................
//  if (Key < 0 || Key > 1) return -1;
//  // iRet = 0;

//  if (rMinMax->XI < -9999999999.99 || rMinMax->XI > 9999999999.99) return -2;
//  if (rMinMax->YI < -9999999999.99 || rMinMax->YI > 9999999999.99) return -2;
//  if (rMinMax->ZI <    -9999999.99 || rMinMax->ZI >    9999999.99) return -2;

//  sprintf(cLineDbl.Txt,"MinX %10.2f MinY %10.2f MinZ %7.2f",rMinMax->XI,rMinMax->YI,rMinMax->ZI);
//  // strcat(cLineOut.Txt, cLineDbl.Txt);
//  // iStat = casc_wr_line_c ( 0, &Prt->Fil, &cLineDbl);
//  iStat = this->Fil.wr_line( 0, &cLineDbl);

//  if(Key ==1)
//    iStat = SST_PrtWrtConsole ( 0, cLineDbl.Txt);

//  if (rMinMax->XA < -9999999999.99 || rMinMax->XA > 9999999999.99) return -2;
//  if (rMinMax->YA < -9999999999.99 || rMinMax->YA > 9999999999.99) return -2;
//  if (rMinMax->ZA <    -9999999.99 || rMinMax->ZA >    9999999.99) return -2;

//  sprintf(cLineDbl.Txt,"MaxX %10.2f MaxY %10.2f MaxZ %7.2f",rMinMax->XA,rMinMax->YA,rMinMax->ZA);
//  // strcat(cLineOut.Txt, cLineDbl.Txt);
//  // iStat = casc_wr_line_c ( 0, &Prt->Fil, &cLineDbl);
//  iStat = this->Fil.wr_line( 0, &cLineDbl);

//  if(Key ==1)
//    iStat = SST_PrtWrtConsole ( 0, cLineDbl.Txt);

//  return iStat;
//}
//=============================================================================
/**
* @brief Write Message to Protocolfile with char-Value
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtFilIntCls::SST_PrtWrtChar ( int           Key,
                     char         *CharVal,
                     char         *Mld)
//.............................................................................
{
  sstMisc01AscRowIntCls cLineOut;

  // int iRet = 0;
  int iStat = 0;
//.............................................................................
  if (Key < 0 || Key > 1) return -1;

  strcpy(cLineOut.Txt, Mld);

  strcat(cLineOut.Txt, CharVal);

  // Eine Zeile in Ascii-Datei schreiben
  // iStat = casc_wr_line_c ( 0, &Prt->Fil, &cLineOut);
  iStat = this->Fil.wr_line( 0, &cLineOut);

  if(Key ==1)
    // Write to Console too
    // fprintf(stdout," %s \n", cLineOut.Txt);
    iStat = SST_PrtWrtConsole ( 0, cLineOut.Txt);

  return iStat;
}
//=============================================================================
/**
* @brief Write Message to Console
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtFilIntCls::SST_PrtWrtConsole (int   iKey,
                       char *OutText)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if ( strlen( OutText)<= 0) return -2;

  // if ( strlen(OutText) <= 0) return -1;
  // puts(OutText);
  fprintf ( stdout," %s \n", OutText);

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    // assert("Error in function: xxx");
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
/**
* @brief Close Protocol
*/
//-----------------------------------------------------------------------------
int sstMisc01PrtFilIntCls::SST_PrtZu ( int           iKey)
//.............................................................................
{
  // int iRet;
  // Cint4 iStat4;
  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;
  // iRet = 0;

  // Write Message to Protocolfile with char-Value
  // iStat = SST_PrtWrtChar ( iKey, Prt, Prt->Fil.Nam, (char*)"Protokolldatei geschlossen: ");
  iStat = this->SST_PrtWrtChar ( iKey, this->Fil.GetFileName(), (char*)"Protokolldatei geschlossen: ");

  // if(Key == 1)
  //   fprintf ( stdout," Protokolldatei geschlossen: %s \n", Prt->Fil.Nam);

  // Ascii-Datei schließen
  // iStat = casc_fclose_c ( 0, &Prt->Fil);
  iStat = this->Fil.fcloseFil( 0);

  return iStat;
}
//=============================================================================


