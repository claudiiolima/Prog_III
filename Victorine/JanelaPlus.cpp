#include <iostream>
// #include <windows>

inline int maximo(int x, int y) { return (x > y) ? x : y; }

inline int minimo(int x, int y) { return (x < y) ? x : y; }

void poscur(int col, int lin) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  if (INVALID_HANDLE_VALUE != hConsole) {
    COORD pos = {col, lin};
    SetConsoleCursorPosition(hConsole, pos);
  }
}

class Janela {
protected:
  int LinIni, ColIni, LinFin, ColFin;

public:
  Janela() : LinIni(0), ColIni(0), LinFin(23), ColFin(79) {}
  Janela(int li, int ci, int lf, int cf);
  void Moldura(char modo[] = "\xC9\xBB\xBA\xBC\xCD\xC8");
};

Janela::Janela(int li, int ci, int lf, int cf) {
  LinIni = maximo(0, li);
  LinIni = minimo(23, li);
  LinFin = maximo(0, lf);
  LinFin = minimo(23, lf);
  LinIni = minimo(li, lf);

  ColIni = maximo(0, li);
  ColIni = minimo(79, li);
  ColFin = maximo(0, cf);
  ColFin = minimo(79, cf);
  ColIni = minimo(ci, cf);
}

void Janela::Moldura(char modo[]) {
  poscur(ColIni, LinIni);
  std::cout << modo[0];
  int i;
  for (i = ColIni; i < ColFin; ++i)
    std::cout << modo[4];
  std::cout << modo[1];

  for (i = LinIni; i < LinFin; ++i) {
    poscur(ColIni, i);
    std::cout << modo[2];
    poscur(ColFin, i);
    std::cout << modo[2];
  }

  poscur(ColIni, LinFin);
  std::cout << modo[5];

  for (i = ColIni; i < ColFin; ++i)
    std::cout << modo[4];
  std::cout << modo[3];
}

class JanelaPlus : public Janela {
  void cls();
  void cursor(int lin, int col);
  void centra(int lin, char s[]);
};

void JanelaPlus::cls() {
  int lin, col;
  int brancos = ColFin - ColIni - 1;
  for (lin = LinIni; lin < LinFin; ++lin) {
    poscur(ColIni + 1, lin);
    for (col = 0; col < brancos; col++)
      std::cout << ' ';
  }
  poscur(ColIni + 1, LinIni + 1);
}

void JanelaPlus::cursor(int lin, int col) {
  if (lin >= LinFin || col >= ColFin)
    lin = col = 0;
  poscur(ColIni + 1; LinIni + 1);
}
