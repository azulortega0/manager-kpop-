#include <stdio.h>
int main(){
	char nombre[100];
  float cal;
  
  
  printf("Nombre completo: ");
  scanf ("%d",&nombre);
  
  
  printf("Tu calificacion de la materia de Programacion es de : ");
  scanf("%f",&cal);
  
  
  if(cal >= 9){
    printf("%s: Exelente\n", nombre);
	  }
	  
	  
	 else if (cal >= 7){
  	printf("%s: Bueno\n", nombre);
	  }
	  
	  
	  else if (cal >= 6){
	  	printf("%s: No aprobado\n", nombre);
	  }
	  
	  
	  else{
	  	printf("%s: Reprobado\n", nombre);
	  }
    
  
  return 0;
}
