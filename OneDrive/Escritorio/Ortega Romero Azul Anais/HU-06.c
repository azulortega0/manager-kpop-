#include <stdio.h>

typedef struct {
    char nombre[30];
    int popularidad;
    int energia;
    int energia_max;
    int fans;
} Idol;

int limitar(int valor, int min, int max) {
    if (valor < min) return min;
    if (valor > max) return max;
    return valor;
}

void descansar(Idol *i) {
    i->energia = limitar(i->energia + 30, 0, i->energia_max);
}

int main() {
    int j;
    Idol jennie = {"jennie", 50, 0, 100, 12000};

    printf("Energia inicial: %d (Max: %d)\n", jennie.energia, jennie.energia_max);

    for (j = 0; j < 20; j++) {
        descansar(&jennie);
    }

    printf("Energia despues de descansar 20 veces: %d\n", jennie.energia);

    return 0;
}