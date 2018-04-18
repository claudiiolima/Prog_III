#include "loja.h"

using namespace std;

Loja::Loja() : itens(0) {}

Loja::Loja(int x) : itens(x) {}

void Loja::SetItens(unsigned int nov_itens) { itens = nov_itens; }

unsigned int Loja::Itens() { return itens; }

void Loja::SetNomeV(string n) { v.SetNome(n); }

string Loja::NomeV() { return v.Nome(); }

void Loja::SetSalarioV(double s) { v.SetSalario(s); }

double Loja::SalarioV() { return v.Salario(); }

void Loja::SetH_abre(unsigned int h, unsigned int m) {
  h_abre.SetHorario(h, m);
}

string Loja::Hora_abre() { return h_abre.Horas(); }

void Loja::SetH_fecha(unsigned int h, unsigned int m) {
  h_fecha.SetHorario(h, m);
}

string Loja::Hora_fecha() { return h_fecha.Horas(); }
