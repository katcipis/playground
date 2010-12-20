#include "xmppgui/xmpp/FileTransfer.hpp"

#include "talk/base/stream.h"

namespace cim{

FileTransfer::FileTransfer(CimClient *client, cricket::FileShareSession *session):
      m_client(client), m_session(session){
  m_session->SignalState.connect(this, &FileTransfer::OnFileSessionState);
  m_session->SignalUpdateProgress.connect(this, &FileTransfer::OnFileUpdateProgress);
  m_session->SignalResampleImage.connect(this, &FileTransfer::OnFileResampleImage);
}

FileTransfer::~FileTransfer(){
  m_session->SignalState.disconnect(this);
  m_session->SignalUpdateProgress.disconnect(this);
  m_session->SignalResampleImage.disconnect(this);
}

void FileTransfer::OnFileSessionState(cricket::FileShareState state){
  m_client->SignalFileSessionState(m_session, state);
}

void FileTransfer::OnFileUpdateProgress(cricket::FileShareSession *sess){
  m_client->SignalFileUpdateProgress(sess);
}

void FileTransfer::OnFileResampleImage(std::string path, int width, int height,
      talk_base::HttpTransaction *trans){
  //TODO: resample it :)
  talk_base::FileStream *s = new talk_base::FileStream();
  if (s->Open(path.c_str(), "rb")){
    m_session->ResampleComplete(s, trans, true);
  } else {
    delete s;
    m_session->ResampleComplete(NULL, trans, false);
  }
        
}

}


