#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

class Cadastro {
private:
  char Nome[30], Fone[20];

public:
  Cadastro();
  void Get();
  void Print();
};

Cadastro::Cadastro() { Nome[0] = Fone[0] = '\0'; }

void Cadastro::Get() {
  cout << "\tNome: ";
  fgets(Nome, sizeof(Nome), stdin);
  cout << "\tFone: ";
  fgets(Fone, sizeof(Fone), stdin);
}
void Cadastro::Print() {
  cout << "\n\tNome: " << Nome << endl << "\tFone: " << Fone << endl;
}

class Imovel {
private:
  char Endereco[30], Bairro[20];
  float AreaUtil, AreaTotal;
  int Quartos;

public:
  Imovel();
  void Get();
  void Print();
};

Imovel::Imovel() {
  Endereco[0] = Bairro[0] = '\0';
  AreaUtil = AreaTotal = 0.0;
  Quartos = 0;
}

void Imovel::Get() {
  cout << "\tEndereco: ";
  fgets(Endereco, sizeof(Endereco), stdin);
  cout << "\tBairro: ";
  fgets(Bairro, sizeof(Bairro), stdin);
  cout << "\tÁrea Útil: ";
  cin >> AreaUtil;
  cout << "\tÁrea Total: ";
  cin >> AreaTotal;
  cout << "\tN\xF8 Quartos: ";
  cin >> Quartos;
  cin.ignore(10, '\n');
}

void Imovel::Print() {
  cout << "\n\tEndereco: " << Endereco << endl
       << "\tBairro: " << Bairro << endl
       << "\tÁrea Útil: " << setiosflags(ios::fixed) << setprecision(2)
       << AreaUtil << endl
       << "\tÁrea Total: " << setiosflags(ios::fixed) << setprecision(2)
       << AreaTotal << endl
       << "\tN\xF8 Quartos: " << Quartos << endl;
}

class Tipo {
private:
  char TipoImovel[20];

public:
  Tipo();
  void Get();
  void Print();
};

Tipo::Tipo() { TipoImovel[0] = '\0'; }

// void Tipo::Get()

class Venda : private Cadastro, Imovel, Tipo {
private:
  float valor;

public:
  Venda();
  void Get();
  void Print();
};

class Aluguel : private Cadastro, Imovel, Tipo {
private:
  float AluguelMensal;
  int Prazo;
  Cadastro Proprietario;

public:
  Aluguel();
  void Get();
  void Print();
};
