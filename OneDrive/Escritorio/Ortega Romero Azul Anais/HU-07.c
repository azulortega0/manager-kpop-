#include <stdio.h>

typedef struct {
    char nombre[30];
    int popularidad;
    int energia;
    int energia_max;
    int fans;
} Idol;

int esta_activa(const Idol *i) {
    if (i->energia > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Idol jennie = {"jennie", 50, 100, 100, 12000};

    printf("Energia: %d -> Estado activa: %d\n", jennie.energia, esta_activa(&jennie));

    jennie.energia = 1;
    printf("Energia: %d -> Estado activa: %d\n", jennie.energia, esta_activa(&jennie));

    jennie.energia = 0;
    printf("Energia: %d -> Estado activa: %d\n", jennie.energia, esta_activa(&jennie));

    return 0;
}