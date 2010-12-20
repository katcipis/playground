#ifndef THREADSWITCHER_HPP_9UVATHU7
#define THREADSWITCHER_HPP_9UVATHU7

#include "talk/base/messagequeue.h"
#include "talk/base/thread.h"

namespace cim{
  
class ThreadSwitcherMessageData: public talk_base::MessageData{
public:
  ThreadSwitcherMessageData() {}
  virtual ~ThreadSwitcherMessageData() {}
  virtual void DoJob() = 0;
};

template<class obj, class job, class Targ0, class Targ1=char>
class ThreadSwitcherMessageDataImpl: public ThreadSwitcherMessageData{
public:
  ThreadSwitcherMessageDataImpl(obj o, job j, Targ0 d):
        object(o), method(j), arg0(d) { }
  ThreadSwitcherMessageDataImpl(obj o, job j, Targ0 d0, Targ1 d1):
        object(o), method(j), arg0(d0), arg1(d1) { }
  virtual ~ThreadSwitcherMessageDataImpl() {}
  obj object;
  job method;
  Targ0 arg0;
  Targ1 arg1;
  void DoJob() { (object->*method)(this); };
};


class ThreadSwitcher: public talk_base::MessageHandler{
public:
  ThreadSwitcher(talk_base::Thread *main_thread): m_main_thread(main_thread){};
  ~ThreadSwitcher() {};
  
  void DoInThread(ThreadSwitcherMessageData *tsm) {
    m_main_thread->Send(this, 0, tsm);
  }
  void OnMessage(talk_base::Message *pmsg){
    ThreadSwitcherMessageData *msgd = dynamic_cast<ThreadSwitcherMessageData *>(pmsg->pdata);
    if (msgd){
      msgd->DoJob();
      delete msgd;
    }
  };
private:
  talk_base::Thread *m_main_thread;
};
  
  
} // namespace cim

#endif /*THREADSWITCHER_HPP_9UVATHU7*/
