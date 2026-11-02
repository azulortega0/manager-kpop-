#include <stdio.h>
int main(){
  int temp, acondicionado;
  printf("Ingrese la temperatura: ");
  scanf("%d",&temp);
  
  if(temp > 28){
    printf("Encender ventilador\n");
	}
	
  else if(temp < 28){
    	printf("Encender aire acondicionado");
	}
	else{
		("No es necesario prender nada ");
		}
  
  return 0;
}
