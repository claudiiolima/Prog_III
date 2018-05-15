#include "Car.h"

int main(int argc, char *argv[]) {
  Car c(2002, "Renault");

  cout << c;
  for (int i = 0; i < 20; ++i)
    c.accelerate();

  cout << c;

  return 0;
}
