#include<iostream>
#include<math.h>
using namespace std;
double function(double x,double y)
{
	double r=x+y;
	return r;
}
double calculatek1(double x,double y)
{
	double r=function(x,y);
	return r;
}
double calculatek2(double x,double y,double h,double k1)
{
	double r1=x+(h/3.0);
	double r2=y+(h/3.0)*k1;
	double r=function(r1,r2);
	return r;
}
double calculatek3(double x,double y,double h,double k2)
{
	double r1=x+(2*h/3.0);
	double r2=y+(2*h/3.0)*k2;
	double r=function(r1,r2);
	return r;
}
void storevalues(double *x,int n,double h)
{
	for(int i=1,j=0;i<=n;i++,j++)
	{
		x[i]=x[j]+h;
	}
}
int main()
{
	cout<<"-----------------HUENS METHOD-----------------"<<endl;
	double h,x0,y0,k1,k2,k3;
	int n;
	cout<<"Enter initial value of Y (y0) : ";
	cin>>y0;
	cout<<"Enter value of x0: ";
	cin>>x0;
	cout<<"Enter value of h: ";
	cin>>h;
	cout<<"Enter max number of X (xn): ";
	cin>>n;
	double X_value[n+1],Y_value[n+1];
	X_value[0]=x0;
	Y_value[0]=y0; 
	// x1 = x0+h, x2 = x1+h , x3 = x2+h , x4 = x3 + h; 
	storevalues(X_value,n,h);
	for(int i=1,j=0;j<=n;i++,j++)
	{
		k1=calculatek1(X_value[j],Y_value[j]);
		k2=calculatek2(X_value[j],Y_value[j],h,k1);
		k3=calculatek3(X_value[j],Y_value[j],h,k2);
		Y_value[i]=Y_value[j]+(h/4.0)*(k1+3*k3);
		cout<<endl<<"----------------------------------------------"<<endl;
		cout<<"Y"<<j+1<<" = "<<Y_value[i];
	}
	
}
