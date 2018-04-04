#include <iostream>

class Base {
protected:
  int Secreto;

private:
  int UltraSecreto;

public:
  int Publico;
};

class Derivada1 : public Base {
private:
  int a, b, c;

public:
  Derivada1() {
    a = Secreto;      // OK
    b = UltraSecreto; // ERRO: não acessível
    c = Publico;      // OK
  }
};

class Derivada2 : private Base {
private:
  int a, b, c;

public:
  Derivada2() {
    a = Secreto;      // OK
    b = UltraSecreto; // ERRO: não acessível
    c = Publico;      // OK
  }
};

class Derivada3 : protected Base {
private:
  int a, b, c;

public:
  Derivada3() {
    a = Secreto;      // OK
    b = UltraSecreto; // ERRO: não acessível
    c = Publico;      // OK
  }
};

int main(void) {
  int x;
  Derivada1 Obj1;
  x = Obj1.Secreto;      // ERRO
  x = Obj1.UltraSecreto; // ERRO
  x = Obj1.Publico;      // OK

  Derivada2 Obj2;
  x = Obj2.Secreto;      // ERRO
  x = Obj2.UltraSecreto; // ERRO
  x = Obj2.Publico;      // ERRO

  Derivada3 Obj3;
  x = Obj3.Secreto;      // ERRO
  x = Obj3.UltraSecreto; // ERRO
  x = Obj3.Publico;      // ERRO

  return 0;
}
