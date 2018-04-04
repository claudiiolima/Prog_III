#include "loja.h"

using namespace std;

Loja::Loja() : itens(0) {}

Loja::Loja(int x) : itens(x) {}

void Loja::GetItens(unsigned int nov_itens) { itens = nov_itens; }

unsigned int Loja::Itens() { return itens; }

void Loja::GetNomeV(string n) { v.GetNome(n); }

string Loja::NomeV() { return v.Nome(); }

void Loja::GetSalarioV(double s) { v.GetSalario(s); }

double Loja::SalarioV() { return v.Salario(); }

void Loja::GetH_abre(unsigned int h, unsigned int m) {
  h_abre.GetHorario(h, m);
}

string Loja::Hora_abre() { return h_abre.Horas(); }

void Loja::GetH_fecha(unsigned int h, unsigned int m) {
  h_fecha.GetHorario(h, m);
}

string Loja::Hora_fecha() { return h_fecha.Horas(); }
