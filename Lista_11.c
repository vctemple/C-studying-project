// LISTA11 - Fila com alocação estática
// VICTOR TEMPLE

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct sElem
{
    char Nome[30];
    int Matricula;
}ELEMENTO;

typedef struct sFila
{
    ELEMENTO Info[TAM];
    int Cabecalho, Ultimo;
}FILA;

void inicializar_fila(FILA *Fila)
{
    Fila->Ultimo = 0;
    Fila->Cabecalho = Fila->Ultimo;
}

int fila_vazia(FILA *Fila)
{
    if(Fila->Ultimo == Fila->Cabecalho)
        return 1;
    return 0;
}

int fila_cheia(FILA *Fila)
{
    int Proximo = (Fila->Ultimo+1) % TAM;
    if(Proximo == Fila->Cabecalho)
        return 1;
    return 0;
}

int enfileirar(FILA *Fila, ELEMENTO Elem)
{
    int Proximo;
    if(fila_cheia(Fila))
        return 0;

    Proximo = (Fila->Ultimo+1) % TAM;
    Fila->Info[Proximo] = Elem;
    Fila->Ultimo = Proximo;
    return 1;
}

ELEMENTO desenfileirar(FILA *Fila)
{
    ELEMENTO Removido;
    Removido.Matricula = -1;

    if(fila_vazia(Fila))
        return Removido;

    Fila->Cabecalho = (Fila->Cabecalho+1) % TAM;
    Removido = Fila->Info[Fila->Cabecalho];
    return Removido;
}

int menu(void)
{
    int op;

    printf("================[MENU]==============\n");
    printf("\n");
    printf("..................................SAIR: [0] \n");
    printf("......................ENFILEIRAR ALUNO: [1] \n");
    printf("...................DESENFILEIRAR ALUNO: [2] \n");
    printf("..............IMPRIMIR DESENFILEIRANDO: [3] \n");
    printf("............IMPRIMIR COM FILA AUXILIAR: [4] \n");
    printf("...........................LIMPAR FILA: [5] \n");
    printf("..VISUALIZAR PRIMEIRO ELEMENTO DA FILA: [6] \n");
    printf("\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &op);

    return op;
}

int main(void)
{
    FILA Fila;
    inicializar_fila(&Fila);
    ELEMENTO Aux[TAM]; //Para receber elementos removidos e de inclus�o
    int Menu, Contador;

    do
    {
        Menu = menu();

        switch(Menu)
        {
            case 0:
                printf("\nSair do programa \n");
                break;

            case 1:

               while( (getchar()) != '\n');
               printf("\nDigite o Nome do Aluno: ");
               scanf("%[^\n]", Aux[0].Nome);
               while( (getchar()) != '\n');

               printf("\nDigite a matricula do Aluno: ");
               scanf("%d", &Aux[0].Matricula);

               enfileirar(&Fila, Aux[0]);
               break;

            case 2:
                Aux[0] = desenfileirar(&Fila);

                if(Aux[0].Matricula == -1)
                    printf("\nFila Vazia! Nao ha o que desenfileirar...");

                printf("\nALUNO REMOVIDO\nNome: %s\tMatricula: %d", Aux[0].Nome, Aux[0].Matricula);

                break;

            case 3:
                Contador = ((Fila.Ultimo + TAM - Fila.Cabecalho) % TAM)+1;
                if(Contador == 0)
                {
                    printf("\nFila Vazia! Nao ha o que imprimir...");
                }
                else
                {
                    for(int i = 0; i <= Contador; i++)
                    {
                    Aux[i] = desenfileirar(&Fila);
                    printf("\nNome do Aluno: %s\tMatricula: %d", Aux[i].Nome, Aux[i].Matricula);
                    }
                }
                break;

            case 4:
                Contador = ((Fila.Ultimo + TAM - Fila.Cabecalho) % TAM)+1;
                if(Contador == 0)
                {
                    printf("\nFila Vazia! Nao ha o que imprimir...");
                }
                else
                {
                    for(int i = 0; i <= Contador; i++)
                    {
                    Aux[i] = desenfileirar(&Fila);
                    printf("\nNome do Aluno: %s\tMatricula: %d", Aux[i].Nome, Aux[i].Matricula);
                    }
                    for(int i = 0; i <= Contador; i++)
                    {
                        enfileirar(&Fila, Aux[i]);
                    }
                }
                break;

            case 5:
                inicializar_fila(&Fila);
                if(fila_vazia(&Fila))
                    printf("\nA fila foi esvaziada!");
                break;

            case 6:
                if(fila_vazia(&Fila))
                    printf("\nFila vazia!");
                else
                    printf("Nome do aluno: %s\tMatricula: %d", Fila.Info[Fila.Cabecalho+1].Nome, Fila.Info[Fila.Cabecalho+1].Matricula);
                break;
        }

        printf("\nPressione Enter para continuar \n");

        while( (getchar()) != '\n');
        getchar();

        system("@cls||clear");

    }while(Menu != 0);

return 0;
}
