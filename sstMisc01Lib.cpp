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
// sstMisc01Lib.cpp    16.12.15  Re.    16.12.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <sstRec04Lib.h>

#include "sstMisc01Lib.h"
#include "sstMisc01LibInt.h"

//==============================================================================
sstMisc01AscRowCls::sstMisc01AscRowCls()
//-----------------------------------------------------------------------------
     {
  this->poAscRowInt = new (sstMisc01AscRowIntCls);
     }
//==============================================================================
sstMisc01AscRowCls::~sstMisc01AscRowCls()
//-----------------------------------------------------------------------------
     {
       delete (this->poAscRowInt);
     }
//==============================================================================
int sstMisc01AscRowCls::CatLine ( int            iKey,
                            sstMisc01AscRowCls *DatZeil2)
//-----------------------------------------------------------------------------
{
  return this->poAscRowInt->CatLine(iKey,DatZeil2->poAscRowInt);
}
//==============================================================================
//int sstMisc01AscRowCls::LineAppendLong (int   iKey,
//                                  long  lValue)
////-----------------------------------------------------------------------------
//{
//  return this->poAscRowInt->LineAppendLong(iKey,lValue);
//}
//==============================================================================
int sstMisc01AscRowCls::Line_toStr1 (int             iKey,
                               std::string    *Str1)
//-----------------------------------------------------------------------------
{
  return this->poAscRowInt->Line_toStr1(iKey,Str1);
}
//==============================================================================
int sstMisc01AscRowCls::Line_toStr2 (int             iKey,
                               std::string    *Str2)
//-----------------------------------------------------------------------------
{
  return this->poAscRowInt->Line_toStr2(iKey,Str2);
}
//==============================================================================
int sstMisc01AscRowCls::Str1_toLine (int          iKey,
                               std::string *Str1)
//-----------------------------------------------------------------------------
{
  return this->poAscRowInt->Str1_toLine(iKey,Str1);
}
//==============================================================================
int sstMisc01AscRowCls::Str2_toLine (int          iKey,
                               std::string *Str2)
//-----------------------------------------------------------------------------
{
  return this->poAscRowInt->Str2_toLine(iKey,Str2);
}
//=============================================================================
sstMisc01AscRowIntCls* sstMisc01AscRowCls::GetIntAdr()
{
  return this->poAscRowInt;
}
//=============================================================================
sstMisc01AscFilCls::sstMisc01AscFilCls()
//-----------------------------------------------------------------------------
{
    this->poAscFilInt = new(sstMisc01AscFilIntCls);
}
//=============================================================================
sstMisc01AscFilCls::~sstMisc01AscFilCls()
//-----------------------------------------------------------------------------
{
    delete (this->poAscFilInt);
}
//==============================================================================
int sstMisc01AscFilCls::fopenRd ( int             iKey,
                            const char     *FilNam)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->fopenRd( iKey, FilNam);
}
//==============================================================================
int sstMisc01AscFilCls::fopenWr ( int         iKey,
                            const char *FilNam)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->fopenWr ( iKey, FilNam);
}
//==============================================================================
int sstMisc01AscFilCls::fopenWr2 ( int  iKey)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->fopenWr2( iKey);
}
//==============================================================================
int sstMisc01AscFilCls::fsize_get ( int    iKey,
                              long  *FSize)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->fsize_get ( iKey, FSize);
}
//==============================================================================
int sstMisc01AscFilCls::fcloseFil ( int iKey)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->fcloseFil(iKey);
}
//==============================================================================
int sstMisc01AscFilCls::fdeleteFil ( int iKey)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->fdeleteFil( iKey);
}
//==============================================================================
int sstMisc01AscFilCls::rd_line ( int             iKey,
                            sstMisc01AscRowCls  *CLine)
//-----------------------------------------------------------------------------
{
  // return this->poAscFilInt->rd_line(iKey,CLine->poAscRowInt);
  return this->poAscFilInt->rd_line(iKey,CLine->GetIntAdr());
}
//==============================================================================
int sstMisc01AscFilCls::wr_line ( int           iKey,
                            sstMisc01AscRowCls *CLine)
//-----------------------------------------------------------------------------
{
  // return this->poAscFilInt->wr_line( iKey, CLine->poAscRowInt);
  return this->poAscFilInt->wr_line( iKey, CLine->GetIntAdr());
}
//==============================================================================
int sstMisc01AscFilCls::wr_txt ( int    iKey,
                           char   Txt[])
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->wr_txt(iKey,Txt);
}
//==============================================================================
int sstMisc01AscFilCls::Rd_StrDS2 ( int           iKey,
                              std::string  *StrDS)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->Rd_StrDS2(iKey,StrDS);
}
//==============================================================================
int sstMisc01AscFilCls::Wr_StrDS2 ( int          iKey,
                              std::string *StrDS)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->Wr_StrDS2 ( iKey, StrDS);
}
//==============================================================================
int sstMisc01AscFilCls::Rd_StrDS1 ( int           iKey,
                              std::string  *StrDS)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->Rd_StrDS1(iKey,StrDS);
}
//==============================================================================
int sstMisc01AscFilCls::Wr_StrDS1 ( int           iKey,
                              std::string  *StrDS)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->Wr_StrDS1 ( iKey, StrDS);
}
//==============================================================================
int sstMisc01AscFilCls::line_back (int iKey)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->line_back(iKey);
}
//==============================================================================
long sstMisc01AscFilCls::GetFileSize()
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->GetFileSize();
}
//==============================================================================
sstMisc01CfgFilCls::sstMisc01CfgFilCls(std::string oCfgFilNam)
{
  this->poTestIntern = new sstMisc01CfgFilIntCls(oCfgFilNam);
}
//==============================================================================
sstMisc01CfgFilCls::~sstMisc01CfgFilCls()
{
  delete (this->poTestIntern);
}
//==============================================================================
int sstMisc01CfgFilCls::DeleteWriteNewClose(int iKey)
{
  return this->poTestIntern->DeleteWriteNewClose(iKey);
}
//==============================================================================
int sstMisc01CfgFilCls::AddConfigSet(int         iKey,
                               std::string oSection,
                               std::string oParameter,
                               std::string oValue)
{
  return this->poTestIntern->AddConfigSet(iKey,oSection,oParameter,oValue);
}
//==============================================================================
sstMisc01CfgSetCls::sstMisc01CfgSetCls()
{
  this->poTestIntern = new (sstMisc01CfgSetIntCls);
}
//==============================================================================
sstMisc01CfgSetCls::~sstMisc01CfgSetCls()
{
  delete (this->poTestIntern);
}
//==============================================================================
