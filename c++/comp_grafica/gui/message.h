#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDialog>

namespace Ui {
    class Message;
}

class Message : public QDialog {
    Q_OBJECT
public:
    Message(QWidget *parent = 0);
    void setMessage(const QString& message);
    ~Message();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Message *ui;
};

#endif // MESSAGE_H
