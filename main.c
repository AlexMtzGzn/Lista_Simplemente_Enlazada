#include "lista.h"
#include <stdlib.h>

int main(void)
{
    struct Lista *lista = malloc(sizeof(struct Lista));

    if (lista == NULL)
        return -1;

    lista->cabeza = NULL;

    if (lista->cabeza != NULL)
    {
        free(lista);
        return -1;
    }

    menu_Principal(lista);
    free(lista);
    
    return 0;
}