#include <stdio.h>

int main() {
    float compra, descuento = 0, total;

    printf("Ingrese el monto de la compra: ");
    scanf("%f", &compra);

    if (compra > 500) {
        descuento = compra * 0.10;
    }

    total = compra - descuento;

    printf("Total a pagar: %.2f\n", total);

    return 0;
}
