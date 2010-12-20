/**
 * \file Term.hpp
 *
 * Header for the Term class.
 *
 * $Rev: $
 * $Date: $
 * $Author: $
 */

#ifndef TERM_HPP_
#define TERM_HPP_

#include <iostream>
//#include <tinyxml.h>
#include <map>
#include <list>

namespace dictionaryeditor{
  
  enum CodingType{
    ct_combo_box,
    ct_check_box,
    ct_text_box,
    ct_radio_box
  };

  /**
   * \class Term 
   * This class is the Term representation for Dictionary. 
   */

  class Term {
    
    public:
    
      /**
       * \brief Class Constructor
       * \param code The code of term.
       * \param meaning The meaning of term.
       * \param designator The designator of term.
       * \param version The version of term.
       * \param description The description of term. 
       * \param coding The coding type of term;
       * \return Return a instance of Term class
       */
      Term(std::string code, std::string meaning, std::string designator, std::string version, std::string description, dictionaryeditor::CodingType coding); 
      
      Term(std::string code, std::string meaning, std::string designator, std::string version, std::string description, std::string coding); 
  
      /**
       * \brief Default Class Constructor.
       */
      Term();
  
      /**
       * \brief Class Destructor. Delete all dinamic objects.
       */
      ~Term();
      
      /**
       * \brief Set the code of term. 
       * \param aCode The new code.
       */    
      void SetCode(std::string aCode);
      
     /**
       * \brief Set the meaning of term. 
       * \param aMeaning The new meaning.
       */ 
      void SetMeaning(std::string aMeaning);
      
      /**
       * \brief Set the designator of term. 
       * \param aDesignator The new designator.
       */ 
      void SetDesignator(std::string aDesignator);
      
      /**
       * \brief Set the version of term. 
       * \param aVersion The new version.
       */ 
      void SetVersion(std::string aVersion);
      
      /**
       * \brief Set the description of term. 
       * \param aDescription The new description.
       */ 
      void SetDescription(std::string aDescription);
      
      /**
       * \brief Set the coding type of term. 
       * \return The new coding type.
       */ 
      void SetCodingType(dictionaryeditor::CodingType coding);        
      
      /**
       * \brief Get the code of term. 
       * \return The term's code.
       */    
      std::string GetCode();
      
     /**
       * \brief Set the meaning of term. 
       * \return The term's meaning.
       */ 
      std::string GetMeaning();
      
      /**
       * \brief Get the designator of term. 
       * \return The term's designator.
       */ 
      std::string GetDesignator();
      
      /**
       * \brief Get the version of term. 
       * \return The term's version.
       */ 
      std::string GetVersion();
      
      /**
       * \brief Get the description of term. 
       * \return The term's description.
       */ 
      std::string GetDescription();
      
      /**
       * \brief Get the coding type of term. 
       * \return The term's coding type.
       */ 
      dictionaryeditor::CodingType GetCodingType();        
      
      /**
       * \brief Get the string form of term. 
       * \return The string form of term.
       */ 
       
       std::string ToString();  
       
       std::list<std::string> GetUnits();
       
      /**
       * \brief Get the XML form of term. 
       * \return The XML form of term.
       */ 
       
//       TiXmlElement* AsXml();
       
      /**
       * \brief Creates the maps.
       */     
      static void CreateMaps(){
        m_mapvaluestring[ct_combo_box] = "ComboBox";
        m_mapvaluestring[ct_check_box] = "CheckBox";
        m_mapvaluestring[ct_text_box] = "TextBox";
        m_mapvaluestring[ct_radio_box] = "RadioBox";
        
        m_mapstringvalue["ComboBox"] = ct_combo_box;
        m_mapstringvalue["CheckBox"] = ct_check_box;
        m_mapstringvalue["TextBox"] = ct_text_box;
        m_mapstringvalue["RadioBox"] = ct_radio_box;
      }
       
      /**
       * \brief Converts a coding type on string.
       * \param v The coding type.
       * \return Return the string form of the coding type.
       */     
      static std::string ToString(dictionaryeditor::CodingType v){
        CreateMaps(); 
        return m_mapvaluestring[v];
      }
      /**
       * \brief Converts a string on a coding type.
       * \param v The string
       * \return Return a coding type.
       */     
      static dictionaryeditor::CodingType ToValue(std::string v){
        CreateMaps();
        return m_mapstringvalue[v];
      }
    
    protected:
      std::string m_code;
      std::string m_meaning;
      std::string m_designator;
      std::string m_version;
      std::string m_description;
      dictionaryeditor::CodingType m_codingtype;
      std::list<std::string> m_codeList;
      static std::map<dictionaryeditor::CodingType, std::string> m_mapvaluestring;
      static std::map<std::string, dictionaryeditor::CodingType> m_mapstringvalue;
  };
  
} //end namespace

#endif /*TERM_HPP_*/
