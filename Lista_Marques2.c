// LISTA2 - ESTRUTURAS DE DADOS [EDDA3]
// VICTOR TEMPLE - CJ3011771

#include<stdio.h>
#include<math.h>
#include <stdlib.h>

void FOREX1(int X)
{
   int I=1, F=1;

   for(I; I<=X; I++)
   {
       F *= I;
   }

   printf("\nFATORIAL COM LACO FOR: %d\n", F);
}

void WHILEEX1(int X)
{
   int I=1, F=1;

        while(I<=X)
        {
            F *= I;
            I++;
        }

        printf("FATORIAL COM LACO WHILE: %d\n", F);
}

void DOWHILEEX1(int X)
{
    int I=1, F=1;

    do
    {
        F *= I;
        I++;

    }while (I<=X);

    printf("FATORIAL COM LACO DO-WHILE: %d\n", F);
}

void EX1(void)
{
    int N;
    printf("DIGITE UM NUMERO: ");
    scanf("%d", &N);

    FOREX1(N);
    WHILEEX1(N);
    DOWHILEEX1(N);
}

void EX2(void)
{
    int N, I = 1, COUNT = 0;

    printf("DIGITE UM NUMERO: ");
    scanf("%d", &N);


    for(I; I <= N; I++)
    {
        if(N % I == 0)
        {
            COUNT++;
        }
    }

    if(COUNT == 2)
    {
        printf("\nO NUMERO FORNECIDO EH PRIMO\n");
    }
    else
    {
        printf("\nO NUMERO FORNECIDO NAO EH PRIMO\n");
    }
}

void PRIMOEX3(int N)
{
    int I = 1, COUNT = 0;

    for(I; I <= N; I++)
    {
        if(N % I == 0)
        {
            COUNT++;
        }
    }

    if(COUNT == 2 || N == 1)
    {
        printf("%d\n", N);
    }

}

void EX3(void)
{
    int X;

    printf("DIGITE UM NUMERO: ");
    scanf("%d", &X);

    for (int I = 1; I <= X; I++)
    {
        PRIMOEX3(I);
    }
}

void EX4(void)
{
    int N, I, J, ESPACE=0;

    printf("DIGITE O NUMERO DE LINHAS: ");
    scanf("%d",&N);

    printf("\n[A]\n\n");
    for(I=1;I<=N;I++)
    {
        for(J=1;J<=N-I; J++)
        {
            printf(" ");
        }
        for(J=1;J<=2*I-1;J++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n\n[B]\n\n");
    for(I=N; I>= 1; --I)
    {
        for(ESPACE=0; ESPACE<N-I; ++ESPACE)
        {
            printf(" ");
        }
        for(J=I; J<=2*I-1; ++J)
        {
            printf("*");
        }
        for (J=0; J<I-1; ++J)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n\n[C]\n\n");
    for(I=1; I<=N; I++)
    {
        for(J=I; J<N; J++)
        {
            printf(" ");
        }
        for(J=1; J<=I; J++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(I=1; I<=N; ++I)
    {
        for(J=2; J<=I; J++)
        {
            printf(" ");
        }
        for(J=I; J<=N; J++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n\n[D]\n\n");
    for(I=1; I<=N; I++)
    {
        for(J=1; J<=I; J++)
        {
            printf( "*");
        }
        printf("\n");
    }
    for(I=N-1; I>=1; I--)
    {
        for(J=1; J<=I; J++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int MENU (void)
{
    int op;

    printf(">>>Escolha qual opcao deseja<<< \n");
    printf("\n");
    printf("SAIR = [0] \n");
    printf("EX1  = [1] \n");
    printf("EX2  = [2] \n");
    printf("EX3  = [3] \n");
    printf("EX4  = [4] \n");
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
        }

        printf("\nPressione Enter para continuar \n");
        while( (getchar()) != '\n');

        getchar();
        system("@cls||clear");

    }while(X != 0);

return 0;
}
