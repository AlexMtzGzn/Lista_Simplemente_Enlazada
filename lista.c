#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct Nodo *crearNodo(int *elemento)
{
    struct Nodo *nodoNuevo = malloc(sizeof(struct Nodo));
    if (nodoNuevo == NULL)
        return nodoNuevo;

    nodoNuevo->dato = *elemento;
    nodoNuevo->siguiente = NULL;

    return nodoNuevo;
}

bool es_Vacia_Lista(struct Lista *lista)
{
    return lista->cabeza == NULL;
}

int obtener_Longitud(struct Lista *lista)
{
    if (es_Vacia_Lista(lista))
    
        return -1;
    
    else
    {
        struct Nodo *nodoActual = lista->cabeza;
        int longitud = 0;

        while (nodoActual != NULL)
        {
            nodoActual = nodoActual->siguiente;
            longitud++;
        }

        return longitud;
    }
}

void inserta_Principio_Lista(struct Lista *lista, int *elemento)
{

    struct Nodo *nodoNuevo = crearNodo(elemento);

    if (nodoNuevo != NULL)
    {
        if (es_Vacia_Lista(lista))
        
            lista->cabeza = lista->cola = nodoNuevo;
        
        else
        {
            nodoNuevo->siguiente = lista->cabeza;
            lista->cabeza = nodoNuevo;
        }
    }
    else
    
        printf("\nError al asignar memoria al nodo.");
    
}

void inserta_Final_Lista(struct Lista *lista, int *elemento)
{
    struct Nodo *nodoNuevo = crearNodo(elemento);

    if (nodoNuevo != NULL)
    {
        if (es_Vacia_Lista(lista))
        
            lista->cabeza = lista->cola = nodoNuevo;
        
        else
        {
            lista->cola->siguiente = nodoNuevo;
            lista->cola = nodoNuevo;
        }
    }
    else
    
        printf("\nError al asignar memoria al nodo.");
    
}

void inserta_Posicion_Lista(struct Lista *lista, int *elemento, int *posicion)
{
    struct Nodo *nodoNuevo = crearNodo(elemento);

    if (nodoNuevo != NULL)
    {
        if (es_Vacia_Lista(lista))
        
            lista->cabeza = lista->cola = nodoNuevo;
        
        else
        {
            struct Nodo *nodoActual = lista->cabeza, *nodoAnterior = NULL;
            int contador = 0;

            while (nodoActual != NULL && contador < *posicion)
            {
                nodoAnterior = nodoActual;
                nodoActual = nodoActual->siguiente;
                contador++;
            }

            if (contador == *posicion)
            {
                nodoNuevo->siguiente = nodoActual;

                if (nodoAnterior != NULL)
                
                    nodoAnterior->siguiente = nodoNuevo;
                
                else
                
                    lista->cabeza = nodoNuevo;
                

                if (nodoActual == NULL)
                
                    lista->cola = nodoNuevo;
                
            }
            else
            {
                printf("Posición fuera de rango. No se pudo insertar.\n");
                free(nodoNuevo);
            }
        }
    }
    else
        printf("Error al asignar memoria al nodo.\n");
}

void eliminar_Principio_Lista(struct Lista *lista)
{
    if (!es_Vacia_Lista(lista))
    {

        struct Nodo *nodoEliminar = lista->cabeza;
        lista->cabeza = nodoEliminar->siguiente;
        free(nodoEliminar);

        if(obtener_Longitud(lista) == 1)
            lista->cola = lista->cabeza;
        if(es_Vacia_Lista(lista))
            lista->cabeza = lista->cola = NULL;
    }
}

void eliminar_Final_Lista(struct Lista *lista)
{
    if (!es_Vacia_Lista(lista))
    {
        struct Nodo *nodoActual = lista->cabeza, *nodoAnterior = NULL;

        while (nodoActual->siguiente != NULL)
        {
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->siguiente;
        }
        if (nodoAnterior == NULL)
        {
            lista->cabeza = lista->cola = NULL;
        }
        else
        {
            nodoAnterior->siguiente = NULL;
            lista->cola = nodoAnterior;
        }

        free(nodoActual);
    }
}

void eliminar_Posicion_Lista(struct Lista *lista, int *posicion)
{
    if (!es_Vacia_Lista(lista) && *posicion < obtener_Longitud(lista))
    {
        int contador = 0;
        struct Nodo *nodoActual = lista->cabeza, *nodoAnterior = NULL;

        // Avanzar hasta la posición a eliminar
        while (nodoActual != NULL && contador != *posicion)
        {
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->siguiente;
            contador++;
        }

        if (contador == *posicion)
        {
            if (nodoAnterior == NULL) 
            {
                lista->cabeza = nodoActual->siguiente;
                free(nodoActual);

                if (lista->cabeza == NULL) {
                    lista->cola = NULL;
                }
            }
            else
            {
                nodoAnterior->siguiente = nodoActual->siguiente;
                free(nodoActual);

                if (nodoActual->siguiente == NULL)
                
                    lista->cola = nodoAnterior;
                
            }
        }
    }
}

void eliminar_valor_Lista(struct Lista *lista, int *elemento)
{

    if (!es_Vacia_Lista(lista))
    {

        struct Nodo *nodoActual = lista->cabeza, *nodoAnterior = NULL;

        while (nodoActual != NULL)
        {
            if (*elemento == nodoActual->dato)
            {
                if (nodoAnterior == NULL)
                {
                    lista->cabeza = nodoActual->siguiente;
                    free(nodoActual);
                    nodoActual = lista->cabeza;
                }
                else
                {
                    nodoAnterior->siguiente = nodoActual->siguiente;
                    free(nodoActual);
                    nodoActual = nodoAnterior->siguiente;
                }
            }
            else
            {
                nodoAnterior = nodoActual;
                nodoActual = nodoActual->siguiente;
            }
        }
    }
}

int obtener_Elemento_En_Posicion(struct Lista *lista, int *elemento)
{
    if (es_Vacia_Lista(lista))
    
        return -1;
    
    else
    {
        struct Nodo *nodoActual = lista->cabeza;
        int posicion = 0;
        while (nodoActual != NULL)
        {
            if (nodoActual->dato == *elemento)
                return posicion;

            posicion++;
            nodoActual = nodoActual->siguiente;
        }
        return -1;
    }
}

int obtener_Posicion_Por_Elemento(struct Lista *lista, int *posicion)
{
    if (es_Vacia_Lista(lista) || *posicion < 0)
    
        return -1;
    
    else
    {
        struct Nodo *nodoActual = lista->cabeza;
        int contador = 0;

        while (nodoActual != NULL)
        {
            if (contador == *posicion)

                return nodoActual->dato;
            
            contador++;
            nodoActual = nodoActual->siguiente;
        }

        return -1;
    }
}

void imprimir_Lista(struct Lista *lista)
{
    if (es_Vacia_Lista(lista))
    
        printf("\nLa lista está vacía.\n");
    
    else
    {
        struct Nodo *nodoActual = lista->cabeza;

        printf("\nLista: ");

        while (nodoActual != NULL)
        {
            printf("%i", nodoActual->dato);

            if (nodoActual->siguiente != NULL)
                printf(" - ");

            nodoActual = nodoActual->siguiente;
        }

        printf("\n");
    }
}

void vaciar_Lista(struct Lista *lista)
{
    if (!es_Vacia_Lista(lista))
    {
        while (lista->cabeza != NULL)
            eliminar_Principio_Lista(lista);
        lista->cabeza = NULL;
    }
}

void menu_Insercion(struct Lista *lista)
{
    int opcion, elemento, posicion;
    do
    {

        printf("\n\nInserción.");
        printf("\n1- Agregar un elemento al principio de la lista.");
        printf("\n2- Agregar un elemento al final de la lista.");
        printf("\n3- Agregar un elemento en una posición determinada de la lista.");
        printf("\n4- Atrás.");
        printf("\nSelecciona opción: ");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:

            printf("Ingresa el elemento: ");
            scanf("%i", &elemento);
            inserta_Principio_Lista(lista, &elemento);
            imprimir_Lista(lista);
            break;
        case 2:

            printf("Ingresa el elemento: ");
            scanf("%i", &elemento);
            inserta_Final_Lista(lista, &elemento);
            imprimir_Lista(lista);
            break;
        case 3:

            printf("Ingresa el elemento: ");
            scanf("%i", &elemento);
            printf("Ingresa la posición: ");
            scanf("%i", &posicion);
            inserta_Posicion_Lista(lista, &elemento, &posicion);
            imprimir_Lista(lista);
            break;
        default:
            printf("\nOpción no válida\n");
            break;
        }

    } while (opcion != 4);
}

void menu_Eliminacion(struct Lista *lista)
{
    int opcion, elemento, posicion;
    do
    {

        printf("\n\nEliminación.");
        printf("\n1- Elimina el primer elemento de la lista.");
        printf("\n2- Elimina el último elemento de la lista.");
        printf("\n3- Elimina un elemento en una posición específica de la lista.");
        printf("\n4- Elimina todos los nodos que contienen un valor específico.");
        printf("\n5- Atrás.");
        printf("\nSelecciona opción: ");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:

            eliminar_Principio_Lista(lista);
            imprimir_Lista(lista);
            break;
        case 2:

            eliminar_Final_Lista(lista);
            imprimir_Lista(lista);
            break;
        case 3:

            printf("\nIngresa la posición: ");
            scanf("%i", &posicion);
            eliminar_Posicion_Lista(lista, &posicion);
            imprimir_Lista(lista);
            break;
        case 4:

            printf("\nIngresa el elemento: ");
            scanf("%i", &elemento);
            eliminar_valor_Lista(lista, &elemento);
            imprimir_Lista(lista);
            break;
        default:
            printf("\nOpción no válida\n");
            break;
        }

    } while (opcion != 5);
}

void menu_Busqueda(struct Lista *lista)
{
    int opcion, elemento, posicion;
    do
    {

        printf("\n\nBúsqueda.");
        printf("\n1- Busca un elemento en la lista y devuelve su posición.");
        printf("\n2- Devuelve el elemento en una posición específica de la lista.");
        printf("\n3- Atrás.");
        printf("\nSelecciona opción: ");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:

            printf("Ingresa el elemento: ");
            scanf("%i", &elemento);
            printf("\nPosición: %i", obtener_Elemento_En_Posicion(lista, &elemento));
            imprimir_Lista(lista);
            break;
        case 2:

            printf("Ingresa la posición: ");
            scanf("%i", &posicion);
            printf("\nElemento en la posición %i: %i", posicion, obtener_Posicion_Por_Elemento(lista, &posicion));
            imprimir_Lista(lista);
            break;
        default:
            printf("\nOpción no válida\n");
            break;
        }

    } while (opcion != 3);
}

void menu_Operaciones_Generales(struct Lista *lista)
{
    int opcion;
    do
    {

        printf("\n\nOperaciones Generales.");
        printf("\n1- Verifica si la lista está vacía.");
        printf("\n2- Devuelve la cantidad de elementos en la lista.");
        printf("\n3- Atrás.");
        printf("\nSelecciona opción: ");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:

            if (es_Vacia_Lista(lista))
                printf("\nLa lista está vacía.\n");
            else
                printf("\nLa lista no está vacía.\n");
            break;
        case 2:
            printf("\nLongitud de la lista: %i", obtener_Longitud(lista));
            imprimir_Lista(lista);
            break;
        default:
            printf("\nOpción no válida\n");
            break;
        }

    } while (opcion != 3);
}

void menu_Principal(struct Lista *lista)
{
    int opcion;
    do
    {
        printf("\n\nLISTAS");
        printf("\n1- Inserción.");
        printf("\n2- Eliminación.");
        printf("\n3- Búsqueda.");
        printf("\n4- Operaciones Generales.");
        printf("\n5- Imprimir Lista.");
        printf("\n6- Vaciar Lista");
        printf("\n7- Salir.");
        printf("\nSelecciona opción: ");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:
            menu_Insercion(lista);
            break;
        case 2:
            menu_Eliminacion(lista);
            break;
        case 3:
            menu_Busqueda(lista);
            break;
        case 4:
            menu_Operaciones_Generales(lista);
            break;
        case 5:
            imprimir_Lista(lista);
            break;
        case 6:
            vaciar_Lista(lista);
            imprimir_Lista(lista);
            break;
        default:
            printf("\nOpción no válida\n");
            break;
        }

    } while (opcion != 7);
}
