#include <iostream>

using namespace std;

class Vendedor {
protected:
  string _nome;
  double _salario;

public:
  Vendedor();                        // Construtor default
  Vendedor(double sal, string name); // Construtor inicializador
  void GetNome(string nov_nome);     // Altera valor de _nome
  void GetSalario(double nov_sal);   // Altera valor de _salario
  string Nome();                     // Retorna string de _nome
  double Salario();                  // Retorna valor de _salario
};
