#include <stdio.h>

typedef struct {
    char nombre[30];
    int popularidad;
    int energia;
    int energia_max;
    int fans;
} Idol;

void modificar_por_valor(Idol i) {
    i.popularidad = i.popularidad + 50;
    printf("  [Dentro de modificar_por_valor] Popularidad = %d\n", i.popularidad);
}

void modificar_por_apuntador(Idol *i) {
    i->popularidad = i->popularidad + 50;
    printf("  [Dentro de modificar_por_apuntador] Popularidad = %d\n", i->popularidad);
}

int main() {
    Idol jennie = {"jennie", 50, 100, 100, 12000};

    printf("Popularidad inicial: %d\n\n", jennie.popularidad);

    printf("1. Probando paso por valor:\n");
    modificar_por_valor(jennie);
    printf("  [En main despues del llamado] Popularidad = %d (NO cambio)\n\n", jennie.popularidad);

    printf("2. Probando paso por apuntador:\n");
    modificar_por_apuntador(&jennie);
    printf("  [En main despues del llamado] Popularidad = %d (SI cambio)\n", jennie.popularidad);

    return 0;
}