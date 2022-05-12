// LISTA7 - ESTRUTURAS DE DADOS [EDDA3]
// VICTOR TEMPLE - CJ3011771

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sPessoa
{
    char nome[20];
    char idade[3];
    char telefone[12];
};

struct sCarro
{
    char modelo[20];
    char marca [20];
    char ano[5];
    char preco[10];
    char placa[8];
};

void EX1(void)
{
    int *a;

    a = (int*) malloc(2*sizeof(int));
    if (a == NULL)
    {
        printf("Nao foi possivel alocar memoria.\n");
        exit(0);
    }

    for(int i = 0; i <= 1; i++)
    {
        printf("\nDigite o numero %d: ", i+1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i <= 1; i++)
    {
        printf("\nNumero[%d]: %d", i+1, a[i]);
    }

    free(a);
}

void EX2(void)
{
    int *a, n;

    printf("\nDigite a quantidade numeros para alocar: ");
    scanf("%d", &n);

    a = (int*) malloc(n*sizeof(int));
    if (a == NULL)
    {
        printf("Nao foi possivel alocar memoria.\n");
        exit(0);
    }

    for(int i = 0; i <= n-1; i++)
    {
        printf("\nDigite o numero %d: ", i+1);
        scanf("%d", &a[i]);
    }

    for(int i = 0; i <= n-1; i++)
    {
        printf("\nNumero[%d]: %d", i+1, a[i]);
    }

    free(a);
}

void EX3(void)
{
    struct sPessoa *a;
    int n;

    printf("\nDigite a quantidade pessoas para alocar: ");
    scanf("%d", &n);

    a = (struct sPessoa*) malloc(n*sizeof(struct sPessoa));
    if (a == NULL)
    {
        printf("Nao foi possivel alocar memoria.\n");
        exit(0);
    }

    for(int i = 0; i <= n-1; i++)
    {
        while( (getchar()) != '\n');
        printf("\nDigite o nome da pessoa %d: ", i+1);
        scanf("%[^\n]", a[i].nome);

        while( (getchar()) != '\n');
        printf("\nDigite a idade da pessoa %d: ", i+1);
        scanf("%[^\n]", a[i].idade);

        while( (getchar()) != '\n');
        printf("\nDigite o telefone da pessoa %d: ", i+1);
        scanf("%[^\n]", a[i].telefone);
    }

    free(a);

}

void EX4(void)
{
    int **matriz, l, c;

    printf("\nDigite a quantidade de linhas para a matriz: ");
    scanf("%d", &l);
    printf("\nDigite a quantidade de colunas para a matriz: ");
    scanf("%d", &c);

    matriz = (int**) malloc((l-1)*sizeof(int*));

    for (int i = 0; i <= l-1; i++)
    {
        matriz[i] = (int*) malloc((c-1)*sizeof(int));

        for(int j = 0; j <= c-1; j++)
        {
            printf("\nDigite o numero para a posicao [%d]x[%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i= 0; i <= l-1; i++)
    {
        for(int j = 0; j <= c-1; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i <= l-1; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;

}

void cadcarro(struct sCarro* b, int n)
{
    for(int i = 0; i <= n-1; i++)
    {
        while( (getchar()) != '\n');
        printf("\nDigite a marca do carro %d: ", i+1);
        scanf("%[^\n]", b[i].marca);

        while( (getchar()) != '\n');
        printf("\nDigite o modelo do carro %d: ", i+1);
        scanf("%[^\n]", b[i].modelo);

        while( (getchar()) != '\n');
        printf("\nDigite o ano de fabricacao do carro %d: ", i+1);
        scanf("%[^\n]", b[i].ano);

        while( (getchar()) != '\n');
        printf("\nDigite a placa do carro %d: ", i+1);
        scanf("%[^\n]", b[i].placa);

        while( (getchar()) != '\n');
        printf("\nDigite o preco de venda do carro %d: ", i+1);
        scanf("%[^\n]", b[i].preco);
    }
}

void editcarro(struct sCarro *c, int n)
{
    char placa[8];
    int comp, i = 0;

    while( (getchar()) != '\n');
    printf("\nDigite a placa do carro a ser editado: ");
    scanf("%[^\n]", placa);

    do
    {
        comp = strcmp(placa, c[i].placa);

        if(comp != 0)
            i += 1;

    }while(comp != 0);

    while( (getchar()) != '\n');
        printf("\nDigite a marca do carro %d: ", i+1);
        scanf("%[^\n]", c[i].marca);

        while( (getchar()) != '\n');
        printf("\nDigite o modelo do carro %d: ", i+1);
        scanf("%[^\n]", c[i].modelo);

        while( (getchar()) != '\n');
        printf("\nDigite o ano de fabricacao do carro %d: ", i+1);
        scanf("%[^\n]", c[i].ano);

        while( (getchar()) != '\n');
        printf("\nDigite a placa do carro %d: ", i+1);
        scanf("%[^\n]", c[i].placa);

        while( (getchar()) != '\n');
        printf("\nDigite o preco de venda do carro %d: ", i+1);
        scanf("%[^\n]", c[i].preco);
}

int MENU(void)
{
    int op;

    printf("=====[MENU]=====\n");
    printf("\n");
    printf("....SAIR[0].....\n");
    printf("......EX[1].....\n");
    printf("......EX[2].....\n");
    printf("......EX[3].....\n");
    printf("......EX[4].....\n");
    printf("......EX[5].....\n");

    printf("\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &op);

    return op;
}

int main (void)
{
    int X, op, ncarro;
    struct sCarro *a;

    a = (struct sCarro*) malloc(100*sizeof(struct sCarro));
    if (a == NULL)
    {
        printf("Nao foi possivel alocar memoria.\n");
        exit(0);
    }

    do
    {
        X = MENU();

        switch(X)
        {
            case 0:
                printf("\nSair do programa \n");
                break;

            case 1:
                EX1();
                break;

            case 2:
                EX2();
                break;

            case 3:
                EX3();
                break;

            case 4:
                EX4();
                break;

            case 5:
                printf("\n=====[CONCESSIONARIA]=====\n");
                printf("\n");
                printf("...............SAIR[0]....\n");
                printf("....Cadastrar carro[1]....\n");
                printf(".......Editar carro[2]....\n");
                printf("\n");
                printf(".....Digite a sua opcao: ");
                scanf("%d", &op);

                switch(op)
                {
                    case 0:
                        break;

                    case 1:

                        printf("\nDigite a quantidade de carros a ser cadastrada: ");
                        scanf("%d", &ncarro);
                        cadcarro(a, ncarro);
                        break;

                    case 2:
                        editcarro(a, ncarro);
                        break;
                }

                break;
        }

        printf("\nPressione Enter para continuar \n");
        while( (getchar()) != '\n');

        getchar();
        system("@cls||clear");

    }while(X != 0);
free(a);
return 0;
}

