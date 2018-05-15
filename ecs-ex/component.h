/*Component class- this describes the various parts of the circuit- R, C, L,
  battery, wires, (and in the future diodes, real wires (with resistance),
  real resistors (with current dependence), time dependent voltage/ current
  sources etc).  This is what will
  be used in the Breadboard class' array to represent the circuit.
  This class has info to describe what the part is, how it should be
  drawn, and how it should behave when in the circuit.
*/

/* Jeff Phillips     */

#ifndef CompenentH
#define ComponentH

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Component {
private:
  float coef; /* this is the value of the cap, res, induct  */
  char type;  /* this describes what the part is and  the current */
              /*dependance I vs dI/dt, etc */
              /* dI/dt  inductors      l
                 I      resistors      r
                 q      capacitors     c
                 const  batteries      b
                 -      wires          w
                 -      nothing        n
              */

  int variablenum; /*this is to store which current is passing*/
                   /* through I1, I2*/

  int solderd; /*these are to store the info on how the part is*/
  int solderu; /*soldered into the circuit- to the part down from it*/
  int solderr; /*up from it, on it's right or on it's left */
  int solderl;

  /* for now a component is only allowed to be soldered to two other parts, but
     there will be nodes (three or four way wire junctions) in the future- and
     possibly transitors in the distant future
  */

  int label; /*to identify each component R1 vs R2 vs R3... */

public:
  Component()
      : type('n'), solderu(0), solderd(0), solderr(0), solderl(0), coef(0.0),
        label(0), variablenum(0) {}

  Component(char tag, int su, int sd, int sr, int sl, float num)
      : type(tag), solderu(su), solderd(sd), solderr(sr), solderl(sl),
        coef(num) {}

  ~Component() {}

  void Assigntype(char tag) { type = tag; }

  void Assigncoef(float x) { coef = x; }

  void Assignlabel(int x) { label = x; }

  void Assignvnum(int x) { variablenum = x; }

  int Returnlabel() const { return label; }

  float Returncoef() const { return coef; }

  char Returntype() const { return type; }

  int Returnvnum() const { return variablenum; }

  int Returnsolderu() const { return solderu; }

  int Returnsolderl() const { return solderl; }

  int Returnsolderd() const { return solderd; }

  int Returnsolderr() const { return solderr; }

  void Printpic(int x) /* this function is used to print the iamge*/
  {
    switch (type) {
    case 'n':
    case 'N':

      if (x == 1) {
        cout << "     ";
      } /*all are 5x5 characters  */
      else if (x == 2) {
        cout << "     ";
      } else if (x == 3) {
        cout << "     ";
      } else if (x == 4) {
        cout << "     ";
      } else if (x == 5) {
        cout << "     ";
      } else {
      }
      break;

    case 'r':
    case 'R':

      if (solderu == 1) {
        if (x == 1) {
          cout << " R|  ";
        } else if (x == 2) {
          if (label < 10) {
            cout << " " << label << ">  ";
          } else {
            cout << label << ">  ";
          }
        } else if (x == 3) {
          cout << "  >  ";
        } else if (x == 4) {
          cout << "  >  ";
        } else if (x == 5) {
          cout << "  |  ";
        } else {
        }
      } else {
        if (x == 1) {
          cout << "     ";
        } else if (x == 2) {
          if (label < 10) {
            cout << "R" << label << "   ";
          } else {
            cout << "R" << label << "  ";
          }
        } else if (x == 3) {
          cout << "-vvv-";
        } else if (x == 4) {
          cout << "     ";
        } else if (x == 5) {
          cout << "     ";
        } else {
        }
      }
      break;

    case 'c':
    case 'C':

      if (solderu == 1) {
        if (x == 1) {
          cout << " C|  ";
        } else if (x == 2) {
          if (label < 10) {
            cout << " " << label << "-  ";
          } else {
            cout << label << "-  ";
          }
        } else if (x == 3) {
          cout << "     ";
        } else if (x == 4) {
          cout << "  -  ";
        } else if (x == 5) {
          cout << "  |  ";
        } else {
        }
      } else {
        if (x == 1) {
          cout << "     ";
        } else if (x == 2) {
          if (label < 10) {
            cout << "C" << label << "   ";
          } else {
            cout << "C" << label << "  ";
          }
        } else if (x == 3) {
          cout << "-| |-";
        } else if (x == 4) {
          cout << "     ";
        } else if (x == 5) {
          cout << "     ";
        } else {
        }
      }
      break;

    case 'l':
    case 'L':

      if (solderu == 1) {
        if (x == 1) {
          cout << " L|  ";
        } else if (x == 2) {
          if (label < 10) {
            cout << " " << label << "c  ";
          } else {
            cout << label << "c  ";
          }
        } else if (x == 3) {
          cout << "  c  ";
        } else if (x == 4) {
          cout << "  c  ";
        } else if (x == 5) {
          cout << "  |  ";
        } else {
        }
      } else {
        if (x == 1) {
          cout << "     ";
        } else if (x == 2) {
          if (label < 10) {
            cout << "L" << label << "   ";
          } else {
            cout << "L" << label << "  ";
          }
        } else if (x == 3) {
          cout << "-uuu-";
        } else if (x == 4) {
          cout << "     ";
        } else if (x == 5) {
          cout << "     ";
        } else {
        }
      }
      break;

    case 'b':
    case 'B':

      if (solderu == 1) {
        if (x == 1) {
          cout << " B|  ";
        } else if (x == 2) {
          if (label < 10) {
            cout << " " << label << "|  ";
          } else {
            cout << label << "|  ";
          }
        } else if (x == 3) {
          cout << "  V  ";
        } else if (x == 4) {
          cout << "  |  ";
        } else if (x == 5) {
          cout << "  |  ";
        } else {
        }
      } else {
        if (x == 1) {
          cout << "     ";
        } else if (x == 2) {
          if (label < 10) {
            cout << "B" << label << "   ";
          } else {
            cout << "B" << label << "  ";
          }
        } else if (x == 3) {
          cout << "--V--";
        } else if (x == 4) {
          cout << "     ";
        } else if (x == 5) {
          cout << "     ";
        } else {
        }
      }
      break;

    case 'w':
    case 'W':

      if (solderu == 1 && solderd == 1) {
        if (x == 1) {
          cout << "  |  ";
        } else if (x == 2) {
          cout << "  |  ";
        } else if (x == 3) {
          cout << "  |  ";
        } else if (x == 4) {
          cout << "  |  ";
        } else if (x == 5) {
          cout << "  |  ";
        } else {
        }
      } else if (solderl == 1 && solderr == 1) {
        if (x == 1) {
          cout << "     ";
        } else if (x == 2) {
          cout << "     ";
        } else if (x == 3) {
          cout << "-----";
        } else if (x == 4) {
          cout << "     ";
        } else if (x == 5) {
          cout << "     ";
        } else {
        }
      } else if (solderu == 1 && solderl == 1) {
        if (x == 1) {
          cout << "  |  ";
        } else if (x == 2) {
          cout << "  |  ";
        } else if (x == 3) {
          cout << "--   ";
        } else if (x == 4) {
          cout << "     ";
        } else if (x == 5) {
          cout << "     ";
        } else {
        }
      } else if (solderu == 1 && solderr == 1) {
        if (x == 1) {
          cout << "  |  ";
        } else if (x == 2) {
          cout << "  |  ";
        } else if (x == 3) {
          cout << "   --";
        } else if (x == 4) {
          cout << "     ";
        } else if (x == 5) {
          cout << "     ";
        } else {
        }
      } else if (solderd == 1 && solderl == 1) {
        if (x == 1) {
          cout << "     ";
        } else if (x == 2) {
          cout << "     ";
        } else if (x == 3) {
          cout << "--   ";
        } else if (x == 4) {
          cout << "  |  ";
        } else if (x == 5) {
          cout << "  |  ";
        } else {
        }
      } else /*solderd==1 && solderr==1 */
      {
        if (x == 1) {
          cout << "     ";
        } else if (x == 2) {
          cout << "     ";
        } else if (x == 3) {
          cout << "   --";
        } else if (x == 4) {
          cout << "  |  ";
        } else if (x == 5) {
          cout << "  |  ";
        } else {
        }
      }

      break;
    }
  }
};
#endif
