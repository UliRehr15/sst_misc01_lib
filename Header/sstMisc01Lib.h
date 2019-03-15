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
// sstMisc01Lib.h   16.05.18  Re.   16.12.15  Re.
//
// Datastructures and Prototypes for system "sstMisc01Lib"
//

#ifndef   _SST_MISC01_LIB_HEADER
#define   _SST_MISC01_LIB_HEADER

/**
 * @defgroup sstMisc01Lib sstMisc01Lib: cpp sst miscellanious library (Version 1)
 *
 * sst Miscellaneous functions Lib <BR>
 *   functions for reading/writing Asc Files  <BR>
 *   functions for logging / protocol file <BR>
 *   functions for config file reading / writing <BR>
 *
 */



// Defines ---------------------------------------------------------------------

#define dCASC2_TEXTLEN    1000  /**< Fix Lenght of Misc01 Asc file row    @ingroup sstMisc01Lib */
#define MAX_PFAD          260  /**< Misc01 maximal path+filename length  @ingroup sstMisc01Lib */


// Structures and Classes ------------------------------------------------------

// forward declarations --------------------------------------------------------
class sstMisc01AscRowIntCls;
class sstMisc01AscFilIntCls;
class sstMisc01CfgSetIntCls;
class sstMisc01CfgFilIntCls;
class sstMisc01PrtMsgIntCls;
class sstMisc01PrtFilIntCls;
class sstMisc01FilNamIntCls;

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
     * @brief // Open Asc File for reading <BR>
     * iStat = oAscFil.fopenRd ( iKey, FilNam);
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
     * @brief // Open Asc File for Writing <BR>
     * iStat = oAscFil.fopenWr ( iKey, FilNam);
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
     * @brief // Open Asc File for Writing with intern file name<BR>
     * iStat = oAscFil.fopenWr2 ( iKey);
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
     * @brief // Open Asc File for appending data <BR>
     * iStat = oAscFil.fopenAppend ( iKey, oFilNam);
     *
     * @param iKey   [in] For the moment 0
     * @param oFilNam [in] Name of existing file
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int fopenAppend ( int               iKey,
                       const std::string oFilNam);
     //==============================================================================
     /**
     * @brief // Get Size of file <BR>
     * iStat = oAscFil.fsize_get ( iKey, FSize);
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
     * @brief // Close file <BR>
     * iStat = oAscFil.fcloseFil ( iKey);
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
     * @brief // Close and delete file <BR>
     * iStat = oAscFil.fdeleteFil ( iKey);
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
     * @brief // Read Row from file <BR>
     * iStat = oAscFil.rd_line ( iKey, CLine);
     *
     * @param iKey  [in]  For the moment 0
     * @param CLine [out] File Row
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -4: File not open
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int rd_line ( int             iKey,
                   sstMisc01AscRowCls  *CLine);
     //==============================================================================
     /**
     * @brief // Write Row to file <BR>
     * iStat = oAscFil.wr_line ( iKey, CLine);
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
     int wr_line ( int                 iKey,
                   sstMisc01AscRowCls *CLine);
     //==============================================================================
     /**
     * @brief // Write Txt String to file <BR>
     * iStat = oAscFil.wr_txt ( iKey, Txt);
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
     * @brief // Read string object from file <BR>
     * iStat = oAscFil.Rd_StrDS1 ( iKey, &oString);
     *
     * @param iKey    [in]  For the moment 0
     * @param oString [out] Str1 structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Rd_StrDS1 ( int           iKey,
                     std::string  *oString);
     //==============================================================================
     /**
     * @brief // Write string object to file <BR>
     * iStat = oAscFil.Wr_StrDS1 ( iKey, &oString);
     *
     * iKey = 0: Empty row will not be written. <BR>
     * iKey = 1: Write empty row too. <BR>
     *
     * @param iKey    [in] 0 or 1
     * @param oString [in] String object
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Wr_StrDS1 ( int           iKey,
                     std::string  *oString);
     //==============================================================================
     /**
     * @brief // Write string object to file <BR>
     * iStat = oAscFil.Wr_String ( iKey, oString);
     *
     * iKey = 0: Empty row will not be written. <BR>
     * iKey = 1: Write empty row too. <BR>
     *
     * @param iKey    [in] 0 or 1
     * @param oString [in] String object
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Wr_String ( int          iKey,
                     std::string  oString);
     //==============================================================================
     /**
     * @brief // Step one line back <BR>
     * iStat = oAscFil.line_back ( iKey);
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
     * @brief // GetFileSize <BR>
     * iStat = oAscFil.GetFileSize ( iKey);
     *
     * @retval   = File Size
     */
     // ----------------------------------------------------------------------------
     long GetFileSize();
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
     sstMisc01AscFilIntCls* poAscFilInt;

};
//==============================================================================
/**
* @brief Definition Enum Config file row type
*
* For example: <BR>
* Comment row:   ; xxx  <BR>
* Section row:   [xxx]  <BR>
* Parameter row: xx=yy  <BR>
*
* Changed: 10.05.16  Re.
*
* @ingroup sstMisc01Lib
*
* @author Re.
*
* @date 10.05.16
*/
// ----------------------------------------------------------------------------
enum _sstMisc01CfgFilRowTyp_enum
{ esstMisc01CfgRowSetEmpty,     /**< Empty Row         */
  esstMisc01CfgRowSetComment,   /**< Comment Row       */
  esstMisc01CfgRowSetSection,   /**< Section Row       */
  esstMisc01CfgRowSetSetting,   /**< Parameter Row     */
  esstMisc01CfgRowSetUnknown,   /**< Unknown Row       */
  esstMisc01CfgRowSetError,     /**< Error   Row       */
     };
typedef enum _sstMisc01CfgFilRowTyp_enum sstMisc01CfgFilRowTyp_enum;
//==============================================================================
/**
* @brief sst Lib Config Set Class
*
* More Comment
*
* Changed: 10.12.14  Re.
*
* @ingroup sstMisc01Lib
*
* @author Re.
*
* @date 10.12.14
*/
// ----------------------------------------------------------------------------
class sstMisc01CfgSetCls
{
  public:   // Public functions
  sstMisc01CfgSetCls();    // Constructor
  ~sstMisc01CfgSetCls();   // Destructor

  //==============================================================================
  /**
  * @brief // Find row type of given Config Row <BR>
  * iStat = oCfgSet.GetCfgIniRowTyp( iKey, &oCfgFilRow, &eCfgType);
  *
  * Return Cfg Rowtype Error, Empty, Comment, Section or Setting. <BR>
  * Section will be stored inside. <BR>
  *
  * @param iKey        [in]  For the moment 0
  * @param sCfgFilRow  [in]  set file row
  * @param eCfgSetTyp  [out] return Cfg row Type of fil row
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------

  int GetCfgIniRowType(int iKey, std::string *sCfgFilRow, sstMisc01CfgFilRowTyp_enum *eCfgSetTyp);
     //==============================================================================
     /**
     * @brief Find settings values in ini file row and set into cfg object
     *
     * iStat = oCfgSet.FindSetSettings ( iKey, std::string  *sFilRow);
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
     * oCfgSet.SetSelection(oSection);
     *
     * @param oSection [in] Section
     */
     // ----------------------------------------------------------------------------
     void SetSection(std::string oSection);
     //==============================================================================
     /**
     * @brief // Set Parameter <BR>
     * oCfgSet.SetParameter(oSection);
     *
     * @param oParameter [in] Parameter
     */
     // ----------------------------------------------------------------------------
     void SetParameter(std::string oParameter);
     //==============================================================================
     /**
     * @brief // Set Value <BR>
     * oCfgSet.SetValue(oValue);
     *
     * @param oValue [in] Value
     */
     // ----------------------------------------------------------------------------
     void SetValue(std::string oValue);
     //==============================================================================
     /**
     * @brief // Set Sort Char <BR>
     * oCfgSet.CfgSort(oSection, oParameter);
     *
     * @param oSection   [in] Value
     * @param oParameter [in] Value
     */
     // ----------------------------------------------------------------------------
     void SetCfgSort(std::string oSection, std::string oParameter);
     //==============================================================================
     /**
     * @brief // Get Section <BR>
     * oSection = oCfgSet.GetSection()
     *
     * @return Section string
     */
     // ----------------------------------------------------------------------------
     char* GetSection();
     //==============================================================================
     /**
     * @brief // Get Parameter <BR>
     * oParameter = oCfgSet.GetParameter();
     *
     * @return Parameter string
     */
     // ----------------------------------------------------------------------------
     char* GetParameter();
     //==============================================================================
     /**
     * @brief // Get Value <BR>
     * oValue = oCfgSet.GetValue()
     *
     * @return Value string
     */
     // ----------------------------------------------------------------------------
     char* GetValue();
     //==============================================================================
     /**
     * @brief // Get Sort Char Adress <BR>
     * oValue = oCfgSet.GetCfgSortAdr()
     *
     * @return Value string
     */
     // ----------------------------------------------------------------------------
     char* GetCfgSortAdr();
     //==============================================================================
     /**
     * @brief // Get Sort Char size <BR>
     * oValue = oCfgSet.GetCfgSortSize()
     *
     * @return Sort Char Size
     */
     // ----------------------------------------------------------------------------
     unsigned int GetCfgSortSize();
     //==============================================================================
     /**
     * @brief // Write Section Row into file <BR>
     * iStat = oCfgSet.WritFileSection(&oExpFil);
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
     * iStat = oCfgSet.WriFileParameterValue()
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
     sstMisc01CfgSetIntCls *poInternObject;   /**< Pointer to intern object */
};
//==============================================================================
/**
* @brief sst Lib Config File Class
*
* More Comment
*
* Changed: 10.12.14  Re.
*
* @ingroup sstMisc01Lib
*
* @author Re.
*
* @date 10.12.14
*/
// ----------------------------------------------------------------------------
class sstMisc01CfgFilCls : public sstMisc01AscFilCls
{
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // Constructor <BR>
  * @param oCfgFilNam [in] Config File Name
  */
  // ----------------------------------------------------------------------------
    sstMisc01CfgFilCls(std::string oCfgFilNam);   // Constructor
    ~sstMisc01CfgFilCls();   // Constructor
     // Delete existing config file, write and close new one
     //==============================================================================
     /**
     * @brief // DeleteWriteNewClose <BR>
     * iStat = oCfgFile.DeleteWriteNewClose(iKey);
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
     * iStat = oCfgFile.OpenWriteClose(iKey);
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
     * iStat = oCfgFile.AddConfigSet(iKey,oSection);
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

private:  // Private functions
     sstMisc01CfgFilIntCls *poInternObject;   /**< Pointer to intern object */
};
//==============================================================================
/**
* @brief sst Protocol message class
*
* Changed: 09.07.15  Re.
*
* @ingroup sstMisc01Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstMisc01PrtMsgCls
{
  public:   // Public functions
     sstMisc01PrtMsgCls();  // Constructor
    ~sstMisc01PrtMsgCls();  // Destructor
     //=============================================================================
     /**
     * @brief // Return intern adress  <BR>
     * poPrtMsgInt = oSstMsg.GetInternAdress ();
     *
     * @return Return intern adress
     */
     // ----------------------------------------------------------------------------
     sstMisc01PrtMsgIntCls* GetInternAdress ();
// ----------------------------------------------------------------------------
  private:  // Private functions
     sstMisc01PrtMsgIntCls *poInternObject;   /**< Pointer to intern object */
};
//==============================================================================
/**
* @brief sst Protocol file class
*
* Changed: 09.07.15  Re.
*
* @ingroup sstMisc01Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstMisc01PrtFilCls
{
  public:   // Public functions
     sstMisc01PrtFilCls();  // Constructor
    ~sstMisc01PrtFilCls();  // Destructor

     //=============================================================================
     /**
     * @brief // Open Protocol with filename<BR>
     * iStat = oSstPrt.SST_PrtAuf ( iKey, cFilNam);
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
     int SST_PrtAuf ( int      iKey,
                      char    *cFilNam);
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
                         sstMisc01PrtMsgCls *oMld);
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
  sstMisc01PrtFilIntCls *poInternObject;   /**< Pointer to intern object */
};
//==============================================================================
/**
* @brief Progress Bar for console output
*
* More Comment
*
* Changed: 08.06.15  Re.
*
* @ingroup sstMisc01Lib
*
* @author Re.
*
* @date 08.06.15
*/
// ----------------------------------------------------------------------------
class sstMisc01ConPrgBarCls
{
  public:   // Public functions
     sstMisc01ConPrgBarCls();   // Constructor
    // ~X();   // Destructor
     //==============================================================================
     /**
     * @brief // open progress bar on console <BR>
     * iStat = oPrgBar.Open ( iKey, *cMld, ulParLimit);
     *
     * @param iKey       [in] For the moment 0
     * @param cMld       [in] message with start of progress bar
     * @param ulParLimit [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Open (int                 iKey,
               char               *cMld,
               unsigned long       ulParLimit);
     //==============================================================================
     /**
     * @brief // close progress bar on console <BR>
     * iStat = oPrgBar.Close ( iKey, *cMld);
     *
     * @param iKey       [in] For the moment 0
     * @param cMld       [in] message with close of progress bar
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Close (int                 iKey,
                char               *cMld);
     //==============================================================================
     /**
     * @brief // write tick on progress bar <BR>
     * oPrgBar.Tick ();
     */
     // ----------------------------------------------------------------------------
     void Tick ();
     // ----------------------------------------------------------------------------
  private:  // Private functions
  unsigned long ulPointsSet;  /**< ulPointsSet */
  unsigned long ulLimit;      /**< ulLimit */
  unsigned long ulLimitMult;  /**< ulLimitMult */
  unsigned long ulNumCalls;   /**< Number of Calls */

};
//==============================================================================
/**
* @brief File Name Manager Class
*
* Should work also with lower/upper case file extension
*
* Changed: 30.11.18  Re.
*
* @ingroup sstMisc01Lib
*
* @author Re.
*
* @date 01.03.16
*/
// ----------------------------------------------------------------------------
class sstMisc01FilNamCls
{
  public:   // Public functions
     sstMisc01FilNamCls();  // Constructor
    ~sstMisc01FilNamCls();  // Destructor
     //==============================================================================
     /**
     * @brief // remove given extension from filename <BR>
     * iStat = oSstFilNam.RemoveExtension(iKey, FilNamEnding, FilNamWith, FilNamWithout);
     *
     * @param iKey            [in]   For the moment 0
     * @param oFilNamEnding   [in]   for exampel dxf with/without dot
     * @param oFilNamWith     [in]   for exampel test.dxf
     * @param poFilNamWithout [out]  file name for example -test-
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: Extension string too long
     * @retval   = -3: Extension string not at end of file name string
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int RemoveExtension ( int   iKey,
                           std::string  oFilNamEnding,
                           std::string  oFilNamWith,
                           std::string *poFilNamWithout);
     //==============================================================================
     /**
     * @brief // Find point char position in filename (1 to n) <BR>
     * iStat = oSstFilNam.GetPntPos ( iKey, &oFilNam, &uiPntPos);
     *
     * Search from file end <BR>
     *
     * @param iKey     [in] For the moment 0
     * @param oFilNam  [in]  Filename
     * @param uiPntPos [out] Point Position in String (1 to n)
     *
     * @return Errorstate
     *
     * @retval   = 1: Yes, point char found
     * @retval   = 0: Nothing found
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int GetPntPos ( int   iKey,
                     std::string *oFilNam,
                     unsigned int  *uiPntPos);
     //==============================================================================
     /**
     * @brief // exchange ending in filename with new ending <BR>
     * iStat = oSstFilNam.ReplaceExtension ( iKey, FilNamOld, FilNamEnd, FilNamNew);
     *
     * @param iKey      [in]  For the moment 0
     * @param oFilNamOld [in]  given filename with ending
     * @param oFilNamEnd [in]  new ending
     * @param oFilNamNew [out] new filename with new ending
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReplaceExtension ( int          iKey,
                            std::string *oFilNamOld,
                            std::string *oFilNamEnd,
                            std::string *oFilNamNew);
     //==============================================================================
     /**
     * @brief // Split filenamestring to name and ending <BR>
     * iStat = oSstFilNam.SplitExtension(iKey, oFilNamEnd, oFilEnd, oFilNam);
     *
     * @param iKey       [in]  For the moment 0
     * @param oFilNamEnd [in]   for example "test.csv"
     * @param oFilEnd    [out] result for example "csv"
     * @param oFilNam    [out] result for example "Test"
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int SplitExtension (int   iKey,
                         std::string *oFilNamEnd,
                         std::string *oFilEnd,
                         std::string *oFilNam);
// ----------------------------------------------------------------------------
  private:  // Private functions
    sstMisc01FilNamIntCls *poInternObject;   /**< Pointer to intern object */
};
//==============================================================================
/**
* @brief // Compare two Asc files and return first diffent file row <BR>
* iStat = sstMisc01FileCompare( iKey, oFilNam1, oFilNam2, *ulRowNo);
*
* iKey = 1: Ignore Different files sizes and return first different row no. <BR>
*
* Changed: 09.07.15  Re.
*
* @ingroup sstMisc01Lib
*
* @param iKey     [in] 0 oder 1
* @param oFilNam1 [in] File Name 1
* @param oFilNam2 [in] File Name 2 for comparing
* @param ulRowNo  [out] Row number
*
* @return Errorstate
*
* @retval   =  0: Files are equal
* @retval   = -1: Wrong Key
* @retval   = -2: File 1 not found
* @retval   = -3: File 2 not found
* @retval   = -4: Row length not equal in RowNo
* @retval   = -5: Row string not equal in RowNo
* @retval   = -6: File Size not equal
* @retval   <  0: Unspecified Error
*
* @author Re.
*
* @date 09.07.15
*/
//------------------------------------------------------------------------------
int sstMisc01FileCompare(int iKey, const std::string oFilNam1, const std::string oFilNam2,
                         unsigned long *ulRowNo);
//==============================================================================


#endif

// --------------------------------------------------------------- File End ----
