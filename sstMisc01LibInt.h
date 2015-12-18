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
// sstMisc01LibInt.h   08.07.15  Re.   08.07.15  Re.
//
// Intern Datastructures and Prototypes for system "sstMisc01Lib"
//

#ifndef   _SST_MISC01_LIB_INT_HEADER
#define   _SST_MISC01_LIB_INT_HEADER

/**
 * @defgroup sstTemplateIntLib
 * cpp template library for intern sst
 */


// Defines ---------------------------------------------------------------------

#define dFINFO_NAM_LEN   12    /**< Extended Explanation for this Define @ingroup sstTemplateIntLib */

/**
 * @brief Extended explanation for define
 * @ingroup sstTemplateIntLib
 */
#define dKODE_MIN

// Structures and Classes ------------------------------------------------------

//==============================================================================
/**
* @brief Casc2 File Row Class
*
* More Comment
*
* Changed: 11.01.14  Re.
*
* @ingroup casc2_lib
*
* @author Re.
*
* @date 11.01.14
*/
// ----------------------------------------------------------------------------
class sstMisc01AscRowIntCls
{
  public:   // Öffentliche Funktionen
     sstMisc01AscRowIntCls();  // Konstruktor
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
                   sstMisc01AscRowIntCls *DatZeil2);
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


     char Txt[dCASC2_TEXTLEN];  /**< One Row in File    */
     int  Len;                 /**< Lenght of File Row  */
  private:  // Private Funktionen
};
//==============================================================================
//==============================================================================
/**
* @brief Casc2 File object Class
*
* More Comment
*
* Changed: 11.01.14  Re.
*
* @ingroup casc2_lib
*
* @author Re.
*
* @date 11.01.14
*/
// ----------------------------------------------------------------------------
class sstMisc01AscFilIntCls
{
  public:   // Öffentliche Funktionen
     sstMisc01AscFilIntCls();  // Konstruktor
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
                   sstMisc01AscRowIntCls  *CLine);
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
                   sstMisc01AscRowIntCls *CLine);

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
     char  Nam[MAX_PFAD];  /**< Dateiname mit Pfad  */
     FILE *Hdl;            /**< Dateihandle         */
     long  Siz;            /**< Dateigröße Bytes    */
};
//==============================================================================


#endif

// --------------------------------------------------------------- File End ----
