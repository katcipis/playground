/////////////////////////////////////////////////////////////////////////////
// Name:        tutorialapp.h
// Purpose:     
// Author:      Katcipis
// Modified by: 
// Created:     Mon 03 Mar 2008 14:13:39 BRT
// RCS-ID:      
// Copyright:   Cyclops Group
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _TUTORIALAPP_H_
#define _TUTORIALAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * TutorialApp class declaration
 */

class TutorialApp: public wxApp
{    
    DECLARE_CLASS( TutorialApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    TutorialApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(TutorialApp)
////@end declare app

#endif
    // _TUTORIALAPP_H_

