#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
	int j,i,n;
	printf("Ingrese el tamaño del vector\n");
	scanf("%i",&n);
	int a[n];
	int b[n][n];
	int c[n];
	for(i=0;i<n;i++){
	   c[i]=0;
	}
	printf("Ingrese elemento de la matriz\n");
	for(i=0;i<n;i++){
	   for(j=0;j<n;j++){
	      printf("Elemento de la fila %d columna %d\n",i+1,j+1);
	      scanf("%i",&b[i][j]);  
	   }
	}
	printf("Ingrese elementos del vector \n");
	for(i=0;i<n;i++){
	   printf("Elemento %d\n",i+1);
	   scanf("%i",&a[i]);
	}
	#pragma omp parallel
	{
	  #pragma omp for private(i,j)
	  for(i=0;i<n;i++){
	     for(j=0;j<n;j++){
	     	c[i]=b[i][j]*a[j]+c[i];
	     }
	  }	
	}
	printf("La multiplicacion de matrices ingresa y el vector es \n");
	for(i=0;i<n;i++){
	   printf("%d ",c[i]);
	}
	printf("\n");

}
