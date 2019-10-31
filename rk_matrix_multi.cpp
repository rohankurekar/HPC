#include<iostream>
#include<omp.h>	
using namespace std;
int main()
{
	int m,n;
	cout<<"\nEnter first matrix  size(i.e m * n)";
	cin>>m>>n;  
	
	int a[m][n];
	
	cout<<"\nEnter first matrix";
	
	for(int i=0;i<m;i++)
	{
	  for(int j=0;j<n;j++)
		cin>>a[i][j];
	}
	
	int x,y;
	cout<<"\nEnter second matrix  size(i.e x * y)";
	cin>>x>>y;  
	
	int b[x][y],c[m][y];
	
	cout<<"\nEnter second matrix";
	
	for(int i=0;i<x;i++)
	{
	  for(int j=0;j<y;j++)
		cin>>b[i][j];
	}
	
		
	omp_set_num_threads(m*y);  
        int i,j,k;
        #pragma omp parallel shared(a,b,c) private(i,j,k)
	{
	#pragma omp for schedule(static)
	for( i=0;i<m;i++)
	{       
		
		for(j=0;j<y;j++)
		{    c[i][j]=0;
			for( k=0;k<n;k++){
				cout<<"\n Thread id "<<omp_get_thread_num();
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	}

	for(int i=0;i<m;i++)
	{
	  for(int j=0;j<y;j++)
		cout<<c[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
