#include "array2.h"
#include "component.h"
#include "point.h"

class Circuit
{
 private:
  Point Start;
  Point Current;
  Point Previous;

  int Closed;  /*equals 1 if closed circuit, 0 if open*/

  Array2<Component> Breadboard;

  int Partcount;  /*used to label the parts as they are added */
  int Numcomps;  /*number of nonwire components*/

 public:
  Circuit(int xx,int yy);

  void Addtoboard();

  void Removefromboard();

  void Printboard();

  void Assignclosed(int x);

  int Returnclosed();

  void Advance();

  int More();

  void Begin();

  void Findstart();

  int Open();

  void Checkboard();

  void Printtable();

  void Build();

  int Numcomponents();

  char Whatis(int x, int y);

  float Valueof (int x, int y);

  int Labelof (int x, int y);

  int Currentx();
  
  int Currenty();
};
 
