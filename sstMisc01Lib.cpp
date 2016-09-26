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

#include <list>
#include <string>

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
int sstMisc01AscRowCls::Line_toStr1 (int             iKey,
                               std::string    *Str1)
//-----------------------------------------------------------------------------
{
  return this->poAscRowInt->Line_toStr1(iKey,Str1);
}
//==============================================================================
int sstMisc01AscRowCls::Str1_toLine (int          iKey,
                               std::string *Str1)
//-----------------------------------------------------------------------------
{
  return this->poAscRowInt->Str1_toLine(iKey,Str1);
}
//==============================================================================
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
int sstMisc01AscFilCls::fopenAppend ( int               iKey,
                                      const std::string oFilNam)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->fopenAppend( iKey, oFilNam);
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
  return this->poAscFilInt->rd_line(iKey,CLine->GetIntAdr());
}
//==============================================================================
int sstMisc01AscFilCls::wr_line ( int           iKey,
                            sstMisc01AscRowCls *CLine)
//-----------------------------------------------------------------------------
{
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
int sstMisc01AscFilCls::Wr_String ( int           iKey,
                                    std::string  StrDS)
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->Wr_String ( iKey, StrDS);
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
char* sstMisc01AscFilCls::GetFileName()
//-----------------------------------------------------------------------------
{
  return this->poAscFilInt->GetFileName();
}
//==============================================================================
sstMisc01CfgFilCls::sstMisc01CfgFilCls(std::string oCfgFilNam)
{
  this->poInternObject = new sstMisc01CfgFilIntCls(oCfgFilNam);
}
//==============================================================================
sstMisc01CfgFilCls::~sstMisc01CfgFilCls()
{
  delete (this->poInternObject);
}
//==============================================================================
int sstMisc01CfgFilCls::DeleteWriteNewClose(int iKey)
{
  return this->poInternObject->DeleteWriteNewClose(iKey);
}
//==============================================================================
int sstMisc01CfgFilCls::AddConfigSet(int         iKey,
                               std::string oSection,
                               std::string oParameter,
                               std::string oValue)
{
  return this->poInternObject->AddConfigSet(iKey,oSection,oParameter,oValue);
}
//==============================================================================
sstMisc01CfgSetCls::sstMisc01CfgSetCls()
{
  this->poInternObject = new (sstMisc01CfgSetIntCls);
}
//==============================================================================
sstMisc01CfgSetCls::~sstMisc01CfgSetCls()
{
  delete (this->poInternObject);
}
//=============================================================================
sstMisc01PrtMsgCls::sstMisc01PrtMsgCls()
{
    poInternObject = new(sstMisc01PrtMsgIntCls);
}
//=============================================================================
sstMisc01PrtMsgCls::~sstMisc01PrtMsgCls()
{
    delete(poInternObject);
}
//=============================================================================
sstMisc01PrtMsgIntCls* sstMisc01PrtMsgCls::GetInternAdress ()
{
  return this->poInternObject;
}
//=============================================================================
sstMisc01PrtFilCls::sstMisc01PrtFilCls()
{
    poInternObject = new(sstMisc01PrtFilIntCls);
}
//=============================================================================
sstMisc01PrtFilCls::~sstMisc01PrtFilCls()
{
    delete(poInternObject);
}
//=============================================================================
int sstMisc01PrtFilCls::SST_PrtAuf ( int      iKey,
                                     char    *cFilNam)
//-----------------------------------------------------------------------------
{
  return this->poInternObject->SST_PrtAuf(iKey,cFilNam);
}
//=============================================================================
int sstMisc01PrtFilCls::SST_PrtWrt ( int           iKey,
                                     char         *cMld)
//-----------------------------------------------------------------------------
{
  return this->poInternObject->SST_PrtWrt( iKey, cMld);
}
//=============================================================================
int sstMisc01PrtFilCls::SST_PrtWrtMld ( int                 iKey,
                                        sstMisc01PrtMsgCls *oMld)
//-----------------------------------------------------------------------------
{
  return this->poInternObject->SST_PrtWrtMld( iKey, oMld->GetInternAdress());
}
//=============================================================================
int sstMisc01PrtFilCls::SST_PrtWrtZeil ( int             iKey,
                                         unsigned long   ulZeil,
                                         char           *cMld)
//-----------------------------------------------------------------------------
{
  return this->poInternObject->SST_PrtWrtZeil( iKey, ulZeil, cMld);
}
//=============================================================================
int sstMisc01PrtFilCls::SST_PrtWrtDbl ( int           iKey,
                                        double        dDblVal,
                                        char         *cMld)
//-----------------------------------------------------------------------------
{
  return this->poInternObject->SST_PrtWrtDbl( iKey, dDblVal, cMld);
}
//=============================================================================
int sstMisc01PrtFilCls::SST_PrtWrtInt4 ( int           iKey,
                                         unsigned long          lVal,
                                         char         *cMld)
//-----------------------------------------------------------------------------
{
  return this->poInternObject->SST_PrtWrtInt4( iKey, lVal, cMld);
}
//=============================================================================
int sstMisc01PrtFilCls::SST_PrtWrtChar ( int           iKey,
                                         char         *cVal,
                                         char         *cMld)
//-----------------------------------------------------------------------------
{
  return this->poInternObject->SST_PrtWrtChar( iKey, cVal, cMld);
}
//=============================================================================
int sstMisc01PrtFilCls::SST_PrtWrtConsole (int   iKey,
                                           char *cOutText)
//-----------------------------------------------------------------------------
{
  return this->poInternObject->SST_PrtWrtConsole( iKey, cOutText);
}
//=============================================================================
int sstMisc01PrtFilCls::SST_PrtZu ( int           iKey)
//-----------------------------------------------------------------------------
{
  return this->poInternObject->SST_PrtZu( iKey);
}
//=============================================================================
sstMisc01FilNamCls::sstMisc01FilNamCls()
{
    poInternObject = new(sstMisc01FilNamIntCls);
}
//=============================================================================
sstMisc01FilNamCls::~sstMisc01FilNamCls()
{
    delete(poInternObject);
}
//=============================================================================
int sstMisc01FilNamCls::RemoveExtension ( int   iKey,
                std::string  oFilNamEnding,
                std::string  oFilNamWith,
                std::string *poFilNameWithout)
{
  return this->poInternObject->RemoveExtension(iKey,oFilNamEnding,oFilNamWith,poFilNameWithout);
}
//==============================================================================
int sstMisc01FilNamCls::GetPntPos ( int           iKey,
                                    std::string  *oDatNam,
                                    unsigned int *uiPntPos)
{
  return this->poInternObject->GetPntPos( iKey, oDatNam, uiPntPos);

}
//==============================================================================
int sstMisc01FilNamCls::ReplaceExtension ( int          iKey,
                                    std::string *oFilNamOld,
                                    std::string *oFilNamEnd,
                                    std::string *oFilNamNew)
{
  return this->poInternObject->ReplaceExtension(iKey,oFilNamOld,oFilNamEnd,oFilNamNew);

}
//==============================================================================
int sstMisc01FilNamCls::SplitExtension (int           iKey,
                                   std::string  *oFilNamEnd,
                                   std::string  *oFilEnd,
                                   std::string  *oFilNam)
                                   // unsigned int  uiFilNamLen)
{
  return this->poInternObject->SplitExtension(iKey,oFilNamEnd,oFilEnd,oFilNam);

}
//==============================================================================

