#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
	int i,a,b,c,d;
	a=98;
	b=2;
	c=0;
	#pragma omp parallel
	{
	  #pragma omp for reduction(+:c)
	  for(i=0;i<a;i++){
	     c=c+b;
	  }	
	}
	printf("multiplicacion de %d por %d es %d\n",a,b,c);
	a=46;
    	c=0;
    	b=8;
    	#pragma omp parallel
	{
	  #pragma omp for reduction(+:c)
	  for(i=b;i<=a;i=i+b){
	     c=c+1;
	  }	
	}
    	printf("Division de %d entre %d es %d el resto es %d\n",a,b,c,(a-b*c));
}
