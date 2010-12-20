#include "dialogoconfirmacao.h"
#include "ui_dialogoconfirmacao.h"

DialogoConfirmacao::DialogoConfirmacao(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::DialogoConfirmacao)
{
    m_ui->setupUi(this);
}

DialogoConfirmacao::~DialogoConfirmacao()
{
    delete m_ui;
}

void DialogoConfirmacao::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
