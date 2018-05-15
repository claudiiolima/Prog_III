#include "Rectangle.h"

Rectangle::Rectangle() : altura(1), largura(1) {}

int Rectangle::perimetro() { return (2 * altura + 2 * largura); }

int Rectangle::area() { return (altura * largura); }

int Rectangle::getAltura() { return altura; }

int Rectangle::getLargura() { return largura; }

void Rectangle::setAltura(int h) {
  if (h >= 20 || h <= 0)
    throw - 1;
  altura = h;
}

void Rectangle::setLargura(int w) {
  if (w >= 20 || w <= 0)
    throw - 1;
  largura = w;
}
