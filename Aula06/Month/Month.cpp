#include "Month.h"

Month::Month() : name(_month[1]), monthNumber(1) {}

Month::Month(string m) : name(m) {
  for (int i = 1; i < 13; i++)
    if (name == _month[i])
      monthNumber = i;
}

Month::Month(int n) : monthNumber(n) { name = _month[n]; }

string Month::getName() { return name; }

void Month::setName(string m) {
  name = m;
  for (int i = 1; i < 13; i++)
    if (name == _month[i])
      monthNumber = i;
}

int Month::getMonthNumber() { return monthNumber; }

void Month::setMonthNumber(int n) {
  monthNumber = n;
  name = _month[n];
}

Month Month::operator++() {
  if (monthNumber == 12)
    monthNumber = 1;
  else
    monthNumber++;

  name = _month[monthNumber];
  Month tmp(monthNumber - 1);

  return tmp;
}

Month &Month::operator++(int) {
  name = _month[++monthNumber];

  return *this;
}

Month Month::operator--() {
  if (monthNumber == 1)
    monthNumber = 12;
  else
    monthNumber--;

  name = _month[monthNumber];
  Month tmp(monthNumber + 1);

  return tmp;
}

Month &Month::operator--(int) {
  name = _month[--monthNumber];
  return *this;
}

Month &Month::operator=(Month &M) {
  this->monthNumber = M.monthNumber;
  this->name = M.name;

  return *this;
}

ostream &operator<<(ostream &output, const Month &M) {
  output << M.monthNumber << '-' << M.name << endl;

  return output;
}

istream &operator>>(istream &input, Month &M) {
  input >> M.monthNumber >> M.name;
  if (M.name != M._month[M.monthNumber])
    throw string("Numero de mes inconsistente com mes");

  return input;
}
