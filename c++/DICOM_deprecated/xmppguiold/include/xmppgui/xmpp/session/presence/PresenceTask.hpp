#ifndef PRESENCETASK_HPP_9UVATHU7
#define PRESENCETASK_HPP_9UVATHU7
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
 
#include "talk/xmpp/xmppengine.h"
#include "talk/xmpp/xmpptask.h"
#include "talk/xmpp/jid.h"

#include <map>

namespace cim {

class RosterItem;

class PresenceTask : public buzz::XmppTask{
public:
    PresenceTask(Task *parent) : buzz::XmppTask(parent, buzz::XmppEngine::HL_TYPE) {}
    virtual ~PresenceTask() {};
    virtual int ProcessStart();
    
    void RequestSubscription(buzz::Jid jid);
    void ApproveRequest(buzz::Jid jid);
    void RefuseRequest(buzz::Jid jid);
    void CancelSubscription(buzz::Jid jid);
    void UnsubscribFromEntity(buzz::Jid jid);
    
    sigslot::signal1<buzz::Jid> SignalSubscriptionRequest;
    //sigslot::signal2<buzz::Jid, bool> SignalSubscriptionAnswer;
     
    void OnRosterReceived(RosterItem item);

protected:
    virtual bool HandleStanza(const buzz::XmlElement *stanza);

    typedef std::map<std::string, int> SubscriptionMap;
    SubscriptionMap m_subscriptions;
    
};

}


#endif /*PRESENCETASK_HPP_9UVATHU7*/
