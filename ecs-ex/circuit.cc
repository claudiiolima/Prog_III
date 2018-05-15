#include "circuit.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

/*in the 'extra' spaces around board edg, there are pieces of wires */
/* this helps in preventing the user from building circuits off the edge*/
/*of the board- see Addtoboard for the checks */
Circuit:: Circuit(int i, int j)
{
  Breadboard.setSize(i+2,j+2);
  Start.moveTo(0,0);
  Closed=0;
  Partcount=0;
  Numcomps=0;
  Component wud('w',1,1,0,0,0.0);
  Component wlr('w',0,0,1,1,0.0);

  for (int xx=1; xx<=(Breadboard.columns()-1); xx++)
    {Breadboard(xx,0)=wlr;}
  for (int xx=1;xx<=(Breadboard.columns()-1);xx++)
    {Breadboard(xx,Breadboard.rows())=wlr;}
  for (int yy=1; yy<=(Breadboard.rows()-1); yy++)
    {Breadboard(0, yy)=wud;}
  for (int yy=1; yy<=(Breadboard.rows()-1);yy++)
    {Breadboard(Breadboard.columns(),yy)=wud;}

  
}

int Circuit::Returnclosed()
{
  return Closed;
}

void Circuit::Assignclosed(int x)
{
  Closed=x;
}

/*******************/
/* my attempt to define a space- used in Addtoboard*/

#define SP cout<<"  ";




/*this adds a component c at (x,y)  */
void Circuit::Addtoboard()
{
  int x,y;
  Component c;

  cout<<"Where do you want to add a component? x coord: ";
    cin>>x;cout<<endl;
  cout<<"                                      y coord: ";
    cin>>y; cout<<endl;

  cout<<"What type of component to you wish to insert? "<<endl;
  cout<<"r resistor           c capacitor       l inductor "<<endl;
  cout<<"w wire               b battery                    ";
  char select;
  cin>> select; cout<<endl;
  float value=0.0;

/* input what will be coef of the component class */
/* for the future one could add routines to recognize the various prefixes */
/* m= 10e-3, k = 10e3, etc   */

  if (select =='w' || select =='W'){}
  else
    {
      cout<<"What is the vlaue of the new component? ";
      switch(select)
	{
	case 'r':
	case 'R':
	  cout<<" (in ohms) ";
	  break;
	case 'c':
	case 'C':
	  cout<<" (in farads) ";
	  break;
	case 'l':
	case 'L':
	  cout<<" (in henries) ";
	  break;
	case 'b':
	case 'B':
	  cout<<" (in volts) ";
	  break;
	}
      cin>>value; cout<<endl;
    }

  
/* look around at the nearborhing locations on the board to try and determine*/
/* the orientation of the new component and determine if it may be an*/
/* illegal placement - a resistor that has three wires exiting from it. */

  int neighbors;     /* are there any neighbors & if so how many? */
  int nabove, nbelow, nright, nleft;

  nabove=1;
  nbelow=1;
  nleft=1;
  nright=1;
  if (Breadboard(x-1,y).Returntype()=='n' ||Breadboard(x-1,y).Returntype()=='N')
    {nleft=0;}
  if (Breadboard(x,y-1).Returntype()=='n' ||Breadboard(x,y-1).Returntype()=='N')
    {nabove=0;}
  if (Breadboard(x+1,y).Returntype()=='n' ||Breadboard(x+1,y).Returntype()=='N')
    {nright=0;}
  if (Breadboard(x,y+1).Returntype()=='n' ||Breadboard(x,y+1).Returntype()=='N')
    {nbelow=0;}
  neighbors= nleft+ nabove+ nright+ nbelow;

  int joints;
  int left, above, right, below; /*are there any solder joints to connect to*/
  left= Breadboard(x-1,y).Returnsolderr();
  above=Breadboard(x,y-1).Returnsolderd();
  right=Breadboard(x+1,y).Returnsolderl();
  below=Breadboard(x,y+1).Returnsolderu();
  joints=left+ right+ below+ above;


  char orien ='x';  /*orientation of the new part v vertical, h horizontal */
                    /*a dl      b ul     c ur     d dr       x   bad*/


/*scrap components- to display possible selections & used in assigning */
/*  to the board*/
  Component rv('r',1,1,0,0,0.0);
  Component rh('r',0,0,1,1,0.0);
  Component cv('c',1,1,0,0,0.0);
  Component ch('c',0,0,1,1,0.0);
  Component lv('l',1,1,0,0,0.0);
  Component lh('l',0,0,1,1,0.0);
  Component bv('b',1,1,0,0,0.0);
  Component bh('b',0,0,1,1,0.0);
  Component wud('w',1,1,0,0,0.0);
  Component wlr('w',0,0,1,1,0.0);
  Component wur('w',1,0,1,0,0.0);
  Component wul('w',1,0,0,1,0.0);
  Component wdr('w',0,1,1,0,0.0);
  Component wdl('w',0,1,0,1,0.0);
  Component empty('n',0,0,0,0,0.0);



if (neighbors==0)
  {
    if (select=='w' || select=='W')
      {
	cout<<"Here are the possible shapes of wire to choose from:"<<endl;
	for (int cc=1;cc<=5;cc++)
	  {wud.Printpic(cc);SP wlr.Printpic(cc);SP wdl.Printpic(cc);
	   SP wul.Printpic(cc);SP wur.Printpic(cc);SP wdr.Printpic(cc);
	   cout<<endl;
	 }
	cout<<"   v      h      a      b      c      d"<<endl;
	cout<<"Choose: v, h, a, b, c, or d ";
	cin>>orien;cout<<endl;
      }
    else 
      {
	cout<<"Choose either vertical or horizontal (v or h): ";
	cin>>orien; cout<<endl;
      }
  }

else if (neighbors==1)
  {
    if (joints==1)
      {
	if (select=='w' || select=='W')
	  {
	    if (left==1)
	      {
		cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		for (int cc=1;cc<=5;cc++)
		  {wlr.Printpic(cc);SP wdl.Printpic(cc);
		   SP wul.Printpic(cc);
		   cout<<endl;
		 }
		cout<<"  h      a      b"<<endl;
		cout<<"Choose:h, a, or b ";
		cin>>orien;cout<<endl;
	      }

	    else if(right==1)
	      {
		cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		  for (int cc=1;cc<=5;cc++)
		    {wlr.Printpic(cc);
		     SP wur.Printpic(cc);SP wdr.Printpic(cc);
		     cout<<endl;
		   }
		cout<<"  h      c      d"<<endl;
		cout<<"Choose: h, c, or d ";
		cin>>orien;cout<<endl;
	      }
	    else if(above==1)
	      {
		cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		for (int cc=1;cc<=5;cc++)
		  {wud.Printpic(cc);
		   SP wul.Printpic(cc);SP wur.Printpic(cc);
		   cout<<endl;
		 }
		cout<<"   v      b      c"<<endl;
		cout<<"Choose: v, b, or c ";
		cin>>orien;cout<<endl;
	      }

	    else /*below==1 */
	      {
		cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		for (int cc=1;cc<=5;cc++)
		  {wud.Printpic(cc);SP wdl.Printpic(cc);
		   SP wdr.Printpic(cc);
		   cout<<endl;
		 }
		cout<<"   v      a      d"<<endl;
		cout<<"Choose: v, a, or d ";
		cin>>orien;cout<<endl;
	      }
	  }
	else  /* not a wire */
	  {
	    if (left==1 || right==1)
	      {orien='h';}
	    else {orien='v';}
	  }
      }

    else  /*joint==0*/
      {
	if (select=='w' || select =='W')
	  {
	    if (nleft==1)
	      {
		cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		for (int cc=1;cc<=5;cc++)
		  {wud.Printpic(cc);SP wur.Printpic(cc);
		   SP wdr.Printpic(cc);
		   cout<<endl;
		 }
		cout<<"  v      c      d"<<endl;
		cout<<"Choose:v, c, or d ";
		cin>>orien;cout<<endl;
	      }

	    else if(nright==1)
	      {
		cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		for (int cc=1;cc<=5;cc++)
		  {wud.Printpic(cc);
		   SP wdr.Printpic(cc);SP wur.Printpic(cc);
		   cout<<endl;
		 }
		cout<<"  v      a      b"<<endl;
		cout<<"Choose: v, a, or b ";
		cin>>orien;cout<<endl;
	      }

	    else if(nabove==1)
	      {
		cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		for (int cc=1;cc<=5;cc++)
		  {wlr.Printpic(cc);
		   SP wdr.Printpic(cc);SP wdl.Printpic(cc);
		   cout<<endl;
		 }
		cout<<"   h      a      d"<<endl;
		cout<<"Choose: h, a, or d ";
		cin>>orien;cout<<endl;
	      }
	    else /*nbelow==1 */
	      {
		cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		for (int cc=1;cc<=5;cc++)
		  {wlr.Printpic(cc);SP wul.Printpic(cc);
		   SP wur.Printpic(cc);
		   cout<<endl;
		 }
		cout<<"   h      b      c"<<endl;
		cout<<"Choose: h, b, or c ";
		cin>>orien;cout<<endl;
	      }
	  }
	else /* not a wire */
	  {
	    if (nleft==1 || nright==1)
	      {orien='v';}
	    else {orien='h';}
	  }
      }
  }

else if (neighbors==2)
  {
    if (joints==2)
      {
	if (select=='w' || select=='W')
	  {
	    if (left==1 && right==1)
	      {orien='h';}
	    else if (below ==1 && above==1)
	      {orien='v';}
	    else if (below==1 && left==1)
	      {orien='a';}
	    else if (left==1 && above==1)
	      {orien='b';}
	    else if (above==1 && right==1)
	      {orien='c';}
	    else if (below==1 && right==1)
	      {orien ='d';}
	    else {}
	  }
	else  /*not a wire*/
	  {
	    if (left==1 && right==1)
	      {orien='h';}
	    else if (below ==1 && above==1)
	      {orien='v';}
	    else {}
	  }
      }
    else if (joints==1)
      {
	if (select=='w' || select=='W')
	  {
	    if (left==1)
	      {
		if (nabove==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wlr.Printpic(cc);
		       SP wdl.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  h      a "<<endl;
		    cout<<"Choose: h or a ";
		    cin>>orien;cout<<endl;
		  }
		else if (nright==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wdl.Printpic(cc);
		       SP wul.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  a      b "<<endl;
		    cout<<"Choose: a or b ";
		    cin>>orien;cout<<endl;
		  }
		else if (nbelow==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wlr.Printpic(cc);
		       SP wul.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  h      b "<<endl;
		    cout<<"Choose: h or b ";
		    cin>>orien;cout<<endl;
		  }
	      }
	    else if (right==1)
	      {
		if (nabove==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wlr.Printpic(cc);
		       SP wdr.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  h      d "<<endl;
		    cout<<"Choose: h or d ";
		    cin>>orien;cout<<endl;
		  }
		else if (nleft==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wur.Printpic(cc);
		       SP wdr.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  c      d "<<endl;
		    cout<<"Choose: c or d ";
		    cin>>orien;cout<<endl;
		  }
		else if (nbelow==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wlr.Printpic(cc);
		       SP wur.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  h      c "<<endl;
		    cout<<"Choose: h or c ";
		    cin>>orien;cout<<endl;
		  }
	      }
	    else if (above==1)
	      {
		if (nleft==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wud.Printpic(cc);
		       SP wur.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  v      c "<<endl;
		    cout<<"Choose: v or c ";
		    cin>>orien;cout<<endl;
		  }
		else if (nbelow==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wul.Printpic(cc);
		       SP wur.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  b      c "<<endl;
		    cout<<"Choose: b or c ";
		    cin>>orien;cout<<endl;
		  }
		else if (nright==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wud.Printpic(cc);
		       SP wul.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  v      b "<<endl;
		    cout<<"Choose: v or b ";
		    cin>>orien;cout<<endl;
		  }
	      }
	    else if (below==1)
	      {
		if (nright==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wud.Printpic(cc);
		       SP wdr.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  v      d "<<endl;
		    cout<<"Choose: v or d ";
		    cin>>orien;cout<<endl;
		  }
		else if (nabove==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wdl.Printpic(cc);
		       SP wdr.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  a      d "<<endl;
		    cout<<"Choose: a or d ";
		    cin>>orien;cout<<endl;
		  }
		else if (nright==1)
		  {
		    cout<<"Here are the possible shapes of wire to choose from:"<<endl;
		    for (int cc=1;cc<=5;cc++)
		      {wud.Printpic(cc);
		       SP wdl.Printpic(cc);
		       cout<<endl;
		     }
		    cout<<"  v      a "<<endl;
		    cout<<"Choose: v or a ";
		    cin>>orien;cout<<endl;
		  }
	      }
	    else{}
	  }
	else /* not a wire 2 neighbors & 1 good solder */
	  {
	    if (left==1)
	      {
		if (nabove==1 || nbelow==1)
		  {orien='h';}
	      }
	    else if (right==1)
	      {
		if (nabove==1 || nbelow==1)
		  {orien='h';}
	      }
	    else if (above==1)
	      {
		if (nright==1 || nleft==1)
		  {orien='v';}
	      }
	    else if (below==1)
	      {
	      if (nright==1 || nleft==1)
		{orien='v';}
	  }
	else {}
      }
  }
       else /*joint=0 */
	 {
	   if (select=='w' || select=='W')
	     {
	       if (nleft==1 && nabove==1)
		 {orien='d';}
	       else if (nright==1 && nabove==1)
		 {orien='a';}
	       else if (nleft==1 && nright==1)
		 {orien ='v';}
	       else if (nleft==1 && nbelow==1)
		 {orien ='c';}
	       else if (nabove==1 && nbelow==1)
		 {orien='h';}
	       else if (nbelow==1 && nright==1)
		 {orien ='b';}
	       else {}
	     }
	   else
	     {
	       if (nleft==1 && nright==1)
		 {orien='v';}
	       else if (nabove==1 && nbelow==1)
		 {orien='h';}
	       else {}
	     }
	 }
}

else if (neighbors==3)
{
  if (joints==3)
    {}
  if (joints==2)
    {
      if (select=='w' || select=='W')
	{
	  if (left==1 && right==1)
	    {orien='h';}
	  else if (below ==1 && above==1)
	    {orien='v';}
	  else if (below==1 && left==1)
	    {orien='a';}
	  else if (left==1 && above==1)
	    {orien='b';}
	  else if (above==1 && right==1)
	    {orien='c';}
	  else if (below==1 && right==1)
	    {orien ='d';}
	  else {}
	}
      else  /*not a wire*/
	{
	  if (left==1 && right==1)
	    {orien='h';}
	  else if (below ==1 && above==1)
	    {orien='v';}
	  else {}
	}
    }
  if (joints==1)
    {
      if (select=='w' || select=='W')
	{
	  if (above==1)
	    {
	      if (nbelow==0)
		{orien='v';}
	      else if (nright==0)
		{orien='c';}
	      else if (nleft==0)
		{orien='b';}
	      else{}
	    }
	  if (left==1)
	    {
	      if (nbelow==0)
		{orien='a';}
	      else if (nabove==0)
		{orien='b';}
	      else if (nright==0)
		{orien='h';}
	      else{}
	    }
	  if (below==1)
	    {
	      if (nright==0)
		{orien='d';}
	      else if (nleft==0)
		{orien='a';}
	      else if (nabove==0)
		{orien='v';}
	      else{}
	    }
	  if (right==1)
	    {
	      if (nbelow==0)
		{orien='d';}
	      else if (nleft==0)
		{orien='h';}
	      else if (nabove==0)
		{orien='c';}
	      else{}
	    }
	}
      else /*nonwire 3 neighbors & i joint*/
	{
	  if (left==1 && nright==0)
	    {orien='h';}
	  else if (nleft==0 && right==1)
	    {orien='h';}
	  else if (above==1 && nbelow==0)
	    {orien ='v';}
	  else if (nabove==0 && below==1)
	    {orien='v';}
	}
    }
  else  /*joint==0*/
    {}
}
else  /*neighbors=4*/
{
  if (joints==2)
    {
      if (select=='w' || select=='W')
	{
	  if (left==1 && right==1)
	    {orien='h';}
	  else if (below ==1 && above==1)
	    {orien='v';}
	  else if (below==1 && left==1)
	    {orien='a';}
	  else if (left==1 && above==1)
	    {orien='b';}
	  else if (above==1 && right==1)
	    {orien='c';}
	  else if (below==1 && right==1)
	    {orien ='d';}
	  else {}
	}
      else  /*not a wire*/
	{
	  if (left==1 && right==1)
	    {orien='h';}
	  else if (below ==1 && above==1)
	    {orien='v';}
	  else {}
	}
    }
  else {} /*for 4 neighbors, anything, but joint=2 is bad*/
}


  switch(select)
{
      case'r':
    case 'R':
         if (orien =='v' || orien =='V') {c=rv;}
         else {c=rh;}
         break;
    case 'c':
    case 'C':
         if (orien =='v' || orien =='V') {c=cv;}
         else {c=ch;}
         break;
    case 'l':
    case 'L':
         if (orien =='v' || orien =='V') {c=lv;}
         else {c=lh;}
         break;
    case 'b':
    case 'B':
         if (orien =='v' || orien =='V') {c=bv;}
         else {c=bh;}
         break;
    case 'w':
    case 'W':
         if (orien == 'v' || orien =='V') {c=wud;}
         else if (orien == 'h' || orien =='H') {c=wlr;}
         else if (orien == 'a' || orien =='A') {c=wdl;}
         else if (orien == 'b' || orien =='B') {c=wul;}
         else if (orien == 'c' || orien =='C') {c=wur;}
         else if (orien == 'd' || orien =='D') {c=wdr;}
         break;
    }

int ident;

  if (orien == 'x' || orien =='X')
{
  cout<<"Your selection will not fit into this location"<<endl;
  c=empty;
  ident=0;
}
else
{
  Partcount++;
  ident=Partcount;

  if (select=='w' || select=='W')
    {}
  else
    {Numcomps++;}
}

c.Assignlabel(ident);

  c.Assigncoef(value);
  Breadboard(x,y)=c;
  

}


/************************/


/*this removes a whatever component is at (x,y) and replaces with an empty c */

void Circuit::Removefromboard()
{
  int x,y;
  cout<<"Where is the component you wish to remove? x coord:";
  cin>>x;cout<<endl;
  cout<<"                                           y coord:";
  cin>>y;cout<<endl;
    if (x<1 || (x> Breadboard.columns()-2) ||y<1 || (y>Breadboard.rows()-2))
      {cout<<"You gave a bad (non-existant) location."<<endl;}
      else {
	char tag;
	tag= Breadboard(x,y).Returntype();
	if (tag=='w' || tag =='W' || tag =='n' || tag=='N')
	  {}
	else
	  {Numcomps--;}
	Component c;
	Breadboard(x,y)=c;}
}


void Circuit::Printboard()
{
 
  /*don't forget the extra rows & columns in the board*/

  int endrow= Breadboard.rows()-2;
  int endcol= Breadboard.columns()-2;
  cout<<"  ";
  for (int col=1; col<= endcol; col++)  /*this prints the column numbers */
    {cout<<" ";
     if (col<10) {cout<<" ";}
     cout<<col<<"  ";
   }
  cout<<endl;


  for (int row=1; row<=endrow; row++)
    {
      for (int chr=1; chr<=5 ; chr++)
        {
          if (chr==3)        /*this prints the row numbers */
            {
              if (row<10){cout<<" "<<row;}
              else {cout<<row;}
            }
          else {cout<<"  ";}

          for (int col =1; col<=endcol; col++)
           {
/*
             Component* address=Breadboard (col, row);
	     (* address).Printpic(chr);
*/
	    Breadboard(col, row).Printpic(chr);
	
	    }
        cout<<endl;
        }
    }
}



/*this moves you along the circuit- changes current and*/
/* previous- it does NOT handle nodes! */
void Circuit:: Advance()
{
  int x,y;
  x=(int) Current.x();
  y= (int)Current.y();
  Point Nextl, Nextr, Next, Nextu, Nextd;
  Nextl.moveTo(x-1,y);
  Nextr.moveTo(x+1,y);
  Nextd.moveTo(x,y+1);
  Nextu.moveTo(x,y-1);

  if ((Breadboard (x,y).Returnsolderl() ==1) &&( Nextl != Previous))
    {
      x=x-1;
      Previous=Current;
      Current.moveTo(x,y);
    }
  
  else if ((Breadboard (x,y).Returnsolderu() ==1) &&( Nextu != Previous))
    {
      y=y-1;
      Previous=Current;
      Current.moveTo(x,y);
    }

  else if ((Breadboard (x,y).Returnsolderd() ==1) &&( Nextd != Previous))
    {
      y=y+1;
      Previous=Current;
      Current.moveTo(x,y);
    }
  
  else if ((Breadboard (x,y).Returnsolderr() ==1) &&( Nextr != Previous))
    {
      x=x+1;
      Previous=Current;
      Current.moveTo(x,y);
    }
  else{}

}


/*this returns 0 if you are back at the start--> */
/* you're done searching through the circuit */
/*BTW you need to use begin with this function*/
int Circuit::More()
{
  if (Current==Start && Start != Previous)
    { return 0;}
  else
    {return 1;}
}

/*this resets previous and current so you can begin */
/*tracing out the circuit using advance & more */
void Circuit::Begin()
{
  Previous=Start;
  Current=Start;
}


/* looks for the first non void component (from */
/* the upper left) and makes that loacation the */
/* start. BTW it assumes that there is something */
/* in the board --> don't run on an empty board*/
void Circuit::Findstart()
{
  int x=0;
  int y=1;
  char tag ='n';

  while (tag=='n' || tag =='N')
    {
      x=x+1;
      if (x> (Breadboard.columns()-2) )
	{
	  x=1;
	  y=y+1;
	}
      tag=Breadboard(x,y).Returntype();
    }
  Start.moveTo (x,y);
}


/*returns 0 is the current componet is a void */
int Circuit::Open()
{
  int x,y;
  x= (int)Current.x();
  y= (int)Current.y();
  char tag;
  
  tag=Breadboard(x,y).Returntype();
  if (tag=='n' || tag=='N')
    {
      return 0;
    }
  else
    {
      return 1;
    }
}




/*sets Closed variable to 1 if the circuit is closed and*/
/* 0 if open */
void Circuit::Checkboard()
{
  this->Findstart();
  int again=1;

  for (this->Begin(); again; this->Advance())
    {
      if (this->Open()==0)
	{this->Assignclosed(0);}
      else
	{this->Assignclosed(1);}
      again=(this->More() && this->Open());
    }
}



/*prints a table of the parts with their labels and values */
/*for the future one could tinker with the print of the coef*/
/*to print in a pretty format - with prefixes */
void Circuit::Printtable()
{
  cout<<"Part        Value"<<endl;
  cout<<"----       -----"<<endl;

  for (int y=1; y<=(Breadboard.rows()-2);y++)
    {
      for (int x=1; x<=(Breadboard.columns()-2);x++)
	{
	  char tag='n';
	  tag=Breadboard(x,y).Returntype();
	  if(tag=='n'|| tag=='N'|| tag=='w'|| tag=='W')
	    {}
	  else
	    {
	      cout<<Breadboard(x,y).Returntype();
	      cout<<Breadboard(x,y).Returnlabel();
	      cout<<"     ";
	      cout<<Breadboard(x,y).Returncoef();

	      if (tag =='r' || tag=='R')
		{cout<<" ohms";}
	      else if (tag=='c' || tag=='C')
		{cout<<" farads";}
	      else if (tag=='l' ||tag=='L')
		{cout<<" henries";}
	      else if (tag=='b'|| tag=='B')
		{cout<<" volts";}
	      else {}

	      cout<<endl;
	    }
	}
    }
}





/*this is the complete package of adding & removing parts */
/* and also automtically does the check on the circuit */
/*Use this for simplest interaction */
void Circuit::Build()
{
  char answer='n';
  
  while(answer=='n' || answer=='N')
    {
      char choice;
      cout<<"What would youlike to do- add a component,"<<endl;
      cout<<"remove a componet, or print the table of values (a, r, or p)? ";
      cin>>choice; cout<<endl;
      if (choice=='a' || choice=='A')
	{
	  this->Addtoboard();
	  this->Printboard();
	}
      else if (choice == 'r' || choice =='R')
	{
	  this->Removefromboard();
	  this->Printboard();
	}
      else if (choice =='p' || choice=='P')
	{
	  this->Printtable();
	}
      else
	{cout<<"Huh?"<<endl;}
      

      cout<<"Are you finished working on your circuit? (y or n)? ";
      cin>>answer; cout<<endl;
      if (answer =='y' || answer=='Y')
	{
	  this->Checkboard();
	  if (this->Returnclosed()==0)
	    {
	      cout<<"You do not have a closed circuit, please continue adding parts.";
	      answer='n';cout<<endl;
	    }
	}
    }
}



int Circuit::Numcomponents()
{ return Numcomps;}


/*these three functions are to make it so the user doesn't have to include*/
/*component.h in the main program and yet can still get to the component info*/
char Circuit::Whatis(int x, int y)
{
  return (Breadboard(x,y).Returntype());
}

float Circuit:: Valueof (int x, int y)
{
  return (Breadboard (x,y).Returncoef());
}

int Circuit:: Labelof(int x, int y)
{
  return (Breadboard (x,y).Returnlabel());
}

int Circuit::Currentx()
{
  return ((int)Current.x());
}

int Circuit::Currenty()
{
  return ((int)Current.y());
} 
