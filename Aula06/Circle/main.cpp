#include "Circle.h"
#include <iostream>

int main() {
  Circle c1;

  std::cout << c1.getRadius() << std::endl;

  c1.setRadius(1.0);

  std::cout << c1.getRadius() << std::endl;
  std::cout << c1.getArea() << std::endl;
  std::cout << c1.getDiameter() << std::endl;
  std::cout << c1.getCircumference() << std::endl;

  return 0;
}
