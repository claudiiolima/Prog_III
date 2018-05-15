#ifndef CAR_H
#define CAR_H

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

class Car {
private:
  int yearModel;
  string make;
  int speed;

public:
  Car(int year, string brand);
  /*Accessors*/
  int getYearModel();          // Retorna valor dos membros
  string getMake();            // Retorna valor dos membros
  int getSpeed();              // Retorna valor dos membros
  void setYearModel(int year); // Altera valor dos membros
  void setMake(string brand);  // Altera valor dos membros
  void setSpeed(int s);        // Altera valor dos membros
  /*Functions*/
  void accelerate(); // Incrementa speed em 5;
  void brake();      // Decrementa speed em 5;
  /*Overloading >>, <<*/
  friend ostream &operator<<(ostream &out, const Car &C);
  friend istream &operator>>(istream &in, Car &C);
};

#endif
