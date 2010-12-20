#ifndef CIMCLIENT_HPP_9UVATHU7
#define CIMCLIENT_HPP_9UVATHU7

//#include "xmppgui/GuiContact.hpp"
#include "xmppgui/util/ThreadSwitcher.hpp"

#include <map>
#include <string>
#include "talk/base/autodetectproxy.h"
#include "talk/p2p/base/session.h"
#include "talk/p2p/client/httpportallocator.h"
#include "talk/xmpp/xmppclient.h"
#include "talk/examples/login/status.h"
//#include "talk/examples/call/console.h"
//#include "talk/base/sigslot.h"

#include "talk/session/text2/textsessionclient.h"
#include "talk/session/tunnel/pseudotcpchannel.h"
#include "talk/session/tunnel/tunnelsessionclient.h"
#include "talk/session/fileshare/fileshare.h"

namespace buzz {
class PresencePushTask;
class Status;
}

namespace talk_base {
class Thread;
class NetworkManager;
}

namespace cricket {
class PortAllocator;
class PhoneSessionClient;
class Receiver;
class Call;
class SessionManagerTask;
}

//struct RosterItem {
//  buzz::Jid jid;
//  buzz::Status::Show show;
//  std::string status;
//};

namespace cim{
  
// Fowarding declaring
class FileTransfer;
class RosterTask;
class RosterItem;
class PresenceTask;
  
struct CallRosterItem {
  buzz::Jid jid;
  buzz::Status status;
};
  
class CimClient: public sigslot::has_slots<> {
public:
  CimClient(buzz::XmppClient* xmpp_client);
  virtual ~CimClient();

  cricket::PhoneSessionClient* phone_client() const { return phone_client_; }

  //void PrintRoster();
  //bool MakeTunnelTo(const std::string& name);
  //void SetConsole(Console *console) {console_ = console;}
  //void ParseLine(const std::string &str);
  //bool IsWritingMessage() const { return writing_message_; };
  //void AppendMessageLine(const std::string &str);
  bool SendTextMessage(const std::string& name, const std::string& message);
  
  void MakeCallTo(const std::string& name);
  void AcceptCall(cricket::Call* call, cricket::Session *session);
  void RejectCall(cricket::Call* call, cricket::Session *session);
  void HangupCall(cricket::Call* call, cricket::Session *session);
  
  void MakeShare(const std::string& name, cricket::FileShareManifest *manifest,
        const std::string& dir);
  void AcceptShare(cricket::FileShareSession *sess);
  void RejectShare(cricket::FileShareSession *sess);
  void CancelShare(cricket::FileShareSession *sess);
  
  void SendState(buzz::Status::Show show, const std::string quote);
  
  void UpdateRosterItem(RosterItem &item);
  
  void SetClient(buzz::XmppClient* xmpp_client);

  // the call
  sigslot::signal1<cricket::Call *> SignalCallEnd;
  // the new state
  sigslot::signal1<buzz::XmppEngine::State> SignalChangeOwnState;
  // the call, session, the call's state
  sigslot::signal3<cricket::Call*, cricket::Session*,
      cricket::Session::State> SignalCallState;
  // other side jid, found, has calling capabilities 
  sigslot::signal3<buzz::Jid, bool, bool> SignalCalling;
  sigslot::signal2<buzz::Jid, std::string> SignalInconingMessage;
  sigslot::signal1<buzz::Status> SignalChangeRosterStatus;
  sigslot::signal1<RosterItem&> SignalChangeRosterData;
  
  sigslot::signal2<cricket::FileShareSession *, cricket::FileShareState> SignalFileSessionState;
  sigslot::signal1<cricket::FileShareSession *> SignalFileUpdateProgress;
  sigslot::signal1<cricket::FileShareSession *> SignalFileShareCreate;
private:
  typedef std::map<std::string, CallRosterItem> RosterMap;

  //Console *console_;
  buzz::XmppClient* xmpp_client_;
  talk_base::Thread* worker_thread_;
  talk_base::NetworkManager network_manager_;
  talk_base::AutoDetectProxy *proxy_detect_;
  cricket::HttpPortAllocator* port_allocator_;
  cricket::SessionManager* session_manager_;
  cricket::SessionManagerTask* session_manager_task_;
  cricket::PhoneSessionClient* phone_client_;
  
  cricket::Call* call_; 
  cricket::Session *session_;
  bool incoming_call_;

  buzz::PresencePushTask* presence_push_;
  RosterMap* roster_;

  cricket::TextSessionClient *text_client_;
  
  RosterTask *roster_task_;
  PresenceTask *presence_task_;
  
  //std::string message_destination_;
  //std::string writen_message_;
  //bool writing_message_;

  //cricket::TunnelSessionClient *tunnel_client_;
  //cricket::Session *tunnel_session_;
  //talk_base::StreamInterface *tunnel_stream_;
  //bool incoming_tunnel_;
  
  cricket::FileShareSessionClient *file_client_;
  typedef std::map<cricket::FileShareSession *, FileTransfer *> ShareMap;
  ShareMap m_shares;
  //talk_base::Thread* file_worker_thread_;

  void GetJingleInto();
  void OnStateChange(buzz::XmppEngine::State state);
  void OnJingleInfo(const std::string &relay_token, const std::vector<std::string> &relay_hosts, 
        const std::vector<talk_base::SocketAddress> &stun_hosts);
  void OnProxyDetect(talk_base::SignalThread *thread);
  void InitPhone();
  void InitFileShare();
  void OnRequestSignaling();
  void OnCallCreate(cricket::Call* call);
  void OnCallDestroy(cricket::Call* call);
  const std::string strerror(buzz::XmppEngine::Error err);
  void OnSessionState(cricket::Call* call,
                      cricket::Session* session,
                      cricket::Session::State state);
  void OnFileShareCreate(cricket::FileShareSession *sess);
  void OnFileShareDestroy(cricket::FileShareSession *sess);
  void InitPresence();
  void OnStatusUpdate(const buzz::Status& status);
  //void OnIncomingTunnel(cricket::TunnelSessionClient* tsc, buzz::Jid initiator, std::string description, cricket::Session* session);
  void OnRosterReceived(RosterItem roster_item);
  
  void OnTextMessage(buzz::Jid from, std::string msg);
  
  void OnSubscription(buzz::Jid jid);
  void OnSubscriptionAnswer(buzz::Jid jid, bool approved);
  
  
  void MakeCallTo_sig(ThreadSwitcherMessageData *tsmd);
  void AcceptCall_sig(ThreadSwitcherMessageData *tsmd);
  void RejectCall_sig(ThreadSwitcherMessageData *tsmd);
  void HangupCall_sig(ThreadSwitcherMessageData *tsmd);
  
  void MakeShare_sig(ThreadSwitcherMessageData *tsmd);
  void AcceptShare_sig(ThreadSwitcherMessageData *tsmd);
  void RejectShare_sig(ThreadSwitcherMessageData *tsmd);
  void CancelShare_sig(ThreadSwitcherMessageData *tsmd);
  
  void SendState_sig(ThreadSwitcherMessageData *tsmd);
  
  void UpdateRosterItem_sig(ThreadSwitcherMessageData *tsmd);

};

} //namespace cim

#endif /*CIMCLIENT_HPP_9UVATHU7*/
