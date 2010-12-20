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
 
#include "xmppgui/xmpp/session/roster/RosterItem.hpp"
#include "talk/xmpp/constants.h"

namespace cim{

namespace{
  typedef ::std::set<std::string> str_set;
}

RosterItem::RosterItem(): m_jid(buzz::JID_EMPTY), m_subscription(s_not_set),
      m_has_ask(false), m_modified(false){
}
RosterItem::RosterItem(const buzz::Jid jid): m_jid(jid),
      m_subscription(s_not_set), m_has_ask(false), m_modified(true){
}

RosterItem::RosterItem(const RosterItem &item){
  m_jid = item.m_jid;
  m_name = item.m_name;
  m_subscription = item.m_subscription;
  m_groups.insert(item.m_groups.begin(), item.m_groups.end());
  m_modified = item.m_modified;
}

RosterItem::~RosterItem(){
  m_groups.clear();
}

bool RosterItem::SetJid(const buzz::Jid jid){
  if (m_jid == jid)
    return false;
  m_modified = true;
  m_jid = jid;
  return true;
}

bool RosterItem::SetName(const std::string &name){
  if (m_name == name)
    return false; 
  m_modified = true;
  m_name = name;
  return true;
}

bool RosterItem::SetSubscription(Subscription subscription){
  if (m_subscription == subscription)
    return false;
  m_modified = true;
  m_subscription = subscription;
  return true;
}

bool RosterItem::SetSubscription(const std::string &subscription){
  Subscription subs = s_not_set;
  if (subscription == "none"){
    subs = s_none;
  } else if (subscription == "to"){
    subs = s_to;
  } else if (subscription == "from"){
    subs = s_from;
  } else if (subscription == "both"){
    subs = s_both;
  }
  if (subs == m_subscription)
    return false;
  m_modified = true;
  m_subscription = subs;
  return false;
}

bool RosterItem::AddGroup(const std::string &group){
  if (m_groups.insert(group).second){
    m_modified = true;
    return true;
  }
  return false;
}

bool RosterItem::RemoveGroup(const std::string &group){
  if (m_groups.erase(group)){
    m_modified = true;
    return true;
  }
  return false;
}

bool RosterItem::ClearGroups(){
  if (m_groups.empty())
    return false;
  m_modified = true;
  m_groups.clear();
  return true;
}

bool RosterItem::SetHasAsk(bool val){
  if (m_has_ask == val)
    return false;
  m_modified = true;
  m_has_ask = val;
  return true;
}

const buzz::Jid RosterItem::GetJid() const{
  return m_jid;
}

const std::string &RosterItem::GetName() const{
  return m_name;
}

RosterItem::Subscription RosterItem::GetSubscription() const{
  return m_subscription; 
}

std::string RosterItem::GetSubscriptionStr() const{
  switch (m_subscription){
    case s_none: return "none"; break;
    case s_to: return "to"; break;
    case s_from: return "from"; break;
    case s_both: return "both"; break;
    default: return "none"; break;
  }
}

int RosterItem::GetGroupNumber() const{
  return m_groups.size();
}

str_set::const_iterator RosterItem::GroupsBegin() const{
  return m_groups.begin();
}

str_set::const_iterator RosterItem::GroupsEnd() const{
  return m_groups.end();
}

bool RosterItem::GetHasAsk() const{
  return m_has_ask;
}

buzz::XmlElement *RosterItem::ToXml(){
  buzz::XmlElement *item = new buzz::XmlElement(buzz::QN_ROSTER_ITEM);
  item->AddAttr(buzz::QN_JID, m_jid.Str());
  item->AddAttr(buzz::QN_NAME, m_name);
  if (m_subscription > 0)
    item->AddAttr(buzz::QN_SUBSCRIPTION, GetSubscriptionStr());
  
  for(str_set::iterator group = m_groups.begin();
        group != m_groups.end(); group++){
    buzz::XmlElement *group_item = new buzz::XmlElement(buzz::QN_ROSTER_GROUP);
    group_item->SetBodyText(*group);
    item->AddElement(group_item);
  }
  
  return item;
}


bool RosterItem::operator==(const RosterItem &i) const{
 bool return_val = (m_jid == i.m_jid) 
   && (m_name == i.m_name)
   &&  (m_subscription == i.m_subscription)
   //  std::vector<std::string> m_groups
   && (m_has_ask == i.m_has_ask);
 return return_val;
}

}

