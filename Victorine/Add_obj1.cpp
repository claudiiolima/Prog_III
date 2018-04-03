#include <iomanip>
#include <iostream>

using namespace std;

class Venda {
private:
  int npecas;
  float preco;

public:
  Venda() {}
  Venda(int np, float p) {
    npecas = np;
    preco = p;
  }
  void GetVenda();
  void PrintVenda() const;
  Venda operator+(Venda &x) const;
  // Venda Add_Venda(Venda &x) const; // = void Add_Venda(Venda v1, Venda v2)
};

void Venda::GetVenda() {
  cout << "Insira No. Peças: " << endl;
  cin >> npecas;
  cout << "Insira Preço: " << endl;
  cin >> preco;
}

void Venda::PrintVenda() const {
  cout << setiosflags(ios::fixed)     // nao notaçao cientifica
       << setiosflags(ios::showpoint) // ponto decimal
       << setprecision(2)             // duas casas decimais
       << setw(10) << npecas;
  cout << setw(10) << preco << endl;
}

// Venda Venda::Add_Venda(Venda &x) const {
//   Venda tmp;
//   tmp.npecas = npecas + x.npecas;
//   tmp.preco = preco + x.preco;
//   return tmp;
// }

/*
*void Venda::Add_Venda(Venda v1, Venda v2) {
*   npecas = v1.npecas + v2.npecas;
*   preco = v1.preco + v2.preco;
*}
*/

Venda Venda::operator+(Venda &x) const {
  Venda tmp;
  tmp.npecas = npecas + x.npecas;
  tmp.preco = preco + x.preco;
  return tmp;
}

// int main(void) {
//   Venda A(58, 12734.53), B, Total;
//   B.GetVenda();
//   Total = A.Add_Venda(B); // Total = A + B0;
//
//   cout << endl;
//   cout << "Venda A.........";
//   A.PrintVenda();
//   cout << "Venda B.........";
//   B.PrintVenda();
//   cout << "Totais..........";
//   Total.PrintVenda();
//
//   return 0;
// }

int main(void) {
  Venda A(58, 12734.53), B, C(30, 6000.3), SubTotal, Total;

  B.GetVenda();

  SubTotal = A + B;     // = A.operator+(B);
  Total = SubTotal + C; // = SubTotal.operator+(C);

  std::cout << std::endl;
  std::cout << "Venda A...........";
  A.PrintVenda();
  std::cout << "Venda B...........";
  B.PrintVenda();
  std::cout << "Sub Total.........";
  SubTotal.PrintVenda();
  std::cout << "Totais............";
  Total.PrintVenda();

  return 0;
}
