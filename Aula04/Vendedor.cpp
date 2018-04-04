#include "vendedor.h"

using namespace std;

Vendedor::Vendedor() : _nome(""), _salario(0) {}

Vendedor::Vendedor(double sal, string name) : _nome(name), _salario(sal) {}

void Vendedor::GetSalario(double nov_sal) { _salario = nov_sal; }

void Vendedor::GetNome(string nov_nome) { _nome = nov_nome; }

double Vendedor::Salario() { return _salario; }

string Vendedor::Nome() { return _nome; }
