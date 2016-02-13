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
 * @defgroup sstMisc01IntLib sstMisc01IntLib: cpp sst miscellanious intern library (Version 1)
 *
 * cpp sst base functions <BR>
 *
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
* @ingroup sstMisc01IntLib
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
* @ingroup sstMisc01IntLib
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
//==============================================================================
enum _sstCfgFilRowTyp_enum
{ eCfgRowSetEmpty,     /**< Empty Row         */
  eCfgRowSetComment,   /**< Comment Row       */
  eCfgRowSetSection,   /**< Section Row       */
  eCfgRowSetSetting,   /**< Parameter Row     */
  eCfgRowSetUnknown,   /**< Unknown Row       */
  eCfgRowSetError,     /**< Error   Row       */
     };
typedef enum _sstCfgFilRowTyp_enum sstCfgFilRowTyp_enum;

#define dSST_CFG_SECTION_TXTLEN   10  /**< Fix Lenght of config section @ingroup casc_lib2 */
#define dSST_CFG_PARAMETER_TXTLEN   10  /**< Fix Lenght of config parameter @ingroup casc_lib2 */
#define dSST_CFG_VALUE_TXTLEN   10  /**< Fix Lenght of config value @ingroup casc_lib2 */

//==============================================================================
/**
* @brief sst Lib Config Set Class
*
* More Comment
*
* Changed: 10.12.14  Re.
*
* @ingroup sstMisc01IntLib
*
* @author Re.
*
* @date 10.12.14
*/
// ----------------------------------------------------------------------------
class sstMisc01CfgSetIntCls
{
  public:   // Public functions
     sstMisc01CfgSetIntCls();   // Constructor

     /**
     * @brief Find row type from Config Ini Row
     *
     * @param iKey       [in]  For the moment 0
     * @param sFilRow    [in]  set file row to class
     * @param eCfgSetTyp [out] Setting Type of fil row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
    int GetCfgIniRowType(int iKey, std::string *sFilRow, sstCfgFilRowTyp_enum *eCfgSetTyp);
     //==============================================================================
     /**
     * @brief Find settings values in ini file row and set into cfg object
     *
     * iStat = oCfgIniRow.FindSetSettings ( iKey, std::string  *sFilRow);
     *
     * Settings row is for example "Name=NIS" <BR>
     * Set Settings value 1 > Parameter (Name) <BR>
     * Set Settings Value 2 > value (NIS) <BR>
     *
     * @param iKey       [in]   For the moment 0
     * @param sFilRow    [in]   set file row to class
     * @param sErrTxt    [out]  return error text
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int FindSetSettings (int           iKey,
                          std::string  *sFilRow,
                          std::string  *sErrTxt);

    // ~X();   // Destructor
     //==============================================================================
     /**
     * @brief // SetSection <BR>
     * oCfgIniRow.SetSelection(oSection);
     *
     * @param oSection [in] Section
     */
     // ----------------------------------------------------------------------------
     void SetSection(std::string oSection);
     //==============================================================================
     /**
     * @brief // Set Parameter <BR>
     * oCfgIniRow.SetParameter(oSection);
     *
     * @param oParameter [in] Parameter
     */
     // ----------------------------------------------------------------------------
     void SetParameter(std::string oParameter);
     //==============================================================================
     /**
     * @brief // Set Value <BR>
     * oCfgIniRow.SetValue(oValue);
     *
     * @param oValue [in] Value
     */
     // ----------------------------------------------------------------------------
     void SetValue(std::string oValue);
     //==============================================================================
     /**
     * @brief // Set Sort Char <BR>
     * oCfgIniRow.CfgSort(oSection, oParameter);
     *
     * @param oSection   [in] Value
     * @param oParameter [in] Value
     */
     // ----------------------------------------------------------------------------
     void SetCfgSort(std::string oSection, std::string oParameter);
     //==============================================================================
     /**
     * @brief // Get Section <BR>
     * oSection = oCfgIniRow.GetSection()
     *
     * @return Section string
     */
     // ----------------------------------------------------------------------------
     char* GetSection();
     //==============================================================================
     /**
     * @brief // Get Parameter <BR>
     * oParameter = oCfgIniRow.GetParameter();
     *
     * @return Parameter string
     */
     // ----------------------------------------------------------------------------
     char* GetParameter();
     //==============================================================================
     /**
     * @brief // Get Value <BR>
     * oValue = oCfgIniRow.GetValue()
     *
     * @return Value string
     */
     // ----------------------------------------------------------------------------
     char* GetValue();
     //==============================================================================
     /**
     * @brief // Get Sort Char Adress <BR>
     * oValue = oCfgIniRow.GetCfgSortAdr()
     *
     * @return Value string
     */
     // ----------------------------------------------------------------------------
     char* GetCfgSortAdr();
     //==============================================================================
     /**
     * @brief // Get Sort Char size <BR>
     * oValue = oCfgIniRow.GetCfgSortSize()
     *
     * @return Sort Char Size
     */
     // ----------------------------------------------------------------------------
     unsigned int GetCfgSortSize();
     //==============================================================================
     /**
     * @brief // Write Section Row into file <BR>
     * iStat = oCfgIniRow.WritFileSection(&oExpFil);
     *
     * @param iKey    [in] For the moment 0
     * @param oExpFil [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WritFileSection(int iKey,sstMisc01AscFilCls *oExpFil);
     //==============================================================================
     /**
     * @brief // Write Parameter/Value Row in File <BR>
     * iStat = oCfgIniRow.WriFileParameterValue()
     *
     * @param iKey    [in] For the moment 0
     * @param oExpFil [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WritFileParameterValue(int iKey,sstMisc01AscFilCls *oExpFil);
     //==============================================================================


protected:
private:  // Private functions
  char cSection[dSST_CFG_SECTION_TXTLEN];       /**< actual section */
  char cParameter[dSST_CFG_PARAMETER_TXTLEN];   /**< actual parameter */
  char cValue[dSST_CFG_VALUE_TXTLEN];           /**< actual parameter value */
  char cCfgSort[dSST_CFG_SECTION_TXTLEN+dSST_CFG_PARAMETER_TXTLEN];  /**< Sort String */
};
//==============================================================================
/**
* @brief sst Lib Config File Class
*
* More Comment
*
* Changed: 10.12.14  Re.
*
* @ingroup sstMisc01IntLib
*
* @author Re.
*
* @date 10.12.14
*/
// ----------------------------------------------------------------------------
class sstMisc01CfgFilIntCls : public sstMisc01AscFilCls
{
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // Constructor <BR>
  * @param oCfgFilNam [in] Config File Name
  */
  // ----------------------------------------------------------------------------
    sstMisc01CfgFilIntCls(std::string oCfgFilNam);   // Constructor
    ~sstMisc01CfgFilIntCls();   // Constructor
     // Delete existing config file, write and close new one
     //==============================================================================
     /**
     * @brief // DeleteWriteNewClose <BR>
     * iStat = oCfgIniFile.DeleteWriteNewClose(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int DeleteWriteNewClose(int iKey);

     //==============================================================================
     /**
     * @brief // OpenWriteClose <BR>
     * iStat = oCfgIniFile.OpenWriteClose(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int OpenWriteClose(int iKey);
     //==============================================================================
     /**
     * @brief // AddConfigSet <BR>
     * iStat = oCfgIniFile.AddConfigSet(iKey,oSection);
     *
     * @param iKey       [in] For the moment 0
     * @param oSection   [in] Section
     * @param oParameter [in] Parameter
     * @param oValue     [in] Value
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int AddConfigSet(int         iKey,
                      std::string oSection,
                      std::string oParameter,
                      std::string oValue);
     //==============================================================================


    // ~X();   // Destructor
     //==============================================================================


private:  // Private functions
  std::string oCfgFilNam;
     std::string sFilRow;     /**< actual file row */
  // sstMisc01CfgSetIntCls oCfgSet;    /**< config set */
  sstRec04Cls *poCfgSetMem;  /**< rec mem for config sets */
  sstRec04TreeKeyCls oTre;
  char cActSection[dSST_CFG_SECTION_TXTLEN];       /**< actual section */

};
//-----------------------------------------------------------------------------


#endif

// --------------------------------------------------------------- File End ----
