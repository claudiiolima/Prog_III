#include "Car.h"

Car::Car(int year, string brand) : yearModel(year), make(brand), speed(0) {}

int Car::getYearModel() { return yearModel; }

void Car::setYearModel(int year) { yearModel = year; }

string Car::getMake() { return make; }

void Car::setMake(string brand) { make = brand; }

int Car::getSpeed() { return speed; }

void Car::setSpeed(int s) { speed = s; }

void Car::accelerate() { speed += 5; }

void Car::brake() { speed -= 5; }

ostream &operator<<(ostream &out, const Car &C) {
  out << C.make << ": " << C.yearModel << endl << C.speed << " km/h" << endl;

  return out;
}

istream &operator>>(istream &in, Car &C) {
  cout << "Modelo, Marca, Velocidade" << endl;
  in >> C.yearModel >> C.make >> C.speed;

  return in;
}
