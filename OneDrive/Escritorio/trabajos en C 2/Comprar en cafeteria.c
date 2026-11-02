#include <stdio.h>
int main(){
 float dinero; int abierta, opcion;
 
 
	printf("---- MENU ----\n");
    printf("1. Verificar compra\n");
    printf("2. Salir\n");
    printf("Elige una opcion: ");
	scanf("%d",&opcion);
 
 	if (opcion == 1){
 		printf("¿Tienes dinero Sofia?");
 		 scanf("%f", &dinero);
 		 if(dinero>=50) {
 		 	printf("La tienda esta abierta? (1=si, 0=no): ");
 		 	scanf("%d", &abierta);
 		 	
 		 	
 		 	if(abierta == 1) {
                printf("Puedes comprar\n");
            } 
 		 	else {
                printf("La tienda esta cerrada\n");
            }
 		 	} else {
            printf("No tienes suficiente dinero\n");
        }
} else if(opcion == 2) {
        printf("Adios\n");
    } else {
        printf("Opcion invalida\n");
    }
 
  return 0;
  }

