#include <stdio.h>
#define TAMANHO_TAB 10 //Tamanho do taabuleiro
#define TAMANHO_NAV 3 //Tamanho do navio

/*Caso se queira alterar o tamanho do tabuleiro ou do navio, basta apenas mudar o valor 
das constantes, e todo o resto do código se adaptará autoamticamente aos novos valores*/

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void escreveTabuleiro(int tab[TAMANHO_TAB][TAMANHO_TAB]){
    printf(" \t");

    for(char letra = 'A'; letra < 'A'+TAMANHO_TAB; letra++){
        printf("%c ",letra); //Imprime a representação das colunas, de A a J
        /*A expressão 'A'+TAMANHO_TAB automatiza a escrita da representação das colunas, caso
        haja um aumento no tamanho da tabela*/
    }
    
    printf("\n\n");

    for(int i = 0; i < TAMANHO_TAB; i++){
        printf("%d\t",i+1); //Imprime a representação das linhas. a soma de i+1 altera o intervalo de 0 a 9 para 1 a 10
        for(int j = 0;j < TAMANHO_TAB;j++){
            printf("%d ",tab[i][j]); //Imprime cada valor da matriz de forma organizada
        }
        printf("\n");
    }
}

void preencheTabuleiro(int tab[TAMANHO_TAB][TAMANHO_TAB]){
    for(int i = 0; i < TAMANHO_TAB; i++){
        for(int j = 0; j < TAMANHO_TAB; j++){
            tab[i][j] = 0; //Preenche cada posição da matriz com o valor 0
        }
    }

    escreveTabuleiro(tab);
}

void posicionaNavio(int tab[TAMANHO_TAB][TAMANHO_TAB], int nav[TAMANHO_NAV], int posicao, int inicio, int eixo){
    for (int i = inicio, j = 0; j < TAMANHO_NAV; i++, j++)
    {
        //A variável inicio faz referência à posição inicial do navio no vetor
        //A variável eixo indica o valor da linha/coluna fixa, a qual pertencerá o navio

        switch (posicao){
        case 1://Horizontal, a linha é fixa e a coluna é variável
            tab[eixo][i] = nav[j];
            break;
        case 2://Vertical, a coluna é fixa e a linha é variável
            tab[i][eixo] = nav[j];
            break;
        case 3://Diagonal principal, o valor da linha e coluna são iguais e aumentam igualmente
            tab[i][i] = nav[j];
            break;
        case 4://Diagonal secundária, o valor da coluna se inicia de forma oposta, da direita para a esquerda, diminuindo o valor
            tab[i][TAMANHO_TAB - 1 - i] = nav[j];
            break;
        }
    }
    
    escreveTabuleiro(tab);
}

void preencheNavio(int nav[TAMANHO_NAV]){
    for(int i = 0; i < TAMANHO_NAV; i++){
        nav[i] = 3; //Preenche cada posição do navio com o valor 3
    }
    
}

int main() {
    int tabuleiro[TAMANHO_TAB][TAMANHO_TAB];
    int navio[TAMANHO_NAV];    

    printf("-----JOGO BATALHA NAVAL-----\n\n");

    preencheTabuleiro(tabuleiro); //Preenche toda a matriz com o valor 0
    preencheNavio(navio);//Preenche o navio com a posição 3
    
    printf("\nPosicionando o navio 1\n\n");
    posicionaNavio(tabuleiro,navio,1,2,0);

    printf("\nPosicionando o navio 2\n\n");
    posicionaNavio(tabuleiro,navio,2,7,8);
    
    printf("\nPosicionando o navio 3\n\n");
    posicionaNavio(tabuleiro,navio,3,4,NULL);

    printf("\nPosicionando o navio 4\n\n");
    posicionaNavio(tabuleiro,navio,4,0,NULL);


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    return 0;
}