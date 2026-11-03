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
    if (i->energia > 100) i->energia = 100;
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

void dar_concierto(Grupo *g) {
    if (g == NULL) return;
    Idol *p = g->miembros;
    Idol *fin = g->miembros + g->n;
    
    while (p < fin) {
        if (esta_activa(p)) {
            p->popularidad += popularidad_total(p) / 10;
            p->energia -= 15;
            if (p->energia < 0) p->energia = 0;
            
            if (p->cancion != NULL && p->cancion->vigencia > 0) {
                p->cancion->vigencia--;
                if (p->cancion->vigencia == 0) {
                    printf("La cancion '%s' ya no esta vigente.\n", p->cancion->titulo);
                }
            }
        }
        p++;
    }
}

void mostrar_cancion_lider(const Grupo *g) {
    if (g == NULL) {
        printf("No hay grupo registrado.\n");
        return;
    }
    if (g->lider == NULL) {
        printf("El grupo no tiene una lider asignada.\n");
        return;
    }
    if (g->lider->cancion == NULL) {
        printf("La lider %s no tiene una cancion asignada.\n", g->lider->nombre);
        return;
    }
    printf("Cancion de la lider (%s): %s\n", g->lider->nombre, g->lider->cancion->titulo);
}

void preparar_presentacion(Grupo *g) {
    if (g == NULL) return;
    
    Idol *cansada = idol_mas_cansada(g);
    if (cansada != NULL) {
        descansar(cansada);
    }
    
    dar_concierto(g);
    
    printf("\n=== RESUMEN DE PRESENTACION ===\n");
    mostrar_grupo(g);
    printf("Integrantes activas: %d\n", contar_activas(g));
    mostrar_cancion_lider(g);
    printf("===============================\n");
}

int main() {
    Cancion c1 = {"Super Shy", 15, 2};

    Grupo lumina = {
        "Lumina",
        {
            {"Minji", 80, 40, &c1},
            {"Hanni", 85, 20, &c1},
            {"Danielle", 90, 10, NULL}
        },
        3,
        NULL
    };

    cambiar_lider(&lumina, &lumina.miembros[0]);

    printf("Demostracion de apuntadores HU-22:\n");
    printf("&miembros[0] = %p | miembros + 0 = %p\n", (void*)&lumina.miembros[0], (void*)(lumina.miembros));

    preparar_presentacion(&lumina);

    return 0;
}