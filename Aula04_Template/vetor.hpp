#ifndef VETOR_HPP
#define VETOR_HPP

#include <iostream>

using namespace std;

template <class T, int N> class Vetor {
private:
  unsigned int CAP;
  unsigned int topo = 0;
  T *vet;

public:
  Vetor();
  explicit Vetor(unsigned int cap);
  ~Vetor();
  int busca(T value);
  int push_back(T value);
  int push_front(T value);
  void pop_back();
  void pop_front();
  T &operator[](unsigned int i);
  void Print();
};

template <class T, int N> Vetor<T, N>::Vetor() : CAP(N), topo(0) {
  vet = new T[N];
}

template <class T, int N> Vetor<T, N>::Vetor(unsigned int cap) {
  this->CAP = cap;
  this->vet = new T[N];
}

template <class T, int N> Vetor<T, N>::~Vetor() { delete[] vet; }

template <class T, int N> int Vetor<T, N>::busca(T value) {
  for (unsigned int i = 0; i < topo; i++) {
    if (vet[i] == value)
      return i;
  }

  return -1;
}

template <class T, int N> int Vetor<T, N>::push_back(T value) {
  if (topo >= CAP)
    return -1;

  vet[topo++] = value;
  return 1;
}

template <class T, int N> int Vetor<T, N>::push_front(T value) {
  if (topo >= CAP)
    return -1;
  Vetor<T, N> tmp;
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

template <class T, int N> void Vetor<T, N>::pop_back() { --topo; }

template <class T, int N> void Vetor<T, N>::pop_front() {
  Vetor<T, N> tmp;
  for (unsigned int i = 1; i < topo; i++)
    tmp[i - 1] = vet[i];
  for (unsigned int i = 0; i < topo; i++)
    vet[i] = tmp[i];
  --topo;
}

template <class T, int N> void Vetor<T, N>::Print() {
  for (unsigned int i = 0; i < topo; ++i) {
    cout << vet[i] << ' ';
  }
  cout << endl;
}

template <class T, int N> T &Vetor<T, N>::operator[](unsigned int i) {
  return vet[i];
}

#endif
