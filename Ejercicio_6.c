#include <stdio.h>
#include "mpi.h"
#include <math.h>
void main(int argc,char *argv[]){
    int procesador,cantidad;
    int envio,i,recepcion,n=50000;
    float suma=0.0;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&procesador);
    MPI_Comm_size(MPI_COMM_WORLD,&cantidad);
    int f=n/cantidad;
    if(procesador==0){
    	for(i=f*procesador;i<(procesador+1)*f;i++){
    	  suma=suma+1/(float)((i+1)*(i+1));
    	}
    	MPI_Send(&suma,1,MPI_FLOAT,procesador+1,0,MPI_COMM_WORLD);
    }
    else{
    	if(procesador==cantidad-1){
    MPI_Recv(&suma,1,MPI_FLOAT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    	for(i=f*procesador;i<n;i++){
    	  suma=suma+(float)1/((i+1)*(i+1));
    	}
    	suma=suma*6;
    	suma=sqrt(suma);
    	printf("El valor de pi es %f\n",suma);  
    	}
    	else{
    	MPI_Recv(&suma,1,MPI_FLOAT,procesador-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    	for(i=f*procesador;i<(procesador+1)*f;i++){
    	  suma=suma+1/(float)((i+1)*(i+1));
    	}
    	MPI_Send(&suma,1,MPI_FLOAT,procesador+1,0,MPI_COMM_WORLD);
    	}
    }
    MPI_Finalize();
}
