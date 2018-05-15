typedef float Real;

#include <iostream>

class Point
{
public:
   Point();
   Point(Real x, Real y);
   Real distance(Point p);

   Real x();
   Real y();
   
   void moveTo(Real x, Real y);

   void operator = (Point p);
   int operator == (Point p);
   int operator != (Point p);

   void print();


private:
   Real xc;
   Real yc;

};
