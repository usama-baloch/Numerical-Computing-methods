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
	double r1=x+(h/2.0);
	double r2=y+(h/2.0)*k1;
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
	cout<<"-----------------MID-POINT-----------------"<<endl;
	double h,x0,y0,k1,k2;
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
	storevalues(X_value,n,h);
	for(int i=1,j=0;j<=n;i++,j++)
	{
		k1=calculatek1(X_value[j],Y_value[j]);
		k2=calculatek2(X_value[j],Y_value[j],h,k1);
		Y_value[i]=Y_value[j]+h*k2;
		cout<<endl<<"----------------------------------------------"<<endl;
		cout<<"Y"<<j+1<<" = "<<Y_value[i];
	}
	
}
