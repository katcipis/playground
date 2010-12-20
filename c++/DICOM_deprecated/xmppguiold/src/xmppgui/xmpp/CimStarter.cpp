#include "xmppgui/xmpp/CimStarter.hpp"

#include <time.h>
#include <iomanip>

#include <wx/thread.h>
#include "xmppgui/Constants.hpp"

#include "talk/base/ssladapter.h"
namespace cim{
  

  
CimStarter::CimStarter(): m_main_thread(NULL), m_switcher(NULL), m_pump(NULL){
  talk_base::InitializeSSL();
  m_main_thread = new talk_base::Thread(&m_ss);
  m_switcher = new ThreadSwitcher(m_main_thread);
  Init();
}

CimStarter::~CimStarter(){
  if (m_main_thread){
    m_main_thread->Stop();
  }    
}


CimClient *CimStarter::SCimClient(){
  return CimStarter::GetInstance().GetCimClient();
}
  
CimStarter& CimStarter::GetInstance(){
  static CimStarter my_instance;
  return my_instance;
}

void CimStarter::Init(){
  m_pump = new XmppPump();
  //CallClient *client = new CallClient(pump.client());
  client = new CimClient(m_pump->client());

  //m_main_thread = new talk_base::Thread(&m_ss);
  //talk_base::AutoThread *wxthread = new talk_base::AutoThread(&m_ss);
  

  
  //Console *console = new Console(&main_thread, client);
  //client->SetConsole(console);
  //talk_base::Thread *console_thread = new talk_base::Thread(&ss);
  //console_thread->Start();
  //console_thread->Post(console, MSG_START);

  
  //m_main_thread->Run();
}
  

typedef void (CimStarter::*TsFunc)(ThreadSwitcherMessageData *);
typedef ThreadSwitcherMessageDataImpl<CimStarter *, TsFunc, const std::string, const std::string> LoginMsgData;

void CimStarter::DoLogin_sig(ThreadSwitcherMessageData* tsmd){
  PRU_LOG0
  LoginMsgData *md = dynamic_cast<LoginMsgData *>(tsmd);
  PRU_LOG0
  assert(md);

  // cheating a bit 
  //talk_base::ThreadManager::SetCurrent(m_main_thread);

  PRU_LOG0
  if (m_pump)
    delete m_pump;
  PRU_LOG0
  m_pump = new XmppPump();
  PRU_LOG0
  client->SetClient(m_pump->client());

  PRU_LOG0
  m_jid = buzz::Jid(md->arg0);
  PRU_LOG0
//  std::cout << "md->arg0"<< md->arg1 << std::endl;
//  
//  std::cout << "node" << m_jid.node() << std::endl;
  
  if (!m_jid.IsValid() || m_jid.node() == "") {
    std::cout << "Invalid JID. JIDs should be in the form user@domain" << std::endl;
    return;
  }

  PRU_LOG0
  m_xcs.set_user(m_jid.node());
  // Let's give it a fancy resource name :p
  //xcs.set_resource("MyTest");
  // Better idea! CIM rules!
  PRU_LOG0
  m_xcs.set_resource("Cim");
  PRU_LOG0
  m_xcs.set_host(m_jid.domain());
  PRU_LOG0
  m_xcs.set_use_tls(true);

  PRU_LOG0
  talk_base::InsecureCryptStringImpl pass2;
  PRU_LOG0
  pass2.password() = md->arg1;
  PRU_LOG0
  m_xcs.set_pass(talk_base::CryptString(pass2));
  PRU_LOG0
  m_xcs.set_server(talk_base::SocketAddress("talk.google.com", 5222));

  PRU_LOG0
  m_pump->DoLogin(m_xcs, new XmppSocket(true), NULL);
  
  // geting things right
  //talk_base::ThreadManager::SetCurrent(new talk_base::AutoThread(&m_ss));

  //return 0;
  PRU_LOG0
}
void CimStarter::DoLogin(const std::string &user, const std::string &pass){
  PRU_LOG0
  LoginMsgData *data = new LoginMsgData(this, &CimStarter::DoLogin_sig, user, pass);
  PRU_LOG0
  m_main_thread->Start();
  PRU_LOG0
  GetSwitcher()->DoInThread(data);
  PRU_LOG0
}

CimClient *CimStarter::GetCimClient(){
  return client;
}

talk_base::Thread *CimStarter::GetSignalingThread(){
  return m_main_thread;
}
ThreadSwitcher *CimStarter::GetSwitcher(){
  return m_switcher;
}

void CimStarter::DoLogout(){
//  m_pump.DoDisconnect();
}

} //namespace cim
