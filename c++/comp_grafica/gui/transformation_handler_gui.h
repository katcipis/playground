#ifndef TRANFORMATION_HANDLER_GUI_H
#define TRANFORMATION_HANDLER_GUI_H
#include <QTextStream>
#include <QDialog>
#include "matrix.h"
#include "point.h"

namespace Ui {
    class TransformationHandlerGUI;
}

class TransformationHandlerGUI : public QDialog {
    Q_OBJECT
public:
    TransformationHandlerGUI(QWidget *parent = 0);
    ~TransformationHandlerGUI();
    void resetInternalState();
    const Matrix& getTransformationMatrix() const;
    void setSelectedObjectCenter(const Point& objCenter);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TransformationHandlerGUI *ui;
    Matrix transformation;
    bool reseted;
    Point objectCenter;

    void calculateNewMatrix(const Matrix& matrix);
    void addNewOperation(const QString& operation, const QString& x, const QString& y, const QString& z);
    Point getRotationPoint();
    void rotateAxis(QTextStream& stream, double r_angle);

private slots:
    void handleAddTranslate();
    void handleAddScale();
    void handleAddRotate();
};

#endif // TRANFORMATION_HANDLER_GUI_H
