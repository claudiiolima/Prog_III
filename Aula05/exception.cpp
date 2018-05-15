#include <iostream>

using namespace std;

double div(double a, double b) {
  if (b == 0)
    throw - 99;
  return a / b;
}

int main(int argc, char *argv[]) {
  try {
    cout << "DIV: " << div(5.0, 0.0) << endl;
  } catch (int erro) {
    cerr << "Err " << erro << endl;
  }
  cout << "Fim!! \n";
  return 0;
}
