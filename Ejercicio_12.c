#include <stdio.h>
#include "mpi.h"
#include <math.h>
void main(int argc,char *argv[]){
    int procesador,cantidad;
    int envio,i,recepcion,n=25;
    int a,b,c;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&procesador);
    MPI_Comm_size(MPI_COMM_WORLD,&cantidad);
    int f=n/(cantidad-1);
    int se[f];
    int rec[f+n-f*(cantidad-1)];
    if(procesador==0){
    	for(i=1;i<cantidad;i++){
    	   envio=f*(i-1);
    	   MPI_Send(&envio,1,MPI_INT,i,0,MPI_COMM_WORLD);
    	}
    	for(i=1;i<cantidad;i++){
    	   if(i==cantidad-1){
    	   	MPI_Recv(&rec,f+n-f*(cantidad-1),MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    	   	for(int j=0;j<f+n-f*(cantidad-1);j++){
    	   		printf("%d ",rec[j]);
    	   	}
    	   	printf("\n");
    	   }
    	   else{
    	   	MPI_Recv(&se,f,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    	   	for(int j=0;j<f;j++){
    	   		printf("%d ",se[j]);
    	   	}
    	   }
    	}
    }
    else{
    	MPI_Recv(&envio,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    	float t1,t2;
    	t1=(double)((double)((double)1/(double)pow(5,(double)1/2))*(double)pow(((double)((double)1+(double)pow(5,(double)1/2))/2),envio));
    	t2=(double)((double)((double)1/(double)pow(5,(double)1/2))*(double)pow(((double)((double)1-(double)pow(5,(double)1/2))/2),envio));
    	a=(int)(t1-t2);
    	t1=(double)((double)((double)1/(double)pow(5,(double)1/2))*(double)pow(((double)((double)1+(double)pow(5,(double)1/2))/2),envio+1));
    	t2=(double)((double)((double)1/(double)pow(5,(double)1/2))*(double)pow(((double)((double)1-(double)pow(5,(double)1/2))/2),envio+1));
    	b=(int)(t1-t2);
    	if(procesador==cantidad-1){
	for(int j=0;j<f+n-f*(cantidad-1);j++){
    	   rec[j]=a;
    	   c=b;
    	   b=b+a;
    	   a=c;
    	}
    	MPI_Send(&rec,f+n-f*(cantidad-1),MPI_INT,0,0,MPI_COMM_WORLD);
    	}
    	else{
    	for(int j=0;j<f;j++){
    	   se[j]=a;
    	   c=b;
    	   b=b+a;
    	   a=c;
    	}
    	MPI_Send(&se,f,MPI_INT,0,0,MPI_COMM_WORLD);
    	}
    }
    MPI_Finalize();
}
