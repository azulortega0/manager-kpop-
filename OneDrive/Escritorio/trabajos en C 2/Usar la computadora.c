#include <stdio.h>
int main(){
  int pc,net;
  char usuario[20];
    char password[20];
  
   printf(" Usuario: ");
    scanf("%s", usuario);
    
    
     printf(" Contraseña: ");
    scanf("%s", password);

 if(strcmp(usuario, "blu") == 0 && strcmp(password, "0123") == 0) {

printf("Acceso concedido\n");

  scanf("%d",&pc);
  if(pc==1){
    scanf("%d",&net);
    if(net==1){
      printf("Entrar a clase\n");
    }
  }
  
  }else{
  	printf("Acceso denegado\n");
  }
  return 0;
}
