#include <stdio.h>
#include <stdlib.h>
#include "Estructuras.h"
#include "Funciones.h"




int main() {
    Nodo* Lista;
    int Seleccion, * PS;

    Lista = NULL;
    PS = &Seleccion;

    do {
        Menu(PS);
        switch (*PS) {
        case 0: Salida(PS, Lista); break;
        case 1: Lista = Crea_Nodo(Lista, NULL); break;
        case 2: Lista = Baja(Lista); break;
        case 3: Busca_Alumno(Lista); break;
        case 4: Imprime_Lista(Lista); break;
        case 5: Lista = Borra_Lista(Lista); break;
        case 6: Guardar(Lista); break;
        case 7: Guardar_Como(Lista); break;
        case 8: Lista = Abrir(Lista); break;
        default: printf("\n-----------------------\nOpcion fuera de rango\n"); break;
        }

    } while (*PS != 0);

    return 0;
}