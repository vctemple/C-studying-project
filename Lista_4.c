// LISTA4 - ESTRUTURAS DE DADOS [EDDA3]
// VICTOR TEMPLE - CJ3011771

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void EX1(void)
{
    int N[19];

    for(int I = 0; I <= 19; I++)
    {
        printf("\nDigite um numero inteiro: ");
        scanf("%d", &N[I]);
        printf("\n");
    }

    for(int I = 19; I >= 0; I--)
    {
        printf("%d\n", N[I]);
    }
}

void EX2(void)
{
    int N;

    printf("\nDigite quantas vezes deseja jogar o dado: ");
    scanf("%d", &N);

    int DADO[N];

    for(int I = 1; I <= N; I++)
    {
        DADO[I] = 1+(rand()%6);
        printf("Dado %d", I);
        printf(" caiu: %d\n", DADO[I]);
    }
}

void EX3(void)
{
    int M[5][5];

    for(int I = 1; I <= 5; I++)
    {
        for(int J = 1; J <= 5; J++)
        {
            if(I == J)
            {
                M[I-1][J-1] = 1;
            }
            else
            {
                M[I-1][J-1] = 0;
            }
        }
    }

    printf("\n");
    for(int I = 1; I <= 5; I++)
    {
        for(int J = 1; J <= 5; J++)
        {
            printf("%d  ", M[I-1][J-1]);
        }
        printf("\n");
    }
}

void EX4(void)
{
    int MATRIZ[99][99], L, C, SOMA = 0, COUNT = 0;
    float MEDIA;

    do
    {
       printf("\nDigite o numero de linhas que pretende trabalhar [max 100]: ");
       scanf("%d", &L);

       printf("\nDigite o numero de colunas que pretende trabalhar [max 100]: ");
       scanf("%d", &C);
       printf("\n");

    }while(L > 100 || C > 100);

    for(int I = 1; I <= L; I++)
    {
        for(int J = 1; J <= C; J++)
        {
            printf("Digite o valor para a posicao LINHA %d", I);
            printf(" COLUNA %d: ", J);
            scanf("%d", &MATRIZ[I-1][J-1]);
            SOMA += MATRIZ[I-1][J-1];
        }
    }

    MEDIA = (float)SOMA / (float)(L*C);

    for(int I = 1; I <= L; I++)
    {
        for(int J = 1; J <= C; J++)
        {
            if(MATRIZ[I-1][J-1] % 2 == 0 && MATRIZ[I-1][J-1] > MEDIA)
                COUNT += 1;
        }
    }

    printf("\nSoma dos elementos da matriz: %d\n", SOMA);
    printf("Media dos elementos da matriz: %.2f\n", MEDIA);
    printf("Valores pares acima da media calculada: %d\n\n", COUNT);
    printf("<<< MATRIZ GERADA >>>\n");

    for(int I = 1; I <= L; I++)
    {
        for(int J = 1; J <= C; J++)
        {
            printf(" | %3d | ", MATRIZ[I-1][J-1]);
        }
        printf("\n");
    }

    int MATRIZtransp[C][L];
    for(int I = 1; I <= L; I++)
    {
        for(int J = 1; J <= C; J++)
        {
            MATRIZtransp[J-1][I-1] = MATRIZ[I-1][J-1];
        }
    }

    printf("\n<<< MATRIZ TRANSPOSTA >>>\n");
    for(int I = 1; I <= C; I++)
    {
        for(int J = 1; J <= L; J++)
        {
            printf(" | %3d | ", MATRIZtransp[I-1][J-1]);
        }
        printf("\n");
    }
}

void EX5(void)
{
    char STRING1[50] = "Remove todos os espacos ! ! ! ! !";
    char STRING2[50];
    int C = 0;
    for(int I = 0; I < strlen(STRING1); I++)
    {
        if (!(isspace(STRING1[I])))
        {
            STRING2[C] = STRING1[I];
            C++;
        }
    }
    STRING2[C] = '\0';
    printf("\n%s\n", STRING2);
}

int MENU(void)
{
    int op;

    printf(">>>Escolha qual opcao deseja<<< \n");
    printf("\n");
    printf("SAIR = [0] \n");
    printf("EX1  = [1] \n");
    printf("EX2  = [2] \n");
    printf("EX3  = [3] \n");
    printf("EX4  = [4] \n");
    printf("EX5  = [5] \n");
    printf("\n");
    printf("Digite o numero: ");
    scanf("%i", &op);

    return op;
}

int main (void)
{
    int X;

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
                EX5();
                break;
        }

        printf("\nPressione Enter para continuar \n");
        while( (getchar()) != '\n');

        getchar();
        system("@cls||clear");

    }while(X != 0);

return 0;
}
