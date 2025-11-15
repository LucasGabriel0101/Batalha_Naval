#include <stdio.h>
#include <stdbool.h> 
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

bool posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao);
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int linha_n1 = 2; 
    int coluna_n1 = 3; 
    
    int linha_n2 = 5; 
    int coluna_n2 = 5; 

    printf("--- Posicionamento de Navios (Tamanho %d) ---\n", TAMANHO_NAVIO);

    if (posicionar_navio(tabuleiro, linha_n1, coluna_n1, 'H')) {
        printf("Navio 1 (Horizontal) posicionado com sucesso em (%d, %d).\n", linha_n1, coluna_n1);
    } else {
        printf("ERRO: Navio 1 (Horizontal) FORA dos limites ou sobreposto. Nao posicionado.\n");
    }

    if (posicionar_navio(tabuleiro, linha_n2, coluna_n2, 'V')) {
        printf("Navio 2 (Vertical) posicionado com sucesso em (%d, %d).\n", linha_n2, coluna_n2);
    } else {
        printf("ERRO: Navio 2 (Vertical) FORA dos limites ou sobreposto. Nao posicionado.\n");
    }
    
    printf("\n");
    
    exibir_tabuleiro(tabuleiro);

    return 0;
}

bool posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return false;
        }
    } else if (orientacao == 'V') {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return false;
        }
    } else {
        return false; 
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            if (tabuleiro[linha][coluna + i] != AGUA) return false; 
        } else {
            if (tabuleiro[linha + i][coluna] != AGUA) return false;
        }
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }

    return true;
}

void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("     0 1 2 3 4 5 6 7 8 9\n"); 
    printf("   -----------------------\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i); 
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n"); 
    }
}