#include <iostream>

using namespace std;

class Pessoa {
private:
  int _idade;
  string _nome;

public:
  Pessoa() : _idade(0) {}
  void GetIdade();
  void GetNome();
  void aniversario();
  int idade();
  string nome();
};

void Pessoa::aniversario() { _idade++; }

int Pessoa::idade() { return _idade; }

string Pessoa::nome() { return _nome; }

void Pessoa::GetIdade() { cin >> _idade; }

void Pessoa::GetNome() { cin >> _nome; }

int main(void) {
  Pessoa p;
  p.GetIdade();
  p.GetNome();
  cout << "Nome: " << p.nome() << endl << "Idade: " << p.idade() << endl;
  p.aniversario();
  cout << "Nova idade: " << p.idade() << endl;

  return 0;
}
