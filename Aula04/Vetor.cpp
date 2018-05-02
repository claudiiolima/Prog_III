#include "vetor.h"
#include <cstring>

Vetor::Vetor(unsigned int cap) {
  this->CAP = cap;
  this->vet = new double[CAP];
}

Vetor::~Vetor() { delete[] vet; }

int Vetor::busca(double value) {
  for (unsigned int i = 0; i < topo; i++) {
    if (vet[i] == value)
      return i;
  }

  return -1;
}

int Vetor::push_back(double value) {
  if (topo >= CAP)
    return -1;

  vet[topo++] = value;
  return 1;
}

int Vetor::push_front(double value) {
  if (topo >= CAP)
    return -1;
  Vetor tmp(CAP);
  for (unsigned int i = 0; i < topo; i++) {
    tmp[i] = vet[i];
  }
  vet[0] = value;
  for (unsigned int i = 1; i < topo + 1; ++i) {
    vet[i] = tmp[i - 1];
  }
  topo++;
  return 1;
}

void Vetor::pop_back() { --topo; }

void Vetor::pop_front() {
  Vetor tmp(CAP);
  for (unsigned int i = 1; i < topo; i++)
    tmp[i - 1] = vet[i];
  for (unsigned int i = 0; i < topo; i++)
    vet[i] = tmp[i];
  --topo;
}

void Vetor::Print() {
  for (unsigned int i = 0; i < topo; ++i) {
    cout << vet[i] << ' ';
  }
  cout << endl;
}

double &Vetor::operator[](unsigned int i) { return vet[i]; }
