#ifndef ROSTERITEM_HPP_9UVATHU7
#define ROSTERITEM_HPP_9UVATHU7
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
 
#include "talk/xmpp/jid.h"
#include "talk/xmllite/xmlelement.h"
#include <set>

namespace cim{

class RosterTask;

class RosterItem{
public:
  RosterItem();
  RosterItem(const buzz::Jid jid);
  RosterItem(const RosterItem &item);
  ~RosterItem();
  
  enum Subscription{
    s_not_set = -1,
    s_none = 1,
    s_to,
    s_from,
    s_both
  };
  
  bool SetJid(const buzz::Jid jid);
  bool SetName(const std::string &name);
  bool SetSubscription(Subscription subscription);
  bool SetSubscription(const std::string &subscription);
  bool AddGroup(const std::string &group);
  bool RemoveGroup(const std::string &group);
  bool ClearGroups();
  bool SetHasAsk(bool val);
  
  const buzz::Jid GetJid() const;
  const std::string &GetName() const;
  Subscription GetSubscription() const;
  std::string GetSubscriptionStr() const;
  int GetGroupNumber() const;
  ::std::set<std::string>::const_iterator GroupsBegin() const;
  ::std::set<std::string>::const_iterator GroupsEnd() const;
  bool GetHasAsk() const;

  buzz::XmlElement *ToXml();
  
  
  bool operator==(const RosterItem &i) const;
  
protected:
  buzz::Jid m_jid;
  std::string m_name;
  Subscription m_subscription;
  ::std::set<std::string> m_groups;
  bool m_has_ask;
  
private:
  bool m_modified;
  friend class ::cim::RosterTask;  
};

}

#endif /*ROSTERITEM_HPP_9UVATHU7*/
