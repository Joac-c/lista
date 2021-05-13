#include "lista.h"
#include "testing.h"
#include "stdlib.h"
#include "stdio.h"

#define ITERACIONES 20


static int valores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

static void prueba_lista_vacia(void) {
    printf("\nPruebas de la lista vacia\n\n");
    lista_t *lista = lista_crear();
    print_test("La lista se crea vacia", lista_esta_vacia(lista) == true );
    print_test("El primero de una lista vacia es nulo", lista_ver_primero(lista) == NULL);
    print_test("Borrar un elemento de la lista vacia devuelve NULL", lista_borrar_primero(lista) == NULL);
    lista_destruir(lista, NULL);
}


void insertar_varios(void* tda, bool funcion(lista_t*, void*), char* mensaje, int direccion){
    int acciones = 2;
    bool seguimos = true;

    while (acciones < ITERACIONES && seguimos == true)
    {
        if(funcion(tda, &valores[acciones]) == true) acciones++;
        else seguimos = false;
    
    }
    print_test(mensaje,  (ITERACIONES == acciones));
    printf("Acciones totales = %d\n",  acciones);
    
}



void prueba_insertar_elementos(void){
    printf("\nPruebas de enlistar\n\n");
    lista_t *lista = lista_crear();
    print_test("encolo un elemento", lista_insertar_ultimo(lista, &valores[0]) == true);
    print_test("El elemento enlistado es el primero", lista_ver_primero(lista) == &valores[0]);
    print_test("encolo otro elemento", lista_insertar_ultimo(lista, &valores[1]) == true);
    print_test("El primer elemento enlistado sigue siendo el primero", lista_ver_primero(lista) == &valores[0]);
    insertar_varios(lista, lista_insertar_ultimo, "Se insertaron varios elementos exitosamente", 1);
    lista_destruir(lista, NULL);

}

void borrar_varios(void* tda, void* funcion(lista_t*), char* mensaje, int direccion){
    int acciones = 2;
    bool seguimos = true;

    while (acciones < ITERACIONES - 1 && seguimos == true)
    {
        if(funcion(tda) == &valores[acciones]) acciones++;
        else seguimos = false;
    
    }
    print_test(mensaje,  (ITERACIONES -1  == acciones));
    printf("Acciones totales = %d\n",  acciones);
    
}


void prueba_borrar_elementos(void){
    printf("\nPruebas de insertar\n\n");
    lista_t *lista = lista_crear();
    lista_insertar_ultimo(lista, &valores[0]);
    lista_insertar_ultimo(lista, &valores[1]);
    insertar_varios(lista, lista_insertar_ultimo, "Se insertaron varios elementos exitosamente", 1);
    print_test("Se borro un elemento exitosamente y es correcto", lista_borrar_primero(lista) == &valores[0]);
    print_test("Se borro otro elemento exitosamente y es correcto", lista_borrar_primero(lista) == &valores[1]);
    borrar_varios(lista, lista_borrar_primero, "se desenlistan varios elementos y los primeros son correctos", 1);
    print_test("Se borro el ultimo elemento exitosamente", lista_borrar_primero(lista) == &valores[19]);
    print_test("bolista_borrar_primero con la lista vacia devuelve NULL", lista_borrar_primero(lista) == NULL);
    insertar_varios(lista, lista_insertar_ultimo, "enlistar varios elementos funciona bien despues de usar insertar", 1);
    lista_destruir(lista, NULL);
}


void pruebas_lista_estudiante() {
    prueba_lista_vacia();
    prueba_insertar_elementos();
    prueba_borrar_elementos();
    // ...
}

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_lista_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
