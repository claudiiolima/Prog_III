#include "data.h"

void mostraData(const Data &d) { cout << d.texto() << endl; }

int main() {
  Data D(1, 2, 1934), D1;

  Data D3;

  D = D1;

  mostraData(D);

  D3 = D + D1;

  mostraData(D);
  mostraData(D1);
  mostraData(D3);

  // {
  //   Data D2(20, 11, 2113);
  //   mostraData(D2);
  // }

  // unsigned int dia, mes, ano;
  // cout << "Digite dia: ";
  // cin >> dia;
  // D.dia(dia);
  // cout << "Digite mes: ";
  // cin >> mes;
  // D.mes(mes);
  // cout << "Digite ano: ";
  // cin >> ano;
  // D.ano(ano);

  // D1 = D;

  // std::cout << '\n' << D1.texto() << endl;

  return 0;
}
