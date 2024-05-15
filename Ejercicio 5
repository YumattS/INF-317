#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>
void main(int argc,char *argv[]){
    int procesador,cantidad;
    int envio,i,j,recepcion;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&procesador);
    MPI_Comm_size(MPI_COMM_WORLD,&cantidad);
    int n=cantidad;
    int matriz[2*cantidad];
    int vector[cantidad];
    int res[cantidad];
    if(procesador==0){
    	for(i=0;i<n;i++){
	   res[i]=0;
	}
	printf("Ingrese elemento de la matriz\n");
	for(i=0;i<n;i++){
	   for(j=0;j<n;j++){
	      printf("Elemento de la fila %d columna %d\n",i+1,j+1);
	      scanf("%i",&matriz[i*n+j]);  
	   }
	}
	printf("Ingrese elementos del vector \n");
	for(i=0;i<n;i++){
	   printf("Elemento %d\n",i+1);
	   scanf("%i",&vector[i]);
	}
    	for(i=0;i<n;i++){
    	  res[procesador]=res[procesador]+matriz[i]*vector[i];
    	}
    	MPI_Send(&matriz,n*n,MPI_INT,procesador+1,0,MPI_COMM_WORLD);
    	MPI_Send(&res,n,MPI_INT,procesador+1,0,MPI_COMM_WORLD);
    	MPI_Send(&vector,n,MPI_INT,procesador+1,0,MPI_COMM_WORLD);
    }
    else{
    	if(procesador==cantidad-1){
    		MPI_Recv(&matriz,n*n,MPI_INT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		MPI_Recv(&res,n,MPI_INT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		MPI_Recv(&vector,n,MPI_INT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		for(i=0;i<n;i++){
    	           res[procesador]=res[procesador]+matriz[procesador*n+i]*vector[i];
    		}
    		printf("La multiplicacion de matriz \n");
    		for(i=0;i<n;i++){
    	           printf("|");
		   for(j=0;j<n;j++){
		      printf("%d ",matriz[i*n+j]); 
		   }
		   printf("|\n");
		}
		printf("\n por el vector \n|");
		for(i=0;i<n;i++){
	    	   printf("%d ",vector[i]);
	    	}
    		printf("|\nes\n|");
	    	for(i=0;i<n;i++){
	    	   printf("%d ",res[i]);
	    	}
    		printf("|\n");
    	}
    	else{
    		MPI_Recv(&matriz,n*n,MPI_INT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		MPI_Recv(&res,n,MPI_INT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		MPI_Recv(&vector,n,MPI_INT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    		for(i=0;i<n;i++){
    	           res[procesador]=res[procesador]+matriz[procesador*n+i]*vector[i];
    		}
    		MPI_Send(&matriz,n*n,MPI_INT,procesador+1,0,MPI_COMM_WORLD);
    		MPI_Send(&res,n,MPI_INT,procesador+1,0,MPI_COMM_WORLD);
    		MPI_Send(&vector,n,MPI_INT,procesador+1,0,MPI_COMM_WORLD);
    	}
    	
    	
    	}
    
    MPI_Finalize();
}
