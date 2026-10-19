#include <stdio.h>
#include <windows.h>

typedef struct{
    char nome[50], curso[30];
    int matricula;
}Aluno;

Aluno alunos[100];
int total_alunos = 0;

void titulo(){
    system("cls");
    printf("----------------------------------\n");
    printf("        Cadastro de alunos        \n");
    printf("----------------------------------");
    printf("\n1 - Cadastrar aluno\n");
    printf("2 - Consultar aluno cadastrado\n");
    printf("3 - Alunos cadastrados\n");
    printf("4 - Editar aluno\n");
    printf("5 - Excluir aluno\n");
    printf("0 - Sair\n");
    printf("\nEscolha uma opcao [digite um numero]\n--> ");
}

void cadastro(){
    system("cls");
    printf("        CADASTRAR ALUNO");


    printf("\nQual o nome?\n--> ");
    fgets(alunos[total_alunos].nome, 50, stdin);
    alunos[total_alunos].nome[strcspn(alunos[total_alunos].nome, "\n")] = 0;

    printf("\nQual o curso?\n--> ");
    fgets(alunos[total_alunos].curso, 30, stdin);
    alunos[total_alunos].curso[strcspn(alunos[total_alunos].curso, "\n")] = 0;

    alunos[total_alunos].matricula = total_alunos + 1000;

    system("cls");
    printf("NOME:      Curso:      MATRICULA:\n");
    printf("\n%s | %s | %d\n", alunos[total_alunos].nome, alunos[total_alunos].curso, alunos[total_alunos].matricula);
    printf("\nAluno cadastrado com sucesso!\n\n");

    total_alunos ++;
    system("pause");

}

void consulta(){
    system("cls");
    int temp, encontrado=0;
    printf("        Consultar aluno\n");
    printf("\nQual a matricula?\n--> ");
    scanf(" %d", &temp);

    for(int i=0; i <= total_alunos; i++){
        if(alunos[i].matricula == temp){

            printf("\n%s | %s | %d\n\n", alunos[i].nome, alunos[i].curso, alunos[i].matricula);
            system("pause");
            encontrado = 1;
            break;

        }
    }
    if(encontrado == 0){
        printf("Matricula nao encontrada! ");
    }
}

void listar(){
    system("cls");
    printf("        Alunos cadastrados:\n");

    for(int i=0; i< total_alunos; i++){
        printf("%s | %s | %d\n", alunos[i].nome, alunos[i].curso, alunos[i].matricula);
    }
    system("pause");
}

void editar(){
    int encontrado = 0, temp;
    system("cls");
    printf("        Editar Cadastro\n");

    printf("\nQual a matricula que deseja editar?\n--> ");
    scanf(" %d", &temp);
    while (getchar() != '\n');

    for(int i = 0; i < total_alunos; i++){
        if(alunos[i].matricula == temp){
            printf("\n %s | %s | %d\n\n", alunos[i].nome, alunos[i].curso, alunos[i].matricula);
            
            printf("Qual o novo nome?\n--> ");
            fgets(alunos[i].nome, 50, stdin);
            alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

            printf("Qual o novo curso?\n--> ");
            fgets(alunos[i].curso, 50, stdin);
            alunos[i].curso[strcspn(alunos[i].curso, "\n")] = 0;

            encontrado = 1;
            break;
        }
    }
    if(encontrado == 0){
        system("cls");
        printf("\nCadastro nao encontrado!\n");
        system("pause");
    }
}

void excluir(){
    int encontrado = 0, temp;
    system("cls");
    printf("        Editar Cadastro\n");

    printf("\nQual a matricula que deseja editar?\n--> ");
    scanf(" %d", &temp);
    while (getchar() != '\n');

    for(int i = 0; i < total_alunos; i++){
        if(temp == alunos[i].matricula){

            char nome[50];
            strcpy(nome, alunos[i].nome);

            for(int j = i; j < total_alunos - 1; j++){
                alunos[j] = alunos[j + 1];
            }

            total_alunos --;
            encontrado = 1;
            
            printf("\nAluno(a) %s removido com sucesso!\n", nome);
            system("pause");
            break;
        }
    }
    if(encontrado == 0){
        system("cls");
        printf("cadastro nao encontrado!");
        system("pause");
    }
}