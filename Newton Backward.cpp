#include "bits/stdc++.h"
using namespace std;


//double BackWard_Fun(double f_x0,double p,double y0,double y1,double y2,int n) // y1 - > y0^2 and y2->y0^3
//{
//	double ans;
//	if(n == 4)
//	ans = (f_x0+(p*y0)+((p*(p+1))*y1)/2+((p*(p+1)*(p+2))*y2)/6);
//	else if(n == 3)
//	ans = (f_x0+(p*y0)+((p*(p+1))*y1)/2);
//	return ans;
//}
int fact(int i )
{
	if(i == 0 || i == 1)
	return 1;
	
	return i*fact(i-1);
}
double mult_p(double k,int i)
{
	double p = 1; 
	for(int j = 0 ; j < i ; j++)
	{
		p = p*(k+j);
	}
	if(i == 0)
	p = k ; 
	return p ; 
}
double Backward_Fun(double f_x0,double p,double *delta_y,int n) // delta_y - > all values of deltas
{
	double ans = f_x0 ;
	int j = 1; 
	for(int i = 0 ; i < n ; i ++)
	{
		p = mult_p(p,i);
		ans = ans + (((p)*delta_y[i])/fact(j));
		j++;
	}
	return ans;
}
void calculate(double *src,double *temp,int n,int *k)
{
	int j = 1 ; 
	double t; 
	for(int i = 0 ; i < n ; i++)
	{
		t = src[j] - src[j-1];
		src[i] = t ; 
		if(i == n-1)
		{
		temp[*k] = src[i];
		*k = *k + 1; 
		} 
		j++; 
	}
}
int main()
{
	//----------------------NEWTON BACKWORD METHOD--------------------------------
	double p,x,f_x0;
	double x_val[10],y_val[10];
	int i,j,n,n1,k=0;
	cout<<"ENTER HOW MANY X AND Y VALUE YOU WANT TO ENTER : "; cin>>n; 
	cout<<"ENTER VALUE OF X FOR P(X)  : "; cin>>x;
	double temp[n];
	
	for(i = 0 ; i < n ; i ++){
	cout<<"ENTER X"<<i<<" : "; 
	cin>>x_val[i];
	}
	
	for(j = 0 ; j < n ; j ++){
	cout<<"ENTER Y"<<j<<" : ";
	cin>>y_val[j];
    }
    
	f_x0 = y_val[n-1];
    
    n1 = n-1;
    j = 1;
    
	while(n1!=0)
    {
	calculate(y_val,temp,n1,&k);
	cout<<j<<" ITERATION :\n";
	for(i = 0 ;i < n1 ; i ++)
	cout<<y_val[i]<<"\n";
	k++;
	n1--;
	j++;
    }
    
    double h = x_val[1] - x_val[0] ; 
    p = (x - x_val[n-1]) / h ; 
    cout<<"p("<<x<<") = "<<Backward_Fun(f_x0,p,temp,n);
	//cout<<"p("<<x<<") = "<<BackWard_Fun(y_val[3],p,a[2],b[1],c,n);
	return 0;
}
