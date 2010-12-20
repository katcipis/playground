/**
 * \file Dictionary.hpp
 *
 * Header for the Dictionary class.
 *
 * $Rev: $
 * $Date: $
 * $Author: $
 */

#ifndef DICTIONARY_HPP_
#define DICTIONARY_HPP_

#include <map>
#include <list>
#include <fstream>
#include <iostream>
#include "Term.hpp"
#include "util/File.hpp"

namespace dictionaryeditor{

  enum DictionaryType{
    dt_unit_dictionary = 1,
    dt_name_dictionary = 2,
  };

  /**
   * \class Dictionary 
   * This class is the Dictionary representation for Dictionary Editor. 
   */
  class Dictionary {
  
    public:
    
      /**
       * \brief Default Class Constructor.
       * \param dicname The name of dictionary
       * \param dictype The type of dictionary
       * \return Return a instance of Dictionary class.
       */
      Dictionary(dictionaryeditor::DictionaryType dictype);
      
      /**
       * \brief Class Constructor.
       * \param aXmlFile A XML file with a Dictionary inside.
       * \param dictype The type of dictionary
       * \return Return a instance of Dictionary class.
       */
      Dictionary(std::string aXmlFile, dictionaryeditor::DictionaryType dictype);
      
      /**
       * \brief Delete all dinamic objects.
       */
      ~Dictionary();
      
      /**
       * \brief Add a term to dictionary.
       * \param aTerm The term that will be added to dictionary.
       */
      void AddTerm(dictionaryeditor::Term* aTerm);
      
      /**
       * \brief Remove a term from dictionary.
       * \param aTerm The term that will be removed from dictionary.
       */
      void RemoveTerm(dictionaryeditor::Term* aTerm);
      
      /**
       * \brief Remove a term from dictionary.
       * \param key The key of term on map.
       */
      void RemoveTerm(std::string key);
      
      /**
       * \brief Get a term from dictionary.
       * \param key The key of term on map.
       * \return Return the term associated with the given key.
       */
      dictionaryeditor::Term* GetTerm(std::string key);
      
      /**
       * \brief Generate a XML file from the dictionary.
       * \param path The path to save the file.
       * \return Return a pointer to XML file.
       */
      File* GenerateXml(std::string path);
      
      /**
       * \brief Concatenate all terms in one string.
       * \return Return the terms on a string.
       */
      std::string GenerateString();
       
      /**
       * \brief Set the dictionary's name.
       * \param newName The new dictionary's name.
       */    
      void SetDictionaryName(std::string newName);
  
      /**
       * \brief Get the dictionary's name.
       * \return Return the dictionary's name.
       */
      std::string GetDictionaryName();
      
      void SetBigestId(int newId);
  
      int GetBigestId();    
      
      int GetNumTerms();
      
      std::list<std::string>* AsList();
      
    protected:
      std::map<std::string, dictionaryeditor::Term*> m_terms;
      int m_numterms;
      int m_bigestid;
      std::string m_dicname;
      dictionaryeditor::DictionaryType m_dictype;
    
  };

} //end namespace

#endif /*DICTIONARY_HPP_*/
