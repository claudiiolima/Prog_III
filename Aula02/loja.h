#include "hora.hpp"
#include "vendedor.hpp"

using namespace std;

class Loja {
protected:
  unsigned int itens;
  Horario h_abre, h_fecha;
  Vendedor v;

public:
  Loja();                                          // Construtor default
  Loja(int x);                                     // Contrutor inicializador
  void SetItens(unsigned int nov_itens);           // Altera valor de itens
  unsigned int Itens();                            // Retorna valor de itens
  void SetNomeV(string n);                         // Altera valor de v._nome
  string NomeV();                                  // Retorna string de v._nome;
  void SetSalarioV(double s);                      // Altera valor de v._salario
  double SalarioV();                               // Retorna valor de _salario
  void SetH_abre(unsigned int h, unsigned int m);  // Altera valor de h_abre
  string Hora_abre();                              // Retorna string de h_abre
  void SetH_fecha(unsigned int h, unsigned int m); // Altera valor de h_fecha
  string Hora_fecha();                             // Retorna string de h_fecha
};
