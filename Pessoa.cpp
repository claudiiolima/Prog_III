#include <iostream>

using namespace std;

class Pessoa {
public:
  int _idade;
  void aniversario();
  int idade();
};

void Pessoa::aniversario() { _idade++; }

// int Pessoa::idade() { return Pessoa::_idade; }
