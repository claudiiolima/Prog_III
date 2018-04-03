#include <cstdio>
#include <iomanip>
#include <iostream>

const double pi = 3.141592653;

class Radianos {
private:
  double rad;

public:
  Radianos() : rad(0.0) {}
  Radianos(double r) : rad(r) {}
  operator double() { return rad; }
  // operator Graus() const;
  void Print() {
    std::cout << std::setiosflags(std::ios::fixed)
              << std::setiosflags(std::ios::showpoint) << std::setprecision(2)
              << rad << " rad" << std::endl;
  }
};

// Radianos::operator Graus() const { return (180 * rad / pi); }

class Graus {
private:
  double g;

public:
  Graus() : g(0.0) {}
  Graus(double x) : g(x) {}
  Graus(Radianos r) { g = (double(r) * 180.0) / pi; }
  operator Radianos() const { return Radianos(g * pi / 180.0); }
  void Print() {
    std::cout << std::setiosflags(std::ios::fixed)
              << std::setiosflags(std::ios::showpoint) << std::setprecision(2)
              << g << "\xF8" << std::endl;
  }
};

int main(void) {
  Graus gr, gA(180.0);
  Radianos rad(pi), rA;
  gr = rad; // = gr(rad);
  rA = gA;  // = Radianos(gA)

  gr.Print();
  gA.Print();

  return 0;
}
