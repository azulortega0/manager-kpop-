#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[50];
    int bonus;
    int vigencia;
} Cancion;

typedef struct {
    char nombre[50];
    int popularidad;
    int energia;
    Cancion *cancion;
} Idol;

typedef struct {
    char nombre[50];
    Idol miembros[4];
    int n;
    Idol *lider;
} Grupo;

void mostrar(const Idol *i) {
    if (i == NULL) return;
    printf("Idol: %s | Pop: %d | Energía: %d\n", i->nombre, i->popularidad, i->energia);
}

int esta_activa(const Idol *i) {
    if (i == NULL) return 0;
    return i->energia > 0;
}

void descansar(Idol *i) {
    if (i == NULL) return;
    i->energia += 20;
}

int popularidad_total(const Idol *i) {
    if (i == NULL) return 0;
    if (i->cancion != NULL && i->cancion->vigencia > 0) {
        return i->popularidad + i->cancion->bonus;
    }
    return i->popularidad;
}

int cambiar_lider(Grupo *g, Idol *nueva) {
    if (g == NULL || nueva == NULL) return 0;
    
    Idol *p = g->miembros;
    Idol *fin = g->miembros + g->n;
    
    while (p < fin) {
        if (p == nueva) {
            g->lider = nueva;
            return 1;
        }
        p++;
    }
    return 0;
}

void mostrar_grupo(const Grupo *g) {
    if (g == NULL) return;
    printf("--- Grupo: %s ---\n", g->nombre);
    
    const Idol *p = g->miembros;
    const Idol *fin = g->miembros + g->n;
    
    while (p < fin) {
        mostrar(p);
        p++;
    }
}

int contar_activas(const Grupo *g) {
    if (g == NULL || g->n == 0) return 0;
    
    int activas = 0;
    const Idol *p = g->miembros;
    const Idol *fin = g->miembros + g->n;
    
    while (p < fin) {
        if (esta_activa(p)) {
            activas++;
        }
        p++;
    }
    return activas;
}

Idol* idol_mas_cansada(Grupo *g) {
    if (g == NULL || g->n == 0) return NULL;
    
    Idol *cansada = g->miembros;
    Idol *p = g->miembros + 1;
    Idol *fin = g->miembros + g->n;
    
    while (p < fin) {
        if (p->energia < cansada->energia) {
            cansada = p;
        }
        p++;
    }
    return cansada;
}

int main() {
    Cancion c1 = {"Super Shy", 15, 1};

    Grupo lumina = {
        "Lumina",
        {
            {"Minji", 80, 40, &c1},
            {"Hanni", 85, 10, &c1},
            {"Danielle", 90, 0, NULL}
        },
        3,
        NULL
    };

    mostrar_grupo(&lumina);

    printf("\nPop total de Minji: %d\n", popularidad_total(&lumina.miembros[0]));

    printf("Activas: %d\n", contar_activas(&lumina));

    if (cambiar_lider(&lumina, &lumina.miembros[0])) {
        printf("\nSe cambió de líder.\n");
    }

    Idol *p_cansada = idol_mas_cansada(&lumina);
    if (p_cansada != NULL) {
        printf("\nLa más cansada es: %s\n", p_cansada->nombre);
        descansar(p_cansada);
        printf("Energía después de descansar: %d\n", p_cansada->energia);
    }

    return 0;
}