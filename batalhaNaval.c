#include <stdio.h>
#define LINHA 10
#define COLUNA 10
#define TAMANHO_BARCO 3
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void escreveTabuleiro(int tab[LINHA][COLUNA]){
    printf(" \t");

    for(char letra = 'A'; letra <= 'J'; letra++){
        printf("%c ",letra); //Imprime a representalção das colunas, de A a J
    }
    
    printf("\n\n");

    for(int i = 0; i < 10; i++){
        printf("%d\t",i+1); //Imprime a representação das linhas. a soma de i+1 altera o intervalo de 0 a 9 para 1 a 10
        for(int j = 0;j < 10;j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

void preencheTabuleiro(int tab[LINHA][COLUNA]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tab[i][j] = 0;
        }
    }
}

int main() {
    int tabuleiro[LINHA][COLUNA];
    int navio1[TAMANHO_BARCO] = {3,3,3}, navio2[TAMANHO_BARCO] = {3,3,3}, navio3[TAMANHO_BARCO] = {3,3,3}, navio4[TAMANHO_BARCO] = {3,3,3};    

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    printf("-----JOGO BATALHA NAVAL-----\n");

    preencheTabuleiro(tabuleiro); //Preenche toda a matriz com o valor 0
    escreveTabuleiro(tabuleiro);  //Imprime a matriz de forma organizada
    
    printf("\nPosicionando o navio 1\n\n");
    
    for(int i = 2, j = 0; j < 3; j++, i++){
        //A variável i = 2 indica o início da posição do barco
        tabuleiro[0][i] = navio1[j];
    }

    escreveTabuleiro(tabuleiro);

    printf("\nPosicionando o navio 2\n\n");

    for(int i = 7, j = 0; j < 3; j++, i++){
        //A variável i = 7 indica o início da posição do barco
        tabuleiro[i][8] = navio2[j];
    }

    escreveTabuleiro(tabuleiro);

    printf("\nPosicionando o navio 3\n\n");

    for(int i = 4; i < 7; i++){
        tabuleiro[i][i] = 3;
    }

    escreveTabuleiro(tabuleiro);

    printf("\nPosicionando o navio 4\n\n");

    for(int i = 0; i < 3; i++){
        tabuleiro[i][LINHA - 1 - i] = 3;
    }

    escreveTabuleiro(tabuleiro);

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