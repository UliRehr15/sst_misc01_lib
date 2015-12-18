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
sstMisc01AscFilIntCls::sstMisc01AscFilIntCls()
//------------------------------------------------------------------------------
{
  strcpy( this->Nam,"\0");
  this->Hdl = (int) NULL;
  this->Siz = 0;                 // Dateigröße
}
//=============================================================================
// Complete function description is in headerfile
//------------------------------------------------------------------------------
int sstMisc01AscFilIntCls::fopenRd ( int             iKey,
                             const char     *FilNam)
//------------------------------------------------------------------------------
{
  int iStat;
//.............................................................................
  if (iKey != 0) return -1;
  // iStat = 0;

  iStat = strlen( FilNam);
  if (iStat < 1 || iStat >= MAX_PFAD) return -1;

  // Allgemeines ASC-Datei-System initialisieren
  // iStat = casc_ini_c ( 0, CFile);

  // setting b is nessasary from difference between UNIX/Windows
  // (CR/LF or LF)
  if ((  this->Hdl = fopen( FilNam, "r+b")) == NULL)
  {
    // puts("Datei konnte nicht geöffnet werden.");
    iStat = -1;
  }
  else
  {
    // Dateigröße feststellen
    // CFile->Hdl = iStat;
    strcpy( this->Nam, FilNam);
    fseek ( this->Hdl, 0, SEEK_END);  // Get File-Size-Information
    this->Siz = ftell( this->Hdl);
    fseek ( this->Hdl, 0, SEEK_SET);
    iStat = 0;
  }
  return iStat;
}
//=============================================================================
int sstMisc01AscFilIntCls::fopenWr ( int         iKey,     // v  -> Vorerst immer 0
                             const char *FilNam)   //    -> Name der ASC-Datei
//------------------------------------------------------------------------------
{
  // int Hdl;
  int iStat;
//.............................................................................
  if (iKey != 0) return -1;
  iStat = 0;
  Hdl   = 0;

  // Name leer oder fehlerhaft, zurück
  if ( strlen( FilNam) <= 0) return -2;

  // Allgemeines ASC-Datei-System initialisieren
  // iStat = casc_ini_c ( 0, CFile);

  if (( this->Hdl = fopen( FilNam, "w")) == NULL)
  {
    // puts("Datei konnte nicht geöffnet werden.");
    iStat = -1;
  }
  else
  {
    strncpy( this->Nam, FilNam, MAX_PFAD);
    this->Siz = 0;
  }
  return iStat;
}
//=============================================================================
int sstMisc01AscFilIntCls::fopenWr2 ( int         iKey)
//------------------------------------------------------------------------------
{
  // int Hdl;
  int iStat;
//.............................................................................
  if (iKey != 0) return -1;
  iStat = 0;
  Hdl   = 0;

  // Name leer oder fehlerhaft, zurück
  if ( strlen( this->Nam) <= 0) return -2;

  // Allgemeines ASC-Datei-System initialisieren
  // iStat = casc_ini_c ( 0, CFile);

  if (( this->Hdl = fopen( this->Nam, "w")) == NULL)
  {
    // puts("Datei konnte nicht geöffnet werden.");
    iStat = -1;
  }
  else
  {
    // strncpy( this->Nam, FilNam, MAX_PFAD);
    this->Siz = 0;
  }
  return iStat;
}
//=============================================================================
//------------------------------------------------------------------------------
int sstMisc01AscFilIntCls::fsize_get ( int            iKey,    // v  -> Vorerst immer 0
                               long          *FSize)  //   <-  Dateigröße
//------------------------------------------------------------------------------
{
  int iret;
  // int istat;
//.............................................................................
  if (iKey != 0) return -1;
  iret = 0;

  *FSize = this->Siz;

  return iret;
}
//=============================================================================
//------------------------------------------------------------------------------
int sstMisc01AscFilIntCls::fcloseFil ( int Key)
//------------------------------------------------------------------------------
{
  int iStat;
  int iRet;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;


  if ( this->Hdl != 0)
  {
    iStat = fclose( this->Hdl);
    this->Hdl = 0;
    iRet = iStat;
  }
  else
  {
    iRet = -1;
  }
  return iRet;
}
//=============================================================================
//------------------------------------------------------------------------------
int sstMisc01AscFilIntCls::fdeleteFil ( int iKey)
//------------------------------------------------------------------------------
{
  int iStat;
  int iRet;
//.............................................................................
  if (iKey != 0) return -1;
  iRet = 0;


  if ( this->Hdl != 0)
  {
    // iStat= -1;
    // iStat= C_close_c ( CFile->Hdl);
    iStat= fclose( this->Hdl);
    this->Hdl = 0;
    iRet = iStat;
  }
  else
  {
    iRet = -1;
  }

  // Delete File how?
  iRet = -1;
  // iRet = C_unlink_c  ( CFile->Nam);

  return iRet;
}
//=============================================================================
// Complete function description is in headerfile
//-----------------------------------------------------------------------------
int sstMisc01AscFilIntCls::rd_line ( int             iKey,
                             sstMisc01AscRowIntCls  *CLine)
{
  int ichar;

  int ii;

  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 3) return -1;
  iStat = 0;
  ichar = 0;

  // Struktur Text-Zeile initialisieren
  // iStat = casc_LineIni_c ( 0, CLine);

  for (ii=1; ii<=dCASC2_TEXTLEN; ii++)
  {
    ichar = 0;
    iStat = fread ( &ichar, 1, 1, this->Hdl);

    // Test auf nicht druckbare Zeichen an dieser Stelle geht nicht,
    // da noch LF, CR usw. dabei

    if (ichar == EOF || iStat != 1)
    {
      // Datei-Ende erreicht
      CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
      CLine->Len = ii-1;       // Zeilenlänge merken

      // Wenn bis jetzt Inhalt gefunden, ganz normal behandeln,
      // keinen Fehler melden, ansonsten Fehler
      if(ii == 1)
      {
        return -1;
      }
      else
      {
        return ii-1;
      }
    }

    // Test auf Zeilenende

    if(ichar == 10 && iKey >= 2)  // 10 -> LF    (UNIX-Variante)
    {
      // Zeilen-Ende erreicht
      CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
      CLine->Len = ii-1;       // Zeilenlänge merken

      return ii-1;
    }

    if(ichar == 13)  // 13 -> CR/LF (DOS-Variante)
    {

      // LF lesen
      ichar = 0;
      iStat = fread ( &ichar, 1, 1, this->Hdl);
      if (ichar == 10)
      {
        // Zeilen-Ende erreicht
        CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
        CLine->Len = ii-1;       // Zeilenlänge merken
        return ii-1;

      }
      ii++;

    }

    // Hier Test auf nichtdruckbare Zeichen
    // isprint testet nur ASCII (0-127), d.h. keine Umlaute!
    // if ( ! isprint(ichar) && !Str_IsSonderzeichen(0,ichar))
    if ( ichar < 32 || ichar > 255 )
    {
      if (ichar == 9 || ichar == 10)
      {
        // Tabulator und LF (UNIX) übernehmen
      }
      else
      {
        // Abbruch bei nicht druckbaren Zeichen
        CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
        CLine->Len = ii-1;       // Zeilenlänge merken
        return -2;
      }
    }

    CLine->Txt[ii-1] = (char)ichar;  // Buchstaben eintragen
  }

  // Kein reguläres Ende gefunden
  CLine->Txt[dCASC2_TEXTLEN-1] = '\0'; // Zeile ordnungsgemäß abschließen
  CLine->Len = dCASC2_TEXTLEN-1;

  // alle Buchstaben jenseits Spalte dCASC_TEXTLEN in die Tonne
  do
  {
    // iStat = 0;
    ichar = 0;
    iStat = fread ( &ichar, 1, 1, this->Hdl);

  } while ( ichar != 10 && ichar != 13 && ichar != EOF && iStat == 1);

  if ( iKey == 1 || iKey == 3) return -3;
  else return ii-2;
}
//=============================================================================
//-----------------------------------------------------------------------------
int sstMisc01AscFilIntCls::wr_line ( int           iKey,
                             sstMisc01AscRowIntCls *CLine)
{
  // int iStat;
  int iRet;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;

  if (this->Hdl <= NULL) return -2;

  if ( strlen( CLine->Txt) <= 0 && iKey != 1) return -3;
  iRet = 0;

  fprintf(this->Hdl,"%s\n",CLine->Txt);

  return iRet;
}
//=============================================================================
//-----------------------------------------------------------------------------
int sstMisc01AscFilIntCls::wr_txt ( int    iKey,
                            char   Txt[])
{
  // int iStat;
  int iRet;
//.............................................................................
  if (iKey != 0) return -1;

  if (this->Hdl <= NULL) return -2;

  if ( strlen( Txt) <= 0) return -3;
  iRet = 0;

  fprintf(this->Hdl,"%s\n", Txt);

  return iRet;
}
//=============================================================================
int sstMisc01AscFilIntCls::Rd_StrDS2 ( int           iKey,
                               std::string  *StrDS)
//.............................................................................
{
  sstMisc01AscRowIntCls CLine;
  // Cchar tChar;
  // int iChar;
  unsigned int ii;

  // int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;
//  iStat = 0;
//  iChar = 0;

  ii = this->rd_line( 0, &CLine);

  *StrDS = CLine.Txt;

  return ii;
}
//=============================================================================
int sstMisc01AscFilIntCls::Wr_StrDS2 ( int          iKey,
                               std::string *StrDS)
//.............................................................................
{
  sstMisc01AscRowIntCls oAscRow;

  int iRet = 0;
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  iStat = oAscRow.Str2_toLine(0,StrDS);

  iStat = wr_line(0,&oAscRow);

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
int sstMisc01AscFilIntCls::Rd_StrDS1 ( int           iKey,
                               std::string  *StrDS)
//.............................................................................
{
  // Cchar tChar;
  // int iChar;
  sstMisc01AscRowIntCls CLine;
  unsigned int ii;

  // int iStat;
//.............................................................................
  if (iKey != 0) return -1;

  ii = this->rd_line(0,&CLine);

  *StrDS = CLine.Txt;

  return ii;
}
//=============================================================================
int sstMisc01AscFilIntCls::Wr_StrDS1 ( int          iKey,
                               std::string *sStrDS)
//.............................................................................
{
  sstMisc01AscRowIntCls oFilRow;
  int iRet = 0;
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  iStat = oFilRow.Str1_toLine ( 0, sStrDS);

  iStat = this->wr_line ( 0, &oFilRow);

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
//$DA
//$TOPIC casc_line_back_c
int sstMisc01AscFilIntCls::line_back (int iKey)
                           //
                           //   <- Rückgabe Funktion
                           //      0 = OK
                           //     <0 = allgemeiner Fehler
//
//  Erstellt: 11.06.02   UR
//  Geändert: 11.06.02   UR
//
//$KAT ASCI-Dateizeilen-Verwaltung
//$KT  Datei-Lese-Position eine Zeile zurücksetzen
//
//$DE
//.............................................................................
{
  char tchar = 0;
  // int ichar;
  // int ReadSiz;
  // long iPos;
  // int ii;

  int iRet;
  int iStat = 0;
  // Cint4 iStat4;
//.............................................................................
  if (iKey != 0) return -1;
  iRet = 0;
  // iStat = 0;

  // iPos = -1;
  // iStat4 = C_lseek_c ( CFile->Hdl, iPos, 1);
  // iStat = C_read_c (  CFile->Hdl, &tchar, 1);

  // Vorletztes Zeichen noch einmal lesen
  // Bei DOS-Asc-Dateien wird noch einmal -ichar = 10- gelesen,
  // bei Unix-Asc-Dateien wird bereits der letzte Buchstabe gelesen.
  // iPos = -2;
  // iStat4 = C_lseek_c ( CFile->Hdl, iPos, 1);
  // iStat = C_read_c (  CFile->Hdl, &tchar, 1);

  do
  {
    // iStat4 = C_lseek_c ( CFile->Hdl, iPos, 1);
    // iStat = C_read_c (  CFile->Hdl, &tchar, 1);
  } while (tchar != 10 || iStat != 1);

  return iRet;
}
//=============================================================================
long sstMisc01AscFilIntCls::GetFileSize()
{
  return this->Siz;
}
//=============================================================================
