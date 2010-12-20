#ifndef DICOMSRAPP_HPP_
#define DICOMSRAPP_HPP_

#include "wx/image.h"
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "DicomSrFrame.hpp"

class DicomSrApp: public wxApp {
  DECLARE_CLASS( DicomSrApp )  
  
public:
  DicomSrApp();
  void Init();
  virtual bool OnInit();
  virtual int OnExit();
  
};

DECLARE_APP( DicomSrApp )

#endif /*DICOMSRAPP_HPP_*/
