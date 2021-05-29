#include<iostream>
#include<math.h>
using namespace std;
double function(double x)
{
	return (x*x*x*x);
}
void storevalue(double *x,double *y,int n,double a,double h)
{
	double d1,d;
	for(int i=0;i<=n;i++) //generating x0-xn and storing them into array also caculating values of function and storing them into an array
	{
		x[i]=a+i*h;
		d1=x[i];
		d=function(d1);
		y[i]=d;
	}
}
double calculatesum1(double *y,int n)
{
	double sum=0;
	int j=1;
	for(int i=1;i<n;i++)
	{
		if(j<=2)  //calculating sum of odd indexes
		{
			sum+=y[i];
		}
		else
		{
			j=0;
		}
		j++;
	}
	return sum;
}
double calculatesum2(double *y,int n)
{
	double sum=0;
	int j=1;
	for(int i=1;i<n;i++)
	{
		if(j>2)  //calculating sum of even indexes
		{
			sum+=y[i];
			j=0;
		}
		j++;
	}
	return sum;
}
int main()
{
	cout<<"-----------------------SIMPSON 3/8th RULE:-------------------------"<<endl;
	double a,b,h,result,sum1,sum2,y0,yn;//a and b are intervals, h is width
	int n; //max numbers of x, i.e xn
	cout<<"Enter lower limit: ";
	cin>>a;
	cout<<"Enter upper limit: ";
	cin>>b;
	again:
	cout<<"Enter max numbers of x: ";
	cin>>n;
	if(n<3)
	{
		cout<<"Please enter max number of x greater or equal to 3."<<endl;
		goto again;
	}
	h=(b-a)/n;
	double X_value[n+1],Y_value[n+1]; //n+1 b/c x0-xn
	storevalue(X_value,Y_value,n,a,h);  //calling function to store valuees of x0-xn into X_value array and y0-yn in Y_value array
	sum1=calculatesum1(Y_value,n);
	
	if(n!=3)
	{
		sum2=calculatesum2(Y_value,n);
	}
	
	y0=Y_value[0];
	yn=Y_value[n];
	result=((3*h)/8.0)*(y0+3*sum1+ 2*sum2+yn);
	cout<<endl<<"---------------------------------------"<<endl;
	cout<<"Integral= "<<result;
}
