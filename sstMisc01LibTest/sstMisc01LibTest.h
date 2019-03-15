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
// sstMisc01LibTest.h   12.03.19  Re.   18.12.15  Re.
//
// Intern Datastructures and Prototypes for system "sstMisc01LibTest"
//

#ifndef   _SST_MISC01_LIB_TEST_HEADER
#define   _SST_MISC01_LIB_TEST_HEADER

int Test_AscFile (int iKey);
int Test_LogSystem (int iKey);
int Test_ConfigSystem (int iKey);
int Test_ProgressBar (int iKey);
int Test_FileNameCls (int iKey);
//==============================================================================
/**
* @brief // Test Frame for File Diff functions <BR>
* iStat = Test_FileDiff ( iKey);
*
* More Comment
*
* Changed: 05.03.19  Re.
*
* @ingroup
*
* @param iKey [in] For the moment 0
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Run Test Error
*
* @author Re.
*
* @date 05.03.19
*/
//------------------------------------------------------------------------------
int Test_FileDiff (int iKey);
//==============================================================================


#endif

// --------------------------------------------------------------- File End ----
