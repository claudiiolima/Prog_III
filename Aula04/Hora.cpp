#include "hora.h"
#include <iomanip>

using namespace std;

Horario::Horario() : _hora(0), _minuto(0) {}

void Horario::GetHorario(unsigned int nov_hor, unsigned int nov_min) {
  _hora = nov_hor;
  _minuto = nov_min;
}

string Horario::Horas() {
  stringstream out;
  out << setfill('0') << setw(2) << _hora << ':' << setfill('0') << setw(2)
      << _minuto;
  return (out.str());
}
