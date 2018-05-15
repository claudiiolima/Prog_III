template <typename T> class Pilha {
private:
  T *data;
  unsigned int _topo;
  unsigned int CAP;

public:
  Pilha();
  Pilha<T>(int t);
  void empilha(T dado);
  T desempilha();
  T topo();
  int getPosTopo();
  void limparPilha();
  bool PilhaVazia();
  bool PilhaCheia();
};

template <typename T> Pilha<T>::Pilha() : _topo(0), CAP(0) {
  data = new T[CAP];
}

template <typename T> Pilha<T>::Pilha(int t) : _topo(0), CAP(t) {
  data = new T[CAP];
}

template <typename T> void Pilha<T>::empilha(T dado) {
  if (PilhaCheia())
    throw 0;
  data[_topo++] = dado;
}

template <typename T> T Pilha<T>::desempilha() {
  if (PilhaVazia())
    throw 0;
  return data[--_topo];
}

template <typename T> T Pilha<T>::topo() {
  if (PilhaVazia())
    throw 0;
  return data[getPosTopo()];
}

template <typename T> int Pilha<T>::getPosTopo() {
  if (PilhaVazia())
    throw 0;
  return _topo - 1;
}

template <typename T> void Pilha<T>::limparPilha() {
  _topo = 0;
  delete[] data;
}

template <typename T> bool Pilha<T>::PilhaVazia() {
  return (_topo == 0) ? true : false;
}

template <typename T> bool Pilha<T>::PilhaCheia() {
  return (_topo == CAP) ? true : false;
}
