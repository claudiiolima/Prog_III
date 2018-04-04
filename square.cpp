#include <iostream>

using namespace std;

auto square(int x) { return x * x; }

// auto square(double x) { return x * x; }

int main() {
  cout << square(7);
  cout << square(7.5);

  return 0;
}
