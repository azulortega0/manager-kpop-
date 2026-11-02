#include <stdio.h>
int main(){
  float saldo; int activa;
  
  float costo=10.0;

  scanf("%f",&saldo);
  
  
  if(saldo>=costo){
    scanf("%d",&activa);
    
    
    if(activa==1){
    	saldo=saldo - costo;
      printf("Puede viajar\n");
      printf("Saldo restante:%.2f", saldo);
    }
    
	} else{
		printf("Saldo insuficiente");
	}
  return 0;
}
