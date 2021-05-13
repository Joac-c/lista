#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>



/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/


struct lista;

typedef struct lista lista_t;

struct nodo;

typedef struct nodo nodo_t;

struct lista_iter;

typedef struct lista_iter lista_iter_t;


/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

lista_t *lista_crear(void);

bool lista_esta_vacia(const lista_t *lista);

bool lista_insertar_primero(lista_t *lista, void *dato);

bool lista_insertar_ultimo(lista_t *lista, void *dato);

void *lista_borrar_primero(lista_t *lista);

void *lista_ver_primero(const lista_t *lista);

void *lista_ver_ultimo(const lista_t* lista);

size_t lista_largo(const lista_t *lista);

void lista_destruir(lista_t *lista, void (*destruir_dato)(void *));


/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR
 * *****************************************************************/

lista_iter_t *lista_iter_crear(lista_t *lista);

bool lista_iter_avanzar(lista_iter_t *iter);

void *lista_iter_ver_actual(const lista_iter_t *iter);

bool lista_iter_al_final(const lista_iter_t *iter);

void lista_iter_destruir(lista_iter_t *iter);

bool lista_iter_insertar(lista_iter_t *iter, void *dato);

void *lista_iter_borrar(lista_iter_t *iter);

/* *****************************************************************
 *                      PRUEBAS UNITARIAS
 * *****************************************************************/

// Realiza pruebas sobre la implementación realizada.
//
// Las pruebas deben emplazarse en el archivo ‘pruebas_lista.c’, y
// solamente pueden emplear la interfaz pública tal y como aparece en lista.h
// (esto es, las pruebas no pueden acceder a los miembros del struct lista).
//
// Para la implementación de las pruebas se debe emplear la función
// print_test(), como se ha visto en TPs anteriores.

void pruebas_lista_estudiante(void);

#endif  // lISTA_H