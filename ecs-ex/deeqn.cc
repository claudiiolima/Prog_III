#include "deeqn.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;

 DEeqn::DEeqn(int num)
{
  Equation.setSize(num,0);

  Current=0.0;
  Charge=0.0;
  Oldcharge=0.0;
  Oldcurrent=0.0;
  Dcurrent=0.0;
  Olddcurrent=0.0;
  Order=0;

  for (int x=0; x<num;x++)
    {
      Equation(x,0).derivative=-1;
    }
}


void DEeqn::Addtoeqn(char tag, float value, int num)
{
  int x=-1;
  int der=0;
 /*find first empty term in Equation */
  while(der!=-1 && x<Equation.columns())
    {
      x++;
      der= Equation(x,0).derivative;
    }
  Equation(x,0).coef= value;
  Equation(x,0).label=num;
  if (tag=='l' || tag=='L') {der=3;}
  else if (tag=='r' || tag=='R') {der=2;}
  else if (tag=='c' || tag=='C') {der=1;}
  else if (tag=='b' || tag=='B') {der=0;}
  Equation(x,0).derivative=der;

  if (der>Order) {Order=der;} /*adjust the order of the equation accordingly*/
}


/* input the intial conditions */
void DEeqn::Inputinitial()
{
  cout<<"What is the initial charge (in coulombs)?";
  float qi=0.0;
  cin>>qi;cout<<endl;

  Charge=qi;
  Oldcharge=qi;

  cout<<"What is the initial current (in amps)?";
  float ii=0.0;
  cin>>ii;cout<<endl;

  Current=ii;
  Oldcurrent=ii;
}


/*steps the Current, Charge and Dcurrent using the Improved Euler's method*/
void DEeqn::Dteqn(float delta)
{

  if (Order==0 || Order==1)   /*no I or dI/dt terms */
    {
      float v=0.0;
      float cinv=0.0;
      float c=0.0;
      for(int x=0; x<Equation.columns();x++)
	{
	  if (Equation(x,0).derivative==0)
	    {
	      v=v+Equation(x,0).coef;
	    }
	  else 
	    {
	      cinv=cinv+ 1/(Equation(x,0).coef);
	    }
	}

      if (cinv!=0.0) {c=1/cinv;}
      else {}

      Current=0.0;
      Charge=v*c;
      Oldcurrent=0.0;
      Oldcharge=Charge;

    }

  else if (Order==2)   /*only I and q terms */
    {
      float r=0.0;
      float v=0.0;
      float c=0.0;
      float cinv=0.0;

      for(int x=0; x<Equation.columns();x++)
        {
          if (Equation(x,0).derivative==0)
            {
              v=v+Equation(x,0).coef;
            }
          else if (Equation(x,0).derivative==1)
            {
              cinv=cinv+ 1/(Equation(x,0).coef);
            }
	  else
	    {r=r+Equation(x,0).coef;}
        }
      c=1/cinv;

      Oldcharge=Charge;
      Oldcurrent=Current;

      Charge=Oldcharge + delta*Oldcurrent;
      Current=(v-Charge*cinv)/r;
      Charge=Oldcharge+ 0.5*delta*(Current+Oldcurrent);
      

    }

  else if (Order==3)  /*has dI/dt terms */
    {
      float l=0.0;
      float r=0.0;
      float v=0.0;
      float c=0.0;
      float cinv=0.0;
      for(int x=0; x<Equation.columns();x++)
        {
          if (Equation(x,0).derivative==0)
            {
              v=v+Equation(x,0).coef;
            }
          else if (Equation(x,0).derivative==1)
            {
              cinv=cinv + 1/(Equation(x,0).coef);
            }
          else if (Equation(x,0).derivative==2)
            {
	      r=r+Equation(x,0).coef;
	    }
	  else
	    {
	      l=l+Equation(x,0).coef;
	    }

        }

      c=1/cinv;

      Olddcurrent=Dcurrent;
      Oldcurrent=Current;
      Oldcharge=Charge;

      Charge=Oldcharge+Oldcurrent*delta;
      Current=Oldcurrent+Olddcurrent*delta;
      Dcurrent=(v-Current*r-Charge*cinv)/l;
      Charge=Oldcharge+0.5*delta*(Oldcurrent+Current);
      Current=Oldcurrent+0.5*delta*(Dcurrent+ Olddcurrent);


    }

  else{cout<<"You have a dork equation"<<endl;}
}



void DEeqn::Printeqn()
{
  for (int x=0; x<Equation.columns();x++)
    {
      int der;
      int name;
      der= Equation(x,0).derivative;
      name=Equation(x,0).label;
  
      if (der==0)
	{
	  cout<<"+ V"<<name<<" ";
	}
      else if (der==1)
	{
	  cout<<"+ q/C"<<name<<" ";
        }
      else if (der==2)
        {
          cout<<"+ IR"<<name<<" ";
	}
      else if (der==3)
	{
	  cout<<"+ L"<<name<<"dI/dt ";
	}
      else {}
    }
  cout<<"= 0"<<endl;

  cout<<"Part    Value"<<endl;
  cout<<"----    -----"<<endl;
  for (int x=0; x<Equation.columns();x++)
    {
      int der;
      int name;
      float value;
      der= Equation(x,0).derivative;
      name=Equation(x,0).label;
      value=Equation(x,0).coef;
      if (der==0)
        {
          cout<<"V"<<name<<"    "<<value<<endl;
        }
      else if (der==1)
        {
          cout<<"C"<<name<<"    "<<value<<endl;
        }
      else if (der==2)
        {
          cout<<"R"<<name<<"    "<<value<<endl;;
        }
      else if (der==3)
        {
          cout<<"L"<<name<<"    "<<value<<endl;
	}  
    }
}



void DEeqn::Ivstime(float tf, float dt, int label)
{
  ofstream out("output.dat");
  
  out<<"#time    current"<<endl;
  for (float time=0.0; time<=tf; time+=dt)
    {
      out<<time<<"     "<<Current<<endl;
      Dteqn(dt);
    }
  cout<<"The data has been written to the file 'output.dat'"<<endl;
}


void DEeqn::Vvstime(float tf, float dt, int Wahoo)
{
  ofstream out("output.dat");

  int x=-1;
  int name=-1;
  /*find the term the user wants the voltage drop across */
  while (name !=Wahoo)
    {
      x++;
      name= Equation(x,0).label;
    }

  out<<"#time   Voltage for part"<<name<<endl;

  for (float time=0.0; time<=tf; time+=dt)
    {
      float v=0.0;
      if (Equation(x,0).derivative==0)
	{
	  v=Equation(x,0).coef;
	}
      else if(Equation(x,0).derivative==1)
	{
	  v=Charge/Equation(x,0).coef;
	}
      else if(Equation(x,0).derivative==2)
	{
	  v=Current*Equation(x,0).coef;
	}
      else if(Equation(x,0).derivative==3)
	{
	  v=Dcurrent*Equation(x,0).coef;
	}

      out<<time<<"     "<<v<<endl;
      Dteqn(dt);
    }
  cout<<"The data has been written to the file 'output.dat'"<<endl;
}
