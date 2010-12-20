#ifndef TESTAPP_HPP_
#define TESTAPP_HPP_

#include "wx/image.h"
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <vector>

class TestApp : public wxApp {
  
DECLARE_CLASS( DicomSrApp )

public:
  TestApp();
  void Init();
  virtual bool OnInit();
  virtual int OnExit();
  
  SRFormBuilder* builder;

};

DECLARE_APP( TestApp )

#endif /*TESTAPP_HPP_*/

