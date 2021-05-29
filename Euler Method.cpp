#include "bits/stdc++.h"
using namespace std;

double Euler_Method(double Y_n,double h,double y,double x)
{
	return Y_n+h*((0.1*(sqrt(y))+(0.4*(pow(x,2)))));
}
int main()
{
	double h,n,x[10],y[10],in_x,in_y;
	int i,j;
	i = 0 ; j = 0 , n = 0 ;//n initially n = 0 
	cout<<"ENTER VAL OF X0 :"; cin>>in_x;
	cout<<"ENTER VAL OF Y0 :"; cin>>in_y;
	cout<<"ENTER VAL OF h : "; cin>>h; 
	while(x[i-1]<2.5)
	{
		if(i == 0 && j == 0)
		{
		x[i] = in_x ; 
		y[j] = in_y ;
	    }
	    else
	    {
	    	x[i] = (in_x+(n*h)); // xn = x0 + nh ;  
		}
		n++;
		y[j+1] = Euler_Method(y[j],h,y[j],x[i]);
		i++; 
		j++;
	}
	int k = 0; 
	while(k!=i)
	{
		cout<<"X = "<<x[k]<<" :  Y = "<<y[k]<<endl;
		k++;
	}
	return 0;
}
