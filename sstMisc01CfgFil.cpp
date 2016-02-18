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
#include <list>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>

#include "sstMisc01LibInt.h"

//=============================================================================
sstMisc01CfgFilIntCls::sstMisc01CfgFilIntCls(std::string oTmpCfgFilNam)
{
  sstMisc01CfgSetIntCls oCfgSet;
  memset(&this->cActSection,0,dSST_CFG_SECTION_TXTLEN);
  this->oCfgFilNam = oTmpCfgFilNam + ".cfg";
}
//=============================================================================
int sstMisc01CfgFilIntCls::DeleteWriteNewClose(int iKey)
{
  int iStat = 0;
  // int iStat1 = 0;
  if ( iKey != 0) return -1;

  // Rebuild Tree system
  this->oCfgSetList.sort(compare_CfgSetInt);

  // CascObjekt open to write
  sstMisc01AscFilCls oExpFil;

  // open file
  iStat = oExpFil.fopenWr( 0, this->oCfgFilNam.c_str());

  sstMisc01CfgSetIntCls oCfgSet;    /**< config set */

  for (oIterCfgSet=oCfgSetList.begin(); oIterCfgSet!=oCfgSetList.end(); ++oIterCfgSet)
  {
      // std::cout << ' ' << *it;

        iStat = strncmp(this->cActSection,oIterCfgSet->GetSection(),dSST_CFG_SECTION_TXTLEN);
        if (iStat != 0)
        {
          strncpy(this->cActSection,oIterCfgSet->GetSection(),dSST_CFG_SECTION_TXTLEN);
          iStat = oIterCfgSet->WritFileSection(0,&oExpFil);
        }
        iStat = oIterCfgSet->WritFileParameterValue(0,&oExpFil);
  }

  // CascObjekt beenden und zugehörige Datei schließen.
  iStat = oExpFil.fcloseFil(0);

  return iStat;
}
//=============================================================================
int sstMisc01CfgFilIntCls::OpenWriteClose(int iKey)
{
    if ( iKey != 0) return -1;
    return 0;
}
//=============================================================================
int sstMisc01CfgFilIntCls::AddConfigSet(int iKey,
                                std::string oTmpSection,
                                std::string oTmpParameter,
                                std::string oTmpValue)
{
  sstMisc01CfgSetIntCls oCfgSet;    /**< config set */

  if ( iKey != 0) return -1;

    oCfgSet.SetSection(oTmpSection);
    oCfgSet.SetParameter(oTmpParameter);
    oCfgSet.SetValue(oTmpValue);
    oCfgSet.SetCfgSort(oTmpSection,oTmpParameter);
    // this->poCfgSetMem->WritNew( 0,&oCfgSet,&dRecNo);
    this->oCfgSetList.push_back(oCfgSet);

    return 0;
}
//=============================================================================
