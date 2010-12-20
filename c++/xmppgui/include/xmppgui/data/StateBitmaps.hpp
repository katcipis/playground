#ifndef STATEBITMAPS_HPP_9UVATHU7
#define STATEBITMAPS_HPP_9UVATHU7

#include <wx/bitmap.h>

namespace cim{

class StateBitmaps{
public:
  StateBitmaps();
  virtual ~StateBitmaps();
  
  static StateBitmaps &GetInstance();
  
  virtual wxBitmap &ShowNone();
  virtual wxBitmap &ShowOffline();
  virtual wxBitmap &ShowXa();
  virtual wxBitmap &ShowAway();
  virtual wxBitmap &ShowDnd();
  virtual wxBitmap &ShowOnline();
  virtual wxBitmap &ShowChat();

protected:
  wxBitmap m_show_none;
  wxBitmap m_show_offline;
  wxBitmap m_show_xa;
  wxBitmap m_show_away;
  wxBitmap m_show_dnd;
  wxBitmap m_show_online;
  wxBitmap m_show_chat;
  
};

}

#endif /*STATEBITMAPS_HPP_9UVATHU7*/
