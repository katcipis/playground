#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class JanelaPrincipalClass;
}

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();

private:
    Ui::JanelaPrincipalClass *ui;
};

#endif // JANELAPRINCIPAL_H
