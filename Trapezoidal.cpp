#include<iostream>
#include<math.h>
using namespace std;
double function(double x)
{
	double r=1/(x*x);
	return r;
}
void storevalue(double *x,double *y,int n,double a,double h)
{
	double d,d1;
	for(int i=0;i<=n;i++) //generating x0-xn and storing them into array also caculating values of function and storing them into an array
	{
		x[i]=a+i*h;
		d1=x[i];
		d=function(d1);
		y[i]=d;
	}
}
double calculatesum(double *y,int n) 
{
	double sum=0;
	for(int i=1;i<n;i++) //calculating sum of y1 - yn-1
	{
		sum+=y[i];
	}
	return sum;
}
int main()
{
	double a,b,h,sum,result,y0,yn;//a,b are intervals, h is gap
	cout<<"-----------GENERALIZED TRAPEZOIDAL----------------"<<endl;
	int n; // x0-xn i.e max value of x
	cout<<"Enter lower limit: ";
	cin>>a;
	cout<<"Enter upper limit: ";
	cin>>b;
	cout<<"Enter max numbers of x: ";
	cin>>n;
	h=(b-a)/n;
	double X_value[n+1],Y_value[n+1]; //n+1 b/c x0-xn
	storevalue(X_value,Y_value,n,a,h);  //calling function to store valuees of x0-xn into X_value array and y0-yn in Y_value array
	sum=calculatesum(Y_value,n);
	y0=Y_value[0];
	yn=Y_value[n];
	result=(h/2.0)*(y0+yn+ 2*sum);
	cout<<endl<<"---------------------------------------"<<endl;
	cout<<"Integral= "<<result;
	
	
	
	
}
