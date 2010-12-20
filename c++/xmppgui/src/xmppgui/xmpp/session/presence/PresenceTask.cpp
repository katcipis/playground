#include "xmppgui/xmpp/session/presence/PresenceTask.hpp"
#include "xmppgui/xmpp/session/roster/RosterItem.hpp"

#include "talk/xmpp/constants.h"

#include "xmppgui/Constants.hpp"

namespace{
  std::string STR_PROBE("probe");
}

namespace cim {


void PresenceTask::OnRosterReceived(RosterItem item){
  std::string jid_str(item.GetJid().BareJid().Str());
  RosterItem::Subscription new_subs = item.GetSubscription();
  SubscriptionMap::iterator iter = m_subscriptions.find(jid_str);
  if (iter != m_subscriptions.end()){
    // cast :/
    RosterItem::Subscription old_subs = (RosterItem::Subscription)m_subscriptions[jid_str];
    if (new_subs != old_subs){
      
    }  
  }
  m_subscriptions[jid_str] = new_subs;
}

bool PresenceTask::HandleStanza(const buzz::XmlElement *stanza){
  if (stanza->Name() != buzz::QN_PRESENCE)
    return false;
  if (!stanza->HasAttr(buzz::QN_FROM))
    return false;
  if (!stanza->HasAttr(buzz::QN_TYPE))
    return false;
  else if (stanza->Attr(buzz::QN_TYPE) == buzz::STR_UNAVAILABLE
          || stanza->Attr(buzz::QN_TYPE) == STR_PROBE
          || stanza->Attr(buzz::QN_TYPE) == buzz::STR_ERROR)
    return false;
  QueueStanza(stanza);
  return true;
}

int PresenceTask::ProcessStart(){
  const buzz::XmlElement *stanza = NextStanza();
  if (stanza == NULL)
      return STATE_BLOCKED;
  PRU_LOG2("ProcessStart", stanza);
  std::string type(stanza->Attr(buzz::QN_TYPE));
  buzz::Jid sender(stanza->Attr(buzz::QN_FROM));
  if (type == buzz::STR_SUBSCRIBE){
    SignalSubscriptionRequest(sender);
//  } else if (type == buzz::STR_SUBSCRIBED){
//    SignalSubscriptionAnswer(sender, true);
  } else if (type == buzz::STR_UNSUBSCRIBE){
    PRU_LOG1("ProcessStart STR_UNSUBSCRIBE");
    //SignalSubscriptionRequest(sender, false);
//  } else if (type == buzz::STR_UNSUBSCRIBED){
//    SignalSubscriptionAnswer(sender, false);
  } else{
    PRU_LOG1("ProcessStart else???");
  }
}

void PresenceTask::RequestSubscription(buzz::Jid jid){
  buzz::XmlElement *subs = new buzz::XmlElement(buzz::QN_PRESENCE);
  subs->AddAttr(buzz::QN_TO, jid.BareJid().Str());
  subs->AddAttr(buzz::QN_TYPE, buzz::STR_SUBSCRIBE);
  SendStanza(subs);
}

void PresenceTask::UnsubscribFromEntity(buzz::Jid jid){
  buzz::XmlElement *subs = new buzz::XmlElement(buzz::QN_PRESENCE);
  subs->AddAttr(buzz::QN_TO, jid.BareJid().Str());
  subs->AddAttr(buzz::QN_TYPE, buzz::STR_UNSUBSCRIBE);
  SendStanza(subs);
}

void PresenceTask::ApproveRequest(buzz::Jid jid){
  buzz::XmlElement *subs = new buzz::XmlElement(buzz::QN_PRESENCE);
  subs->AddAttr(buzz::QN_TO, jid.BareJid().Str());
  subs->AddAttr(buzz::QN_TYPE, buzz::STR_SUBSCRIBED);
  SendStanza(subs);
}

void PresenceTask::RefuseRequest(buzz::Jid jid){
  buzz::XmlElement *subs = new buzz::XmlElement(buzz::QN_PRESENCE);
  subs->AddAttr(buzz::QN_TO, jid.BareJid().Str());
  subs->AddAttr(buzz::QN_TYPE, buzz::STR_UNSUBSCRIBED);
  SendStanza(subs);
}

void PresenceTask::CancelSubscription(buzz::Jid jid){
  //buzz::XmlElement *subs = new buzz::XmlElement(buzz::QN_PRESENCE);
  //subs->AddAttr(buzz::QN_TO, jid.BareJid().Str());
  //subs->AddAttr(buzz::QN_TYPE, buzz::STR_UNSUBSCRIBED);
  //SendStanza(subs);
  RefuseRequest(jid);
}


}




