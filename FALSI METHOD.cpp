#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;


inline float func(float x){
	return ((x*x*x)-x-11);
//	 return x - 0.8 - 0.2 * sin(x);
}

void print(int stp,float x){
	cout<<"Iteration "<< stp<<": ";
		  cout<<"\t x = "<< setw(11);
		  cout<<x<<" and f(x) = "<< setw(11)<< func(x);
		  cout<<"\n";
}

int main()
{
	 float xi, xj, x;
	 float f0, f1, f, e;
	 int stp = 1;

     cout<< setprecision(6)<< fixed;

	 repeat:
	 cout<<"Enter first guess: ";
     cin>>xi;
     
     cout<<"Enter second guess: ";
     cin>>xj;
     
     
     cout<<"Enter tolerable error: ";
     cin>>e;

	 f0 = func(xi);
	 f1 = func(xj);

	 if( f0 * f1 > 0.0)
	 {
		  cout<<"Incorrect Initial Guesses."<< endl;
		  goto repeat;
	 }


	 cout<<"\n";
	 
	 
	 
	 while(true)
	 {

		  x = ((xi*f1) - (xj*f0))/ (f1-f0);
		  f = func(x);

		  print(stp,x);
		  
		  if( f0 * f < 0)
		  {
			   xj = x;
			   f1 = f;
		  }
		  else
		  {
			   xi = x;
			   f0 = f;
		  }
		  stp++;
		  
		  if(fabs(f)<=e){
		  	break;
		  }
	 }

	 cout<<"\nRoot: "<< x<< endl;

	 return 0;
}


