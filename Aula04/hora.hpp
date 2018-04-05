#include <iostream>
#include <sstream>

using namespace std;

class Horario {
protected:
  unsigned int _hora;
  unsigned int _minuto;

public:
  Horario(); // Construtor default
  void GetHorario(unsigned int nov_hor,
                  unsigned int nov_min); // Altera valor de _hora e _minuto
  string Horas();                        // Retorna string com o horario
};
