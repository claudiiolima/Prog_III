/*This class handles differentional equations up to order 2.  Specificaly, */
/*it's designed for Ldi/dt + Ri + q/C = V.  It can have an arbitrary number*/
/*of terms- the size of the array is set to the proper size in the */
/*constructor.  The most useful functions for the end user are the Ivstime */
/* and Vvstime- they will generate an output file with I or V vs time */
/*suitable for plotting with gnuplot*/

#include "array2.h"

class DEeqn
{
 private:
  struct Term
    {
      float coef;
      int derivative;    /*3  dI/dt    2  I */
                         /*1  q        0 no charge/ current dependence */
      int label;         /*label from circuit/ component class */
    };

  Array2 <Term> Equation;

  float Charge;
  float Oldcharge;
  float Current;
  float Oldcurrent;
  float Dcurrent;   /*di/dt */
  float Olddcurrent;

  int Order;  /* order of equation in terms of Term's derivative */

 public:
  DEeqn(int num);

  void Addtoeqn(char t, float v, int l);  /*type, value, label number*/

  void Ivstime(float tf, float dt, int label);
  void Vvstime(float tf, float dt, int label);


  void Inputinitial();

  void Dteqn(float delta);  /*steps eqn by dt- updates Current and Charge*/

  void Printeqn();


}; 
