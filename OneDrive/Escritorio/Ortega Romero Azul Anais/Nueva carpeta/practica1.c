#include <stdio.h>
int validarEvento(int tipo, int totalTipos) {
    if (tipo >= 0 && tipo < totalTipos) {
        return tipo; // devuelve el mismo tipo si es valido
    }
    return -1;
}
    void sumarUnEvento(int *contador) {
        if (contador != NULL) {
            *contador = *contador + 1; // Incrementa el valor en memoria
        }
    }
int main() {
    const int EQUIPOS = 4;
    const int EVENTOS = 10;
    const int TIPOS = 4;
    const int UMBRAL = 3; // Valor de X = 3

    int arregloEquipos[10] = {0, 1, 0, 1, 1, 2, 3, 3, 1, 3};
    int arregloEventos[10] = {0, 1, 0, 1, 2, 0, 2, 2, 1, 2};
    int matriz[4][4];

for (int i = 0; i < EQUIPOS; i++) {
    for (int j = 0; j < TIPOS; j++) {
        matriz[i][j] = 0;
    }
}
int *ptrEq = arregloEquipos;
    int *ptrEv = arregloEventos;

    for (int i = 0; i < EVENTOS; i++) {
        int eq = *(ptrEq + i); // Aritmetica de punteros
        int ev = *(ptrEv + i);

        int tipoValido = validarEvento(ev, TIPOS); 
        if (eq >= 0 && eq < EQUIPOS && tipoValido != -1) {
            sumarUnEvento(&matriz[eq][tipoValido]);
        }
    }

    printf("--- LOG DE EVENTOS ---\n");

    for (int i = 0; i < EVENTOS; i++) {
        printf("Evento %d: Equipo PC-0%d, Tipo de evento: %d\n", i + 1, arregloEquipos[i] + 1, arregloEventos[i]);
    }
    
    printf("\n");
    printf("--- RESUMEN POR EQUIPO ---\n");
    printf("Equipo | Acc.Correcto|Cont.Inco|Usr.NoExis.|Bloqueados|Total Fallos| Estado\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < EQUIPOS; i++) {
        int ok = matriz[i][0];
        int passErr = matriz[i][1];
        int usrErr = matriz[i][2];
        int bloq = matriz[i][3];
        int intentosFallidos = passErr + usrErr;

        printf("PC-0%d   | %d         | %d        | %d       | %d         | %d           | ", 
            i + 1, ok, passErr, usrErr, bloq, intentosFallidos);
            if (intentosFallidos > UMBRAL) {
            printf("SOSPECHOSO\n");
        } else {
            printf("NORMAL\n");
        }
    }

    return 0;
}
