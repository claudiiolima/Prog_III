
/* this is a class for a 2-d array (n by m) */
/* the rows and columns are numbered 0,1,2,... */
#ifndef ArrayH
#define ArrayH

#include <iostream>

using namespace std;

template <class T>

class Array2 {
public:
  Array2(int m = 0, int n = 0);           /* constructor */
  Array2(const Array2<T> &a) { copy(a); } /* copy array */
  ~Array2() { delete[] data; }            /* destructor */
  T &operator()(int i, int j) {
    int pos = i * n + j;
    return data[pos];
  }                           /*subscripting */
  int columns() { return n; } /* number of columns */
  int rows() { return m; }    /* number of rows */
  Array2<T> &operator=(const Array2<T> &a) {
    copy(a);
    return *this;
  } /* array assignment */
  Array2<T> &operator=(T x) {
    for (int i = 0; i < n * m; i++) {
      data[i] = x;
    }
    return *this;
  } /* scalar assignment */
  void setSize(int i, int j) {
    Array2 tmp(m, n);
    int p = n * m;
    for (int k = 0; k < p; k++)
      tmp.data[k] = data[k];
    delete[] data;
    // cout << n << " ?!!!? ";
    m = i;
    n = j;
    data = new T[i * j];
    for (int k = 0; k < p; k++) {
      data[k] = tmp.data[k];
    }
  } /* change size */
  void print() {
    int k = 0;
    for (int j = 0; j < m; j++) {
      for (int i = k; i < k + n; i++) {
        cout << ' ' << data[i];
      }
      k = k + n;
      cout << endl;
    }
  }

private:
  int m; /*number of columns */
  int n; /*number of rows */
  T *data;
  void copy(const Array2<T> &a) {
    m = a.m;
    n = a.n;
    this->data = new T[n * m];
    for (int i = 0; i < n * m; i++) {
      data[i] = a.data[i];
    }
  }
};

template <class T> Array2<T>::Array2(int m, int n) : n(n), m(m) {
  data = new T[n * m];
}

#endif
