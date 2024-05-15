#include <stdio.h>
#include "mpi.h"
#include <math.h>
void main(int argc,char *argv[]){
    int procesador,cantidad;
    int envio,i,recepcion,n=100;
    int a[n];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&procesador);
    MPI_Comm_size(MPI_COMM_WORLD,&cantidad);
    int f=n/cantidad;
    if(procesador==0){
    	for(i=f*procesador;i<(procesador+1)*f;i++){
    	  a[i]=(i+1)*2;
    	}
    	MPI_Send(&a,f,MPI_FLOAT,procesador+1,0,MPI_COMM_WORLD);
    }
    else{
    	if(procesador==cantidad-1){
    MPI_Recv(&a,f*procesador,MPI_FLOAT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    	for(i=f*procesador;i<n;i++){
    	  a[i]=(i+1)*2;
    	}
    	for(i=0;i<n;i++){
    	   printf("%d ",a[i]);
    	}
    	printf("\n");
    	}
    	else{
    	MPI_Recv(&a,f*procesador,MPI_FLOAT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    	for(i=f*procesador;i<(procesador+1)*f;i++){
    	   a[i]=(i+1)*2;
    	}
    	MPI_Send(&a,f*(1+procesador),MPI_FLOAT,procesador+1,0,MPI_COMM_WORLD);
    	}
    }
    MPI_Finalize();
}
