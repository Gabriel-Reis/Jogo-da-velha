#include <stdio.h>
#include <stdlib.h>

#define LIMPAR system("cls")

/*
*                           ***** Jogo da Velha *****
*
* Notas da versão 1.0.0:
* Versão Inicial do jogo da velha
* Preparado para implementacao da versao estendida
*
*/

// Armazena nome dos jogadores
void nomes(char jog1[], char jog2[]){

    LIMPAR;
    printf("1.0.0");
    printf("\n\n\n\n\n\n\n\t\t\t\t Bem vindo ao jogo da velha!!!");
    fflush(stdin);
    printf("\n\n\n\n\n\n\n   Digite o nome do Jogador 1:  ");
    gets(jog1);
    fflush(stdin);
    printf("   Digite o nome do Jogador 2:  ");
    gets(jog2);
    LIMPAR;
}

// Menu com opções
int menu(void){

    int x, op=0;
    while (op == 0)
    {
        LIMPAR;
        printf("1.0.0");
        printf("\n\n\n\n\n\n\n\t\t\t\t Bem vindo ao jogo da velha!!!");
        printf("\n\n\n\n\n\n\n\tQual versao deseja jogar?\n");
        printf("\t1 - Versao classica\n");
        printf("\t2 - Versao estendida\n");
        printf("\n\tOpcao escolhida:  ");
        scanf("%d", &x);
        if (x==1)
            return 1;
        else if (x==2)
            return 2;
        else
            op = 0;
    }
}

// Exibe o jogo atual
void exibejogo(char mat[3][3]){

    LIMPAR;
    printf("\n\n\n");
    printf("\t\t      1   2   3\n");
    printf("\t\t    -------------\n");
    printf("\t\t1 - | %c | %c | %c |\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("\t\t    -------------\n");
    printf("\t\t2 - | %c | %c | %c |\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("\t\t    -------------\n");
    printf("\t\t3 - | %c | %c | %c |\n", mat[2][0], mat[2][1], mat[2][2]);
    printf("\t\t    -------------\n\n\n\n");
}

// Processa jogada atual
void jogada(char mat[3][3], char jog[], char inst){

    int x,y,op=1;

    while (op == 1)
    {
        system ("cls");
        exibejogo(mat);
        printf("  %s, \n  Escolha a linha e coluna para preencher com %c:  ", jog, inst);
        scanf ("%d %d", &x, &y);
            if (mat[x-1][y-1] == ' ')
                {
                    mat[x-1][y-1] = inst;
                    break;
                }
            else if (mat[x-1][y-1] != ' ')
            {
                printf("Posicao ja utilizada anteriormente. \nTente novamente\n\n\n");
                system("pause");
                op = 1;
            }
    }
}

// Limpa matriz do jogo atual
void limpamatriz(char mat[3][3]){

    int i,j;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            mat[i][j] = ' ';
}

// Verifica se há ganhadores
int ganhador(int tam, char mat[tam][tam], char jog[], char jogesp[], int k){
    int i,j,count =0;
    //linhas
    if  ((mat[0][0] == mat[0][1] && mat[0][1] == mat[0][2] && mat[0][0] != ' ') ||
        (mat[1][0] == mat[1][1] && mat[1][1] == mat[1][2] && mat[1][0] != ' ') ||
        (mat[2][0] == mat[2][1] && mat[2][1] == mat[2][2] && mat[2][0] != ' '))
    {
        LIMPAR;
        exibejogo(mat);
        printf("\n\n\t\t%s Ganhou. Parabens!!!\n\n\n", jog);
        return 1;
    }
    //colunas
    else if  ((mat[0][0] == mat[1][0] && mat[1][0] == mat[2][0] && mat[0][0] != ' ') ||
             (mat[0][1] == mat[1][1] && mat[1][1] == mat[2][1] && mat[0][1] != ' ') ||
             (mat[0][2] == mat[1][2] && mat[1][2] == mat[2][2] && mat[0][2] != ' '))
    {
        LIMPAR;
        exibejogo(mat);
        printf("\n\n\t\t%s Ganhou. Parabens!!!\n\n\n", jog);
        return 1;
    }
    //diagonais
    else if  ((mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[0][0] != ' ') ||
             (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[0][2] != ' '))
    {
        LIMPAR;
        exibejogo(mat);
        printf("\n\n\t\t%s Ganhou. Parabens!!!\n\n\n", jog);
        return 1;
    }
    //Empate
    for(i=0; i<tam; i++)
        for(j=0; j<tam; j++)
            if (mat[i][j] == 'X' || mat[i][j] == 'O')
                count++;
    if (count == tam*tam)
    {
        LIMPAR;
        exibejogo(mat);
        printf("\n\n\t\t O Jogo deu velha!!!");
        printf("\n\t\t %s e %s empataram desta vez !!!\n\n\n", jog, jogesp);
        return 1;
    }
return 0;
}

// Jogo clássico
int classica(int tam, char mat[tam][tam], char jog1[], char jog2[]){

    int i,j;

    printf("Versao Classica:   \n\n");
    for (i=0; i<5; i++)
    {
        jogada(mat, jog1, 'X');
        if ( ganhador(tam, mat, jog1, jog2, i) == 1)
            return 1;
        jogada(mat, jog2, 'O');
        if ( ganhador(tam, mat, jog2, jog1, i) == 1)
            return 1;
    }
return 0;
}

// Jogo de tamanho estendido
void estendida(void){
    LIMPAR;
    printf("Versao Estendida:   ");
    printf("Versão disponivel somente na versao 2.0.0");
}

// Recomeçar jogo
int jogar_novamente(void){

    int op=1;
    char ag;

    while (op == 1)
    {
        system("pause");
        LIMPAR;
        printf("\n\n\n\n\n\n\n");
        printf("\t\t Deseja jogar novamente ? \n");
        printf("\t\t S - Sim\n");
        printf("\t\t N - Nao\n");
        printf("\n\n\t\t Sua escolha: ");
        scanf(" %c", &ag);
        if (ag == 's' || ag =='S')
            return 1;
        else if (ag == 'n' || ag == 'N')
            return 0;
        else
        {
            op = 1;
            printf("\n\tOpcao invalida. Tente novamente.\n\t");
        }
    }
}

// Agradecimentos
void agradecimento (void){
    LIMPAR;
    printf ("\n\n\n\n\n\n\n\n\n\n\n\n\t\t        Obrigado por usar este programa!!\n");
    printf ("\t\tDesenvolvido por: Gabriel Augusto Requena dos Reis\n");
    printf ("\t\t       Sistemas de informacao - UFOP (2016) \n\n\n\n\n");
    system ("pause");
}

// Função principal
int main (){

    int op = 1, tam=3;
    char jog1[31], jog2[31], mat[tam][tam];

    nomes(jog1, jog2);

    while (op == 1)
    {
        limpamatriz(mat);

        if (menu() == 1)
            classica(tam, mat, jog1, jog2);
        else
            estendida();
        op = jogar_novamente();
    }

    agradecimento();

return 0;
}
