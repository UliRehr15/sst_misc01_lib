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
// sstMisc01Lib.h   16.12.15  Re.   16.12.15  Re.
//
// Datastructures and Prototypes for system "sstMisc01Lib"
//

#ifndef   _SST_MISC01_LIB_HEADER
#define   _SST_MISC01_LIB_HEADER

/**
 * @defgroup sstMisc01Lib sstMisc01Lib: cpp sst miscellanious library (Version 1)
 *
 * cpp sst base functions <BR>
 *
 */



// Defines ---------------------------------------------------------------------

#define dCASC2_TEXTLEN    200  /**< Fix Lenght of file row cpp fnc  @ingroup sstMisc01Lib */
#define MAX_PFAD          260  /**< maximale path+filename length   @ingroup sstMisc01Lib */


// Structures and Classes ------------------------------------------------------

// forward declarations --------------------------------------------------------
class sstMisc01AscRowIntCls;
class sstMisc01AscFilIntCls;

//==============================================================================
/**
* @brief sst Asc File Row Class
*
* More Comment
*
* Changed: 11.01.14  Re.
*
* @ingroup sstMisc01Lib
*
* @author Re.
*
* @date 11.01.14
*/
// ----------------------------------------------------------------------------
class sstMisc01AscRowCls
{
  public:   // Öffentliche Funktionen
  sstMisc01AscRowCls();
  ~sstMisc01AscRowCls();
     //==============================================================================
     /**
     * @brief Append second row to object
     *
     * @param iKey     [in] For the moment 0
     * @param DatZeil2 [in] Second Row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int CatLine ( int            iKey,
                   sstMisc01AscRowCls *DatZeil2);
     //==============================================================================
     /**
     * @brief append long value as string to row
     *
     * @param iKey   [in] For the moment 0
     * @param lValue [in] Long value
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int LineAppendLong (int   iKey,
                         long  lValue);
     //==============================================================================
     /**
     * @brief Write object to str1 structure
     *
     * @param iKey [in]  For the moment 0
     * @param Str1 [out] Str1 structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Line_toStr1 (int             iKey,
                      std::string    *Str1);
     //==============================================================================
     /**
     * @brief write object to str2 structure
     *
     * @param iKey [in]  For the moment 0
     * @param Str2 [out] Str2 structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Line_toStr2 (int             iKey,
                      std::string    *Str2);
     //==============================================================================
     /**
     * @brief Import Str1 structure
     *
     * @param iKey [in] For the moment 0
     * @param Str1 [in] Str1 structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Str1_toLine (int          iKey,
                      std::string *Str1);
     //==============================================================================
     /**
     * @brief Import Str2 structure
     *
     * @param iKey [in] For the moment 0
     * @param Str2 [in] Str2 structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Str2_toLine (int          iKey,
                      std::string *Str2);
     //==============================================================================
     /**
     * @brief Get intern object adress
     *
     * @return Return intern object adress
     */
     // ----------------------------------------------------------------------------
     sstMisc01AscRowIntCls* GetIntAdr();
     //==============================================================================
  private:  // Private Functions
     sstMisc01AscRowIntCls* poAscRowInt;
};
//==============================================================================
/**
* @brief sst Asc File object Class
*
* More Comment
*
* Changed: 11.01.14  Re.
*
* @ingroup sstMisc01Lib
*
* @author Re.
*
* @date 11.01.14
*/
// ----------------------------------------------------------------------------
class sstMisc01AscFilCls
{
  public:   // Öffentliche Funktionen
  sstMisc01AscFilCls();
  ~sstMisc01AscFilCls();
     //==============================================================================
     /**
     * @brief Shortstory
     *
     * @param iKey   [in] For the moment 0
     * @param FilNam [in] Name of new file
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int fopenRd ( int             iKey,
                   const char     *FilNam);
     //==============================================================================
     /**
     * @brief Open Asc File for Writing
     *
     * @param iKey   [in] For the moment 0
     * @param FilNam [in] Name of new file
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int fopenWr ( int         iKey,
                   const char *FilNam);
     //==============================================================================
     /**
     * @brief Open Asc File for Writing
     *
     * @param iKey   [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int fopenWr2 ( int         iKey);
     //==============================================================================
     /**
     * @brief Get Size of file
     *
     * @param iKey  [in]  For the moment 0
     * @param FSize [out] Size of file
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int fsize_get ( int    iKey,
                     long  *FSize);
     //==============================================================================
     /**
     * @brief Close file
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int fcloseFil ( int iKey);
     //==============================================================================
     /**
     * @brief Close and delete file
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int fdeleteFil ( int iKey);
     //==============================================================================
     /**
     * @brief Read Row from file
     *
     * @param iKey  [in]  For the moment 0
     * @param CLine [out] File Row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int rd_line ( int             iKey,
                   sstMisc01AscRowCls  *CLine);
     //==============================================================================
     /**
     * @brief Write Row to file
     *
     * @param iKey  [in] For the moment 0
     * @param CLine [in] File Row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int wr_line ( int           iKey,
                   sstMisc01AscRowCls *CLine);

     //==============================================================================
     /**
     * @brief Write Txt String to file
     *
     * @param iKey [in] For the moment 0
     * @param Txt  [in] Text string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int wr_txt ( int    iKey,
                  char   Txt[]);

     //==============================================================================
     /**
     * @brief Read Str2 structure from file
     *
     * iStat = oFile.Rd_StrDS2 ( iKey, *StrDS);
     *
     * @param iKey  [in]  For the moment 0
     * @param StrDS [out] Str2 structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Rd_StrDS2 ( int           iKey,
                     std::string  *StrDS);
     //==============================================================================
     /**
     * @brief Write Str2 structure to file
     *
     * iStat = oFile.Wr_StrDS2 ( iKey, *StrDS);
     *
     * @param iKey  [in] For the moment 0
     * @param StrDS [in] Str2 structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Wr_StrDS2 ( int          iKey,
                     std::string *StrDS);
     //==============================================================================
     /**
     * @brief Read Str1 structure from file
     *
     * iStat = oFile.Rd_StrDS1 ( iKey, *StrDS);
     *
     * @param iKey  [in]  For the moment 0
     * @param StrDS [out] Str1 structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Rd_StrDS1 ( int           iKey,
                     std::string  *StrDS);
     //==============================================================================
     /**
     * @brief Write Str1 structure to file
     *
     * iStat = oFile.Wr_StrDS1 ( iKey, *StrDS);
     *
     * @param iKey  [in] For the moment 0
     * @param StrDS [in] String 1 structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Wr_StrDS1 ( int          iKey,
                     std::string  *StrDS);
     //==============================================================================
     /**
     * @brief Step one line back
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int line_back (int iKey);
     //==============================================================================
     /**
     * @brief GetFileSize
     *
     * @retval   = File Size
     */
     // ----------------------------------------------------------------------------
     long GetFileSize();
     // ----------------------------------------------------------------------------

  private:  // Private Funktionen
     sstMisc01AscFilIntCls* poAscFilInt;

};
//==============================================================================
#endif

// --------------------------------------------------------------- File End ----
