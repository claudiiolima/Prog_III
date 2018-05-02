#include <iostream>

template <typename T> class Lista {
private:
  typedef struct celula {
    T *data;
    struct celula *next;
    struct celula *prev;
  } celula_t;
  celula_t *head;
  celula_t *tail;
  unsigned int tam;

public:
  Lista();
  ~Lista();
  void push_head(T value);
  void push_tail(T value);
  void push_next(T value, celula_t *c);
};

template <typename T> Lista<T>::Lista() : tam(0), head(NULL), tail(NULL) {}

template <typename T> Lista<T>::~Lista() {}

template <typename T> void Lista<T>::push_head(T value) {
  celula_t *tmp;
  tmp->data = value;
  tmp->next = head;
  tmp->prev = NULL;
  head->next = head->next->next;
  head = tmp;
  tam++;
}

template <typename T> void Lista<T>::push_tail(T value) {
  celula_t tmp;
  tmp.data = value;
  tmp->next = NULL;
  tmp->prev = tail;
  tail->next = tmp;
  tail = tmp;
  tam++;
}
