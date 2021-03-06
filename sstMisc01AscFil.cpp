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
// sstMisc01AscFil.cpp    12.03.19  Re.    16.12.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <list>
#include <string>

#include "sstMisc01Lib.h"
#include "sstMisc01LibInt.h"

//=============================================================================
sstMisc01AscFilIntCls::sstMisc01AscFilIntCls()
//------------------------------------------------------------------------------
{
  strcpy( this->Nam,"\0");
  this->Hdl = NULL;
  this->Siz = 0;                 // Dateigröße
  this->iLastChar = 0;
}
//=============================================================================
sstMisc01AscFilIntCls::~sstMisc01AscFilIntCls()
//------------------------------------------------------------------------------
{
  strcpy( this->Nam,"\0");
  this->Siz = 0;                 // Dateigröße
  if (this->Hdl != NULL)
  {
    this->fcloseFil(0);
    this->Hdl = NULL;
  }
}
//=============================================================================
int sstMisc01AscFilIntCls::fopenRd ( int             iKey,
                             const char     *FilNam)
//------------------------------------------------------------------------------
{
  int iStat;
//.............................................................................
  if (iKey != 0) return -1;
  // iStat = 0;

  iStat = strlen( FilNam);
  if (iStat < 1 || iStat >= MAX_PFAD) return -2;

  // setting b is nessasary from difference between UNIX/Windows
  // (CR/LF or LF)
  if ((  this->Hdl = fopen( FilNam, "r+b")) == NULL)
  {
    iStat = -3;
  }
  else
  {
    // Get Filesize
    strcpy( this->Nam, FilNam);
    fseek ( this->Hdl, 0, SEEK_END);
    this->Siz = ftell( this->Hdl);
    fseek ( this->Hdl, 0, SEEK_SET);
    this->iLastChar = 0;
    iStat = 0;
  }
  return iStat;
}
//=============================================================================
int sstMisc01AscFilIntCls::fopenWr ( int         iKey,
                                     const char *FilNam)
//------------------------------------------------------------------------------
{
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // file name empty, return with error
  if ( strlen( FilNam) <= 0) return -2;

  if (( this->Hdl = fopen( FilNam, "w")) == NULL)
  {
    iStat = -1;
  }
  else
  {
    // store file name
    strncpy( this->Nam, FilNam, MAX_PFAD);
    this->Siz = 0;  // File is empty
  }
  return iStat;
}
//=============================================================================
int sstMisc01AscFilIntCls::fopenWr2 ( int         iKey)
//------------------------------------------------------------------------------
{
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // file name empty, return with error
  if ( strlen( this->Nam) <= 0) return -2;

  if (( this->Hdl = fopen( this->Nam, "w")) == NULL)
  {
    iStat = -1;
  }
  else
  {
    this->Siz = 0;
  }
  return iStat;
}
//=============================================================================
int sstMisc01AscFilIntCls::fopenAppend ( int               iKey,
                                         const std::string oFilNam)
//------------------------------------------------------------------------------
{
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // file name empty, return with error
  if ( oFilNam.length() <= 0) return -2;

  if (( this->Hdl = fopen( oFilNam.c_str(), "a")) == NULL)
  {
    iStat = -1;
  }
  else
  {
    // store file name
    strncpy( this->Nam, oFilNam.c_str(), MAX_PFAD);
    this->Siz = 0;  // File is empty
  }
  return iStat;
}
//=============================================================================
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
int sstMisc01AscFilIntCls::fcloseFil ( int iKey)
//------------------------------------------------------------------------------
{
  int iStat = 0;
  int iRet  = 0;
//.............................................................................
  if (iKey != 0) return -1;

  if ( this->Hdl != NULL)
  {
    iStat = fclose( this->Hdl);
    this->Hdl = NULL;
    iRet = iStat;
  }
  else
  {
    iRet = -2;
  }

  return iRet;
}
//=============================================================================
int sstMisc01AscFilIntCls::fdeleteFil ( int iKey)
//------------------------------------------------------------------------------
{
  int iStat = 0;
  int iRet  = 0;
//.............................................................................
  if (iKey != 0) return -1;

  if ( this->Hdl != 0)
  {
    iStat= fclose( this->Hdl);
    this->Hdl = NULL;
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
int sstMisc01AscFilIntCls::rd_line ( int                     iKey,
                                     sstMisc01AscRowIntCls  *CLine)
{
  int ichar = 0;

  // int ii = 0;
  int jj=1;

  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 3) return -1;
  if (this->Hdl == NULL) return -4;
  iStat = 0;
  ichar = 0;

  if (this->iLastChar != 0 && this->iLastChar != 13&& this->iLastChar != 10)
  {
    CLine->Txt[0] = (char)this->iLastChar;  // Buchstaben eintragen
    CLine->Len = 1;
    jj++;
  }
  // this->iLastChar = 0;
  // Struktur Text-Zeile initialisieren
  // iStat = casc_LineIni_c ( 0, CLine);

  for (int ii=jj; ii<=dCASC2_TEXTLEN; ii++)
  {
    if (ii > 1 ) this->iLastChar = ichar;
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
        if (this->iLastChar == 10) return ii-2;
        else return ii-1;
      }
    }

    // Test auf Zeilenende

    switch (ichar)
    {
      case 10:
      {  // LF
        switch (this->iLastChar)
        {
          case 10:
          {  // LF LF

            // Zeilen-Ende erreicht
            CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
            CLine->Len = ii-1;       // Zeilenlänge merken
            this->iLastChar = ichar;
            return ii-1;

            break;
          }  // end case 10 LF LF
          case 13:
          {  // CR LF

            // Zeilen-Ende erreicht
            CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
            CLine->Len = ii-1;       // Zeilenlänge merken
            this->iLastChar = ichar;
            return ii-1;

            break;
          }  // end case CR LF
          default:
          {
            break;
          }  // end default
        }  // end switch ilastchar
        // break;
            // switch ilastchar
        break;
      }      // case 10
      case 13:
      {  // CR
        switch (this->iLastChar)
        {
          case 10:
          {  // LF CR

            // Zeilen-Ende erreicht
//            CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
//            CLine->Len = ii-1;       // Zeilenlänge merken
//            this->iLastChar = ichar;
//            return ii-1;

            break;
          }
          case 13:
          {  // CR CR
            // Zeilen-Ende erreicht
            CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
            CLine->Len = ii-1;       // Zeilenlänge merken
            this->iLastChar = ichar;
            return ii-1;

            break;
          }
          default:
          {
            // do nothing
            break;
          }
          // break;
        }      // switch ilastchar
        break;
      }  // case 13

      default:
      {

      switch (this->iLastChar)
      {
        case 10:
        {  // LF CR

          // Zeilen-Ende erreicht
            CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
            CLine->Len = ii-1;       // Zeilenlänge merken
            this->iLastChar = ichar;
            return ii-1;

          break;
        }
        case 13:
        {  // CR CR
          // Zeilen-Ende erreicht
          CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
          CLine->Len = ii-1;       // Zeilenlänge merken
          this->iLastChar = ichar;
          return ii-1;

          break;
        }
        default:
        {
          // do nothing
          break;
        }
        // break;
      }      // switch ilastchar

      // Hier Test auf nichtdruckbare Zeichen
      // isprint testet nur ASCII (0-127), d.h. keine Umlaute!
      // if ( ! isprint(ichar) && !Str_IsSonderzeichen(0,ichar))
      if ( ichar < 32 || ichar > 255 )
      {
        if (ichar == 9 || ichar == 10|| ichar == 13)
        {
          // Tabulator und LF (UNIX) übernehmen
        }
        else
        {
          if(iKey == 2)
          {
            CLine->Txt[ii-1] = '?'; // Replace not printable char with questionmark
          }
          else
          {
            // Abbruch bei nicht druckbaren Zeichen
            CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
            CLine->Len = ii-1;       // Zeilenlänge merken
            return -2;
          }
        }
      }
      else
      {
        CLine->Txt[ii-1] = (char)ichar;  // Buchstaben eintragen
      }

        break;
      }
    }  // switch ichar

//    // if(ichar == 10 && iKey >= 2)  // 10 -> LF    (UNIX-Variante)
//    if(ichar == 10)  // 10 -> LF    (UNIX-Variante)
//    {
//      // Zeilen-Ende erreicht
//      CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
//      CLine->Len = ii-1;       // Zeilenlänge merken

//      return ii-1;
//    }

//    if(ichar == 13)  // 13 -> CR/LF (DOS-Variante)
//    {

//      // LF read
//      ichar = 0;
//      iStat = fread ( &ichar, 1, 1, this->Hdl);
//      if (ichar == 10)
//      {
//        // CR/LF found
//        CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
//        CLine->Len = ii-1;       // Zeilenlänge merken
//        return ii-1;
//      }
//      else
//      {
//        // only CR found
//        CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
//        CLine->Len = ii-1;       // Zeilenlänge merken
//        this->iLastChar = ichar;
//        return ii-1;
//        //     ii++;
//      }
//    }

//    // Hier Test auf nichtdruckbare Zeichen
//    // isprint testet nur ASCII (0-127), d.h. keine Umlaute!
//    // if ( ! isprint(ichar) && !Str_IsSonderzeichen(0,ichar))
//    if ( ichar < 32 || ichar > 255 )
//    {
//      if (ichar == 9 || ichar == 10|| ichar == 13)
//      {
//        // Tabulator und LF (UNIX) übernehmen
//      }
//      else
//      {
//        // Abbruch bei nicht druckbaren Zeichen
//        CLine->Txt[ii-1] = '\0'; // Zeile ordnungsgemäß abschließen
//        CLine->Len = ii-1;       // Zeilenlänge merken
//        return -2;
//      }
//    }

//    CLine->Txt[ii-1] = (char)ichar;  // Buchstaben eintragen
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
  // else return ii-2;
  else return dCASC2_TEXTLEN-2;
}
//=============================================================================
int sstMisc01AscFilIntCls::wr_line ( int           iKey,
                             sstMisc01AscRowIntCls *CLine)
{
  // int iStat;
  int iRet;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;

  if (this->Hdl == NULL) return -2;

  if ( strlen( CLine->Txt) <= 0 && iKey != 1) return -3;
  iRet = 0;

  fprintf(this->Hdl,"%s\n",CLine->Txt);

  return iRet;
}
//=============================================================================
int sstMisc01AscFilIntCls::wr_txt ( int    iKey,
                            char   Txt[])
{
  // int iStat;
  int iRet;
//.............................................................................
  if (iKey != 0) return -1;

  if (this->Hdl == NULL) return -2;

  if ( strlen( Txt) <= 0) return -3;
  iRet = 0;

  fprintf(this->Hdl,"%s\n", Txt);

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
  // if (iKey != 0) return -1;
  if (iKey < 0 || iKey > 3) return -1;

  ii = this->rd_line ( iKey, &CLine);

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
  if (iKey < 0 || iKey > 1) return -1;

  // Copy string to row object
  iStat = oFilRow.Str1_toLine ( 0, sStrDS);

  // write row objekt to file, if iKey = 1, write also empty row
  iStat = this->wr_line ( iKey, &oFilRow);

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
int sstMisc01AscFilIntCls::Wr_String ( int                iKey,
                                       std::string  sStrDS)
//.............................................................................
{
  sstMisc01AscRowIntCls oFilRow;
  int iRet = 0;
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  iStat = oFilRow.Str1_toLine ( 0, &sStrDS);

  iStat = this->wr_line( 0, &oFilRow);

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
int sstMisc01AscFilIntCls::line_back (int iKey)
//.............................................................................
{
  char tchar = 0;

  int iRet;
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;
  iRet = 0;
  // iStat = 0;

  do
  {
  } while (tchar != 10 || iStat != 1);

  return iRet;
}
//=============================================================================
long sstMisc01AscFilIntCls::GetFileSize()
{
  return this->Siz;
}
//=============================================================================
char* sstMisc01AscFilIntCls::GetFileName()
{
  return this->Nam;
}
//=============================================================================
int sstMisc01FileCompare(int iKey, const std::string oFilNam1, const std::string oFilNam2,
                         unsigned long *ulRowNo)
{
  if (iKey < 0 || iKey > 1) return -1;

  sstMisc01AscFilCls oFil1;
  sstMisc01AscFilCls oFil2;
  int iStat = 0;
  iStat = oFil1.fopenRd(0,(char*) oFilNam1.c_str());
  if (iStat < 0)
  {
    return -2;
  }
  iStat = oFil2.fopenRd(0,(char*) oFilNam2.c_str());
  if (iStat < 0)
  {
    oFil1.fcloseFil(0);
    return -3;
  }
  long lFilSize1 = oFil1.GetFileSize();
  long lFilSize2 = oFil2.GetFileSize();
  if (lFilSize1 != lFilSize2 && iKey != 1)
  {
    *ulRowNo = 0;
    return -6;
  }

  std::string oStr1;
  std::string oStr2;
  int iStat1 = 0;
  int iStat2 = 0;

  *ulRowNo = 0;

  iStat1 = oFil1.Rd_StrDS1(0,&oStr1);
  iStat2 = oFil2.Rd_StrDS1(0,&oStr2);
  while (iStat1 >= 0 && iStat2 >= 0)
  {
    *ulRowNo = *ulRowNo + 1;
    std::size_t tSize = oStr1.compare(oStr2);
    if (tSize != 0)
    {
      oFil1.fcloseFil(0);
      oFil2.fcloseFil(0);
      return -5;
    }
    iStat1 = oFil1.Rd_StrDS1(0,&oStr1);
    iStat2 = oFil2.Rd_StrDS1(0,&oStr2);
    if (iStat1 != iStat2)
    {
      *ulRowNo = *ulRowNo + 1;
      oFil1.fcloseFil(0);
      oFil2.fcloseFil(0);
      return -4;
    }
  }

  *ulRowNo = 0;  // no different row found

  oFil1.fcloseFil(0);
  oFil2.fcloseFil(0);

  return 0;

}
//=============================================================================
