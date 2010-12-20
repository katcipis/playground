#ifndef FUZZYSET_H
#define FUZZYSET_H

#include <QList>
#include <QPointF>

class FuzzySet {

private:
    QList<QPointF> points;

public:

    FuzzySet();

    void add(QPointF p);

    bool operator==(const FuzzySet& f) const;

    bool operator!=(const FuzzySet& f) const;

    /**
      * Varre os pontos que definem a função e retorna o y referente ao ponto x.
      *
      * @param x
      * @return y
      */
    double y(double x);

    int size() const;

    FuzzySet ou(const FuzzySet& s1);

    /**
      * Cepa um conjunto nebuloso em um determinado valor y
      *
      * @param y
      * @return novo conjunto cepado em y
      */
    FuzzySet cepar(double y);

    QPointF getPoints(int i) const;

    double centroide();
};

#endif // FUZZYSET_H
