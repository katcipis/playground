#include "message.h"
#include "ui_message.h"

Message::Message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Message)
{
    this->ui->setupUi(this);
    this->ui->message->setReadOnly(true);
}

Message::~Message()
{
    delete ui;
}

void Message::setMessage(const QString& message)
{
    this->ui->message->setPlainText(message);
}

void Message::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
