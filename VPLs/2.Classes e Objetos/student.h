#include <iostream>

using namespace std;

class Student {
private:
  static const int TAM = 5;
  int scores[TAM];

public:
  void input();
  int calculateTotalScore();
};
