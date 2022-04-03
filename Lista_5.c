// LISTA5 - ESTRUTURAS DE DADOS [EDDA3]
// VICTOR TEMPLE - CJ3011771

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

void Deuclides(int A1, int B1, int A2, int B2)
{
    float D;

    D = sqrt(pow((A1-A2), 2) + pow((B1-B2), 2));
    printf("\nDistancia euclidiana das coordenadas: %.2f\n", D);

}

void EX2(char STRGC[50])
{
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    for(int I = 0; I <= 50; I++)
    {
        if(toupper(STRGC[I]) == 'A')
            a += 1;
        if(toupper(STRGC[I]) == 'E')
            e += 1;
        if(toupper(STRGC[I]) == 'I')
            i += 1;
        if(toupper(STRGC[I]) == 'O')
            o += 1;
        if(toupper(STRGC[I]) == 'U')
            u += 1;
    }

    printf("Quantidade de letras:\n");
    printf("%d letras A\n", a);
    printf("%d letras E\n", e);
    printf("%d letras I\n", i);
    printf("%d letras O\n", o);
    printf("%d letras U\n", u);
}

void EX3(int A, int B, int *S)
{
    for(int I = A; I <= B; I++)
    {
        *S += I;
    }
}

void EX4(int *A, int *B)
{
    int X = 0;

    X = *A;
    *A = *B;
    *B = X;
}

int EX5(int A)
{
    int C = 0, S = A, V;

    do
    {
        S /= 10;
        C += 1;
    }while( S > 0);

    V = C;

    for(int I = 1; I <= C; I++)
    {
        int Expoente = pow(10, V-1);
        S += A / Expoente;
        A = A % Expoente;
        V--;
    }

return S;
}

int main(void)
{
    int X1, X2, Y1, Y2;
    char FRASE[50];

    printf("<<<< EXERCICIO 1 DA LISTA >>>>\n\n");

    printf("Digite a coordenada X do ponto 1: ");
    scanf("%d", &X1);
    printf("\nDigite a coordenada Y do ponto 1: ");
    scanf("%d", &Y1);
    printf("\nDigite a coordenada X do ponto 2: ");
    scanf("%d", &X2);
    printf("\nDigite a coordenada Y do ponto 2: ");
    scanf("%d", &Y2);

    Deuclides(X1, Y1, X2, Y2);

    printf("\n<<<< EXERCICIO 2 DA LISTA >>>>\n\n");

    while( (getchar()) != '\n');
    printf("Digite uma frase: ");
    fgets(FRASE, sizeof(FRASE), stdin);

    EX2(FRASE);

    printf("\n<<<< EXERCICIO 3 DA LISTA >>>>\n\n");

    printf("Digite um numero de partida: ");
    scanf("%d", &X1);
    printf("\nDigite um numero de chegada: ");
    scanf("%d", &X2);
    Y1 = 0;

    EX3(X1, X2, &Y1);

    printf("\nO somatorio eh de: %d", Y1);

    printf("\n<<<< EXERCICIO 4 DA LISTA >>>>\n\n");

    printf("Digite um numero qualquer: ");
    scanf("%d", &X1);
    printf("\nDigite outro numero qualquer: ");
    scanf("%d", &X2);

    printf("Variaveis digitadas:  %d    %d", X1, X2);

    EX4(&X1, &X2);

    printf("\nVariaveis invertidas: %d    %d\n", X1, X2);

    printf("\n<<<< EXERCICIO 5 DA LISTA >>>>\n\n");

    printf("Digite um numero inteiro de 1 a %d: ", INT_MAX);
    scanf("%d", &X1);

    printf("\nA soma dos algarismos do numero digitado eh de: %d\n", EX5(X1));

return 0;
}
