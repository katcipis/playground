#ifndef CIMSTARTER_HPP_9UVATHU7
#define CIMSTARTER_HPP_9UVATHU7

#include "xmppgui/xmpp/CimClient.hpp"

#include "talk/base/physicalsocketserver.h"
#include "talk/xmpp/xmppclientsettings.h"
#include "talk/examples/login/xmppthread.h"
#include "talk/examples/login/xmppauth.h"
#include "talk/examples/call/callclient.h"

#include <string>

namespace cim{
  
class CimStarter{
public:
  
  CimClient *GetCimClient();
  static CimStarter& GetInstance();
  static CimClient *SCimClient();
  void DoLogin(const std::string &user, const std::string &pass);
  void DoLogout();
  
  talk_base::Thread *GetSignalingThread();
  ThreadSwitcher *GetSwitcher();
protected:
  CimStarter();
  virtual ~CimStarter();
  void DoLogin_sig(ThreadSwitcherMessageData* tsmd);
  
private:
  
  XmppPump *m_pump;
  buzz::Jid m_jid;
  buzz::XmppClientSettings m_xcs;
  talk_base::PhysicalSocketServer m_ss;
  talk_base::Thread *m_main_thread;
  CimClient *client;
  
  ThreadSwitcher *m_switcher;

  void Init();
};
  
}

#endif /*CIMSTARTER_HPP_9UVATHU7*/
