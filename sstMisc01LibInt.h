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

#define dCASC_MELDLEN 80


/**
 * @brief Extended explanation for define
 * @ingroup sstTemplateIntLib
 */
#define dKODE_MIN

// Structures and Classes ------------------------------------------------------

//==============================================================================
/**
* @brief sst Asc File Row Class
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
     * @param ulValue [in] Long value
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int LineAppendLong (int   iKey,
                         unsigned long  ulValue);
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


     char Txt[dCASC2_TEXTLEN];  /**< One Row in File    */
     int  Len;                 /**< Lenght of File Row  */
  private:  // Private Funktionen
};
//==============================================================================
/**
* @brief sst Asc File object Class
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
     * @brief Open Asc File for only reading
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
     * @brief Open Asc File for only Writing
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
     //==============================================================================
     /**
     * @brief GetFileName
     *
     * @retval   = File Name
     */
     // ----------------------------------------------------------------------------
     char* GetFileName();
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
//==============================================================================
/**
* @brief warning message class in log file class
*
* Changed: 19.01.16  Re.
*
* @ingroup sstMisc01IntLib
*
* @author Re.
*
* @date 19.01.16
*/
// ----------------------------------------------------------------------------
class sstMisc01PrtMsgIntCls
{
  public:   // Public functions
     sstMisc01PrtMsgIntCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // SST_MldSet <BR>
     * iStat = oMld.SST_MldSet(iKey,cText,iIk,iNr,Typ);
     *
     * @param iKey  [in] For the moment 0
     * @param cText [in] For the moment 0
     * @param iIk   [in] For the moment 0
     * @param iNr   [in] For the moment 0
     * @param iTyp  [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int SST_MldSet (int           iKey,
                     char         *cText,
                     int           iIk,
                     int           iNr,
                     int           iTyp);
     //==============================================================================
     /**
     * @brief // SST_MldAppendLong <BR>
     * iStat = oMld.SST_MldAppendLong( iKey, lValue);
     *
     * @param iKey   [in] For the moment 0
     * @param lValue [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int SST_MldAppendLong (int           iKey,
                            long          lValue);
     //==============================================================================
     /**
     * @brief // GetMldLength <BR>
     * uiMldLength = oMld.GetMldLength();
     *
     * @return String length of mld
     */
     // ----------------------------------------------------------------------------
     unsigned int GetMldLength();
     //==============================================================================
     /**
     * @brief // GetMldText <BR>
     * cMldChar = oMld.GetMldText();
     *
     * @return Mld Char string
     */
     // ----------------------------------------------------------------------------
     char* GetMldText();
// ----------------------------------------------------------------------------
  private:  // Private functions
     int     Ik;                  /**< Fehlertyp 0= hochzählbar */
     int     Nr;                  /**< Fehlernummer */
     int     Typ;                 /**< Fehlerklasse 5=fatal => Abbruch */
     char    Txt[dCASC_MELDLEN];  /**< Meldungstext ASCIZ */
};

//-----------------------------------------------------------------------------
//$DA
//$TOPIC SST_Prt_stru
//
// struct _SST_Prt_stru
//        {
//          Cint4         Hdl;       // Handle des Protokoll-Systems
//          Cchar         Nam[14];   // Name des Protkoll-Systems
//          SST_HPO_stru  Mld;
//        };
// typedef struct  _SST_Prt_stru SST_Prt_stru;
//
//  Erstellt: 22.03.02  UR
//  Geändert: 01.11.02  UR
//
//$KAT SSTLIB
//$KT  Einfaches Protokoll-System
//
//     Setzt auf das "offizielle" Protokollsystem aus der LageLib auf und
//     bietet eine vereinfachte Funktionalität.
//
//     01.11.02: Ab Version 80 Protokoll-Handle jetzt Int*4.  UR
//
//$DE

//==============================================================================
/**
* @brief Protocol class or log file class
*
* Changed: 09.07.15  Re.
*
* @ingroup sstMisc01IntLib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstMisc01PrtFilIntCls
{
  public:   // Public functions
     sstMisc01PrtFilIntCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //=============================================================================
     /**
     * @brief // Open Protocol <BR>
     * iStat = oSstPrt.SST_PrtAuf ( iKey, *cFilNam);
     *
     * Key = 0: Write only in file, Key = 1: Write to console too.
     *
     * Changed: 11.06.03  UR
     *
     * @param iKey    [in] 0 or 1
     * @param cFilNam [in] Name of Protocolfile
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 11.06.03
     */
     //-----------------------------------------------------------------------------
     int SST_PrtAuf ( int           iKey,
                      char         *cFilNam);
     //=============================================================================
     /**
     * @brief Write in Message in Protocolfile// Shortstory <BR>
     * iStat = oSstPrt.SST_PrtWrt ( iKey, *cMld);
     *
     * More Comment
     *
     * Changed: 11.06.03  UR
     *
     * @param iKey  [in]      For the moment 0
     * @param cMld  [in]      Message
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 11.06.03
     */
     //-----------------------------------------------------------------------------
     int SST_PrtWrt ( int           iKey,
                      char         *cMld);
// ----------------------------------------------------------------------------
     //=============================================================================
     /**
     * @brief // Write a Messageobject in Protocolfile <BR>
     * iStat = oPtr.SST_PrtWrtMld ( iKey, *oMld);
     *
     * Changed: 11.02.10  Re.
     *
     * @param iKey: [in]      For the moment 0
     * @param oMld: [in]      Message-Object
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 11.02.10
     */
     //-----------------------------------------------------------------------------
     int SST_PrtWrtMld ( int           iKey,
                         sstMisc01PrtMsgIntCls *oMld);
     //=============================================================================
     /**
     * @brief // Write Message in Protocolfile with Row-Information <BR>
     * iStat = oSstPrt.SST_PrtWrtZeil ( iKey, lZeil, *cMld);
     *
     * Two Row-Information: First Row-Number, Second Text-Information
     *
     * Changed: 11.06.03  UR
     *
     * @param iKey   [in]      For the moment 0
     * @param ulZeil [in]      Row-Number
     * @param cMld   [in]      Output-Message
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 11.06.03
     */
     //-----------------------------------------------------------------------------
     int SST_PrtWrtZeil ( int             iKey,
                          unsigned long   ulZeil,
                          char           *cMld);
     //=============================================================================
     /**
     * @brief // Write Message to Protocolfile with Double-Value <BR>
     * iStat = oSstPrt.SST_PrtWrtDbl ( iKey, dDblVal, *cMld);
     *
     * Key=1: Write to Console
     *
     * @param iKey      [in]      0 or 1
     * @param dDblVal   [in]      Double Value
     * @param cMld      [in]      Output-Message
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 29.01.10
     */
     //-----------------------------------------------------------------------------
     int SST_PrtWrtDbl ( int           iKey,
                         double        dDblVal,
                         char         *cMld);
     //=============================================================================
     /**
     * @brief // Write Message to Protocolfile with Integer-Value <BR>
     * iStat = oSstPrt.SST_PrtWrtInt4 ( iKey, lVal, *cMld);
     *
     * Key=1: Write to Console
     *
     * Changed: 12.11.07  UR
     *
     * @param iKey  [in]      0 or 1
     * @param lVal  [in]      Long Integer-Value
     * @param cMld  [in]      Output-Message
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 12.11.07
     */
     //-----------------------------------------------------------------------------
     int SST_PrtWrtInt4 ( int           iKey,
                          unsigned long          lVal,
                          char         *cMld);
     //=============================================================================
     /**
     * @brief // Write Message to Protocolfile with char-Value <BR>
     * iStat = oSstPrt.SST_PrtWrtChar ( iKey, *cVal, *cMld);
     *
     * Key = 1: Write to Console too
     *
     * Changed: 12.11.07  UR
     *
     * @param iKey    [in]      0 or 1
     * @param cVal    [in]      Char-Value
     * @param cMld    [in]      Output-Message
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 12.11.07
     */
     //-----------------------------------------------------------------------------
     int SST_PrtWrtChar ( int           iKey,
                          char         *cVal,
                          char         *cMld);
     //=============================================================================
     /**
     * @brief // Write Message to Console <BR>
     * iStat = oSstPrt.SST_PrtWrtConsole ( iKey, *cOutText);
     *
     * More Comment
     *
     * Changed: 12.11.07  UR
     *
     * @param iKey     [in] For the moment 0
     * @param cOutText [in] String for Writing to Console
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 12.11.07
     */
     //-----------------------------------------------------------------------------
     int SST_PrtWrtConsole (int   iKey,
                            char *cOutText);
     //=============================================================================
     /**
     * @brief // Close Protocol <BR>
     * iStat = oSstPrt.SST_PrtZu ( iKey);
     *
     * iKey = 1: Write Close-Message to log file
     *
     * Changed: 11.06.03  UR
     *
     * @param iKey  [in]      0 or 1
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 11.06.03
     */
     //-----------------------------------------------------------------------------
     int SST_PrtZu ( int           iKey);
     //=============================================================================
  private:  // Private functions
  sstMisc01AscFilIntCls  Fil;   /**< Protocol-File */
};
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------


#endif

// --------------------------------------------------------------- File End ----
