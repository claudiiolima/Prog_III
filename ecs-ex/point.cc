#include "point.h"
#include <complex>

using namespace std;

Point::Point() : xc(0), yc(0) {}
Point::Point(Real x, Real y) : xc(x), yc(y) {}
Real Point::distance(Point p) {
  Point tmp;
  Real d;
  tmp.xc = xc - p.xc;
  tmp.yc = yc - p.yc;

  d = sqrt(pow(tmp.xc, 2) + pow(tmp.yc, 2));
  return d;
}

Real Point::x() { return xc; }
Real Point::y() { return yc; }

void Point::moveTo(Real x, Real y) {
  xc = x;
  yc = y;
}

void Point::operator=(Point p) {
  xc = p.xc;
  yc = p.yc;
}

int Point::operator==(Point p) { return (xc == p.xc && yc == p.yc) ? 1 : 0; }
int Point::operator!=(Point p) { return (xc == p.xc && yc == p.yc) ? 0 : 1; }

void Point::print() { cout << '(' << xc << ',' << yc << ')' << endl; }
