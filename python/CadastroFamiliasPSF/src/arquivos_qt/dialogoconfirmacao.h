#ifndef DIALOGOCONFIRMACAO_H
#define DIALOGOCONFIRMACAO_H

#include <QtGui/QDialog>

namespace Ui {
    class DialogoConfirmacao;
}

class DialogoConfirmacao : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(DialogoConfirmacao)
public:
    explicit DialogoConfirmacao(QWidget *parent = 0);
    virtual ~DialogoConfirmacao();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::DialogoConfirmacao *m_ui;
};

#endif // DIALOGOCONFIRMACAO_H
