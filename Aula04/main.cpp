#include "loja.h"
#include <iomanip>

using namespace std;

int main() {
  Loja l;
  string n;
  double s;
  int h, m, i;
  cout << "\n\tNome do vendedor: ";
  cin >> n;
  l.GetNomeV(n);
  cout << "\tSalario do " << l.NomeV() << ": ";
  cin >> s;
  l.GetSalarioV(s);
  cout << "\tHorario de abertura :";
  cin >> h >> m;
  l.GetH_abre(h, m);
  cout << "\tHorario de fechamento: ";
  cin >> h >> m;
  l.GetH_fecha(h, m);
  cout << "\tNumero de itens: ";
  cin >> i;
  l.GetItens(i);
  cout << "\n\t=============================\n" << endl;
  cout << "\tVendedor: " << l.NomeV() << endl
       << "\tSalario: R$ " << l.SalarioV() << endl
       << "\tHorario de abertura: " << l.Hora_abre() << endl
       << "\tHorario de fechamento: " << l.Hora_fecha() << endl
       << "\tNumero de itens: " << l.Itens() << '\n'
       << endl;

  return 0;
}
