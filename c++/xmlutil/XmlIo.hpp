#ifndef XMLIO_HPP_
#define XMLIO_HPP_

#include "XmlSearcher.hpp"
#include "XmlWriter.hpp"

class XmlIo : public XmlSearcher, XmlWriter{

public:
	
  virtual ~XmlIo(){};
  XmlIo(){};
  
};


#endif /*XMLIO_HPP_*/
