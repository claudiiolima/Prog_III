#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Data {
private:
  unsigned int _dia, _mes, _ano;

public:
  Data();
  Data(unsigned int d, unsigned int m = 2, unsigned int a = 2000);
  Data(const Data &obj);
  Data &operator=(const Data &obj);
  Data operator+(const Data &obj);
  ~Data();
  void dia(unsigned int);
  void mes(unsigned int);
  void ano(unsigned int);
  unsigned int dia() const;
  unsigned int mes() const;
  unsigned int ano() const;
  string texto() const;
};

#endif
