#include <stdio.h>

#define TABULEIRO_TAMANHO 10
#define HABILIDADE_TAMANHO 5

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO]) {
    for (int i = 0; i < TABULEIRO_TAMANHO; i++) {
        for (int j = 0; j < TABULEIRO_TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" ~ "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf(" # "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf(" * "); // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para aplicar a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO], int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO], int origemLinha, int origemColuna) {
    int offset = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            int tabuleiroLinha = origemLinha + i - offset;
            int tabuleiroColuna = origemColuna + j - offset;
            if (tabuleiroLinha >= 0 && tabuleiroLinha < TABULEIRO_TAMANHO && tabuleiroColuna >= 0 && tabuleiroColuna < TABULEIRO_TAMANHO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[tabuleiroLinha][tabuleiroColuna] = 5;
                }
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cone
void criarHabilidadeCone(int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            habilidade[i][j] = 0;
        }
    }
    habilidade[0][2] = 1;
    habilidade[1][1] = 1;
    habilidade[1][2] = 1;
    habilidade[1][3] = 1;
    habilidade[2][0] = 1;
    habilidade[2][1] = 1;
    habilidade[2][2] = 1;
    habilidade[2][3] = 1;
    habilidade[2][4] = 1;
}

// Função para criar a matriz de habilidade em forma de cruz
void criarHabilidadeCruz(int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            habilidade[i][j] = 0;
        }
    }
    habilidade[0][2] = 1;
    habilidade[1][2] = 1;
    habilidade[2][0] = 1;
    habilidade[2][1] = 1;
    habilidade[2][2] = 1;
    habilidade[2][3] = 1;
    habilidade[2][4] = 1;
    habilidade[3][2] = 1;
    habilidade[4][2] = 1;
}

// Função para criar a matriz de habilidade em forma de octaedro
void criarHabilidadeOctaedro(int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            habilidade[i][j] = 0;
        }
    }
    habilidade[0][2] = 1;
    habilidade[1][1] = 1;
    habilidade[1][2] = 1;
    habilidade[1][3] = 1;
    habilidade[2][0] = 1;
    habilidade[2][1] = 1;
    habilidade[2][2] = 1;
    habilidade[2][3] = 1;
    habilidade[2][4] = 1;
    habilidade[3][1] = 1;
    habilidade[3][2] = 1;
    habilidade[3][3] = 1;
    habilidade[4][2] = 1;
}

int main() {
    // Inicializar o tabuleiro com água (0) e alguns navios (3)
    int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO] = {0};
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[3][2] = 3;
    tabuleiro[4][2] = 3;

    // Criar as matrizes de habilidades
    int habilidadeCone[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];
    int habilidadeCruz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];
    int habilidadeOctaedro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];

    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Definir pontos de origem para as habilidades
    int origemConeLinha = 5, origemConeColuna = 5;
    int origemCruzLinha = 2, origemCruzColuna = 7;
    int origemOctaedroLinha = 7, origemOctaedroColuna = 2;

    // Aplicar habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, habilidadeCruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, origemOctaedroLinha, origemOctaedroColuna);

    // Exibir o tabuleiro com as áreas afetadas
    exibirTabuleiro(tabuleiro);

    return 0;
}