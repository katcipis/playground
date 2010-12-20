#include "transformation_handler_gui.h"
#include "ui_transformation_handler_gui.h"
#include "transform.h"

TransformationHandlerGUI::TransformationHandlerGUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransformationHandlerGUI),
    transformation(),
    reseted(true),
    objectCenter(1,1)
{
    this->ui->setupUi(this);

    QObject::connect(this->ui->adcionaEscalonamento, SIGNAL(clicked()),this,SLOT(handleAddScale()));
    QObject::connect(this->ui->adcionaTranslacao, SIGNAL(clicked()),this,SLOT(handleAddTranslate()));
    QObject::connect(this->ui->adicionaRotacao, SIGNAL(clicked()),this,SLOT(handleAddRotate()));
}

void TransformationHandlerGUI::setSelectedObjectCenter(const Point& objCenter)
{
    this->objectCenter = objCenter;
}

void TransformationHandlerGUI::calculateNewMatrix(const Matrix& matrix)
{
    if (this->reseted) {
        this->transformation = matrix;
        this->reseted = false;
    } else {
        this->transformation = this->transformation * matrix;
    }
}

void TransformationHandlerGUI::addNewOperation(const QString& operation, const QString& x, const QString& y, const QString& z)
{
    QString messageStr;
    QTextStream(&messageStr) << "Operacao: " << operation << " x: " << x << " y: " << y << " z: " << z;
    this->ui->transformacoesPendentes->addItem(messageStr);
}

void TransformationHandlerGUI::handleAddTranslate()
{
    double x = this->ui->translacaoX->text().toDouble();
    double y = this->ui->translacaoY->text().toDouble();
    this->calculateNewMatrix(transform::getTranslateMatrix(x,y));
    this->addNewOperation(QString("Translacao"), this->ui->translacaoX->text(), this->ui->translacaoY->text(), this->ui->translacaoZ->text());
}

Point TransformationHandlerGUI::getRotationPoint()
{
    if (this->ui->rotacionarCentro->isChecked()) {
        return this->objectCenter;
    }

    return Point(this->ui->rotacionaX->text().toDouble(), this->ui->rotacionaY->text().toDouble(), this->ui->rotacionaZ->text().toDouble());
}

void TransformationHandlerGUI::rotateAxis(QTextStream& stream, double r_angle)
{
    if(this->ui->rotacionarEixoX->isChecked()) {
        stream << " em torno do eixo x";
        this->calculateNewMatrix(transform::getXAxisRotateMatrix(r_angle));
        return;
    }

    if(this->ui->rotacionarEixoY->isChecked()) {
        this->calculateNewMatrix(transform::getYAxisRotateMatrix(r_angle));
        stream << " em torno do eixo y";
        return;
    }

    if(this->ui->rotacionarEixoZ->isChecked()) {
        this->calculateNewMatrix(transform::getZAxisRotateMatrix(r_angle));
        stream << " em torno do eixo z";
        return;
    }

    if(this->ui->rotacionarEixoArb->isChecked()) {
        Point axis = Point(this->ui->eixoArbX->text().toDouble(),
                           this->ui->eixoArbY->text().toDouble(),
                           this->ui->eixoArbZ->text().toDouble());

        stream << " em torno do eixo arbitrário [" << axis.toString() << "]";
        this->calculateNewMatrix(transform::getArbAxisRotateMatrix(r_angle, axis));
    }
}

void TransformationHandlerGUI::handleAddRotate()
{
    QString messageStr;
    QTextStream stream(&messageStr);
    double r_angle = transform::fromDegreeToRadian(this->ui->angulo->text().toDouble());

    if (!this->ui->rotacionarCentro->isChecked() &&
        !this->ui->rotacionarOrigem->isChecked() &&
        !this->ui->rotacionarPonto->isChecked()) {
        return;
    }

    if (!this->ui->rotacionarEixoX->isChecked() &&
        !this->ui->rotacionarEixoY->isChecked() &&
        !this->ui->rotacionarEixoZ->isChecked() &&
        !this->ui->rotacionarEixoArb->isChecked()) {
        return;
    }

    stream << "Rotacionar angulo [" << this->ui->angulo->text() << "] em torno ";

    if (this->ui->rotacionarOrigem->isChecked()) {
        stream << "da origem";
        this->rotateAxis(stream, r_angle);
    } else {
        Point rotationPoint = this->getRotationPoint();
        stream << "de [" << rotationPoint.toString() << "]";
        this->calculateNewMatrix(transform::getTranslateMatrix(-rotationPoint.getX(), -rotationPoint.getY(), -rotationPoint.getZ()));
        this->rotateAxis(stream, r_angle);
        this->calculateNewMatrix(transform::getTranslateMatrix(rotationPoint.getX(), rotationPoint.getY(), rotationPoint.getZ()));
    }

    this->ui->transformacoesPendentes->addItem(messageStr);
}

void TransformationHandlerGUI::handleAddScale()
{
    double x = this->ui->escalonaX->text().toDouble();
    double y = this->ui->escalonaY->text().toDouble();
    this->calculateNewMatrix(transform::getTranslateMatrix(-this->objectCenter.getX(), -this->objectCenter.getY()));
    this->calculateNewMatrix(transform::getScaleMatrix(x,y));
    this->calculateNewMatrix(transform::getTranslateMatrix(this->objectCenter.getX(), this->objectCenter.getY()));
    this->addNewOperation(QString("Scale"), this->ui->escalonaX->text(), this->ui->escalonaY->text(), this->ui->escalonaZ->text());
}

TransformationHandlerGUI::~TransformationHandlerGUI()
{
    delete ui;
}

void TransformationHandlerGUI::changeEvent(QEvent *e)
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

const Matrix& TransformationHandlerGUI::getTransformationMatrix() const
{
    return this->transformation;
}

void TransformationHandlerGUI::resetInternalState()
{
    this->reseted = true;
    this->ui->transformacoesPendentes->clear();
}
