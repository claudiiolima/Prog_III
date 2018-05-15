#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
  int Ax, Ay;
  int Bx, By;
  int Cx, Cy;
  int Dx, Dy;

public:
  /*Contructor*/
  Rectangle();
  /*Functions*/
  int perimetro();
  int area();
  /*Accessors*/
  int getAltura();
  int getLargura();
  void setAltura(int h);
  void setLargura(int w);
};

#endif
