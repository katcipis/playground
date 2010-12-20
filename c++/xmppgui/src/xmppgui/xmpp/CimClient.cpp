/*
 * Jingle call example
 * Copyright 2004--2005, Google Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "xmppgui/xmpp/CimStarter.hpp"
#include "xmppgui/xmpp/CimClient.hpp"
#include "xmppgui/xmpp/FileTransfer.hpp"
#include "xmppgui/Constants.hpp"


#include <string>
#include <vector>
#include <io.h>
#include <stdio.h>
#include <iostream>

#include "talk/xmpp/constants.h"
#include "talk/base/helpers.h"
#include "talk/base/thread.h"
#include "talk/base/network.h"
#include "talk/base/socketaddress.h"
#include "talk/base/stream.h"
#include "talk/p2p/base/sessionmanager.h"
#include "talk/p2p/client/httpportallocator.h"
#include "talk/p2p/client/sessionmanagertask.h"
#include "talk/session/phone/phonesessionclient.h"
//#include "talk/examples/call/callclient.h"
//#include "talk/examples/call/console.h"
#include "talk/examples/login/presencepushtask.h"
#include "talk/examples/login/presenceouttask.h"
#include "talk/examples/login/jingleinfotask.h"
#include "talk/base/logging.h"
#include "xmppgui/xmpp/session/roster/RosterTask.hpp"
#include "xmppgui/xmpp/session/presence/PresenceTask.hpp"


//#define CHECKPOINT LOG(LS_INFO) <<"file : "<<__FILE__<<" - line : " <<__LINE__<<std::endl;


//namespace {
//
//    const char* DescribeStatus(buzz::Status::Show show, const std::string& desc) {
// CHECKPOINT
//        switch (show) {
//        case buzz::Status::SHOW_XA:
//            return desc.c_str();
//        case buzz::Status::SHOW_ONLINE:
//            return "online";
//        case buzz::Status::SHOW_AWAY:
//            return "away";
//        case buzz::Status::SHOW_DND:
//            return "do not disturb";
//        case buzz::Status::SHOW_CHAT:
//            return "ready to chat";
//        default:
//            return "offline";
//        }
//    }
//
//} // namespace


namespace cim{

////////
// Call Methods
////////
typedef void (CimClient::*TsFunc)(ThreadSwitcherMessageData *);
typedef struct { cricket::Call* call; cricket::Session *session; } CallData;
typedef ThreadSwitcherMessageDataImpl<CimClient*, TsFunc, CallData> CallMsgData;
typedef ThreadSwitcherMessageDataImpl<CimClient*, TsFunc, std::string> MakeACallMsgData;


void CimClient::AcceptCall(cricket::Call* call, cricket::Session *session){
  CallData cd; cd.call = call; cd.session = session;
  CallMsgData *data = new CallMsgData(this, &CimClient::AcceptCall_sig, cd);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}
void CimClient::AcceptCall_sig(ThreadSwitcherMessageData *tsmd){
  CallMsgData *md = dynamic_cast<CallMsgData *>(tsmd);
  ASSERT(md);
  md->arg0.call->AcceptSession(md->arg0.session);
  phone_client()->SetFocus(md->arg0.call);
}

void CimClient::RejectCall(cricket::Call* call, cricket::Session *session){
  CallData cd; cd.call = call; cd.session = session;
  CallMsgData *data = new CallMsgData(this, &CimClient::RejectCall_sig, cd);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}
void CimClient::RejectCall_sig(ThreadSwitcherMessageData *tsmd){
  CallMsgData *md = dynamic_cast<CallMsgData *>(tsmd);
  ASSERT(md);
  md->arg0.call->RejectSession(md->arg0.session);
}

void CimClient::HangupCall(cricket::Call* call, cricket::Session *session){
  CallData cd; cd.call = call; cd.session = session;
  CallMsgData *data = new CallMsgData(this, &CimClient::HangupCall_sig, cd);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}
void CimClient::HangupCall_sig(ThreadSwitcherMessageData *tsmd){
  CallMsgData *md = dynamic_cast<CallMsgData *>(tsmd);
  ASSERT(md);
  md->arg0.call->TerminateSession(md->arg0.session);
}

void CimClient::MakeCallTo(const std::string& name) {
  MakeACallMsgData *data = new MakeACallMsgData(this, &CimClient::MakeCallTo_sig, name);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}
void CimClient::MakeCallTo_sig(ThreadSwitcherMessageData *tsmd){
  MakeACallMsgData *md = dynamic_cast<MakeACallMsgData *>(tsmd);
  ASSERT(md);
  const std::string name = md->arg0;
  
  bool found = false;
  bool has_cap = false;
  buzz::Jid found_jid;
  buzz::Jid callto_jid(name);
  

  /*RosterMap::iterator iter = roster_->begin();
  while (iter != roster_->end()) {
    if (iter->second.jid.BareEquals(callto_jid)) {
      if (!iter->second.status.available())
        break;
      found = true;
      found_jid = iter->second.jid;
      has_cap = iter->second.status.phone_capability();
      break;
    }
    ++iter;
  }*/
  RosterMap::iterator iter = roster_->find(callto_jid.BareJid().Str());
  found = (iter != roster_->end()) && (iter->second.status.available());
  if (found) {
    has_cap = iter->second.status.phone_capability();
    found_jid = iter->second.jid;
  }
  if (found && has_cap) {
    phone_client()->SignalCallDestroy.connect(this, &CimClient::OnCallDestroy);
/*
 * TEST 1
*/
//    cricket::Call* call_ = NULL; cricket::Session *session_ = NULL;
    if (!call_){
      call_ = phone_client()->CreateCall();
      call_->SignalSessionState.connect(this, &CimClient::OnSessionState);
    }
    if (call_) {
      session_ = call_->InitiateSession(found_jid, NULL);
    } else{
    }
    phone_client()->SetFocus(call_);
  }
  SignalCalling(found_jid, found, has_cap);
}



////////
// Share Methods
////////
typedef ThreadSwitcherMessageDataImpl<CimClient*, TsFunc, cricket::FileShareSession*>
      FileMsgData;
typedef struct { std::string name; cricket::FileShareManifest *manifest; std::string dir; }
      CreateShareData;
typedef ThreadSwitcherMessageDataImpl<CimClient*, TsFunc, CreateShareData> FileOfferMsgData;


void CimClient::MakeShare(const std::string& name, cricket::FileShareManifest *manifest,
const std::string& dir){
  CreateShareData csd; csd.name = name; csd.manifest = manifest; csd.dir = dir;
  FileOfferMsgData *data = new FileOfferMsgData(this, &CimClient::MakeShare_sig, csd);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}
void CimClient::MakeShare_sig(ThreadSwitcherMessageData *tsmd){
  FileOfferMsgData *md = dynamic_cast<FileOfferMsgData *>(tsmd);
  PRU_LOG0
  const std::string name = md->arg0.name;
  
  bool found = false;
  bool has_cap = false;
  buzz::Jid found_jid;
  buzz::Jid callto_jid(name);
  /*RosterMap::iterator iter = roster_->begin();
  while (iter != roster_->end()) {
    if (iter->second.jid.BareEquals(callto_jid)) {
      PRU_LOG0
      if (!iter->second.status.available())
        break;
      found = true;
      found_jid = iter->second.jid;
      has_cap = iter->second.status.fileshare_capability();
      break;
    }
    ++iter;
  }*/
  RosterMap::iterator iter = roster_->find(callto_jid.BareJid().Str());
  found = (iter != roster_->end()) && (iter->second.status.available());
  if (found) {
    has_cap = iter->second.status.fileshare_capability();
    found_jid = iter->second.jid;
  }

  if (found && has_cap) {
    cricket::FileShareSession *new_sess = file_client_->CreateFileShareSession();
    new_sess->SetLocalFolder(md->arg0.dir);
    new_sess->Share(found_jid, md->arg0.manifest);
  }
  PRU_LOG0
  //SignalCalling(found_jid, found, has_cap);
}

void CimClient::AcceptShare(cricket::FileShareSession *sess){
  FileMsgData *data = new FileMsgData(this, &CimClient::AcceptShare_sig, sess);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}
void CimClient::AcceptShare_sig(ThreadSwitcherMessageData *tsmd){
  FileMsgData *md = dynamic_cast<FileMsgData *>(tsmd);
  md->arg0->Accept();
}

void CimClient::RejectShare(cricket::FileShareSession *sess){
  FileMsgData *data = new FileMsgData(this, &CimClient::RejectShare_sig, sess);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}
void CimClient::RejectShare_sig(ThreadSwitcherMessageData *tsmd){
  FileMsgData *md = dynamic_cast<FileMsgData *>(tsmd);
  md->arg0->Decline();
}

void CimClient::CancelShare(cricket::FileShareSession *sess){
  FileMsgData *data = new FileMsgData(this, &CimClient::CancelShare_sig, sess);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}
void CimClient::CancelShare_sig(ThreadSwitcherMessageData *tsmd){
  FileMsgData *md = dynamic_cast<FileMsgData *>(tsmd);
  md->arg0->Cancel();
}



////////
// Message Methods
////////
bool CimClient::SendTextMessage(const std::string& name, const std::string& message){
  // this should be done in the signaling thread
  text_client_->SendTextMessage(name, message);
  return true;
}
void CimClient::OnTextMessage(buzz::Jid from, std::string msg){
  SignalInconingMessage(from, msg);
}



////////
// State Methods
////////
typedef ThreadSwitcherMessageDataImpl<CimClient*, TsFunc, buzz::Status::Show, std::string>
      StateMsgData;


void CimClient::SendState(buzz::Status::Show show, const std::string quote){
  StateMsgData *data = new StateMsgData(this, &CimClient::SendState_sig, show, quote);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}
void CimClient::SendState_sig(ThreadSwitcherMessageData *tsmd){
  StateMsgData *md = dynamic_cast<StateMsgData *>(tsmd);
  buzz::Status my_status;
  my_status.set_jid(xmpp_client_->jid());
  my_status.set_available(true);
  my_status.set_show(md->arg0);
  my_status.set_status(md->arg1);
  my_status.set_priority(0);
  my_status.set_know_capabilities(true);
  my_status.set_phone_capability(true);
  my_status.set_fileshare_capability(true);
  my_status.set_is_google_client(true);
  my_status.set_version("1.0.0.66");
  
  //TODO: instantiate and use the same object... we can end up creating alot of those
  buzz::PresenceOutTask* presence_out_ =
        new buzz::PresenceOutTask(xmpp_client_);
    presence_out_->Send(my_status);
    presence_out_->Start();
  //presence_out_->Send(my_status);
}



////////
// Roster Methods
////////
typedef ThreadSwitcherMessageDataImpl<CimClient*, TsFunc, RosterItem>
      RosterItemMsgData;


void CimClient::UpdateRosterItem(RosterItem &item){
  RosterItemMsgData *data = new RosterItemMsgData(this, &CimClient::UpdateRosterItem_sig, item);
  CimStarter::GetInstance().GetSwitcher()->DoInThread(data);
}

void CimClient::UpdateRosterItem_sig(ThreadSwitcherMessageData *tsmd){
  RosterItemMsgData *md = dynamic_cast<RosterItemMsgData *>(tsmd);
  roster_task_->UpdateRosterItem(md->arg0);
}



////////
// Subscription Methods
////////
void CimClient::OnSubscription(buzz::Jid jid){
  PRU_LOG2("OnSubscription", jid.Str());

  //presence_task_->ApproveRequest(jid);
  //presence_task_->RequestSubscription(jid);
  presence_task_->RefuseRequest(jid);
}

void CimClient::OnSubscriptionAnswer(buzz::Jid jid, bool approved){
  PRU_LOG3("OnSubscriptionAnswer", jid.Str(), approved);
}

//void CimClient::OnIncomingTunnel(cricket::TunnelSessionClient* tsc, buzz::Jid initiator,
//                                  std::string description, cricket::Session* session){
//  tunnel_session_ = session;
//  incoming_tunnel_ = true;            
////  other_name = initiator.node();
//  //console_->Printf("Tunnel [%s] %s", initiator.BareJid().Str().c_str(),  description.c_str());
//  //!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  // Must Fix This Method
//  //!!!!!!!!!!!!!!!!!!!!!!!!!!! 
//}
//bool CimClient::MakeTunnelTo(const std::string& name) {
//    bool found = false;
//    buzz::Jid found_jid;
//    buzz::Jid callto_jid = buzz::Jid(name);
//    RosterMap::iterator iter = roster_->begin();
//    while (iter != roster_->end()) {
//        if (iter->second.jid.BareEquals(callto_jid)) {
//            found = true;
//            found_jid = iter->second.jid;
//            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//            // Must Fix This Method, no phone_capability, other
//            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//            if (iter->second.status.phone_capability()){
//              break; // ok go on
//            } else{
//            }
//              
//        }
//        ++iter;
//    }
//
//
//    if (found) {
//        //console_->Printf("Found online friend '%s'", found_jid.Str().c_str());
//        //phone_client()->SignalCallDestroy.connect(
//        //    this, &CallClient::OnCallDestroy);
//        if (!tunnel_stream_) {
//            //call_ = tunnel_client_()->CreateCall();
//            //console_->SetPrompt(found_jid.Str().c_str());
//            //call_->SignalSessionState.connect(this, &CallClient::OnSessionState);
//            //session_ = call_->InitiateSession(found_jid, NULL);
////            other_name = found_jid.node();
//            tunnel_stream_ = tunnel_client_->CreateTunnel(found_jid, "AnotherTunnel");
//            //(new TestPiper(tunnel_stream_))->Start();
//        }
//        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//        // Must Fix This Method
//        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//        return false;
//        //phone_client()->SetFocus(call_);
//    } else {
//        //console_->Printf("Could not find online friend '%s'", name.c_str());
//        return false;
//    }
//}


CimClient::CimClient(buzz::XmppClient* xmpp_client)
        : xmpp_client_(xmpp_client), roster_(new RosterMap), call_(NULL),
        incoming_call_(false), text_client_(NULL), /*message_destination_(""),
        writen_message_(""), writing_message_(false), tunnel_client_(NULL),
        tunnel_session_(NULL), tunnel_stream_(NULL), incoming_tunnel_(false)*/
        file_client_(NULL), roster_task_(NULL), presence_task_(NULL){
 CHECKPOINT
    xmpp_client_->SignalStateChange.connect(this, &CimClient::OnStateChange);
}

CimClient::~CimClient() {
 CHECKPOINT
    delete roster_;
}

void CimClient::SetClient(buzz::XmppClient* xmpp_client){
  xmpp_client_ = xmpp_client;
  xmpp_client_->SignalStateChange.connect(this, &CimClient::OnStateChange);
}

const std::string CimClient::strerror(buzz::XmppEngine::Error err) {
 CHECKPOINT
    switch (err) {
    case  buzz::XmppEngine::ERROR_NONE:
        return "";
    case  buzz::XmppEngine::ERROR_XML:
        return "Malformed XML or encoding error";
    case  buzz::XmppEngine::ERROR_STREAM:
        return "XMPP stream error";
    case  buzz::XmppEngine::ERROR_VERSION:
        return "XMPP version error";
    case  buzz::XmppEngine::ERROR_UNAUTHORIZED:
        return "User is not authorized (Check your username and password)";
    case  buzz::XmppEngine::ERROR_TLS:
        return "TLS could not be negotiated";
    case   buzz::XmppEngine::ERROR_AUTH:
        return "Authentication could not be negotiated";
    case  buzz::XmppEngine::ERROR_BIND:
        return "Resource or session binding could not be negotiated";
    case  buzz::XmppEngine::ERROR_CONNECTION_CLOSED:
        return "Connection closed by output handler.";
    case  buzz::XmppEngine::ERROR_DOCUMENT_CLOSED:
        return "Closed by </stream:stream>";
    case  buzz::XmppEngine::ERROR_SOCKET:
        return "Socket error";
    default:
        return "Unknown error";
    }
}

void CimClient::OnCallDestroy(cricket::Call* call) {
 CHECKPOINT
   if (call == call_) {
 CHECKPOINT
        //console_->SetPrompt(NULL);
        //console_->Print("call destroyed");
        call_ = NULL;
        session_ = NULL;
    }
    SignalCallEnd(call);
}

void CimClient::OnJingleInfo(const std::string &relay_token,
                              const std::vector<std::string> &relay_addresses,
                              const std::vector<talk_base::SocketAddress> &stun_addresses) {
 CHECKPOINT
    port_allocator_->SetStunHosts(stun_addresses);
    port_allocator_->SetRelayHosts(relay_addresses);
    port_allocator_->SetRelayToken(relay_token);
}

void CimClient::OnStateChange(buzz::XmppEngine::State state) {
 CHECKPOINT
    switch (state) {
    case buzz::XmppEngine::STATE_START:
        //console_->Print("connecting...");
        break;

    case buzz::XmppEngine::STATE_OPENING:
        //console_->Print("logging in...");
        break;

    case buzz::XmppEngine::STATE_OPEN:
        //console_->Print("logged in...");
        PRU_LOG0
        InitPhone();
        InitFileShare();
        GetJingleInto();
        if (text_client_){
          delete text_client_;
          text_client_ = NULL;
        }
        if (!text_client_){
          /* test: text message, works */
          text_client_ = new cricket::TextSessionClient(xmpp_client_);
          //text_client_->SetConsole(console_);
          text_client_->SignalMessageReceived.connect(this, &CimClient::OnTextMessage);
          text_client_->Start();
        }
        if (roster_task_){
          delete roster_task_;
          roster_task_ = NULL;
        }
        if (!roster_task_){
          roster_task_ = new RosterTask(xmpp_client_);
          roster_task_->SignalRosterReceived.connect(this, &CimClient::OnRosterReceived);
          roster_task_->Start();
        }
        roster_task_->RequestRoster();
        if (presence_task_){
          delete presence_task_;
          presence_task_ = NULL;
        }
        if (!presence_task_){
          presence_task_ = new PresenceTask(xmpp_client_);
          presence_task_->SignalSubscriptionRequest.connect(this, &CimClient::OnSubscription);
          //presence_task_->SignalSubscriptionAnswer.connect(this, &CimClient::OnSubscriptionAnswer);
          presence_task_->Start();
        }
//        {//to shut up the compiler's mouth0
//          buzz::Jid jid("prusse.martin@gmail.com");
//          presence_task_->CancelSubscription(jid);
//          presence_task_->UnsubscribFromEntity(jid);
//          RosterItem item(jid);
//          roster_task_->DeleteRosterItem(item);
//        }
    
//        if (tunnel_client_){
//          delete tunnel_client_;
//          tunnel_client_ = NULL;
//        }        
//        if (!tunnel_client_){
//          /* test: pseudo tcp tunnel */
//          tunnel_client_ = new cricket::TunnelSessionClient(buzz::JID_EMPTY, session_manager_);
//          tunnel_client_->SignalIncomingTunnel.connect(this, &CimClient::OnIncomingTunnel);
//          //text_client_->Start();
//        }

        InitPresence();
        break;

    case buzz::XmppEngine::STATE_CLOSED:
        buzz::XmppEngine::Error error = xmpp_client_->GetError(NULL);
        //console_->Print("logged out..." + strerror(error));
        //exit(0);
    }
    SignalChangeOwnState(state);
}

void CimClient::GetJingleInto(){
    buzz::JingleInfoTask *jit = new buzz::JingleInfoTask(xmpp_client_);
    jit->RefreshJingleInfoNow();
    jit->SignalJingleInfo.connect(this, &CimClient::OnJingleInfo);
    jit->Start();
}

void CimClient::InitPhone() {
  PRU_LOG0
    std::string client_unique = xmpp_client_->jid().Str();
    cricket::InitRandom(client_unique.c_str(), client_unique.size());

    worker_thread_ = new talk_base::Thread();

    port_allocator_ = new cricket::HttpPortAllocator(&network_manager_, "call");

    session_manager_ = new cricket::SessionManager(
        port_allocator_, worker_thread_);
    session_manager_->SignalRequestSignaling.connect(
        this, &CimClient::OnRequestSignaling);
    session_manager_->OnSignalingReady();

    session_manager_task_ =
        new cricket::SessionManagerTask(xmpp_client_, session_manager_);
    session_manager_task_->EnableOutgoingMessages();
    session_manager_task_->Start();

    phone_client_ = new cricket::PhoneSessionClient(
        xmpp_client_->jid(),session_manager_);
    phone_client_->SignalCallCreate.connect(this, &CimClient::OnCallCreate);

    worker_thread_->Start();
}

void CimClient::OnRequestSignaling() {
 CHECKPOINT
    session_manager_->OnSignalingReady();
}

void CimClient::OnCallCreate(cricket::Call* call) {
 CHECKPOINT
    call->SignalSessionState.connect(this, &CimClient::OnSessionState);
}

void CimClient::OnSessionState(cricket::Call* call,
                                cricket::Session* session,
                                cricket::Session::State state) {
/*
 * TEST 1
 */
// /*
 CHECKPOINT
    if (state == cricket::Session::STATE_RECEIVEDINITIATE) {
 CHECKPOINT
        buzz::Jid jid(session->remote_name());
        //console_->Printf("Incoming call from '%s'", jid.Str().c_str());
        call_ = call;
        session_ = session;
        incoming_call_ = true;
    } else if (state == cricket::Session::STATE_SENTINITIATE) {
 CHECKPOINT
        //console_->Print("calling...");
    } else if (state == cricket::Session::STATE_RECEIVEDACCEPT) {
 CHECKPOINT
        //console_->Print("call answered");
    } else if (state == cricket::Session::STATE_RECEIVEDREJECT) {
 CHECKPOINT
        //console_->Print("call not answered");
    } else if (state == cricket::Session::STATE_INPROGRESS) {
 CHECKPOINT
        //console_->Print("call in progress");
    } else if (state == cricket::Session::STATE_RECEIVEDTERMINATE) {
 CHECKPOINT
        //console_->Print("other side hung up");
    }
/**/
    SignalCallState(call, session, state);
}

void CimClient::InitPresence() {
 CHECKPOINT
    presence_push_ = new buzz::PresencePushTask(xmpp_client_);
    presence_push_->SignalStatusUpdate.connect(
        this, &CimClient::OnStatusUpdate);
    presence_push_->Start();

    buzz::Status my_status;
    my_status.set_jid(xmpp_client_->jid());
    my_status.set_available(true);
    my_status.set_show(buzz::Status::SHOW_ONLINE);
    my_status.set_priority(0);
    my_status.set_know_capabilities(true);
    my_status.set_phone_capability(true);
    my_status.set_fileshare_capability(true);
    my_status.set_is_google_client(true);
    my_status.set_version("1.0.0.66");

    buzz::PresenceOutTask* presence_out_ =
        new buzz::PresenceOutTask(xmpp_client_);
    presence_out_->Send(my_status);
    presence_out_->Start();
}

void CimClient::OnStatusUpdate(const buzz::Status& status) {
    CallRosterItem item;
    item.jid = status.jid();
    item.status = status;
    
    std::string key = status.jid().BareJid().Str();

    //if (status.available() && status.phone_capability()) {
        //console_->Printf("Adding to roster: %s", key.c_str());
        (*roster_)[key] = item;
    //} else {
        //console_->Printf("Removing from roster: %s", key.c_str());
    //    RosterMap::iterator iter = roster_->find(key);
    //    if (iter != roster_->end())
    //        roster_->erase(iter);
    //}
    SignalChangeRosterStatus(status);
}

//void CimClient::PrintRoster() {
// CHECKPOINT
//    //console_->SetPrompting(false);
//    //console_->Printf("Roster contains %d callable", roster_->size());
//    RosterMap::iterator iter = roster_->begin();
//    while (iter != roster_->end()) {
// CHECKPOINT
//        //console_->Printf("%s - %s",
//        //                 iter->second.jid.BareJid().Str().c_str(),
//        //                 DescribeStatus(iter->second.show, iter->second.status));
//        iter++;
//    }
//    //console_->SetPrompting(true);
//}


void CimClient::OnFileShareCreate(cricket::FileShareSession *sess){
  FileTransfer *data = new FileTransfer(this, sess);
  m_shares[sess] = data;
//  session_ = sess;
  //sess->SignalState.connect(data, &FileTransfer::OnFileSessionState);
  //sess->SignalNextFile.connect(data, &FileTransfer::OnFileUpdateProgress);
  //sess->SignalUpdateProgress.connect(data, &FileTransfer::OnFileUpdateProgress);
  //sess->SignalResampleImage.connect(data, &FileTransfer::OnFileResampleImage);
//  sess->SetLocalFolder(root_dir_);
  SignalFileShareCreate(sess);
}
void CimClient::OnFileShareDestroy(cricket::FileShareSession *sess){
  delete m_shares[sess];
  m_shares.erase(sess);
}

void CimClient::InitFileShare(){
    file_client_ = new cricket::FileShareSessionClient(session_manager_, xmpp_client_->jid(),
          "Cim");
    file_client_->SignalFileShareSessionCreate.connect(this, &CimClient::OnFileShareCreate);
    file_client_->SignalFileShareSessionDestroy.connect(this, &CimClient::OnFileShareDestroy);
    session_manager_->AddClient(NS_GOOGLE_SHARE, file_client_);
}

void CimClient::OnRosterReceived(RosterItem roster_item){
  //TODO: Properly implement this method!
  //PRU_LOG2("OnRosterReceived Jid", roster_item.GetJid().Str());
  //buzz::XmlElement *eee = roster_item.ToXml();
  //PRU_LOG2("OnRosterReceived Stanza", eee->Str());
  //delete eee;
  
  SignalChangeRosterData(roster_item);

  std::string key = roster_item.GetJid().BareJid().Str();
  if (roster_->find(key) == roster_->end()) {
    CallRosterItem item;
    buzz::Status fake_status;
      fake_status.set_jid(roster_item.GetJid());
      fake_status.set_available(false);
      fake_status.set_show(buzz::Status::SHOW_NONE);
      fake_status.set_priority(0);
      fake_status.set_know_capabilities(false);
      fake_status.set_phone_capability(false);
      fake_status.set_fileshare_capability(false);
      fake_status.set_is_google_client(false);
      fake_status.set_version("1.0.0.66");
      
    item.jid = fake_status.jid();
    item.status = fake_status;

    (*roster_)[key] = item;
  }
  //  SignalChangeRosterStatus(fake_status);
}

} // namespace cim
