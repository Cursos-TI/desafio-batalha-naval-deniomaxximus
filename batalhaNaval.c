#include <stdio.h>
#define TAMANHO_TAB 10
#define TAMANHO_NAV 3
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void escreveTabuleiro(int tab[TAMANHO_TAB][TAMANHO_TAB]){
    printf(" \t");

    for(char letra = 'A'; letra < 'A'+TAMANHO_TAB; letra++){
        
        printf("%c ",letra); //Imprime a representalção das colunas, de A a J
    }
    
    printf("\n\n");

    for(int i = 0; i < TAMANHO_TAB; i++){
        printf("%d\t",i+1); //Imprime a representação das linhas. a soma de i+1 altera o intervalo de 0 a 9 para 1 a 10
        for(int j = 0;j < TAMANHO_TAB;j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

void preencheTabuleiro(int tab[TAMANHO_TAB][TAMANHO_TAB]){
    for(int i = 0; i < TAMANHO_TAB; i++){
        for(int j = 0; j < TAMANHO_TAB; j++){
            tab[i][j] = 0;
        }
    }

    escreveTabuleiro(tab);
}

void posicionaNavio(int tab[TAMANHO_TAB][TAMANHO_TAB], int nav[TAMANHO_NAV], int posicao, int inicio, int eixo){
    for (int i = inicio, j = 0; j < TAMANHO_NAV; i++, j++)
    {
        switch (posicao){
        case 1://Horizontal
            tab[eixo][i] = nav[j];
            break;
        case 2://Vertical
            tab[i][eixo] = nav[j];
            break;
        case 3://Diagonal principal
            tab[i][i] = nav[j];
            break;
        case 4://Diagonal secundária
            tab[i][TAMANHO_TAB - 1 - i] = nav[j];
            break;
        }
    }
    
    escreveTabuleiro(tab);
}

void preencheNavio(int nav[TAMANHO_NAV]){
    for(int i = 0; i < TAMANHO_NAV; i++){
        nav[i] = 3;
    }
    
}

int main() {
    int tabuleiro[TAMANHO_TAB][TAMANHO_TAB];
    int navio[TAMANHO_NAV];    

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    printf("-----JOGO BATALHA NAVAL-----\n\n");

    preencheTabuleiro(tabuleiro); //Preenche toda a matriz com o valor 0
    preencheNavio(navio);
    
    printf("\nPosicionando o navio 1\n\n");
    posicionaNavio(tabuleiro,navio,1,2,0);

    printf("\nPosicionando o navio 2\n\n");
    posicionaNavio(tabuleiro,navio,2,7,8);
    
    printf("\nPosicionando o navio 3\n\n");
    posicionaNavio(tabuleiro,navio,3,4,NULL);

    printf("\nPosicionando o navio 4\n\n");
    posicionaNavio(tabuleiro,navio,4,0,NULL);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    return 0;
}