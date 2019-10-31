#include<iostream>
#include<omp.h>	
using namespace std;
int main()
{
	int n;
	cout<<"\nEnter vector size";
	cin>>n;  
	omp_set_num_threads(n);  
	int a[n],b[n],c[n];
	cout<<"\nEnter first vector";
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<"\nEnter second vector";
	
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}

	#pragma omp parallel for
	for(int i=0;i<n;i++)
	{       cout<<"\n Thread id "<<omp_get_thread_num();
		c[i]=a[i]+b[i];
	}

	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<a[i]<<" + "<<b[i]<<" = "<<c[i];
	}
	return 0;
}
