#include <stdio.h>
int main(){
	int lluvia, viento;
	printf ("¿llueve? (1=si,0=no):");
	scanf("%d", &lluvia);
	if (lluvia==1){
		printf("Lleva paraguas \n");
	}
	if (lluvia==0){
		printf("No lleves nada \n");
	}
	
	printf ("¿Hace viento? (2=si,4=no):");
	scanf ("%d",&viento);
	if(viento==2){
		printf("Llevate sueter \n");
	}
	if (viento==4){
		printf("ponte playera delgada \n");
	}
	return 0;
}

