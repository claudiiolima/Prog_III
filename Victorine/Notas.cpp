// Calcula a média das notas de qualquer número de alunos
#include <iomanip>
#include <iostream>

class Matriz {
private:
  static const int MAX = 50;
  float n[MAX];

public:
  Matriz();
  float &operator[](int indice);
  float Media(int i);
};

Matriz::Matriz() {
  for (int i = 0; i < MAX; i++)
    n[i] = 0.0;
}

float &Matriz::operator[](int indice) {
  static float lixo = -1;
  return (indice >= 0 && indice < MAX) ? n[indice] : lixo;
}

float Matriz::Media(int i) {
  float m = 0.0;
  for (int j = 0; j < i; j++)
    m += n[j];

  return m / static_cast<float>(i); // = return m / float(i);
}

int main(void) {
  Matriz notas;
  std::cout << std::setprecision(2);
  int i = 0;

  do {
    std::cout << "Digite a nota do aluno " << (i + 1) << ": ";
    std::cin >> notas[i];
  } while (notas[i++] >= 0);

  std::cout << "\nMédia das notas: " << notas.Media(i - 1) << std::endl;

  return 0;
}
