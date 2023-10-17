#include "point.h"

class Circle {
public:
    void setR(double R) { c_R = R; }
    double getR() { return c_R; }
    void setCenter(Point Center) { c_Center = Center; }
    Point getCenter() { return c_Center; }

private:
    double c_R;
    Point c_Center;
};
