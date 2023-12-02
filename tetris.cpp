#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[16];
    int pontuacoes[12];
    int pontuacaoFinal;
} Jogador;

int calcularPontuacaoFinal(int pontuacoes[]) {
    int i, menor, maior, soma;
    
    menor = maior = soma = pontuacoes[0];

    for (i = 1; i < 12; i++) {
        soma += pontuacoes[i];
        if (pontuacoes[i] < menor) {
            menor = pontuacoes[i];
        } else if (pontuacoes[i] > maior) {
            maior = pontuacoes[i];
        }
    }

    return soma - menor - maior;
}

int compararJogadores(const void *a, const void *b) {
    Jogador *jogadorA = (Jogador *)a;
    Jogador *jogadorB = (Jogador *)b;

    if (jogadorA->pontuacaoFinal > jogadorB->pontuacaoFinal) {
        return -1;
    } else if (jogadorA->pontuacaoFinal < jogadorB->pontuacaoFinal) {
        return 1;
    } else {
        return strcmp(jogadorA->nome, jogadorB->nome);
    }
}

int main() {
    int J, i, teste = 1;

    while (1) {
        scanf("%d", &J);

        if (J == 0) {
            break;
        }

        Jogador jogadores[J];

        for (i = 0; i < J; i++) {
            scanf("%s", jogadores[i].nome);
            for (int j = 0; j < 12; j++) {
                scanf("%d", &jogadores[i].pontuacoes[j]);
            }
            jogadores[i].pontuacaoFinal = calcularPontuacaoFinal(jogadores[i].pontuacoes);
        }

        qsort(jogadores, J, sizeof(Jogador), compararJogadores);

        // Imprimir resultado
        printf("Teste %d\n", teste++);
        int posicao = 1;
        for (i = 0; i < J; i++) {
            if (i > 0 && jogadores[i - 1].pontuacaoFinal == jogadores[i].pontuacaoFinal) {
                printf("%d %d %s\n", posicao, jogadores[i].pontuacaoFinal, jogadores[i].nome);
            } else {
                printf("%d %d %s\n", i + 1, jogadores[i].pontuacaoFinal, jogadores[i].nome);
                posicao = i + 2;
            }
        }
        printf("\n");
    }

    return 0;
}
