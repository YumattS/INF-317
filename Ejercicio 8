#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
	int i,n=100;
	int arreglo[n];
	#pragma omp parallel
	{
	  #pragma omp for 
	  for(i=0;i<n;i++){
	     arreglo[i]=(i+1)*2;
	  }	
	}
	for(i=0;i<n;i++){
	   printf("%d ",arreglo[i]);
	}
	printf("\n");
}
