#ifndef FILETRANSFER_HPP_9UVATHU7
#define FILETRANSFER_HPP_9UVATHU7

#include "talk/session/fileshare/fileshare.h"

#include "xmppgui/xmpp/CimClient.hpp"

namespace cim{
  
class FileTransfer: public sigslot::has_slots<>{
public:
  FileTransfer(CimClient *client, cricket::FileShareSession *session);
  virtual ~FileTransfer();

  void OnFileSessionState(cricket::FileShareState state);
  void OnFileUpdateProgress(cricket::FileShareSession *sess);
  void OnFileResampleImage(std::string path, int width, int height, talk_base::HttpTransaction *trans);

private:
  CimClient *m_client;
  cricket::FileShareSession *m_session;
};

}

#endif /*FILETRANSFER_HPP_9UVATHU7*/
