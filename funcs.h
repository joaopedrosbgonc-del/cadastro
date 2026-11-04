
#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1 - CADASTRAR
void cadastrar(int codigo[], char nome[][15], int *total) {

    system("cls");
    printf("        CADASTRAR\n");

    if (*total == 5) {
        printf("\nCadastro cheio!\n\n");
        system("pause");
        return;
    }

    printf("\nQual o codigo?\n--> ");
    scanf("%d", &codigo[*total]);
    getchar();

    printf("\nQual o nome?\n--> ");
    fgets(nome[*total], 15, stdin);
    nome[*total][strcspn(nome[*total], "\n")] = '\0';

    (*total)++;

    printf("\nCadastro realizado com sucesso!\n\n");
    system("pause");
}

// 2 - CONSULTAR
void consultar(int codigo[], char nome[][15], int total) {

    int busca, encontrado = 0;

    system("cls");
    printf("        CONSULTAR\n");

    printf("\nQual o codigo?\n--> ");
    scanf("%d", &busca);

    for (int i = 0; i < total; i++) {

        if (codigo[i] == busca) {
            printf("\nCodigo: %d\n", codigo[i]);
            printf("Nome: %s\n\n", nome[i]);

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("\nCodigo nao encontrado!\n\n");
    }

    system("pause");
}

// 3 - LISTAR
void listar(int codigo[], char nome[][15], int total) {

    system("cls");
    printf("        REGISTROS CADASTRADOS\n\n");

    if (total == 0) {
        printf("Nenhum registro cadastrado.\n");
    }

    for (int i = 0; i < total; i++) {
        printf("%d | %s\n", codigo[i], nome[i]);
    }

    printf("\n");
    system("pause");
}

// 4 - ALTERAR
void alterar(int codigo[], char nome[][15], int total) {

    int busca, encontrado = 0;

    system("cls");
    printf("        ALTERAR\n");

    printf("\nQual o codigo que deseja alterar?\n--> ");
    scanf("%d", &busca);
    getchar();

    for (int i = 0; i < total; i++) {

        if (codigo[i] == busca) {

            printf("\nRegistro atual: %d | %s\n\n", codigo[i], nome[i]);

            printf("Qual o novo codigo?\n--> ");
            scanf("%d", &codigo[i]);
            getchar();

            printf("\nQual o novo nome?\n--> ");
            fgets(nome[i], 15, stdin);
            nome[i][strcspn(nome[i], "\n")] = '\0';

            printf("\nRegistro alterado com sucesso!\n\n");

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("\nCodigo nao encontrado!\n\n");
    }

    system("pause");
}

// 5 - EXCLUIR
void excluir(int codigo[], char nome[][15], int *total) {

    int busca, encontrado = 0;

    system("cls");
    printf("        EXCLUIR\n");

    printf("\nQual o codigo que deseja excluir?\n--> ");
    scanf("%d", &busca);

    for (int i = 0; i < *total; i++) {

        if (codigo[i] == busca) {

            printf("\nRegistro removido: %s\n", nome[i]);

            for (int j = i; j < *total - 1; j++) {
                codigo[j] = codigo[j + 1];
                strcpy(nome[j], nome[j + 1]);
            }

            (*total)--;

            printf("\nRegistro excluido com sucesso!\n\n");

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("\nCodigo nao encontrado!\n\n");
    }

    system("pause");
}

#endif
