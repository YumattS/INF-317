#include <iostream>
using namespace std;
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
int main(){
    int a=0;
    int c=8;
    int b=2;
    suma(b,c,&a);
    cout << "La multiplicacion de " << c<<" por "<<b<<" es "<<a<<endl;
    a=7;
    int d=a;
    c=0;
    b=4;
    resta(&c,b,&a);
    cout<<"La division de "<<d<<" entre "<<b<<" es "<<c<<" y el resto es "<<a<<endl;
    return 0;
}
