// LISTA9 - Lista com alocação dinâmica
// VICTOR TEMPLE

#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula
{
    char NOME[30];
    int MATRICULA;
    struct sCelula *NEXT; //AQUI EH ALOCADO O ENDERECO DA PROXIMA CELULA DA LISTA, CASO NULL, E O FINAL DA LISTA
}CELULA;

// PARA USAR A FUNCAO FACA: CELULA *q = criar_celula
CELULA* criar_celula(void)
{
    CELULA *Nova = (CELULA*) malloc(sizeof(CELULA));
    return Nova; //RETORNA O ENDERECO DA CELULA CRIADA
}

//INICIA O COMECO DA LISTA COM NULL PARA INDICAR QUE NAO HA MAIS ELEMENTOS
void inicializar_lista(CELULA **Lista)
{
    (*Lista) = NULL;
}

int lista_vazia(CELULA **Lista)
{
    if((*Lista) == NULL)
    {
        return 1; //CASO SEJA NULO, A LISTA EST� VAZIA, RETORNA 1 E SAI DA FUNCAO
    }
    else
    {
        return 0; //CASO NAO SEJA NULO, HA ELEMENTOS NA LISTA, PULA UMA LINHA E RETORNA 0
    }

}

//ALEM DE RECEBER O END DA LISTA, RECEBE OS DADOS PREVIAMENTE INSERIDOS NA MAIN, NOME E MATRICULA
int inserir_fim(CELULA **Lista, char Nome, int Matricula)
{
    CELULA *NovaCelula; // ARMAZENA O END DA NOVA CELULA
    CELULA *Aux; // USADO PARA ENCONTRAR O FINAL DA FILA BUSCANDO A CELULA COM O NEXT == NULL

    NovaCelula = criar_celula();
    if(NovaCelula == NULL)
    {
        printf("\nErro ao alocar a memoria!"); //CASO A NOVA CELULA TENHA O VALOR NULL, A MEMORIA RAM EST� CHEIA
        return 0;
    }

    *NovaCelula->NOME = Nome;
    NovaCelula->MATRICULA = Matricula;
    NovaCelula->NEXT = NULL; //ATRIBUI AGORA O VALOR NULL JA QUE ESTA SERA A ULTIMA CELULA DA FILA

    //VERIFICA SE A LISTA ESTA VAZIA
    if(lista_vazia(Lista))
    {
        (*Lista) = NovaCelula; // CASO vAZIA, ALOCA A CELULA COMO A PRIMEIRA E ULTIMA DESTA LISTA
        return 1;
    }

    // CASO NAO ESTEJA VAZIA, PROCURA-SE O FINAL DA LISTA DESTA FORMA
    Aux = (*Lista);
    while(Aux->NEXT == NULL)
    {
        Aux = Aux->NEXT;
    }

    // APOS ENCONTRAR O FINAL, ATRIBUI O END DA NOVA CELULA NO NEXT DA ULTIMA CELULA DA FILA ENCONTRADA
    Aux->NEXT = NovaCelula;
    return 1;
}

int inserir_inicio(CELULA **Lista, char Nome, int Matricula)
{
    CELULA *NovaCelula;

    NovaCelula = criar_celula();

    //VERICA SE HA MEMORIA
    if(NovaCelula == NULL)
    {
        printf("\nErro ao alocar a memoria!");
        return 0;
    }

    //VERIFICA SE A LISTA EST� VAZIA
    if(lista_vazia(Lista))
    {
        return inserir_fim(Lista, Nome, Matricula); //COMO NAO HA ELEMENTOS NA LISTA, CHAMA-SE A FUNCAO DE INSERIR_FIM
    }

    //CASO CONTRARIO
    *NovaCelula->NOME = Nome;
    NovaCelula->MATRICULA = Matricula;

    NovaCelula->NEXT = (*Lista); //NEXT DA NOVA CELULA PASSA A APONTAR PARA ONDE O COMECO APONTAVA, OU SEJA, O SEGUNDO ELEMENTO
    (*Lista) = NovaCelula; // O COMECO DA LISTA RECEBE AS INFORMACOES DA NOVA CELULA SE TORNANDO O PRIMEIRO ELEMENTO DE FATO
    return 1;
}

void imprimir_lista(CELULA **Lista)
{
    CELULA *Aux = (*Lista); //VARIAVEL PARA NAVEGAR ENTRE AS CELULAS

    if(lista_vazia(Lista))
    {
        printf("\nNao foi possivel imprimir!\nLista Vazia!");
    }
    else
    {
        printf("\nLISTA DE ALUNOS\n");
        while(Aux != NULL)
        {
            printf("\nAluno: %s\tMatricula: %d", Aux->NOME, Aux->MATRICULA);
            Aux = Aux->NEXT;
        }
    }
}

int remover_inicio(CELULA **Lista)
{
    CELULA *Removida; //VARIAVEL PARA COPIAR AS INFORMACOES DA CELULA QUE SERA APAGADA

    if(lista_vazia(Lista))
    {
        printf("\nLista Vazia, nao ha o que remover!");
        return 0;
    }

    Removida = (*Lista);
    (*Lista) = (*Lista)->NEXT;

    printf("\nAluno: %s\tMatricula: %d", Removida->NOME, Removida->MATRICULA);
    free(Removida);

    return 1;
}

int remover_final(CELULA **Lista)
{
    CELULA *Removida = (*Lista); //MESMO OBJETIVO
    CELULA *Anterior; // PARA SUBSTITUIR A CELULA QUE SERA APAGADA

    if(lista_vazia(Lista))
    {
        printf("\nLista Vazia, nao ha o que remover!");
        return 0;
    }

    if((*Lista)->NEXT == NULL)
    {
        return remover_inicio(Lista); //SE HOUVER APENAS 1 ELEMENTO, A FUNCAO DE REMOVER NO INICIO CONTEMPLA
    }


    while(Removida->NEXT != NULL)
    {
        Anterior = Removida;
        Removida = Removida->NEXT;
    }

    Anterior->NEXT = NULL;
    printf("\nAluno: %s\tMatricula: %d", Removida->NOME, Removida->MATRICULA);
    free(Removida);

    return 1;
}

int pesquisar_mat(CELULA **Lista, int Mat)
{
    CELULA *Aux; //PARA NAVEGAR

    if(lista_vazia(Lista))
    {
        printf("\nLista Vazia, nao ha o que procurar!");
        return 0;
    }

    Aux = (*Lista);
    while(Aux != NULL)
    {
        if(Aux->MATRICULA == Mat)
        {
            printf("\nNome: %s", Aux->NOME);
            return 1;
        }
        Aux = Aux->NEXT;
    }

    printf("\nMatricula nao encontrada!");

    return 0;
}

int remover_mat(CELULA **Lista, int Mat)
{
    CELULA *Anterior, *Removida = pesquisar_mat(Lista, Mat);

    if(lista_vazia(Lista))
    {
        printf("\nLista Vazia, nao ha o que remover!");
        return 0;
    }

    if(Removida == NULL);
    {
        printf("\nMatricula nao encontrada!");
        return 0;
    }

    if(Removida == (*Lista))
    {
        return remover_inicio(Lista); //CASO SEJA O PRIMEIRO ELEMENTO
    }

    Anterior = (*Lista);
    while(Anterior->NEXT != Removida)
    {
        Anterior = Anterior->NEXT;
    }

    Anterior->NEXT = Removida->NEXT;
    printf("\nAluno: %s\tMatricula: %d", Removida->NOME, Removida->MATRICULA);
    free(Removida);

    return 1;
}

int main(void)
{
    int op;
    CELULA Lista;
    inicializar_lista(&Lista);

    do
    {
        printf("================[MENU]===============\n");
        printf("\n");
        printf(".........................SAIR[0].....\n");
        printf("...........VERIFICAR SE VAZIA[1].....\n");
        printf(".........INSERIR ALUNO NO FIM[2].....\n");
        printf("......INSERIR ALUNO NO INICIO[3].....\n");
        printf("......IMPRIMIR LISTA COMPLETA[4].....\n");
        printf("......REMOVER ALUNO NO INICIO[5].....\n");
        printf(".........REMOVER ALUNO NO FIM[6].....\n");
        printf("......PESQUISAR POR MATRICULA[7].....\n");
        printf("........REMOVER POR MATRICULA[8].....\n");

        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);

        switch(op)
        {
            case 0:
                printf("\nSair do programa \n");
                break;

            case 1:
                if(lista_vazia(&Lista))
                {
                    printf("\nNao ha elementos na lista ainda!");
                }
                else
                {
                    printf("\nHa elementos na lista!");
                }
                break;

            case 2:;
                char Nome1[30];
                int Mat1;

                while( (getchar()) != '\n');
                printf("\nDigite o nome do aluno: ");
                scanf("%s", Nome1);
                while( (getchar()) != '\n');

                printf("\nDigite a matricula: ");
                scanf("%d", &Mat1);

                if(inserir_fim(&Lista, Nome1, Mat1))
                {
                    printf("\nAluno criado com sucesso!");
                }
                break;

            case 3:;
                char Nome2[30];
                int Mat2;

                while( (getchar()) != '\n');
                printf("\nDigite o nome do aluno: ");
                scanf("%s", Nome2);
                while( (getchar()) != '\n');

                printf("\nDigite a matricula: ");
                scanf("%d", &Mat2);

                if(inserir_inicio(&Lista, Nome2, Mat2))
                {
                    printf("\nAluno criado com sucesso!");
                }
                break;

            case 4:
                imprimir_lista(&Lista);
                break;

            case 5:
                if(remover_inicio(&Lista))
                {
                    printf("\nRemovido com sucesso!");
                }
                break;

            case 6:
                if(remover_final(&Lista))
                {
                    printf("\nRemovido com sucesso!");
                }
                break;

            case 7:;
                int Mat3;

                printf("Digite a matricula do aluno: ");
                scanf("%d", &Mat3);

                if(pesquisar_mat(&Lista, Mat3))
                {
                    printf("\nAluno encontrado!");
                }
                break;

            case 8:;
                int Mat4;

                printf("Digite a matricula do aluno: ");
                scanf("%d", &Mat4);

                if(remover_mat(&Lista, Mat4))
                {
                    printf("\nRemovido com sucesso!");
                }
                break;
        }

        printf("\nPressione Enter para continuar \n");

        while( (getchar()) != '\n');
        getchar();

        system("@cls||clear");

    }while(op != 0);

return 0;
}
