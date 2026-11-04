#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(void) {

    int codigo[5];
    char nome[5][15];

    int total = 0;
    int opcao;

    do {

        system("cls");

        printf("----------------------------------\n");
        printf("            CADASTRO              \n");
        printf("----------------------------------\n");

        printf("\n1 - Cadastrar");
        printf("\n2 - Consultar");
        printf("\n3 - Listar");
        printf("\n4 - Alterar");
        printf("\n5 - Excluir");
        printf("\n0 - Sair");

        printf("\n\nEscolha uma opcao:\n--> ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                cadastrar(codigo, nome, &total);
                break;

            case 2:
                consultar(codigo, nome, total);
                break;

            case 3:
                listar(codigo, nome, total);
                break;

            case 4:
                alterar(codigo, nome, total);
                break;

            case 5:
                excluir(codigo, nome, &total);
                break;

            case 0:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n\n");
                system("pause");
        }

    } while (opcao != 0);

    return 0;
}
