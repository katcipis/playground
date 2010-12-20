#ifndef ROSTER_HPP_
#define ROSTER_HPP_

namespace cim{

//Foward Declartions
class RosterItem;
class RosterTask;

class Roster{
public:
  Roster(RosterTask *roster_task);
  ~Roster();
  bool AddItem(RosterItem *item);
  bool DeleteItem(RosterItem *item);
  
protected:
private:
};

}

#endif /*ROSTER_HPP_*/
