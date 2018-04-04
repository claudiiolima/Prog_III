#include <cstring>
#include <iostream>

class BasAg {
protected:
  static const int Tamanho = 80;
  char Nome[Tamanho];
  char Numero[4];

public:
  BasAg() {
    Nome[0] = '\0';
    Numero[0] = '\0';
  }
  BasAg(char *n, char *ng) {
    if (strlen(n) < Tamanho)
      strcpy(Nome, n);
    if (strlen(ng) < 4)
      strcpy(Numero, ng);
  }
  void Print() {
    std::cout << "DADOS DO AGENTE:" << std::endl
              << "================" << std::endl
              << "Nome: " << Nome << std::endl
              << "Numero: " << Numero << std::endl;
  }
};

class Agente : public BasAg {
protected:
  float Altura;
  int Idade;

public:
  Agente() : BasAg(), Altura(0), Idade(0) {}
  Agente(char *n, char *ng, float a, int i)
      : BasAg(n, ng), Altura(a), Idade(i) {}
  void Print() {
    BasAg::Print();
    std::cout << "Altura: " << Altura << std::endl
              << "Idade: " << Idade << std::endl;
  }
};

int main(void) {
  Agente Ag("James Bond", "007", 1.9, 35), Ag1;
  Ag.Print();
  std::cout << "\n\n";
  Ag1.Print();

  return 0;
}
