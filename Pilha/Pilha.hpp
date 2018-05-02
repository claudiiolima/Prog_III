
template <typename T> class Pilha {
private:
  T *data;
  unsigned int _topo;
  const unsigned int _base = 0;
  unsigned int CAP;

public:
  Pilha(unsigned int topo = 0, unsigned int cap = 0);
  ~Pilha();
  int busca(T value);
  void push_topo(T value);
  void pop_topo();
  void push_base(T value);
  void pop_base();
};

template <typename T>
Pilha<T>::Pilha(unsigned int topo, unsigned int cap) : _topo(topo), CAP(cap) {
  data = new T[CAP];
}

template <typename T> Pilha<T>::~Pilha() {
  _topo = 0;
  CAP = 0;
  delete (data);
}

template <typename T> int Pilha<T>::busca(T value) {
  for (int i = 0; i < _topo; i++) {
    if (data[i] == value)
      return i;
  }

  return -1;
}

template <typename T> void Pilha<T>::push_topo(T value) {
  data[_topo++] = value;
}

template <typename T> void Pilha<T>::pop_topo() { _topo--; }

template <typename T> void Pilha<T>::push_base(T value) {
  Pilha tmp(this->_topo, this->CAP);
  for (unsigned int i = 0; i < _topo; i++) {
    tmp.data[_topo] = this->data[_topo];
  }
  _topo++;
  this->data[_base] = value;
  for (unsigned int i = 1; i < _topo; i++) {
    this->data[i] = tmp.data[i - 1];
  }
}

template <typename T> void Pilha<T>::pop_base() {
  Pilha tmp(this->_topo, this->CAP);
  for (unsigned int i = 1; i < _topo; i++)
    tmp.data[i - 1] = this->data[i];
  for (unsigned int i = 0; i < _topo; i++)
    this->data[i] = tmp.data[i];
  _topo--;
}
