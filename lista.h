#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

struct Lista
{
    struct Nodo *cabeza, *cola;
};

//Crear Nodo Nuevo
struct Nodo* crearNodo(int *elemento);

//Operaciones Generales
bool es_Vacia_Lista(struct Lista *lista);
int obtener_Longitud(struct Lista *lista);

//Insertar
void inserta_Principio_Lista(struct Lista *lista,int * elemento);
void inserta_Final_Lista(struct Lista *lista,int * elemento);
void inserta_Posicion_Lista(struct Lista * lista, int *elemento, int *posicion);

//Eliminacion
void eliminar_Principio_Lista(struct Lista *lista);
void eliminar_Final_Lista(struct Lista *lista);
void eliminar_Posicion_Lista(struct Lista *lista, int * posicion);
void eliminar_valor_Lista(struct Lista *lista, int *elemento);

// Busqueda
int obtener_Elemento_En_Posicion(struct Lista *lista,int *elemento);
int obtener_Posicion_Por_Elemento(struct Lista *lista,int *posicion);

// Recorrido
void imprimir_Lista(struct Lista *lista);

//Vaciar Lista
void vaciar_Lista(struct Lista *lista);

// Menús
void menu_Principal(struct Lista *lista);
void menu_Eliminacion(struct Lista *lista);
void menu_Insercion(struct Lista *lista);
void menu_Busqueda(struct Lista *lista);
void menu_OperacionesGenerales(struct Lista *lista);

#endif /*lista.c*/