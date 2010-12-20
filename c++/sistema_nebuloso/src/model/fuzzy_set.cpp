#include "model/fuzzy_set.h"

FuzzySet::FuzzySet()
{

}

void FuzzySet::add(QPointF p)
{
    this->points.append(p);
}

bool FuzzySet::operator==(const FuzzySet& f) const
{
    for (int i = 0; i < this->size(); i++) {
        if (this->getPoints(i).x() != f.getPoints(i).x()) {
            return false;
        }
        if (this->getPoints(i).y() != f.getPoints(i).y()) {
            return false;
        }
    }
    return true;
}

bool FuzzySet::operator!=(const FuzzySet& f) const
{
    return !(*this == f);
}

double FuzzySet::y(double x)
{
    double x1, x2, y1, y2;

    if (x <= points[0].x()) {
        return points[0].y();
    }

    for (int i = 1; i < points.size(); i++) {
        x1 = points[i - 1].x();
        x2 = points[i].x();
        y1 = points[i - 1].y();
        y2 = points[i].y();
        if (x <= x2) {
            if (y1 != y2) {
                if (y1 > y2) {
                    return ((y1 - y2) * (x2 - x)) / (x2 - x1);
                } else if (y1 < y2) {
                    return ((y2 - y1) * (x - x1)) / (x2 - x1);
                }
            } else {
                return y1;
            }
        }
    }
    return points.last().y();
}

int FuzzySet::size() const
{
    return this->points.size();
}

FuzzySet FuzzySet::ou(const FuzzySet& s1)
{
    FuzzySet f1 = *this;
    FuzzySet f2 = s1;
    FuzzySet r;
    double x11, y11, x12, y12, x21, y21, x22, y22, x, y, s, t, det;
    bool intersectou = false;
    bool maior = true;

    if (this->points.first().x() >= s1.points.first().x()) {
        f1 = s1;
        f2 = *this;
    }

    for (int i = 0; i < f1.size(); i++) {
        if (f2.y((f1.points[i].x())) < f1.points[i].y()) {
            maior = false;
        }
    }

    if (maior) {
        return f2;
    }

    x11 = f1.points.first().x();
    x21 = f2.points.first().x();
    x12 = f1.points.last().x();
    x22 = f2.points.last().x();

    if (x12 <= x21) {
        int j = 0;
        if (x12 == x21) {
           j = 1;
        }
        for (int i = 0; i < f1.size(); i++) {
            r.add(f1.getPoints(i));
        }
        for (int i = j; i < f2.size(); i++) {
            r.add(f2.getPoints(i));
        }
        return r;
    }

    y11 = f1.points.first().y();
    y21 = f2.points.first().y();

    for (int i = 1; i < f1.points.size(); i++) {
        if (y11 < f1.points[i].y()) {
            y11 = f1.points[i].y();
        }
    }
    for (int i = 1; i < f2.points.size(); i++) {
        if (y21 < f2.points[i].y()) {
            y21 = f2.points[i].y();
        }
    }
    if (x11 < x21 && x12 > x22 && y11 >= y21) {
        return f1;
    }

    for (int j = 0; j < f2.points.size() - 1; j++) {
        x11 = f1.points.first().x();
        y11 = f1.points.first().y();

        x21 = f2.points[j].x();
        y21 = f2.points[j].y();
        x22 = f2.points[j + 1].x();
        y22 = f2.points[j + 1].y();
        r.add(f1.points.first());

        for (int i = 1; i < f1.points.size(); i++) {

            x12 = f1.points[i].x();
            y12 = f1.points[i].y();

            det = (x22 - x21) * (y12 - y11) - (y22 - y21) * (x12 - x11);
            if (det >= 0.05 || det <= -0.05) {
                // parametro em relação a reta 1
                s = (((x22 - x21) * (y21 - y11) - (y22 - y21) * (x21 - x11)) / det);

                // parametro em relacao a reta 2
                t = (((x12 - x11) * (y21 - y11) - (y12 - y11) * (x21 - x11)) / det);

                if (s >= 0 && s <= 1 && t > 0 && t <= 1) {
                    // (x,y) = t*P2 + (1-t)*P2 da reta 2
                    // poderia ser feito com s mas pra reta 1
                    x = x22 * (t) + x21 * (1 - t);
                    y = y22 * (t) + y21 * (1 - t);
                    if (!(s == 0 || t == 0 || s == 1 || t == 1)) {
                        r.add(QPointF(x, y));
                    }
                    intersectou = true;
                    break;
                } else {
                    r.add(f1.points[i]);
                }
            } else {
                r.add(f1.points[i]);
            }

            x11 = x12;
            y11 = y12;
        }

        for (int i = j + 1; i < f2.points.size(); i++) {
            r.add(f2.points[i]);
        }
        if (intersectou) {
            break;
        } else {
            r = FuzzySet();
        }
    }

    if (r.size() > 0) {
        return r;
    } else {
        return f1;
    }
}

FuzzySet FuzzySet::cepar(double y)
{
    FuzzySet s1;
    double x11, x12, y11, y12, det, s, t, x, cx1, cx2;

    cx1 = this->points.first().x();
    cx2 = this->points.last().x();

    if(this->points.first().y() > y) {
        s1.add(QPointF(this->points.first().x(), y));
    } else {
        s1.add(this->points.first());
    }

    for (int i = 0; i < this->size() - 1; i++) {

        x11 = this->points[i].x();
        y11 = this->points[i].y();
        x12 = this->points[i + 1].x();
        y12 = this->points[i + 1].y();

        det = (cx2 - cx1) * (y12 - y11);
        if (det >= 0.05 || det <= -0.05) {
            // parametro em relação a reta 1
            s = ((cx2 - cx1) * (y - y11)) / det;

            // parametro em relacao a reta 2
            t = (((x12 - x11) * (y - y11) - (y12 - y11) * (cx1 - x11)) / det);

            if (s >= 0 && s <= 1 && t > 0 && t <= 1) {
            // (x,y) = t*P2 + (1-t)*P2 da reta 2
            // poderia ser feito com s mas pra reta 1
                x = cx2 * (t) + cx1 * (1 - t);
                s1.add(QPointF(x, y));
            } else if (y11 < y) {
                s1.add(points[i]);
            }
        } else if (y11 < y) {
            s1.add(points[i]);
        }
    }

    if(points.last().y() > y) {
        s1.add(QPointF(points.last().x(), y));
    } else {
        s1.add(points.last());
    }

    return s1;
}

QPointF FuzzySet::getPoints(int i) const
{
    return this->points[i];
}

double FuzzySet::centroide()
{
    double num = 0, denom = 0;
    double min = points.first().x();
    double max = points.last().x();
    double step = 0.1;

    for (double x = min; x <= max; x += step) {
        double m = this->y(x);
        num += x * m;
        denom += m;
    }

    if (denom == 0) {
        return (min + max) / 2.0;
    }

    return num / denom;
}
