/**
 * \file Dictionary.cpp
 *
 * Implementation for the Dictionary class.
 *
 * $Rev: $
 * $Date: $
 * $Author: $
 */

#include "Dictionary.hpp"
#include <iostream>
using std::cout;
using std::endl;


using namespace std;

using namespace dictionaryeditor;

Dictionary::Dictionary(DictionaryType dictype){ 
  m_dicname = "";
  m_dictype = dictype;
  m_numterms = 0;
  m_bigestid = 0000;
}
    
Dictionary::Dictionary(string aFile, DictionaryType dictype){
  m_bigestid = 0000;
  m_dictype = dictype;
  ifstream is;
  char *sb = new char[256];
  string temp1, temp2, temp3, temp4, temp5, temp6;
  Term* t;
  is.open(aFile.c_str(), ifstream::in);
  is.getline(sb, 256, '\t');
  string verify = sb;

  while(verify != ""){
  		
    temp1 = verify;
    is.getline(sb, 256, '\t');
    temp2 = sb;
    is.getline(sb, 256, '\t');
    temp3 = sb;
    is.getline(sb, 256, '\t');
    temp4 = sb;
    is.getline(sb, 256, '\t');
    temp5 = sb;
    is.getline(sb, 256, '\n');
    temp6 = sb;
    t = new Term(temp1, temp4, temp2, temp3, temp5, temp6);

    this->AddTerm(t);
    if(m_bigestid < atoi(temp1.c_str()))
      m_bigestid = atoi(temp1.c_str());
    is.getline(sb, 256, '\t');
    verify = sb;    
  }
  is.close();   
}
    
Dictionary::~Dictionary(){
  //delete m_terms;  
}
    
void Dictionary::AddTerm(Term* aTerm){
  std::string temp = aTerm->GetCode().c_str();
  m_terms[temp] = aTerm;  
  m_numterms++;
}
    
void Dictionary::RemoveTerm(Term* aTerm){
  std::string temp = aTerm->GetCode().c_str();
  m_terms.erase(temp);
  m_numterms--;
}

void Dictionary::RemoveTerm(std::string key){
  m_terms.erase(key);
  m_numterms--;
}

Term* Dictionary::GetTerm(std::string key){
  return m_terms[key];
}
    
File* Dictionary::GenerateXml(std::string path){
  return NULL;
}

string Dictionary::GenerateString(){
  string s = "";
  map<std::string, Term*>::iterator i;
  for(i = m_terms.begin(); i != m_terms.end(); i++)
    if(i->second != NULL)
      s += i->second->ToString(); 
  return s;
}

void Dictionary::SetDictionaryName(string newName){
  m_dicname = newName;
}

string Dictionary::GetDictionaryName(){
  return m_dicname; 
}

void Dictionary::SetBigestId(int newId){
  m_bigestid = newId;
}

int Dictionary::GetBigestId(){
  return m_bigestid; 
}

int Dictionary::GetNumTerms(){
  return m_numterms;
}

std::list<std::string>* Dictionary::AsList(){
  std::list<std::string>* lista = new std::list<std::string>();
  map<std::string, Term*>::iterator i;
  for(i = m_terms.begin(); i != m_terms.end(); i++){
    if(i->second != NULL){
      lista->push_back(i->second->GetMeaning());
    }       
  }
  return lista;
}
