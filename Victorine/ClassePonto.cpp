#include <iostream>

class Ponto {
private:
  int x, y;

public:
  Ponto(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}

  Ponto operator++();
  Ponto operator++(int);
  Ponto operator+(Ponto &p) const;
  Ponto operator+(int n) const;

  void Print() const;
};

Ponto Ponto::operator++() {
  ++x;
  ++y;
  return Ponto(x, y);
}

Ponto Ponto::operator++(int) {
  x++;
  y++;
  return Ponto(x - 1, y - 1);
}

Ponto Ponto::operator+(Ponto &p) const {
  Ponto tmp;
  tmp.x = x + p.x;
  tmp.y = y + p.y;
  return tmp;
  // return Ponto(x + p.x, y + p.y);
}

Ponto Ponto::operator+(int n) const { return Ponto(x + n, y + n); }

void Ponto::Print() const {
  std::cout << '(' << x << ',' << y << ')' << std::endl;
}

int main() {
  Ponto A(5, 1), B(2, 3), C, D;

  std::cout << "A = ";
  A.Print();
  std::cout << "B = ";
  B.Print();

  C = A + B; // = A.operator+(B);
  D = A + 5; // = A.operator+(5);

  std::cout << "A = ";
  C.Print();
  std::cout << "B = ";
  D.Print();

  return 0;
}
