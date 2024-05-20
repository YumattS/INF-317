#include <stdio.h>
void suma(int b,int c,int *a){
  if(b!=0){
  	*a=*a+c;
 	suma(b-1,c,a);
  }
}
void resta(int *c,int b,int *a){
  if(!(*a<b)){
  	*c=*c+1;
  	*a=*a-b;
  	resta(c,b,a);
  }
}
void main(){
  int a,c,b,d;
  a=0;
  c=8;
  b=2;
  suma(b,c,&a);
  printf("multiplicacion de %d por %d es %d\n",b,c,a);
  a=7;
  d=a;
  c=0;
  b=4;
  resta(&c,b,&a);
  printf("Division de %d entre %d es %d el resto es %d\n",d,b,c,a);
  
}
