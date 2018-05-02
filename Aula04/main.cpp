#include "vetor.h"

int main(int argc, char const *argv[]) {
  Vetor v(10);

  v.push_back(1);
  v.push_back(2);
  v.push_front(3);

  v.Print();

  v.pop_back();

  v.Print();

  v.pop_front();

  v.Print();

  return 0;
}
