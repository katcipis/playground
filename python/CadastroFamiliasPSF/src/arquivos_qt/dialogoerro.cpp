#include "dialogoerro.h"
#include "ui_dialogoerro.h"

DialogoErro::DialogoErro(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::DialogoErro)
{
    m_ui->setupUi(this);
}

DialogoErro::~DialogoErro()
{
    delete m_ui;
}

void DialogoErro::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
