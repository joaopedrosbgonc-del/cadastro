#include <stdio.h>
#include "funcs.h"

int main(){
    int r;
    do {
        titulo();
        scanf(" %d", &r);
        while (getchar() != '\n');

        switch (r)
        {
        case 1:
            cadastro();
            break;

        case 2:
            consulta();
            break;

        case 3:
            listar();
            break;

        case 4:
            editar();
            break;
        
        case 5:
            excluir();
            break;
        default:
            printf("FIM");
            break;
        }
    } while(r != 0);
}