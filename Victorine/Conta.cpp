#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

class Conta {
private:
  static const int Tamanho = 80;
  char Nome[Tamanho];
  int Numero;
  float SaldoBase;

public:
  void Get() {
    cout << "Nome: ";
    fgets(Nome, sizeof(Nome), stdin);
    cout << "N\xF8 Conta: ";
    cin >> Numero;
    cout << "Saldo: ";
    cin >> SaldoBase;
    cin.ignore(10, '\n');
  }
  void Print() {
    cout << "Nome: " << Nome << endl
         << "N\xF8 Conta: " << Numero << endl
         << "Saldo: " << setiosflags(ios::fixed) << setprecision(2) << SaldoBase
         << endl;
  }
  float Saldo() { return SaldoBase; }
};

class ContaSimples : public Conta {};

class ContaEspecial : public Conta {
private:
  float Limite;

public:
  void Get() {
    Conta::Get();
    cout << "Limite: ";
    cin >> Limite;
    cin.ignore(10, '\n');
  }
  void Print() {
    Conta::Print();
    cout << "Limite: " << Limite << endl;
    cout << "Saldo Total: " << setiosflags(ios::fixed) << setprecision(2)
         << (Saldo() + Limite) << endl;
  }
};

class ContaPoupanca : public Conta {
private:
  float Taxa;

public:
  void Get() {
    Conta::Get();
    cout << "Taxa: ";
    cin >> Taxa;
    cin.ignore(10, '\n');
  }
  void Print() {
    Conta::Print();
    cout << "Taxa: " << Taxa << endl
         << "Saldo Total: " << setiosflags(ios::fixed) << setprecision(2)
         << (Saldo() * Taxa) << endl;
  }
};

int main(void) {
  ContaSimples c1, c2;
  ContaEspecial c3;
  ContaPoupanca c4;

  cout << "\n* Digite os dados da conta simples 1. " << endl;
  c1.Get();

  cout << "\n* Digite os dados da conta simples 2. " << endl;
  c2.Get();

  cout << "\n* Digite os dados da conta especial. " << endl;
  c3.Get();

  cout << "\n* Digite os dados da conta poupança. " << endl;
  c4.Get();

  cout << "\n\n* Conta Simples 1.\n";
  c1.Print();
  cout << "\n\n* Conta Simples 2.\n";
  c2.Print();
  cout << "\n\n* Conta Especial.\n";
  c3.Print();
  cout << "\n\n* Conta Poupança.\n";
  c4.Print();

  return 0;
}
