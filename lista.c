#include <lista.h>


typedef struct nodo
{
    void* dato;
    struct nodo* prox;
}nodo_t;

typedef struct lista{
    nodo_t* prim;
    nodo_t* ult;
    size_t cant;
}lista_t;


nodo_t* nodo_crear(void* elem){
    nodo_t* nodo = calloc(1, sizeof(nodo_t));
    if(!nodo) return NULL;
    nodo->dato = elem;
    return nodo;
}

lista_t *lista_crear(void){
    lista_t* lista = calloc(1, sizeof(lista_t));
    if(!lista) return NULL;
    return lista;
}



void destruir_nodo_recursivo(nodo_t* nodo, void (*destruir_dato)(void *)){
    if(!nodo) return;
    destruir_nodo_recursivo(nodo->prox, destruir_dato);
    if(destruir_dato) destruir_dato(nodo->dato);
    free(nodo);
    return;
} 

void lista_destruir(lista_t *lista, void (*destruir_dato)(void *)){
    if(!lista) return;
    if(lista->prim) destruir_nodo_recursivo(lista->prim, destruir_dato);
    free(lista);



}

bool lista_esta_vacia(const lista_t *lista){
    if(!lista || !lista->prim || lista->cant == 0) return true;
    return false;
}


bool lista_insertar_primero(lista_t *lista, void *dato){
    if(!lista) return false;
    nodo_t* nodo = nodo_crear(dato);
    if(!nodo) return false;
    nodo->prox = lista->prim;
    if(lista->cant == 0) lista->ult = nodo;
    lista->prim = nodo;
    lista->cant++;
}



bool lista_insertar_ultimo(lista_t *lista, void *dato){
    if(!lista) return false;
    nodo_t* nodo = nodo_crear(dato);
    if(!nodo) return false;
    if(!lista->prim) lista->prim = nodo;
    if(lista->ult) lista->ult->prox = nodo;
    lista->ult = nodo;
    lista->cant++;
    return true;
}



void *lista_borrar_primero(lista_t *lista){
    if(lista_esta_vacia(lista)) return NULL;
    void* elem = lista->prim->dato;
    nodo_t* nodo = lista->prim;
    lista->prim = nodo->prox;
    if(lista->ult == nodo) lista->ult = NULL;
    free(nodo);
    lista->cant--;
    return elem;
}




void *lista_ver_primero(const lista_t *lista){
    if(lista_esta_vacia(lista)) return NULL;
    return lista->prim->dato;
}

void *lista_ver_ultimo(const lista_t* lista){
    if(lista_esta_vacia(lista)) return NULL;
    return lista->ult->dato;
}



size_t lista_largo(const lista_t *lista){
    if(!lista || !lista->prim || lista->cant == 0) return 0;
    return lista->cant;
}







