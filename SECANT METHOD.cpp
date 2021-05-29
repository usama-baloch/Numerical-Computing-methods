
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

using namespace std;



float f(float x){
	return (-(x*x*x)-cos(x)); // x-0.8-0.2sinx
}

void print(int stp,float x){
	cout<<"Iteration "<< stp<<": ";
		  cout<<"\t x = "<< setw(11);
		  cout<<x<<" and f(x) = "<< setw(11)<< f(x);
		  cout<<"\n";
}


//  --------------------------------  secand method ------------------------------------
int main()
{
	 float xi, xj, x2, f_0, f_1, f_2, e;
	 int step = 1, n;
	 
    cout<< setprecision(6)<< fixed;

	 cout<<"First guess: ";
	 cin>>xi;
	 cout<<"Second guess: ";
	 cin>>xj;
	 cout<<"Tolerable error: ";
	 cin>>e;
	 cout<<"Maximum iteration: ";
	 cin>>n;

	 cout<<endl;
	 
	 while(1)
	 {
		  f_0 = f(xi);
		  f_1 = f(xj);
		  
		  // if valid
		  //cout<<f_0<<" "<<f_1<<endl;
		  if(f_0 == f_1)
		  {
			   cout<<"Math Error.";
			   exit(0);
		  }

		  x2 = ((xi*f_1)-(xj*f_0))/(f_1-f_0); 
//		  x2 = xj - a;
		  f_2 = f(x2);

		  print(step,x2);

		  xi = xj;
		  f_0 = f_1;
		  xj = x2;
		  f_1 = f_2;

		  step++;

		  if(step > n)
		  {
			   cout<<"This is not convergent.";
			   exit(0);
		  }
		  
		  if(fabs(f_2)<=e){
		  	break;
		  }
	 }

	 cout<< endl<<"Root: "<< x2;

	 return 0;
}

