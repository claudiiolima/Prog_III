#include "Month.h"
#include <iostream>

int main() {
  Month m(1), m2(8);

  cout << m << m2 << endl;

  m.setMonthNumber(5);

  cout << m << m2 << endl;

  // m2.setMonthNumber(m.getMonthNumber());
  m2 = m;

  cout << m << m2 << endl;

  return 0;
}
