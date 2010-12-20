/*
 * hworld.cpp
 * Hello world sample by Robert Roebling
 */

#include "wx/wx.h"
 
#include <wx/sizer.h>

#include "xmppgui/Login.hpp"
#include "xmppgui/PresenceList.hpp"
#include "xmppgui/util/XmppEvent.hpp"
#include "xmppgui/Constants.hpp"
#include "xmppgui/xmpp/CimStarter.hpp"

#include <stdlib.h> 
#include <time.h>

class MyApp: public wxApp
{
    virtual bool OnInit();
};

class MyFrame: public wxFrame, public  sigslot::has_slots<>
{
public:

    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void OnChangeOwnState(buzz::XmppEngine::State state);
    void OnWxChangeOwnState(wxNotifyEvent &event);
    
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
protected:
  cim::Login *alog;
  cim::PresenceList *apres;
};

enum
{
    ID_Quit = 1,
    ID_About,
};

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Quit, MyFrame::OnQuit)
    EVT_MENU(ID_About, MyFrame::OnAbout)
END_EVENT_TABLE()

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    wxInitAllImageHandlers();
    srand ( time(NULL) );
    MyFrame *frame = new MyFrame( _T("Hello World"), wxPoint(50,50), wxSize(450,340) );
    frame->Show(TRUE);
    SetTopWindow(frame);
    return TRUE;
} 

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
    SetIcon(wxIcon(wxT("imgs/icon/cim.png"), wxBITMAP_TYPE_PNG));
  
    wxMenu *menuFile = new wxMenu;

    menuFile->Append( ID_About, _T("&About...") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, _T("E&xit") );

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, _T("&File") );

    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText( _T("Welcome to wxWindows!") );
    
    //wxGridSizer *asizer = new wxGridSizer(1, 2, 0, 0);
    wxFlexGridSizer *asizer = new wxFlexGridSizer(1, 2, 0, 0);
    asizer->AddGrowableCol(0, 0);
    asizer->AddGrowableCol(1, 0);
    asizer->AddGrowableRow(0, 0);
    //this->SetSizer(asizer);
    
    alog = new cim::Login(this);
    asizer->Add(alog, 0, wxEXPAND);
    
    apres = new cim::PresenceList(this);
    asizer->Add(apres, 0, wxEXPAND);
    //for(int i = 0; i < 10; i++){
    //  cim::RosterItem *item = new cim::RosterItem(this); 
    //  apres->AddContact(item);
    //}
    
    SetSizerAndFit(asizer);
    
    cim::CimClient *acli = cim::CimStarter::GetInstance().GetCimClient();
    acli->SignalCallEnd.connect(apres, &cim::PresenceList::OnCallEnd);
    acli->SignalChangeOwnState.connect(apres, &cim::PresenceList::OnChangeOwnState);
    acli->SignalCallState.connect(apres, &cim::PresenceList::OnCallState);
    acli->SignalCalling.connect(apres, &cim::PresenceList::OnCalling);
    acli->SignalInconingMessage.connect(apres, &cim::PresenceList::OnInconingMessage);
    acli->SignalChangeRosterStatus.connect(apres, &cim::PresenceList::OnChangeRosterStatus);
    acli->SignalChangeRosterData.connect(apres, &cim::PresenceList::OnChangeRosterData);
    
    acli->SignalFileSessionState.connect(apres, &cim::PresenceList::OnFileSessionState);
    acli->SignalFileUpdateProgress.connect(apres, &cim::PresenceList::OnFileUpdateProgress);
    acli->SignalFileShareCreate.connect(apres, &cim::PresenceList::OnFileShareCreate);
    
    acli->SignalChangeOwnState.connect(alog, &cim::Login::OnChangeOwnState);
    acli->SignalChangeOwnState.connect(this, &MyFrame::OnChangeOwnState);
    
    Connect(-1, cim::cimEVT_ChangeOwnState, wxNotifyEventHandler(MyFrame::OnWxChangeOwnState));
    
    SetSize(wxSize(200, 400));
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    PRU_LOG1("MyFrame::OnQuit");
    Close(TRUE);
}


void MyFrame::OnChangeOwnState(buzz::XmppEngine::State state){
  cim::ChangeOwnStateEvent event(cim::cimEVT_ChangeOwnState);
  event.arg0 = state;
  AddPendingEvent(event);
}
void MyFrame::OnWxChangeOwnState(wxNotifyEvent &event){
  cim::ChangeOwnStateEvent *l_event = dynamic_cast<cim::ChangeOwnStateEvent *>(&event);
  if (l_event){
    //switch (state) {
    switch (l_event->arg0) {
    case buzz::XmppEngine::STATE_START:
        SetStatusText( _T("connecting...") );
        break;

    case buzz::XmppEngine::STATE_OPENING:
        SetStatusText( _T("logging in...") );
        break;

    case buzz::XmppEngine::STATE_OPEN:
        SetStatusText( _T("logged in...") );
        apres->SetMyJid(buzz::Jid(WxToStd(alog->GetLogin())));
        break;

    case buzz::XmppEngine::STATE_CLOSED:
        //buzz::XmppEngine::Error error = xmpp_client_->GetError(NULL);
        //SetStatusText( _T("logged out..." + strerror(error)) );
        SetStatusText( _T("logged out...") );
        //exit(0);
    }
  } else{
    //NULL?!
    PRU_LOG1("(l_event == NULL)");
  }
  GetSizer()->Layout();
  Refresh();
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(_T("This is a wxWindows Hello world sample"),
        _T("About Hello World"), wxOK | wxICON_INFORMATION, this);
}
