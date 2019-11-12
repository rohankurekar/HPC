#include<iostream>
#include<omp.h>	
using namespace std;
int main()
{
	int m,n;
	cout<<"\nEnter matrix  size(i.e m * n)";
	cin>>m>>n;  
	omp_set_num_threads(n);  
	int a[m][n],b[n],c[n]={0};
	
	cout<<"\nEnter matrix";
	
	for(int i=0;i<m;i++)
	{
	  for(int j=0;j<n;j++)
		cin>>a[i][j];
	}
	
	cout<<"\nEnter  vector of size "<<n;;
	
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}

        
	#pragma omp parallel for
	for(int i=0;i<m;i++)
	{       
		
		for(int j=0;j<n;j++)
		{
		cout<<"\n Thread id "<<omp_get_thread_num();
		c[i]+=a[i][j]*b[j];
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<"\n "<<c[i];
	}
	return 0;
}
