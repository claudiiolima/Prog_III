#include <iostream>

using namespace std;

auto add(int x, int y) { return x + y; }

auto add(int x, double y) { return x + y; }

auto add(int x, int y, int z) { return x + y + z; }

int main() {
  cout << add(7, 2);
  cout << add(1, 7.5);
  cout << add(7, 2, 5);

  return 0;
}
