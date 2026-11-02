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

void ensayar(Idol *i) {
    i->popularidad = i->popularidad + 5;   
    i->energia = limitar(i->energia - 20, 0, i->energia_max);
}

int main() {
    int j;
    Idol jennie = {"jennie", 50, 100, 100, 12000};

    printf("Popularidad inicial: %d, Energia inicial: %d\n", jennie.popularidad, jennie.energia);

    for (j = 0; j < 20; j++) {
        ensayar(&jennie);
    }

    printf("Despues de 20 ensayos -> Popularidad: %d, Energia: %d\n", jennie.popularidad, jennie.energia);

    return 0;
}