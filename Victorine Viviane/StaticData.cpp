#include <iostream>

class Rec {
private:
  static int n; // membro único para todos os objetos

public:
  Rec() { n++; } // Construtor
  int GetRec() const { return n; }
  ~Rec() { n--; } // Destrutor
};

int Rec::n; // Declarando n para tempo de execução

int main(int argc, char *argv[]) {
  Rec r1, r2, r3;

  std::cout << r1.GetRec() << std::endl;
  std::cout << r2.GetRec() << std::endl;
  std::cout << r3.GetRec() << std::endl;

  {
    Rec r4, r5, r6;
    std::cout << r1.GetRec() << std::endl;
  }

  std::cout << r1.GetRec() << std::endl;

  return 0;
}
