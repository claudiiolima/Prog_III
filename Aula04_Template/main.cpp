#include "vetor.hpp"

int main(int argc, char const *argv[]) {
  Vetor<double, 10> v;

  v.push_back(1.2);
  v.push_back(2.699);
  v.push_front(3.48);

  v.Print();

  v.pop_back();

  v.Print();

  v.pop_front();

  v.Print();

  return 0;
}
