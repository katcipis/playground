#ifndef ROSTERTASK_HPP_9UVATHU7
#define ROSTERTASK_HPP_9UVATHU7
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

#include "talk/xmpp/xmppengine.h"
#include "talk/xmpp/xmpptask.h"
#include "talk/xmpp/jid.h"

namespace cim {
  
class PresenceTask;

class RosterTask : public buzz::XmppTask{
public:
    RosterTask(Task *parent);
    virtual ~RosterTask();
    virtual int ProcessStart();
    
    virtual int ParseItem(const buzz::XmlElement *element);
    
    void RequestRoster();
    void UpdateRosterItem(RosterItem &item);
    void DeleteRosterItem(RosterItem &item);
    
    

    sigslot::signal1<RosterItem> SignalRosterReceived;

protected:
    virtual bool HandleStanza(const buzz::XmlElement *stanza);
    
    PresenceTask *m_presence;
};

}


#endif /*ROSTERTASK_HPP_9UVATHU7*/
