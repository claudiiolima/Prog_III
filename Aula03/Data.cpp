#include "data.h"
#include <sstream>

using namespace std;

Data::Data() : _dia(1), _mes(1), _ano(1999) {}

Data::Data(unsigned int d, unsigned int m, unsigned int a) : Data() {
  this->dia(d);
  this->mes(m);
  this->ano(a);
}

Data::Data(const Data &obj) {
  dia(obj._dia);
  mes(obj._mes);
  ano(obj._ano + 200);
}

Data &Data::operator=(const Data &obj) {
  this->_dia = obj._dia;
  this->_mes = obj._mes;
  this->_ano = obj._ano;
  return *this;
}

Data Data::operator+(const Data &obj) {
  Data tmp;
  tmp._dia = this->_dia + obj._dia;
  tmp._mes = this->_mes + obj._mes;
  tmp._ano = this->_ano + obj._ano;
  return tmp;
}

Data::~Data() { cout << "\nDestructor Data " << texto() << endl; }

void Data::dia(unsigned int d) {
  if (d >= 1 && d <= 31)
    _dia = d;
}

void Data::mes(unsigned int m) {
  if (m >= 1 && m <= 12)
    _mes = m;
}

void Data::ano(unsigned int a) {
  if (a > 1900 && a < 2200)
    _ano = a;
}

unsigned int Data::dia() const { return _dia; }

unsigned int Data::mes() const { return _mes; }

unsigned int Data::ano() const { return _ano; }

string Data::texto() const {
  stringstream out;
  out << _dia << '/' << _mes << '/' << _ano << endl;
  return (out.str());
}
