// LISTA6 - ESTRUTURAS DE DADOS [EDDA3]
// VICTOR TEMPLE - CJ3011771

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct sEndereco
{
    char RUA[50];
    char NRUA[7];
    char BAIRRO[50];
    char CEP[8];
    char CIDADE[30];
    char ESTADO[2];
}s_endereco;

typedef struct sAluno
{
    char NOME[50];
    char DATANASC[11];
    s_endereco END;
    char TEL[12];
    char MATRICULA[4];
    int N1, N2, N3, FALT;
}s_aluno;

void f_cadastro(s_aluno *A)
{
    while( (getchar()) != '\n');
    printf("\nDigite o nome do aluno: ");
    scanf("%[^\n]", A->NOME);

    while( (getchar()) != '\n');
    printf("\nDigite a data de nascimento: ");
    scanf("%[^\n]", A->DATANASC);

    while( (getchar()) != '\n');
    printf("\nDigite o nome da rua: ");
    scanf("%[^\n]", A->END.RUA);

    while( (getchar()) != '\n');
    printf("\nDigite o nemero do endereco: ");
    scanf("%[^\n]", A->END.NRUA);

    while( (getchar()) != '\n');
    printf("\nDigite o bairro: ");
    scanf("%[^\n]", A->END.BAIRRO);

    while( (getchar()) != '\n');
    printf("\nDigite o CEP: ");
    scanf("%[^\n]", A->END.CEP);

    while( (getchar()) != '\n');
    printf("\nDigite a cidade: ");
    scanf("%[^\n]", A->END.CIDADE);

    while( (getchar()) != '\n');
    printf("\nDIgite o estado [sigla]: ");
    scanf("%[^\n]", A->END.ESTADO);

    while( (getchar()) != '\n');
    printf("\nDigite o telefone do aluno [0+ddd+numero]: ");
    scanf("%[^\n]", A->TEL);

    printf("\nDigite a nota da primeira prova: ");
    scanf("%d", &A->N1);

    printf("\nDigite a nota da segunda prova: ");
    scanf("%d", &A->N2);

    printf("\nDigite a nota da terceira prova: ");
    scanf("%d", &A->N3);

    printf("\nDigite o numero de faltas do alunos: ");
    scanf("%d", &A->FALT);
}

void f_exluir(s_aluno* A)
{
    s_aluno ALUNOnada;
    int op;
    printf("\n<<< Aluno selecionado >>>");
    printf("\nNOME: %s", A->NOME);
    printf("\nTELEFONE: %s", A->TEL);
    printf("\nMATRICULA: %s", A->MATRICULA);
    printf("\nTem certeza que deseja deletar este aluno? [1 para SIM / 0 para NAO]: ");
    scanf("%d", &op);

    if(op == 1)
        {
            *A = ALUNOnada;
        }
}

void f_editar(s_aluno* A)
{
    int op;
    printf("\n<<< Aluno selecionado >>>");
    printf("\nNOME: %s", A->NOME);
    printf("\nTELEFONE: %s", A->TEL);
    printf("\nMATRICULA: %s", A->MATRICULA);
    printf("\nTem certeza que deseja editar este aluno? [1 para SIM / 0 para NAO]: ");
    scanf("%d", &op);

    if(op == 1)
        {
            while( (getchar()) != '\n');
            printf("\nDigite o nome do aluno: ");
            scanf("%[^\n]", A->NOME);

            while( (getchar()) != '\n');
            printf("\nDigite a data de nascimento: ");
            scanf("%[^\n]", A->DATANASC);

            while( (getchar()) != '\n');
            printf("\nDigite o nome da rua: ");
            scanf("%[^\n]", A->END.RUA);

            while( (getchar()) != '\n');
            printf("\nDigite o nemero do endereco: ");
            scanf("%[^\n]", A->END.NRUA);

            while( (getchar()) != '\n');
            printf("\nDigite o bairro: ");
            scanf("%[^\n]", A->END.BAIRRO);

            while( (getchar()) != '\n');
            printf("\nDigite o CEP: ");
            scanf("%[^\n]", A->END.CEP);

            while( (getchar()) != '\n');
            printf("\nDigite a cidade: ");
            scanf("%[^\n]", A->END.CIDADE);

            while( (getchar()) != '\n');
            printf("\nDIgite o estado [sigla]: ");
            scanf("%[^\n]", A->END.ESTADO);

            while( (getchar()) != '\n');
            printf("\nDigite o telefone do aluno [0+ddd+numero]: ");
            scanf("%[^\n]", A->TEL);

            printf("\nDigite a nota da primeira prova: ");
            scanf("%d", &A->N1);

            printf("\nDigite a nota da segunda prova: ");
            scanf("%d", &A->N2);

            printf("\nDigite a nota da terceira prova: ");
            scanf("%d", &A->N3);

            printf("\nDigite o numero de faltas do alunos: ");
            scanf("%d", &A->FALT);
        }
}

void f_vizu(s_aluno* A)
{
    printf("\nNOME: %s", A->NOME);
    printf("\nDATA DE NASCIMENTO: %s", A->DATANASC);
    printf("\nENDERECO: %s", A->END.RUA);
    printf("\nNUMERO DA RUA: %s", A->NOME);
    printf("\nBAIRRO: %s", A->END.BAIRRO);
    printf("\CEP: %s", A->END.CEP);
    printf("\nCIDADE: %s", A->END.CIDADE);
    printf("\nESTADO: %s", A->END.ESTADO);
    printf("\nTELEFONE: %s", A->TEL);
    printf("\nMATRICULA: %s", A->MATRICULA);
}

void f_media(s_aluno* A)
{
    float media;
    printf("\n<<< Aluno selecionado >>>");
    printf("\nNOME: %s", A->NOME);
    printf("\nTELEFONE: %s", A->TEL);
    printf("\nMATRICULA: %s", A->MATRICULA);
    printf("\nProva 1: %d", A->N1);
    printf("\nProva 2: %d", A->N2);
    printf("\nProva 3: %d", A->N3);

    media = (float)(A->N1+A->N2+A->N3) / 3.0;
    printf("\nMEDIA FINAL: %.2f", media);

}

void f_faltas(s_aluno* A)
{
    printf("\n<<< Aluno selecionado >>>");
    printf("\nNOME: %s", A->NOME);
    printf("\nTELEFONE: %s", A->TEL);
    printf("\nMATRICULA: %s", A->MATRICULA);
    printf("\nNUMERO DE FALTAS: %d", A->FALT);
}

int f_menu(void)
{
    int op;

    printf("==========[MENU DE OPCOES]==========\n");
    printf("\n");
    printf("..........................SAIR: [0] \n");
    printf("...............CADASTRAR ALUNO: [1] \n");
    printf(".................EXCLUIR ALUNO: [2] \n");
    printf("..................EDITAR ALUNO: [3] \n");
    printf(".....VISUALIZAR CADASTRO ALUNO: [4] \n");
    printf(".....VISUALIZAR MEDIA DE ALUNO: [5] \n");
    printf("....VISUALIZAR FALTAS DE ALUNO: [6] \n");
    printf("\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &op);

    return op;
}


int main(void)
{
    s_aluno ALUNO[50];
    int MENU, N_ALUNO, op, comp;
    char MAT[4];

    do
    {
        MENU = f_menu();

        switch(MENU)
        {
            case 0:
                printf("\nSair do programa \n");
                break;

            case 1:
                do
                {
                    char MAT0[4] = "\000\000\000";
                    N_ALUNO = 0;
                    comp = strcmp(ALUNO[N_ALUNO].MATRICULA, MAT0);
                    if(comp == 0)
                    {

                        break;
                    }
                    else
                    {
                        N_ALUNO++;
                    }
                }while(ALUNO[N_ALUNO].MATRICULA != 0);

                do
                {
                    f_cadastro(&ALUNO[N_ALUNO]);
                    sprintf(ALUNO[N_ALUNO].MATRICULA, "%d", (N_ALUNO+1));
                    N_ALUNO++;

                    printf("\nCadastrar novamente? [1 para SIM / 0 para NAO]: ");
                    scanf("%d", &op);
                }while(op == 1);
                break;

            case 2:
                do
                {
                    N_ALUNO = 0;
                    while( (getchar()) != '\n');
                    printf("\nInsira a matricula do aluno: ");
                    scanf("%[^\n]", MAT);

                    do
                    {
                        comp = strcmp(MAT, ALUNO[N_ALUNO].MATRICULA);
                        if(comp == 0)
                        {
                            f_exluir(&ALUNO[N_ALUNO]);
                        }
                        else
                        {
                            N_ALUNO++;
                        }
                    }while(comp != 0);

                    printf("\nExcluir outro aluno? [1 para SIM / 0 para NAO]: ");
                    scanf("%d", &op);
                }while(op == 1);
                break;

            case 3:
                do
                {
                    N_ALUNO = 0;
                    while( (getchar()) != '\n');
                    printf("\nInsira a matricula do aluno: ");
                    scanf("%[^\n]", MAT);

                    do
                    {
                        comp = strcmp(MAT, ALUNO[N_ALUNO].MATRICULA);
                        if(comp == 0)
                        {
                            f_editar(&ALUNO[N_ALUNO]);
                        }
                        else
                        {
                            N_ALUNO++;
                        }
                    }while(comp != 0);

                    printf("\nEditar outro aluno? [1 para SIM / 0 para NAO]: ");
                    scanf("%d", &op);
                }while(op == 1);
                break;

            case 4:
                do
                {
                    N_ALUNO = 0;
                    while( (getchar()) != '\n');
                    printf("\nInsira a matricula do aluno: ");
                    scanf("%[^\n]", MAT);

                    do
                    {
                        comp = strcmp(MAT, ALUNO[N_ALUNO].MATRICULA);
                        if(comp == 0)
                        {
                            f_vizu(&ALUNO[N_ALUNO]);
                        }
                        else
                        {
                            N_ALUNO++;
                        }
                    }while(comp != 0);

                    printf("\nVisualizar outro aluno? [1 para SIM / 0 para NAO]: ");
                    scanf("%d", &op);
                }while(op == 1);
                break;

            case 5:
                do
                {
                    N_ALUNO = 0;
                    while( (getchar()) != '\n');
                    printf("\nInsira a matricula do aluno: ");
                    scanf("%[^\n]", MAT);

                    do
                    {
                        comp = strcmp(MAT, ALUNO[N_ALUNO].MATRICULA);
                        if(comp == 0)
                        {
                            f_media(&ALUNO[N_ALUNO]);
                        }
                        else
                        {
                            N_ALUNO++;
                        }
                    }while(comp != 0);

                    printf("\nVerificar media de outro aluno? [1 para SIM / 0 para NAO]: ");
                    scanf("%d", &op);
                }while(op == 1);
                break;

             case 6:
                do
                {
                    N_ALUNO = 0;
                    while( (getchar()) != '\n');
                    printf("\nInsira a matricula do aluno: ");
                    scanf("%[^\n]", MAT);

                    do
                    {
                        comp = strcmp(MAT, ALUNO[N_ALUNO].MATRICULA);
                        if(comp == 0)
                        {
                            f_faltas(&ALUNO[N_ALUNO]);
                        }
                        else
                        {
                            N_ALUNO++;
                        }
                    }while(comp != 0);

                    printf("\nVerificar faltas de outro aluno? [1 para SIM / 0 para NAO]: ");
                    scanf("%d", &op);
                }while(op == 1);
                break;
        }

        printf("\nPressione Enter para continuar \n");
        while( (getchar()) != '\n');

        getchar();
        system("@cls||clear");

    }while(MENU != 0);

return 0;
}
