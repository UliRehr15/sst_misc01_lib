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
// sstMisc01CfgFil.cpp    12.02.16  Re.    06.01.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

// #include <kern.h>
// #include <mathem.h>
// #include <str_lib.h>
#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
// #include <sstlib2.h>

#include "sstMisc01LibInt.h"

//=============================================================================
sstCfgFilIntCls::sstCfgFilIntCls(std::string oTmpCfgFilNam)
{
  sstCfgSetIntCls oCfgSet;
  memset(&this->cActSection,0,dSST_CFG_SECTION_TXTLEN);
  this->oCfgFilNam = oTmpCfgFilNam + ".cfg";
  // Str1_Init(0, &sFilRow);
  this->sFilRow.clear();
  this->poCfgSetMem = new sstRec04Cls(sizeof(oCfgSet));
  // Init new Tree sorting object for RecMem object
  int iStat = this->poCfgSetMem->TreIni( 0, &oCfgSet, oCfgSet.GetCfgSortAdr(), oCfgSet.GetCfgSortSize(), sstRecTyp_CC, &this->oTre);
  assert(iStat >= 0);
}
//=============================================================================
sstCfgFilIntCls::~sstCfgFilIntCls()
{
  delete(this->poCfgSetMem);
}
//=============================================================================
int sstCfgFilIntCls::DeleteWriteNewClose(int iKey)
{
  int iStat = 0;
  if ( iKey != 0) return -1;

  // Rebuild Tree system
  iStat = this->poCfgSetMem->TreBld ( 0, &this->oTre);

  // CascObjekt open to write
  sstMisc01AscFilCls oExpFil;

  // open file
  iStat = oExpFil.fopenWr( 0, this->oCfgFilNam.c_str());

  sstCfgSetIntCls oCfgSet;    /**< config set */

//  for(dREC04RECNUMTYP ii = 1; ii <= this->poCfgSetMem->count(); ii++)
//  {
//    this->poCfgSetMem->Read(0,ii,&oCfgSet);

//    iStat = oCfgSet.WritFileSection(0,&oExpFil);
//    iStat = oCfgSet.WritFileParameterValue(0,&oExpFil);
//  }

  dREC04RECNUMTYP dRecNo1 = 0;
  int iStat1 = 0;
  iStat1 = this->poCfgSetMem->TreReadNxtGE ( 0, &this->oTre, &oCfgSet, &dRecNo1);
  while (iStat1 >= 0)
  {
    iStat = strncmp(this->cActSection,oCfgSet.GetSection(),dSST_CFG_SECTION_TXTLEN);
    if (iStat != 0)
    {
      strncpy(this->cActSection,oCfgSet.GetSection(),dSST_CFG_SECTION_TXTLEN);
      iStat = oCfgSet.WritFileSection(0,&oExpFil);
    }
    iStat = oCfgSet.WritFileParameterValue(0,&oExpFil);
    iStat1 = this->poCfgSetMem->TreReadNxtGE ( 0, &this->oTre, &oCfgSet, &dRecNo1);
  }

  // CascObjekt beenden und zugehörige Datei schließen.
  iStat = oExpFil.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstCfgFilIntCls::OpenWriteClose(int iKey)
{
    if ( iKey != 0) return -1;
    return 0;
}
//=============================================================================
int sstCfgFilIntCls::AddConfigSet(int iKey,
                                std::string oTmpSection,
                                std::string oTmpParameter,
                                std::string oTmpValue)
{
  sstCfgSetIntCls oCfgSet;    /**< config set */

  if ( iKey != 0) return -1;

    dREC04RECNUMTYP dRecNo = 0;
    oCfgSet.SetSection(oTmpSection);
    oCfgSet.SetParameter(oTmpParameter);
    oCfgSet.SetValue(oTmpValue);
    oCfgSet.SetCfgSort(oTmpSection,oTmpParameter);
    this->poCfgSetMem->WritNew( 0,&oCfgSet,&dRecNo);

    return 0;
}
//=============================================================================
