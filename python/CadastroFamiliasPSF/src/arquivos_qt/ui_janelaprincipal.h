/********************************************************************************
** Form generated from reading ui file 'janelaprincipal.ui'
**
** Created: Sun Jul 19 19:08:56 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_JANELAPRINCIPAL_H
#define UI_JANELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaPrincipalClass
{
public:
    QAction *actionSalvar;
    QAction *actionSair;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *caixaAdciona;
    QVBoxLayout *verticalLayout_3;
    QWidget *nomeWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *rotuloNome;
    QLineEdit *entradaNome;
    QWidget *infoWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *rotuloArea;
    QLineEdit *entradaArea;
    QLabel *rotuloMicroArea;
    QLineEdit *entradaMicroArea;
    QLabel *rotuloFamilia;
    QLineEdit *entradaFamilia;
    QLabel *rotuloDataNasc;
    QLineEdit *entradaDataNasc;
    QWidget *enderecoWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *rotuloRua;
    QLineEdit *entradaRua;
    QLabel *rotuloNumero;
    QLineEdit *entradaNumero;
    QLabel *rotuloComplemento;
    QLineEdit *entradaComplemento;
    QPushButton *botaoAdcionar;
    QGroupBox *caixaBusca;
    QHBoxLayout *horizontalLayout;
    QLineEdit *entradaBusca;
    QComboBox *modosPesquisa;
    QPushButton *botaoBuscar;
    QGroupBox *caixaPacientes;
    QVBoxLayout *verticalLayout_2;
    QTableView *tabelaPacientes;
    QPushButton *botaoListar;
    QMenuBar *barraMenu;
    QMenu *menuPSF_Beta;
    QToolBar *barraMenuPrincipal;
    QStatusBar *barraStatus;

    void setupUi(QMainWindow *JanelaPrincipalClass)
    {
        if (JanelaPrincipalClass->objectName().isEmpty())
            JanelaPrincipalClass->setObjectName(QString::fromUtf8("JanelaPrincipalClass"));
        JanelaPrincipalClass->resize(894, 820);
        actionSalvar = new QAction(JanelaPrincipalClass);
        actionSalvar->setObjectName(QString::fromUtf8("actionSalvar"));
        actionSair = new QAction(JanelaPrincipalClass);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        centralWidget = new QWidget(JanelaPrincipalClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        caixaAdciona = new QGroupBox(centralWidget);
        caixaAdciona->setObjectName(QString::fromUtf8("caixaAdciona"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(caixaAdciona->sizePolicy().hasHeightForWidth());
        caixaAdciona->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(caixaAdciona);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        nomeWidget = new QWidget(caixaAdciona);
        nomeWidget->setObjectName(QString::fromUtf8("nomeWidget"));
        horizontalLayout_2 = new QHBoxLayout(nomeWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setMargin(11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 2, -1, 2);
        rotuloNome = new QLabel(nomeWidget);
        rotuloNome->setObjectName(QString::fromUtf8("rotuloNome"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rotuloNome->sizePolicy().hasHeightForWidth());
        rotuloNome->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(rotuloNome);

        entradaNome = new QLineEdit(nomeWidget);
        entradaNome->setObjectName(QString::fromUtf8("entradaNome"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(entradaNome->sizePolicy().hasHeightForWidth());
        entradaNome->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(entradaNome);


        verticalLayout_3->addWidget(nomeWidget);

        infoWidget = new QWidget(caixaAdciona);
        infoWidget->setObjectName(QString::fromUtf8("infoWidget"));
        horizontalLayout_3 = new QHBoxLayout(infoWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setMargin(11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 2, -1, 2);
        rotuloArea = new QLabel(infoWidget);
        rotuloArea->setObjectName(QString::fromUtf8("rotuloArea"));
        sizePolicy1.setHeightForWidth(rotuloArea->sizePolicy().hasHeightForWidth());
        rotuloArea->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(rotuloArea);

        entradaArea = new QLineEdit(infoWidget);
        entradaArea->setObjectName(QString::fromUtf8("entradaArea"));
        sizePolicy2.setHeightForWidth(entradaArea->sizePolicy().hasHeightForWidth());
        entradaArea->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(entradaArea);

        rotuloMicroArea = new QLabel(infoWidget);
        rotuloMicroArea->setObjectName(QString::fromUtf8("rotuloMicroArea"));
        sizePolicy1.setHeightForWidth(rotuloMicroArea->sizePolicy().hasHeightForWidth());
        rotuloMicroArea->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(rotuloMicroArea);

        entradaMicroArea = new QLineEdit(infoWidget);
        entradaMicroArea->setObjectName(QString::fromUtf8("entradaMicroArea"));
        sizePolicy2.setHeightForWidth(entradaMicroArea->sizePolicy().hasHeightForWidth());
        entradaMicroArea->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(entradaMicroArea);

        rotuloFamilia = new QLabel(infoWidget);
        rotuloFamilia->setObjectName(QString::fromUtf8("rotuloFamilia"));
        sizePolicy1.setHeightForWidth(rotuloFamilia->sizePolicy().hasHeightForWidth());
        rotuloFamilia->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(rotuloFamilia);

        entradaFamilia = new QLineEdit(infoWidget);
        entradaFamilia->setObjectName(QString::fromUtf8("entradaFamilia"));
        sizePolicy2.setHeightForWidth(entradaFamilia->sizePolicy().hasHeightForWidth());
        entradaFamilia->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(entradaFamilia);

        rotuloDataNasc = new QLabel(infoWidget);
        rotuloDataNasc->setObjectName(QString::fromUtf8("rotuloDataNasc"));
        sizePolicy1.setHeightForWidth(rotuloDataNasc->sizePolicy().hasHeightForWidth());
        rotuloDataNasc->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(rotuloDataNasc);

        entradaDataNasc = new QLineEdit(infoWidget);
        entradaDataNasc->setObjectName(QString::fromUtf8("entradaDataNasc"));
        sizePolicy2.setHeightForWidth(entradaDataNasc->sizePolicy().hasHeightForWidth());
        entradaDataNasc->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(entradaDataNasc);


        verticalLayout_3->addWidget(infoWidget);

        enderecoWidget = new QWidget(caixaAdciona);
        enderecoWidget->setObjectName(QString::fromUtf8("enderecoWidget"));
        horizontalLayout_4 = new QHBoxLayout(enderecoWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setMargin(11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 2, -1, 2);
        rotuloRua = new QLabel(enderecoWidget);
        rotuloRua->setObjectName(QString::fromUtf8("rotuloRua"));
        sizePolicy1.setHeightForWidth(rotuloRua->sizePolicy().hasHeightForWidth());
        rotuloRua->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(rotuloRua);

        entradaRua = new QLineEdit(enderecoWidget);
        entradaRua->setObjectName(QString::fromUtf8("entradaRua"));
        sizePolicy2.setHeightForWidth(entradaRua->sizePolicy().hasHeightForWidth());
        entradaRua->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(entradaRua);

        rotuloNumero = new QLabel(enderecoWidget);
        rotuloNumero->setObjectName(QString::fromUtf8("rotuloNumero"));
        sizePolicy1.setHeightForWidth(rotuloNumero->sizePolicy().hasHeightForWidth());
        rotuloNumero->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(rotuloNumero);

        entradaNumero = new QLineEdit(enderecoWidget);
        entradaNumero->setObjectName(QString::fromUtf8("entradaNumero"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(entradaNumero->sizePolicy().hasHeightForWidth());
        entradaNumero->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(entradaNumero);

        rotuloComplemento = new QLabel(enderecoWidget);
        rotuloComplemento->setObjectName(QString::fromUtf8("rotuloComplemento"));
        sizePolicy1.setHeightForWidth(rotuloComplemento->sizePolicy().hasHeightForWidth());
        rotuloComplemento->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(rotuloComplemento);

        entradaComplemento = new QLineEdit(enderecoWidget);
        entradaComplemento->setObjectName(QString::fromUtf8("entradaComplemento"));
        sizePolicy3.setHeightForWidth(entradaComplemento->sizePolicy().hasHeightForWidth());
        entradaComplemento->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(entradaComplemento);


        verticalLayout_3->addWidget(enderecoWidget);

        botaoAdcionar = new QPushButton(caixaAdciona);
        botaoAdcionar->setObjectName(QString::fromUtf8("botaoAdcionar"));
        sizePolicy1.setHeightForWidth(botaoAdcionar->sizePolicy().hasHeightForWidth());
        botaoAdcionar->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(botaoAdcionar);


        verticalLayout->addWidget(caixaAdciona);

        caixaBusca = new QGroupBox(centralWidget);
        caixaBusca->setObjectName(QString::fromUtf8("caixaBusca"));
        sizePolicy.setHeightForWidth(caixaBusca->sizePolicy().hasHeightForWidth());
        caixaBusca->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(caixaBusca);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        entradaBusca = new QLineEdit(caixaBusca);
        entradaBusca->setObjectName(QString::fromUtf8("entradaBusca"));

        horizontalLayout->addWidget(entradaBusca);

        modosPesquisa = new QComboBox(caixaBusca);
        modosPesquisa->setObjectName(QString::fromUtf8("modosPesquisa"));
        modosPesquisa->setEditable(false);
        modosPesquisa->setMinimumContentsLength(1);

        horizontalLayout->addWidget(modosPesquisa);

        botaoBuscar = new QPushButton(caixaBusca);
        botaoBuscar->setObjectName(QString::fromUtf8("botaoBuscar"));

        horizontalLayout->addWidget(botaoBuscar);


        verticalLayout->addWidget(caixaBusca);

        caixaPacientes = new QGroupBox(centralWidget);
        caixaPacientes->setObjectName(QString::fromUtf8("caixaPacientes"));
        verticalLayout_2 = new QVBoxLayout(caixaPacientes);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabelaPacientes = new QTableView(caixaPacientes);
        tabelaPacientes->setObjectName(QString::fromUtf8("tabelaPacientes"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tabelaPacientes->sizePolicy().hasHeightForWidth());
        tabelaPacientes->setSizePolicy(sizePolicy4);
        tabelaPacientes->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        tabelaPacientes->setAlternatingRowColors(true);
        tabelaPacientes->setSortingEnabled(false);
        tabelaPacientes->horizontalHeader()->setCascadingSectionResizes(false);

        verticalLayout_2->addWidget(tabelaPacientes);

        botaoListar = new QPushButton(caixaPacientes);
        botaoListar->setObjectName(QString::fromUtf8("botaoListar"));
        sizePolicy1.setHeightForWidth(botaoListar->sizePolicy().hasHeightForWidth());
        botaoListar->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(botaoListar);


        verticalLayout->addWidget(caixaPacientes);

        JanelaPrincipalClass->setCentralWidget(centralWidget);
        barraMenu = new QMenuBar(JanelaPrincipalClass);
        barraMenu->setObjectName(QString::fromUtf8("barraMenu"));
        barraMenu->setGeometry(QRect(0, 0, 894, 25));
        menuPSF_Beta = new QMenu(barraMenu);
        menuPSF_Beta->setObjectName(QString::fromUtf8("menuPSF_Beta"));
        JanelaPrincipalClass->setMenuBar(barraMenu);
        barraMenuPrincipal = new QToolBar(JanelaPrincipalClass);
        barraMenuPrincipal->setObjectName(QString::fromUtf8("barraMenuPrincipal"));
        JanelaPrincipalClass->addToolBar(Qt::TopToolBarArea, barraMenuPrincipal);
        barraStatus = new QStatusBar(JanelaPrincipalClass);
        barraStatus->setObjectName(QString::fromUtf8("barraStatus"));
        JanelaPrincipalClass->setStatusBar(barraStatus);

        barraMenu->addAction(menuPSF_Beta->menuAction());
        menuPSF_Beta->addAction(actionSalvar);
        menuPSF_Beta->addAction(actionSair);

        retranslateUi(JanelaPrincipalClass);

        QMetaObject::connectSlotsByName(JanelaPrincipalClass);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaPrincipalClass)
    {
        JanelaPrincipalClass->setWindowTitle(QApplication::translate("JanelaPrincipalClass", "Cadastro De Familias", 0, QApplication::UnicodeUTF8));
        actionSalvar->setText(QApplication::translate("JanelaPrincipalClass", "salvar", 0, QApplication::UnicodeUTF8));
        actionSair->setText(QApplication::translate("JanelaPrincipalClass", "sair", 0, QApplication::UnicodeUTF8));
        caixaAdciona->setTitle(QApplication::translate("JanelaPrincipalClass", "Adcionar paciente", 0, QApplication::UnicodeUTF8));
        rotuloNome->setText(QApplication::translate("JanelaPrincipalClass", "Nome:", 0, QApplication::UnicodeUTF8));
        rotuloArea->setText(QApplication::translate("JanelaPrincipalClass", "\303\201rea:", 0, QApplication::UnicodeUTF8));
        rotuloMicroArea->setText(QApplication::translate("JanelaPrincipalClass", "Micro \303\201rea:", 0, QApplication::UnicodeUTF8));
        rotuloFamilia->setText(QApplication::translate("JanelaPrincipalClass", "Familia:", 0, QApplication::UnicodeUTF8));
        rotuloDataNasc->setText(QApplication::translate("JanelaPrincipalClass", "Data Nasc:", 0, QApplication::UnicodeUTF8));
        rotuloRua->setText(QApplication::translate("JanelaPrincipalClass", "Rua:", 0, QApplication::UnicodeUTF8));
        rotuloNumero->setText(QApplication::translate("JanelaPrincipalClass", "Numero:", 0, QApplication::UnicodeUTF8));
        rotuloComplemento->setText(QApplication::translate("JanelaPrincipalClass", "Complemento:", 0, QApplication::UnicodeUTF8));
        botaoAdcionar->setText(QApplication::translate("JanelaPrincipalClass", "Adcionar", 0, QApplication::UnicodeUTF8));
        caixaBusca->setTitle(QApplication::translate("JanelaPrincipalClass", "Encontrar Paciente", 0, QApplication::UnicodeUTF8));
        modosPesquisa->clear();
        modosPesquisa->insertItems(0, QStringList()
         << QApplication::translate("JanelaPrincipalClass", "Nome", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("JanelaPrincipalClass", "Idade", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("JanelaPrincipalClass", "Area", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("JanelaPrincipalClass", "Micro area", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("JanelaPrincipalClass", "Familia", 0, QApplication::UnicodeUTF8)
        );
        botaoBuscar->setText(QApplication::translate("JanelaPrincipalClass", "Buscar", 0, QApplication::UnicodeUTF8));
        caixaPacientes->setTitle(QApplication::translate("JanelaPrincipalClass", "Pacientes", 0, QApplication::UnicodeUTF8));
        botaoListar->setText(QApplication::translate("JanelaPrincipalClass", "Listar todos", 0, QApplication::UnicodeUTF8));
        menuPSF_Beta->setTitle(QApplication::translate("JanelaPrincipalClass", "Arquivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipalClass: public Ui_JanelaPrincipalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H
