#include <iostream>

using namespace std;

class Vetor {
private:
  unsigned int CAP;
  unsigned int topo = 0;
  double *vet;

public:
  Vetor(unsigned int topo = 10);
  ~Vetor();
  int busca(double value);
  int push_back(double value);
  int push_front(double value);
  void pop_back();
  void pop_front();
  double &operator[](unsigned int i);
  void Print();
};
