#include <stdio.h>

int main() {
    int boleto, edad;

    printf("¿Tienes boleto?\n (Si = 1) (No = 2): ");
    scanf("%d", &boleto);

    if (boleto == 1) {
        printf("BIEN\n");

        printf("Ingresa tu edad: ");
        scanf("%d", &edad);

        if (edad >= 18) {
            printf("Bienvenido, puedes entrar al cine\n");
        } else {
            printf("No puedes pasar\n");
        }

    } else if (boleto == 2) {
        printf("Debes comprar el boleto para continuar\n");
    } else {
        printf("Opcion invalida\n");
    }

    return 0;
}
