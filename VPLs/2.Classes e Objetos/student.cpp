#include "student.h"

using namespace std;

void Student::input() {
  for (int i = 0; i < TAM; i++) {
    cin >> scores[i];
  }
}

int Student::calculateTotalScore() {
  int sum = 0;
  for (int i = 0; i < TAM; i++) {
    sum += scores[i];
  }

  return sum;
}
