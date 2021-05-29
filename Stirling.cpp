#include "bits/stdc++.h"
using namespace std;

double Stirlings(double *x,double *yn,double *delta_yn,double *delta_yn2,double *delta_yn3,double delta_yn4,double p,int h,int x0,int n)
{
	int t ,i,j,k;
	double y0,ans; 
	for(i = 0 ; i < n ; i ++)
	{
		t = (x[i]-x0)/5;
		if(t == 0) break;
    }
    if(i%2==0)
    j=(i+1)/2;
	ans = yn[i]+(p*((delta_yn[j]+delta_yn[j+1])/2)+(((pow(p,2))/2)*delta_yn2[j])+
	(((p*(pow(p,2)-1))/6)*((delta_yn3[j]+delta_yn3[j+1])/2))+((((pow(p,2))*(pow(p,2)-1))/24)*delta_yn4));
	return ans;
}
int Take_val(double *x,int n,double x1)
{
	double temp[n],min;
	int index ;
	for(int i = 0 ; i < n ; i ++)
	{
		temp[i] = x1-x[i];
		if(temp[i]<0) temp[i] = temp[i]*-1;
	}
	min = temp[0];
	for(int i = 1 ; i < n ; i ++)
	{
		if(min>temp[i])
		{
			min = temp[i];
			index = i ; 
		}
	}
	return x[index];
}
int main()
{
	double p,x1,x[10],y[10],a[5],b[5],c[5],d,h,x0;
	int i,j,k,n;
	cout<<"ENTER NO OF VALUES OF X AND Y WILL BE :\n"; cin>>n;
	cout<<"ENTER X VAL "; cin>>x1;
	cout<<"Xn VAL :\n";
	for(i = 0 ; i < n ; i ++)
	{
		cout<<"ENTER DATA :\n"; 
		cin>>x[i];
	}
	cout<<"Yn VAL : \n";
	for(j = 0 ; j < n ; j ++)
	{
		cout<<"ENTER DATA :\n"; 
		cin>>y[j];
	}
	x0 = Take_val(x,n,x1);
	h = 5;
	p = (x1-x[2])/h;
	i = 0 ; 
	for(j = 1 ; j < n ; j ++)
	{
	a[i] = y[j]-y[j-1];
	i++;
    }
	k = 0 ;
	for(j = 1 ; j < i ; j ++)
	{
	b[k] = a[j] - a[j-1];
	k++;	
    }
	i = 0 ;
	for(j = 1 ; j < k ; j ++)
	{
		c[i] = b[j] - b[j-1]; 
		i++;
	}
	d = c[1] - c[0];
    cout<<"Ans = "<<Stirlings(x,y,a,b,c,d,p,h,x0,n);
	return 0 ; 
}
