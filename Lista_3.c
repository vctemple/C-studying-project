// LISTA3 - ESTRUTURAS DE DADOS [EDDA3]
// VICTOR TEMPLE - CJ3011771

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void EX1(void)
{
    int N, count1 = 0, count2 = 0, S1 = 0, S2 = 0, Maior, Menor;
    float M1, M2;

    printf("\nDigite um numero inteiro ou zero para sair: ");
    scanf("%d", &N);
    if (N != 0)
    {
        Maior = N; Menor = N;
        do
        {
        count1 += 1;
        S1 = S1 + N;
        if(N >= Maior)
        {
            Maior = N;
        }
        if(N <= Menor)
        {
            Menor = N;
        }
        if(N % 2 == 0)
        {
            count2 += 1;
            S2 = S2 + N;
        }

        printf("\nDigite novamente um inteiro ou zero para exibir os resultados: ");
        scanf("%d", &N);

        }while (N != 0);
    }

    printf("\nA soma dos numeros sao: %d", S1);
    printf("\nA quantidade de numeros digitados eh: %d", count1);

    M1 = (float)S1 / (float)count1;
    printf("\nA media das entradas eh de: %.2f", M1);

    printf("\nO maior numero digitado foi: %d", Maior);
    printf("\nO menor numero digitado foi: %d", Menor);

    M2 = (float)S2 / (float)count2;
    printf("\nA media das entradas pares eh de: %.2f", M2);
}

void EX2(void)
{
    int M, N, Q;

    printf("Digite o numero de partida: ");
    scanf("%d", &M);

    printf("\nDigite o numero de chegada: ");
    scanf("%d", &N);

    for(M; M <= N; M += 1)
    {
        Q = pow(M, 2);
        printf("\n%d", Q);
    }
}

void FuncaoEEX3(int N)
{
    int X = 1;
    double E = 0.0;

    for(int I=1; I<=N; I++)
    {
        X *= I;
        E = E + (1.0 / (float)X);
    }

    printf("\nPara N: %d", N);
    printf(" a funcao E = %.18f", E);

}

void EX3(void)
{
    for(int I=1; I<=30; I++)
    {
        FuncaoEEX3(I);
    }
}

void FuncaoPEX4(int N)
{
    printf("Os multiplos do numero %d", N);
    printf(" sao: ");

    for(int I=1; I<=N; I++)
    {
        if(N % I == 0)
        {
            printf("%d ", I);
        }
    }
    printf("\n");
}

void EX4(void)
{
    for(int I=1; I<=9; I++)
    {
        FuncaoPEX4(I);
    }
}

void EX5(void)
{
    int T;
    for(int I=1; I<=10; I++)
    {
        printf("Tabuada do numero %d: ", I);
        for(int J=1; J<=10; J++)
        {
            T = (I * J);
            printf("%d ", T);
        }
        printf("\n");
    }
}

void EX6(void)
{
    setlocale(LC_ALL, "");
    int I, Verif = 0;
    char Palavra[15], Inversa[15];

    while( (getchar()) != '\n');
    printf("\nDigite uma palavra: ");
    gets(Palavra);

    for(I=0; Palavra[I]; I++)
    {
        Palavra[I] = tolower(Palavra[I]);
    }

    strcpy(Inversa, Palavra);

    strrev(Inversa);

    Verif = strcmp(Palavra, Inversa);

    if (Verif == 0)
    {
        printf("\nA palavra %s é palíndroma.\n", Palavra);
    }
    else
    {
        printf("\nA palavra %s não é palíndroma.\n", Palavra);
    }
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
    printf("EX6  = [6] \n");
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

            case 6:
                EX6();
                break;
        }

        printf("\nPressione Enter para continuar \n");
        while( (getchar()) != '\n');

        getchar();
        system("@cls||clear");

    }while(X != 0);

return 0;
}
