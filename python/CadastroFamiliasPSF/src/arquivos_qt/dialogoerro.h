#ifndef DIALOGOERRO_H
#define DIALOGOERRO_H

#include <QtGui/QDialog>

namespace Ui {
    class DialogoErro;
}

class DialogoErro : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(DialogoErro)
public:
    explicit DialogoErro(QWidget *parent = 0);
    virtual ~DialogoErro();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::DialogoErro *m_ui;
};

#endif // DIALOGOERRO_H
