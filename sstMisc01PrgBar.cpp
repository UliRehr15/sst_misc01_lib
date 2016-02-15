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
// sstMisc01PrgBar.cpp    15.02.16  Re.    16.12.15  Re.
//
// console progress bar class

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include <string>

// #include <kern.h>
// #include <mathem.h>
// #include <str_lib.h>
#include <sstRec04Lib.h>
#include <sstMisc01Lib.h>
// #include <sstlib2.h>
#include "sstMisc01LibInt.h"

//=============================================================================
sstMisc01ConPrgBarCls::sstMisc01ConPrgBarCls()
{

}
//=============================================================================
int sstMisc01ConPrgBarCls::Open (int                 iKey,
                             char               *cMld,
                             unsigned long       ulParLimit)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  this->ulPointsSet=0;
  // sConPrgBar->dLimit = (double) ulParLimit;
  this->ulLimit = ulParLimit;
  this->ulLimitMult = ulParLimit;
  this->ulNumCalls = 0;

  printf("\n %s: %ld %s \n",cMld,this->ulLimit,"Calls per point");

  printf("\n");

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
int sstMisc01ConPrgBarCls::Close (int    iKey,
                              char  *cMld)
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  printf("\n %ld Calls: %s \n",this->ulNumCalls,cMld);

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
void sstMisc01ConPrgBarCls::Tick ()
//-----------------------------------------------------------------------------
{
  // int iRet  = 0;
  // int iStat = 0;
//-----------------------------------------------------------------------------
  this->ulNumCalls++;  // Number of Calls

  if(this->ulNumCalls >= this->ulLimitMult)
  {
    printf("%s",".");
    this->ulPointsSet++;
    this->ulLimitMult = this->ulLimitMult + this->ulLimit;

  }

  if (this->ulPointsSet >=50)
  {
    printf("%ld",this->ulNumCalls);
    // new line
    printf("\n");
    this->ulPointsSet=0;
  }
}
//=============================================================================


