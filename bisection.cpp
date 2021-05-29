#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

float fi(float x){
 return x*x*x - x - 11;
}

void print(int stp,float x){
	cout<<"Iteration "<< stp<<": ";
		  cout<<"\t x = "<< setw(11);
		  cout<<x<<" and f(x) = "<< setw(11)<< fi(x);
		  cout<<"\n";
}

int main()
{
	 float xi, xj, x, f0, f1, f, e;
	 int stp = 1;

     cout<<setprecision(6)<<fixed;


	 rep:
	 cout<<"First guess: ";
     cin>>xi;
     cout<<"Second guess: ";
     cin>>xj;
     cout<<"Tolerable error: ";
     cin>>e;

	 f0 = fi(xi);
	 f1 = fi(xj);

	 if( f0*f1 > 0.0)
	 {
		  cout<<"\n Incorrect Initial Guesses\n "<< endl;
		  goto rep;
	 }

	 cout<<"\nBisection Method\n"<< endl;
	 
	 while(1)
	 {
		  x = (xi + xj);
		  x /= 2;
		  
		  f = fi(x);

		  print(stp,x);

		  if(f0*f<0)
		  {
			   xj = x;
		  }
		  else
		  {
			   xi = x;
		  }
		  
		  stp++;
		  
		  if(fabs(f) <= e){
		  	break;
		  }
		  
	 }

	 cout<<"\nRoot = "<<  x<< endl;

	 return 0;
}
