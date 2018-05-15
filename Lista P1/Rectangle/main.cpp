#include "Rectangle.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  try {
    Rectangle r;

    r.setAltura(2);
    r.setLargura(2);

    cout << r.area() << " --- " << r.perimetro() << endl;

    r.setAltura(22);

    cout << r.area() << " --- " << r.perimetro() << endl;
  } catch (int erro) {
    cout << "Err: " << erro << endl;
  }

  return 0;
}
