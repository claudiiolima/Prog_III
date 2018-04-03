#include <iostream>

class Moeda {
private:
  float R$;

public:
  static float US$;
  Moeda(float x) : R$(x) {}
  Moeda();
  static void ValorUS$();
  float USdolar() { return R$ / US$; }
  float Val() { return R$; }
};

Moeda::Moeda() {
  std::cout << "Digite R$: ";
  std::cin >> R$;
}

void Moeda::ValorUS$() {
  std::cout << "Digite o valor do dólar" << std::endl;
  std::cin >> US$;
}

float Moeda::US$;

int main(int argc, char *argv[]) {

  Moeda::ValorUS$(); // Chama método static

  Moeda A(3.5), B;
  std::cout << "A em R$ " << A.Val() << " em US$: " << A.USdolar() << std::endl;
  std::cout << "B em R$ " << B.Val() << " em US$: " << B.USdolar() << std::endl;

  return 0;
}
