#include <stdio.h>
int main(){
  int salir,lluvia, clima;
  
  printf("¿Vas a salir? (1=si, 0=no): ");
  scanf("%d",&salir);
  
  
  if(salir == 1){
  	printf("¿Esta lloviendo? (1=si, 0=no):");
    scanf("%d",&lluvia);
    
    
    if(lluvia == 1){
      printf("Lleva paraguas\n");
    }
    
    printf("¿Hace frio? (1=si, 0=no):");
    scanf("%d", &clima);
    
    
     if (clima == 1) {     	
     	printf("Lleva chamarra\n");     	
	 }
	 else{
            printf("No necesitas chamarra\n");
        }
	 	 
  }
  else{
        printf("No salgas, quedate en casa\n");
    }
    
  return 0;
}
