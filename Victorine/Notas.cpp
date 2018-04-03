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
[Enter steps to reproduce:]

        1. ... 2. ...

            **Atom ** : 1.25.0 x64 **Electron ** : 1.7.11 *
        *OS ** : Ubuntu 17.10 *
        *Thrown From ** :
         [gpp -
          compiler](https
                    : // github.com/kriscross07/atom-gpp-compiler) package 3.0.7

                    ## #Stack Trace

                        Uncaught TypeError
                    : Bad argument

``` At internal /
                          child_process.js : 294

                          TypeError
                    : Bad argument at ChildProcess
                                  .spawn(internal / child_process.js : 294 : 26)
                                      at Object.exports
                                  .spawn(child_process.js : 390 : 9)
                                      at compile(/ packages / gpp -
                                                 compiler / index.js : 274 : 31)
                                          at compileFile(/ packages / gpp -
                                                         compiler /
                                                             index.js : 216 : 5)
                                              at /
                              packages / gpp -
                          compiler / index.js : 23 : 11) at CommandRegistry
             .handleCommandEvent(/ usr / share / atom / resources / app / src /
                                     command -
                                 registry.js : 384 : 49) at CommandRegistry
             .dispatch(/ usr / share / atom / resources / app / src / command -
                       registry.js : 273 : 23) at AtomEnvironment
             .dispatchContextMenuCommand(
                 / usr / share / atom / resources / app / src / atom -
                 environment.js : 1347 : 25) at EventEmitter
             .outerCallback(/ usr / share / atom / resources / app / src /
                                application -
                            delegate.js : 346 : 53) at
         emitThree(events.js : 116 : 13) at
         EventEmitter.emit(events.js : 197 : 7)
```

         ## #Commands

``` 2x -
    9 : 39.4.0 core
    : move
      -
      up(input.hidden - input) 18x - 9 : 38.8.0 core
      : move
        -
        left(input.hidden - input) - 9 : 37.5.0 core
        : move
          -
          down(input.hidden - input) 2x -
          9 : 37.3.0 core
          : move
            -
            left(input.hidden - input) - 9 : 34.5.0 core
            : move
              -
              right(input.hidden - input) - 9 : 33.2.0 core
              : move
                -
                left(input.hidden - input) 3x -
                9 : 32.9.0 core
                : move
                  -
                  down(input.hidden - input) - 9 : 31.9.0 core
                  : move
                    -
                    up(input.hidden - input) - 9 : 31.1.0 editor
                    : select
                      -
                      to - first - character - of -
                      line(input.hidden - input) 2x - 9 : 29.8.0 core
                      : backspace(input.hidden - input) -
                        9 : 27.9.0 core
                        : move
                          -
                          up(input.hidden - input) 2x - 9 : 27.2.0 core
                          : move
                            -
                            right(input.hidden - input) - 9 : 26.2.0 editor
                            : select
                              -
                              to - end - of -
                              line(input.hidden - input) 2x - 9 : 25.5.0 core
                              : backspace(input.hidden - input) 2x -
                                8 : 50.2.0 tree - view
                                : remove(div.tool - panel.tree - view) -
                                  2 : 18.4.0 gpp - compiler
                                  : compile(div.line.cursor - line)
```

                                    ## #Non
                                    -
                                    Core Packages

``` apex - ui 1.0.3 atom - beautify 0.32.2 atom - bootstrap4 1.4.0 atom - clock
                                    0.1.16 atom
                                    -
                                    eclipse - syntax 0.0.5 atom - material -
                                    syntax 1.0.8 atom - material - syntax - dark
                                    1.0.0 atom
                                    -
                                    material - ui 2.1.3 atom - monokai
                                    0.10.9 autocomplete 0.47.0 brahalla
                                    -
                                    syntax 0.5.0 build 0.70.0 busy - signal
                                    1.4.3 chester
                                    -
                                    atom - syntax 0.3.2 city - lights -
                                    ui 1.3.3 cpp - generator 1.0.1 dash - ui
                                    0.4.4 dbg 1.6.3 dbg
                                    -
                                    gdb 1.7.8 doont - spotify 0.1.0 file - icons
                                    2.1.18 git
                                    -
                                    plus 7.10.2 gpp 0.4.3 gpp - compiler
                                    3.0.7 hey
                                    -
                                    pane 1.1.0 highlight - selected
                                    0.13.1 intentions 1.1.5 juicy
                                    -
                                    syntax 1.0.5 language - cpp14 0.6.2 language
                                    -
                                    ini 1.19.0 linter 2.2.0 linter -
                                    gcc 0.7.1 linter - ui -
                                    default 1.7.1 linter - ui -
                                    plus 0.3.2 material - monokai - syntax
                                    1.0.1 minimap 4.29.8 minimap
                                    -
                                    highlight - selected 4.6.1 minimap - linter
                                    2.1.3 monokai 0.24.0 open
                                    -
                                    terminal - here 2.3.1 output -
                                    panel 0.3.4 pdf - view 0.67.0 pristine -
                                    ui 1.1.11 pure - syntax 0.3.0 seti -
                                    icons 1.5.4 seti - ui 1.10.0 styri - syntax
                                    0.2.0 teletype 0.11.0 toggler 0.3.1 vector
                                    -
                                    syntax 1.0.0 visualdark -
                                    syntax 1.0.0 zooce - syntax 1.0.1
```

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
