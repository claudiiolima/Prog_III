#include "circuit.h"
#include "deeqn.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

/* This is a sample program that will demonstrate the circuit & deeqn classes*/
/* Basically, you create a circuit, build it, create a differential equation*/
/* add terms via a for loop, then write a file with either current or voltage*/
/* vs time (which can be viewd using gnuplot). */

int main() {

  // Array2<int> arr1(0, 0);
  //
  // arr1.print();
  //
  // arr1.setSize(3, 2);
  // arr1 = 1;
  // z
  // // arr1.print();
  //
  // arr1.setSize(3, 4);
  //
  // arr1.print();
  /* the size of the breadboard is limited by the size of your screen
  */
  /* x= # columns/ 5 and y= # rows/ 5    (x=15, y=4 is good for
  vt100)*/
  Circuit mycircuit(15, 4);

  cout << "hello." << endl;

  mycircuit.Build();

  /*create the eqn that has the number of terms equal to number of */
  /* non-wire parts in circuit */
  DEeqn myeqn(mycircuit.Numcomponents());

  for (mycircuit.Begin(); mycircuit.More(); mycircuit.Advance()) {
    myeqn.Addtoeqn(
        mycircuit.Whatis(mycircuit.Currentx(), mycircuit.Cu\
rrenty()),
        mycircuit.Valueof(mycircuit.Currentx(), mycircuit.Currenty()),
        mycircuit.Labelof(mycircuit.Currentx(), mycircuit.Currenty()));
  }
  myeqn.Printeqn();

  myeqn.Inputinitial();

  float tfinal;
  char choice;

  cout << "Do you wish to calculate current or voltage as a function of time? "
          "(i or v)";
  cin >> choice;
  cout << endl;

  cout
      << "What part do you want to find the voltage across or current through? "
      << endl;
  cout << "Input the part number (eg. if R2 the input 2)";
  int part;
  cin >> part;
  cout << endl;

  cout << "What is the size of the time interval you wish to calculate(in "
          "seconds)? ";
  cin >> tfinal;
  cout << endl;

  cout << "What is the time step (in seconds)?";
  float step;
  cin >> step;
  cout << endl;

  if (choice == 'i' || choice == 'I') {
    myeqn.Ivstime(tfinal, step, part);
  } else if (choice == 'v' || choice == 'V') {
    myeqn.Vvstime(tfinal, step, part);
  } else {
  }

  cout << "Have a nice day." << endl;

  return 1;
}
