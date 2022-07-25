// LISTA8 - Lista com alocação estática
// VICTOR TEMPLE

#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 10

typedef struct sLista
{
    char caixa[MAX_TAM];
    int ultimo;
}LISTA;

void start_lista(LISTA *lista)
{
    lista->ultimo = -1;
}

void insert_lista(LISTA *lista)
{
    int pos, ok;
    char letra;

    printf("\nDigite a posicao que deseja inserir o novo elemento: ");

    do
    {
        scanf("%d", &pos);

        if (pos >= 0 && pos <= lista->ultimo + 1)
        {
            ok = 1;
        }
        else
        {
            printf("\nPosicao invalida!!! Digite novamente: ");
        }
    }while(ok != 1);

    while( (getchar()) != '\n');
    printf("\nDigite uma letra para o novo elemento: ");
    scanf("%c,", &lista->caixa[pos-1]);

}

void invert_lista(LISTA *lista)
{
    LISTA invlista;
    start_lista(&invlista);

    for (int i = 0; i <= lista->ultimo; i++)
    {
        invlista.caixa[invlista.ultimo + 1] = lista->caixa[lista->ultimo - i];
        invlista.ultimo++;
    }

    for(int i = 9; i >= 0; i--)
    {
        lista->caixa[lista->ultimo - i] = invlista.caixa[invlista.ultimo - i];
    }
}

void order_lista(LISTA *lista)
{
    char x;

    for (int i = 0; i <= lista->ultimo; i++)
    {
        for (int j = 0; j <= lista->ultimo; j++)
        {
            if (lista->caixa[i] < lista->caixa[j])
            {
                x = lista->caixa[i];
                lista->caixa[i] = lista->caixa[j];
                lista->caixa[j] = x;
            }
        }
    }
}

void print_lista(LISTA *lista)
{
    printf("\n");
    for (int i = 0; i <= 9; i++)
    {
        printf("[%d]\t", i + 1);
    }
    printf("\n");

    for (int i = -1; i <= lista->ultimo; i++)
    {
        printf(" %c\t", lista->caixa[i+1]);
    }
}

int main(void)
{
    int op;
    LISTA lista;
    start_lista(&lista);

    printf("Voce vai criar uma lista com 10 elementos!!");
    printf("\nDigite uma letra para cada posicao desta lista!\n");



    for (int i = 0; i <= 9; i++)
    {
        printf("\nDigite a letra para a posicao %d: ", i+1);
        scanf("%c", &lista.caixa[lista.ultimo + 1]);
        while( (getchar()) != '\n');
        lista.ultimo++;
    }

    system("@cls||clear");

    printf("\nSua lista ficou preenchida desta forma:\n\n");

    for (int i = 0; i <= 9; i++)
    {
        printf("[%d]\t", i + 1);
    }
    printf("\n");

    for (int i = -1; i <= lista.ultimo; i++)
    {
        printf(" %c\t", lista.caixa[i+1]);
    }
    printf("\n\nAgora selecione a opcao desejada!\n\n");

    do
    {
        printf("===========[MENU]==========\n");
        printf("\n");
        printf("...............SAIR[0].....\n");
        printf("...INSERIR ELEMENTO[1].....\n");
        printf(".....INVERTER LISTA[2].....\n");
        printf("......ORDENAR LISTA[3].....\n");
        printf(".....IMPRIMIR LISTA[4].....\n");

        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);

        switch(op)
        {
            case 0:
                printf("\nSair do programa \n");
                break;

            case 1:
                insert_lista(&lista);
                break;

            case 2:
                invert_lista(&lista);
                break;

            case 3:
                order_lista(&lista);
                break;

            case 4:
                print_lista(&lista);
                break;
        }

        printf("\nPressione Enter para continuar \n");

        while( (getchar()) != '\n');
        getchar();

        system("@cls||clear");

    }while(op != 0);

return 0;
}
