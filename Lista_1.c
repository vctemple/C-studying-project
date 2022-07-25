// LISTA1 - Funções em C
// VICTOR TEMPLE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void EX1 (void)
{
    float M, CM, ML;

    printf("\nEntre uma distancia em metros: ");
    scanf("%f", &M);

    CM = M * 100;

    ML = M * 1000;

    printf("\nDistancia em centimetros: %.2f", CM);

    printf("\nDistancia em milimetros: %.2f \n\n", ML);

}

void EX2 (void)
{

    float F1, C1;
    int F2, C2;
    char X;

    printf("\nUtilizar dados inteiros ou decimais? [I/F]: ");
    scanf("%c", &X);
    while( (getchar()) != '\n');

    if(X=='F')
    {
        printf("Digite uma temperatura em Fahrenheit: ");
        scanf("%f", &F1);

        C1 = (F1 - 32.0) * (5.0/9.0);

        printf("\nTemperatura em Celsius: %.2f \n\n", C1);
    }
    else
    {
        printf("Digite uma temperatura em Fahrenheit: ");
        scanf("%d", &F2);

        C2 = (F2 - 32.0) * (5.0/9.0);

        printf("\nTemperatura em Celsius: %d \n\n", C2);
    }

}

void EX3 (void)
{
    float IMC, PESO, H;

    printf("\nDigite o peso em Kg: ");
    scanf("%f", &PESO);

    printf("\nEntre com sua altura em metros: ");
    scanf("%f", &H);

    IMC = PESO / pow(H,2);

    printf("\n\O IMC deste peso: %.2f \n\n", IMC);


}

void EX4 (void)
{
    float X, Y, Z, P1, P2, P3, M;

    printf("\nDigite o primeiro valor: ");
    scanf("%f", &X);

    printf("\nDigite o segundo valor: ");
    scanf("%f", &Y);

    printf("\nDigite o terceiro valor: ");
    scanf("%f", &Z);

    printf("\nDigite o primeiro peso: ");
    scanf("%f", &P1);

    printf("\nDigite o segundo peso: ");
    scanf("%f", &P2);

    printf("\nDigite o terceiro peso: ");
    scanf("%f", &P3);

    M = (P1 * X + P2 * Y + P3 * Z) / (P1 + P2 + P3);

    printf("\nA media ponderada eh de: %.2f \n\n", M);

}

void EX5 (void)
{
    float VM, So, Sf, To, Tf;

    printf("\nDigite a posicao inicial o objeto [Metros]: ");
    scanf("%f", & So);

    printf("\nDigite a posicao final o objeto [Metros]: ");
    scanf("%f", & Sf);


    printf("\nDigite o tempo inicial do objeto [Segundos]: ");
    scanf("%f", & To);

    printf("\nDigite o tempo final do objeto [Segundos]: ");
    scanf("%f", & Tf);

    VM = (Sf-So) / (Tf-To);

    printf("\nVelocidade media [m/s]: %.2f \n\n", VM);

}

void EX6 (void)
{
    float S, Sup;

    printf("\nDigite o respectivo salario: ");
    scanf("%f", &S);

    Sup = S * 1.25;

    printf("\nSeu salario será: %.2f \n\n", Sup);

}

void EX7 (void)
{
    float Real, Cot, Dolar;

    printf("\nDigite o montante em reais: ");
    scanf("%f", &Real);

    printf("Digite a cotacao atual do dolar: ");
    scanf("%f", &Cot);

    Dolar = Real * Cot;

    printf("\nValor em dolar: %.2f \n\n", Dolar);

}

void EX8 (void)
{
    int N, Ant, Suc, SOMA;

    printf("\nDigite um numero inteiro: ");
    scanf("%d", &N);

    Suc = (N * 3) + 1;
    Ant = (N * 2) - 1;
    SOMA = Ant + Suc;

    printf("\nSucessor do triplo: %d\n", Suc);
    printf("Antecessor do dobro: %d\n", Ant);
    printf("Soma = %d \n\n", SOMA);

}

void EX9 (void)
{
    int N;

    printf("\nDigite um numero de 4 digitos: ");
    scanf("%d", &N);

    printf("N1: %d\n", N / 1000);

    N %= 1000;
    printf("N2: %d\n", N / 100);

    N %= 100;
    printf("N3: %d\n", N / 10);

    printf("N4: %d\n\n", N % 10);

}

void EX10 (void)
{
    float Mo = 1000.00, D1, D2, D3, D4;

    D1 = Mo * (1.0-0.034);
    D2 = D1 * 1.028;
    D3 = D2 * 1.14;
    D4 = D3 * (1.0-0.085);


    printf("\nMontante inicial em reais: %.2f\n", Mo);
    printf("Dia 1 com queda de 3.4 pontos: %.2f\n", D1);
    printf("Dia 2 com alta de 2.8 pontos: %.2f\n", D2);
    printf("Dia 3 com alta de 14 pontos: %.2f\n", D3);
    printf("Dia 4 com queda de 8.5 pontos: %.2f\n\n", D4);

}

void EX11 (void)
{
    float N;

    printf("\nDigite um numero: ");
    scanf("%f", &N);

    printf("\nQuadrado do numero: %.2f\n", pow(N, 2));
    printf("Cubo do numero: %.2f\n\n", pow(N, 3));

}

void EX12 (void)
{
    float P, H;
    char S;

    printf("\nDigite o sexo [M/F]: ");
    scanf("%c", &S);
    while( (getchar()) != '\n');

    printf("Digit altura [Em metros]: ");
    scanf("%f", &H);

    if(S=='M')
    {
        P = (72.7 * H) - 58.0;
    }
    else
    {
        P = (62.1 * H) - 44.7;
    }

    printf("\nPeso ideal: %.2f\n\n", P);

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
    printf("EX5  = [5] \n");
    printf("EX6  = [6] \n");
    printf("EX7  = [7] \n");
    printf("EX8  = [8] \n");
    printf("EX9  = [9] \n");
    printf("EX10 = [10] \n");
    printf("EX11 = [11] \n");
    printf("EX12 = [12] \n");
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

            case 7:
                EX7();
                break;

            case 8:
                EX8();
                break;

            case 9:
                EX9();
                break;

            case 10:
                EX10();
                break;

            case 11:
                EX11();
                break;

            case 12:
                EX12();
                break;
        }

        printf("\nPressione Enter para continuar \n");
        while( (getchar()) != '\n');

        getchar();
        system("@cls||clear");

    }while(X != 0);

return 0;
}
