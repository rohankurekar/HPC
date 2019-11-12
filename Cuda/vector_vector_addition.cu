#include<stdio.h>
#include<iostream>
using namespace std;


__global__ void sum(int*  input1,int*  input2, int *Out,int size)              //kernel
{
    int i = threadIdx.x + blockDim.x * blockIdx.x;
	printf("\nThread id%d",threadIdx.x);
	if(i<size)
    Out[i]= input1[i] + input2[i];
    __syncthreads();
}

int main()
{
  int i,n;
  cout<<"Enter no. of elements";
  cin>>n;                                       //read number of elements in vector
  int a[n],b[n],c[n];
  cout<<"Enter elements of first vector";
  for(int i=0;i<n;i++)
  cin>>a[i];                                    //read first vector
  
  cout<<"Enter elements of second vector";
  for(int i=0;i<n;i++)
  cin>>b[i];                                    //read second vector
  
  
  int *a1, *b1, *c1;                            
  cudaMalloc((void **) &a1, n*sizeof(int));     //allocating memory
  cudaMalloc((void **) &b1, n*sizeof(int));
  cudaMalloc((void **) &c1, n*sizeof(int));
  
 
  
  
  for( i = 0 ; i < n ; i++)
  {
    
	c[i]=0;
  }
  
  
  cudaMemcpy(a1 , a, n*sizeof(int),cudaMemcpyHostToDevice);    //data transfer from host memory to device memory
  cudaMemcpy(b1 , b, n*sizeof(int),cudaMemcpyHostToDevice);
  cudaMemcpy(c1 , c, n*sizeof(int),cudaMemcpyHostToDevice);
  
  sum<<<1,n>>>(a1,b1,c1,n);                                    //calling kernel
  cudaDeviceSynchronize();
  cudaMemcpy(c, c1, n*sizeof(int),cudaMemcpyDeviceToHost);    //data transfer from device memory to host memory
  
  for( i = 0 ; i < n ; i++)
  {
    
	cout<<"\n "<<a[i]<<" + "<<b[i]<<" = "<<c[i];
  }
  
  cudaFree(a1);         //freeing memory
  cudaFree(b1);
  cudaFree(c1);
 
  return 0;
}
