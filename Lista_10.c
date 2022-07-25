// LISTA10 - Pilha est�tica simples
// VICTOR TEMPLE

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct sElem // CRIA��O DO ELEMENTO QUE SER� ARMAZENADO NA PILHA
{
    int Identificador;
    char Proprietario[60];
    char Datafab[11];
}CONTAINER;

typedef struct sPilha // CRIA��O DA ESTRUTURA DE DADOS PILHA
{
    CONTAINER Elem[TAM];
    int Topo;
}PILHA;

void inicializar_pilha(PILHA *Pilha) // AO INICIAR A PILHA TORNAMOS O TOPO DA PILHA VAZIO: -1
{
    Pilha->Topo = -1;
}

int pilha_vazia(PILHA *Pilha) // PILHA VAZIA CASO O TOPO FOR -1
{
    if(Pilha->Topo == -1)
    {
        return 1; // CASO FOR RETORNA VALOR 1
    }
    else
    {
        return 0;
    }
}

int pilha_cheia(PILHA *Pilha) // PILHA CHEIA CASO O TOPO FOR 4 (5 ELEMENTOS PREENCHIDOS)
{
    if(Pilha->Topo == (TAM-1))
    {
        return 1; // RETORNA 1 PARA SABERMOS QUE SIM
    }
    else
    {
        return 0;
    }
}

int emplilhar_elemento(PILHA *Pilha, CONTAINER Elemento) // COMO ARGUMENTO RECEBE A PILHA E O ELEMENTO A SER EMPILHADO
{
    if(pilha_cheia(Pilha)) // VERIFICA SE A PILHA EST� CHEIA, CASO SIM, A OPERA��O SE ENCERRA
    {
        printf("\nPILHA CHEIA!\nImpossivel empilhar novo elemento.");
        return 0;
    }

    Pilha->Elem[Pilha->Topo+1] = Elemento; // O ELEMENTO NA POSI��O DO TOPO+1 RECEBE O ARGUMENTO
    Pilha->Topo++; // � FEITO O ACR�SCIMO DO TOPO PARA A CONTAGEM
    return 1;
}

int retirar_elemento(PILHA *Pilha) // � PASSADO SOMENTE A PILHA COMO ARGUMENTO POIS O ELEMENTO J� EXISTE NELA
{
    if(pilha_vazia(Pilha)) // VERIFICA SE A PILHA TEM ELEMENTOS PARA TIRAR
    {
        printf("\nPILHA VAZIA!\nNao ha o que retirar.");
        return 0; // CASO N�O, � RETORNADO 0
    }

    // � MOSTRADO O ELEMENTO DO TOPO QUE SER� RETIRADO
    printf("\nNumero identificador: %d", Pilha->Elem[Pilha->Topo].Identificador);
    printf("\nNome do proprietario: %s", Pilha->Elem[Pilha->Topo].Proprietario);
    printf("\n  Data de fabricacao: %s", Pilha->Elem[Pilha->Topo].Datafab);
    Pilha->Topo--; // DECREMENTA-SE O TOPO O QUE EQUIVALE TER TIRADO O ELEMENTO, CASO ADICIONADO OUTRO ELEMENTO, � SOBREESCRITO O QUE J� � EXISTENTE
    return 1; // RETORNA 1 PARA INDICAR QUE O PROCEDIMENTO OBTEVE �XITO
}

void ver_topo(PILHA *Pilha)
{
    if(pilha_vazia(Pilha)) // VERIFICA SE A PILHA TEM ELEMENTO NO TOPO
    {
        printf("\nPILHA VAZIA!\nNao ha o que visualizar.");
        return; // SE ENCERRA A SUB-ROTINA
    }

    // S�O MOSTRDAS AS INFORMA��ES DO ELEMENTO DO TOPO
    printf("\nNumero identificador: %d", Pilha->Elem[Pilha->Topo].Identificador);
    printf("\nNome do proprietario: %s", Pilha->Elem[Pilha->Topo].Proprietario);
    printf("\n  Data de fabricacao: %s", Pilha->Elem[Pilha->Topo].Datafab);
}

void pesquisar_pilha(PILHA *Pilha, int Id)
{
    PILHA Aux;
    inicializar_pilha(&Aux);

    //FOI CRIADO UM LOOP PARA PESQUISAR O CONTAINER ASSIM OS REEMPILHANDO EM OUTRA PILHA
    do
    {
        Aux.Elem[Aux.Topo+1] = Pilha->Elem[Pilha->Topo];
        Aux.Topo++;
        Pilha->Topo--;

        if(Aux.Elem[Aux.Topo].Identificador == Id)
        {
            printf("\nNumero identificador: %d", Aux.Elem[Aux.Topo].Identificador);
            printf("\nNome do proprietario: %s", Aux.Elem[Aux.Topo].Proprietario);
            printf("\n  Data de fabricacao: %s", Aux.Elem[Aux.Topo].Datafab);
        }

        if(Pilha->Topo == -1) // CASO O NUMERO N�O BATA COM NENHUM DA PILHA � EFEITUADA A SAIDA DO LA�O ATRAVEZ DE UM GOTO
        {
            printf("\nNumero ID informado incorreto!");
            goto label;
        }
    }while(Aux.Elem[Aux.Topo].Identificador == Id);

    label: //NA LABEL � FEITO O EMPILHAMENTO NOVAMENTE
        do
        {
            Pilha->Elem[Pilha->Topo+1] = Aux.Elem[Aux.Topo];
            Pilha->Topo++;
            Aux.Topo--;
        }while(Aux.Topo >= -1);
}

void imprimir_pilha(PILHA Pilha)
{
    PILHA Aux;
    inicializar_pilha(&Aux);

    do
    {
        Aux.Elem[Aux.Topo+1] = Pilha.Elem[Pilha.Topo];

        printf("\nNumero identificador: %d", Aux.Elem[Aux.Topo].Identificador);
        printf("\nNome do proprietario: %s", Aux.Elem[Aux.Topo].Proprietario);
        printf("\n  Data de fabricacao: %s", Aux.Elem[Aux.Topo].Datafab);

        Aux.Topo++;
        Pilha.Topo--;
    }while(Pilha.Topo >= -1);
}

int main(void)
{
    PILHA P; // CRIA��O DA PILHA
    int op;
    inicializar_pilha(&P);

    do
    {
        printf("================[MENU]===============\n");
        printf("\n");
        printf(".........................SAIR[0].....\n");
        printf("...........VERIFICAR SE VAZIA[1].....\n");
        printf("...........VERIFICAR SE CHEIA[2].....\n");
        printf("......EMPILHAR NOVO CONTAINER[3].....\n");
        printf("....RETIRAR CONTAINER DO TOPO[4].....\n");
        printf("..............VISUALIZAR TOPO[5].....\n");
        printf("...........PESQUISAR NA PILHA[6].....\n");
        printf("..........IMPRIMIR TODA PILHA[7].....\n");

        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);

        switch(op)
        {
            case 0:
                printf("\nSair do programa \n");
                break;

            case 1:
                if(pilha_vazia(&P))
                {
                    printf("\nNao ha elementos na lista ainda!");
                }
                else
                {
                    printf("\nHa elementos na lista!");
                }
                break;

            case 2:
                if(pilha_cheia(&P))
                {
                    printf("\nA pilha esta lotada!");
                }
                else
                {
                    printf("\nAinda e possivel empilhar um elemento!");
                }
                break;

            case 3:;
                CONTAINER NewElem;

                // O USU�RIO PREENCHE AS INFORMA��ES PARA POSTERIORMENTE ENVI�-LAS PARA A FUN��O
                printf("\nDigite o numero de identificacao do Container: ");
                scanf("%d", &NewElem.Identificador);

                while( (getchar()) != '\n');
                printf("\nDigite o nome do proprietario: ");
                scanf("%s", NewElem.Proprietario);

                while( (getchar()) != '\n');
                printf("\nDigite a data de fabricacao: ");
                scanf("%s", NewElem.Datafab);

                if(emplilhar_elemento(&P, NewElem))
                    printf("\nContainer empilhado com sucesso!");
                break;

            case 4:
                if(retirar_elemento(&P))
                    printf("\nContainer retitado com sucesso!");
                break;

            case 5:
                ver_topo(&P);
                break;

            case 6:;
                int Id;

                // O USU�RIO PREENCHE O ID DO CONTAINER PARA POSTERIORMENTE ENVIAR PARA A FUN��O
                printf("\nDigite o c�digo ID do container que deseja pesquisar: ");
                scanf("%d", &Id);

                pesquisar_pilha(&P, Id);
                break;

            case 7:;
                imprimir_pilha(P);
                break;

        }

        printf("\nPressione Enter para continuar \n");

        while( (getchar()) != '\n');
        getchar();

        system("@cls||clear");

    }while(op != 0);

return 0;
}
