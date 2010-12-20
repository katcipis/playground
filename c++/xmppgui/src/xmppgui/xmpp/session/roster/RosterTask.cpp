/*
 * @author Martin Prüsse <prusse.martin@gmail.com> 
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
#include "xmppgui/xmpp/session/roster/RosterTask.hpp"
#include "xmppgui/xmpp/session/presence/PresenceTask.hpp"

#include "talk/xmpp/xmppclient.h"
#include "talk/xmpp/constants.h"

#include "xmppgui/Constants.hpp"

#include <iostream>

namespace cim {
  
RosterTask::RosterTask(Task *parent): buzz::XmppTask(parent, buzz::XmppEngine::HL_TYPE),
      m_presence(NULL){
  //m_presence = new PresenceTask(this);
  //SignalRosterReceived.connect(m_presence, &PresenceTask::OnRosterReceived);
}
RosterTask::~RosterTask(){}

bool RosterTask::HandleStanza(const buzz::XmlElement *stanza){
  if ((stanza->Name() == buzz::QN_IQ)
        && (stanza->FirstWithNamespace(buzz::NS_ROSTER))){
    QueueStanza(stanza);
    return true;
  }
  return false;
}


void RosterTask::RequestRoster(){
  PRU_LOG1("RequestRoster");
  buzz::XmlElement *roster_iq = new buzz::XmlElement(buzz::QN_IQ);
  roster_iq->AddAttr(buzz::QN_FROM, GetClient()->jid().Str());
  roster_iq->AddAttr(buzz::QN_TYPE, buzz::STR_GET);
  roster_iq->AddAttr(buzz::QN_ID, GetClient()->engine()->NextId());
    buzz::XmlElement *roster_query = new buzz::XmlElement(buzz::QN_ROSTER_QUERY);
    roster_iq->AddElement(roster_query);
    roster_query->AddAttr(buzz::QN_XMLNS_CLIENT, buzz::NS_ROSTER);
    
  SendStanza(roster_iq);
}

void RosterTask::UpdateRosterItem(RosterItem &item){
  PRU_LOG1("UpdateRosterItem");
  buzz::XmlElement *element = item.ToXml();
  
  buzz::XmlElement *roster_iq = new buzz::XmlElement(buzz::QN_IQ);
  roster_iq->AddAttr(buzz::QN_FROM, GetClient()->jid().Str());
  roster_iq->AddAttr(buzz::QN_TYPE, buzz::STR_SET);
  roster_iq->AddAttr(buzz::QN_ID, GetClient()->engine()->NextId());
    buzz::XmlElement *roster_query = new buzz::XmlElement(buzz::QN_ROSTER_QUERY);
    roster_iq->AddElement(roster_query);
    roster_query->AddAttr(buzz::QN_XMLNS_CLIENT, buzz::NS_ROSTER);
      roster_query->AddElement(element);
    
  SendStanza(roster_iq);
}

void RosterTask::DeleteRosterItem(RosterItem &item){
  PRU_LOG1("DeleteRosterItem");
  buzz::XmlElement *element = item.ToXml();
  if (element->HasAttr(buzz::QN_SUBSCRIPTION))
    element->SetAttr(buzz::QN_SUBSCRIPTION, buzz::STR_REMOVE);
  else
    element->AddAttr(buzz::QN_SUBSCRIPTION, buzz::STR_REMOVE);
  
  buzz::XmlElement *roster_iq = new buzz::XmlElement(buzz::QN_IQ);
  roster_iq->AddAttr(buzz::QN_FROM, GetClient()->jid().Str());
  roster_iq->AddAttr(buzz::QN_TYPE, buzz::STR_SET);
  roster_iq->AddAttr(buzz::QN_ID, GetClient()->engine()->NextId());
    buzz::XmlElement *roster_query = new buzz::XmlElement(buzz::QN_ROSTER_QUERY);
    roster_iq->AddElement(roster_query);
    roster_query->AddAttr(buzz::QN_XMLNS_CLIENT, buzz::NS_ROSTER);
      roster_query->AddElement(element);
    
  SendStanza(roster_iq);
}


int RosterTask::ProcessStart(){
  const buzz::XmlElement *stanza = NextStanza();
  if (stanza == NULL)
      return STATE_BLOCKED;
  PRU_LOG2("ProcessStart", stanza->Str());
    
  const buzz::XmlElement *query = stanza->FirstWithNamespace(buzz::NS_ROSTER);
  if (query){
    for(const buzz::XmlElement *xml_item = query->FirstElement(); xml_item;
          xml_item = xml_item->NextElement()){
      int state = ParseItem(xml_item);
      if (state != STATE_START){
        return state;
      }
    }
  }
  
  if (stanza->HasAttr(buzz::QN_TYPE) && (stanza->Attr(buzz::QN_TYPE) == buzz::STR_SET)){
    // When more than one resource is active and receiving roster updates, a 'set' from one
    // should cause others to receive the new roster status, they should reply to it
    PRU_LOG2("ProcessStart", stanza->Str());
    buzz::XmlElement *result = MakeIqResult(stanza);
    SendStanza(result);
  }
  
  return STATE_START;
}

int RosterTask::ParseItem(const buzz::XmlElement *element){
  PRU_LOG2("ParseItem", element->Str());
  //RosterItem *roster_item = new RosterItem();
  RosterItem roster_item;
  if (element->HasAttr(buzz::QN_JID))
    roster_item.SetJid(buzz::Jid(element->Attr(buzz::QN_JID)));
  if (element->HasAttr(buzz::QN_NAME))
    roster_item.SetName(element->Attr(buzz::QN_NAME));
  if (element->HasAttr(buzz::QN_SUBSCRIPTION))
    roster_item.SetSubscription(element->Attr(buzz::QN_SUBSCRIPTION));
  for(const buzz::XmlElement *group = element->FirstElement(); group;
        group = group->NextElement())
    roster_item.AddGroup(group->BodyText());
  roster_item.SetHasAsk(element->HasAttr(buzz::QN_ASK));
  roster_item.m_modified = false;
  SignalRosterReceived(roster_item);
  return STATE_START;
}

}
