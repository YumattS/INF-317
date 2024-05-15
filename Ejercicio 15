#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
	#pragma omp parallel
	{
		if(omp_get_thread_num()==0){
			printf("Hola mundo\n");
		}
	}
}
