#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 5

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

typedef struct {
    int tipo; // 1 = destruir cor, 2 = conquistar territórios
    char alvo[10];
    int quantidade;
} Missao;

Territorio *territorios;
int total = MAX;
Missao missao;

// ---------------- FUNÇÕES ----------------

void inicializar() {
    territorios = (Territorio*) calloc(MAX, sizeof(Territorio));

    strcpy(territorios[0].nome, "Brasil\n");
    strcpy(territorios[0].cor, "Azul");
    territorios[0].tropas = 5;

    strcpy(territorios[1].nome, "Japao\n");
    strcpy(territorios[1].cor, "Verde");
    territorios[1].tropas = 5;

    strcpy(territorios[2].nome, "EUA\n");
    strcpy(territorios[2].cor, "Vermelho");
    territorios[2].tropas = 5;

    strcpy(territorios[3].nome, "Canada\n");
    strcpy(territorios[3].cor, "Amarelo");
    territorios[3].tropas = 5;

    strcpy(territorios[4].nome, "China\n");
    strcpy(territorios[4].cor, "Verde");
    territorios[4].tropas = 5;
}

void gerarMissao() {
    int r = rand() % 2;

    if (r == 0) {
        missao.tipo = 1;
        strcpy(missao.alvo, "Verde");
        printf("Missão: Destruir o exército Verde\n");
    } else {
        missao.tipo = 2;
        missao.quantidade = 3;
        printf("Missão: Conquistar 3 territórios\n");
    }
}

void mostrarMapa() {
    for (int i = 0; i < total; i++) {
        printf("\n[%d] %s", i, territorios[i].nome);
        printf("Cor: %s", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }
}

void atacar(int atk, int def) {
    int dadoAtk = rand() % 6 + 1;
    int dadoDef = rand() % 6 + 1;

    printf("\nAtk: %d | Def: %d\n", dadoAtk, dadoDef);

    if (dadoAtk >= dadoDef) {
        territorios[def].tropas--;

        if (territorios[def].tropas <= 0) {
            printf("Conquistado!\n");
            strcpy(territorios[def].cor, territorios[atk].cor);
            territorios[def].tropas = 1;
        }
    } else {
        territorios[atk].tropas--;
    }
}

int verificarMissao() {
    if (missao.tipo == 1) {
        for (int i = 0; i < total; i++) {
            if (strcmp(territorios[i].cor, missao.alvo) == 0) {
                return 0;
            }
        }
        return 1;
    }

    if (missao.tipo == 2) {
        int count = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(territorios[i].cor, territorios[0].cor) == 0) {
                count++;
            }
        }
        return count >= missao.quantidade;
    }

    return 0;
}

// ---------------- MAIN ----------------

int main() {
    srand(time(NULL));

    inicializar();
    gerarMissao();

    int op;

    do {
        printf("\n1 - Atacar\n2 - Verificar Missão\n0 - Sair\n");
        scanf("%d", &op);

        if (op == 1) {
            int atk, def;

            mostrarMapa();

            printf("\nAtacante: ");
            scanf("%d", &atk);

            printf("Defensor: ");
            scanf("%d", &def);

            if (atk != def && atk < total && def < total) {
                atacar(atk, def);
            } else {
                printf("Inválido!\n");
            }
        }

        if (op == 2) {
            if (verificarMissao()) {
                printf("MISSÃO COMPLETA!\n");
                break;
            } else {
                printf("Missão ainda não concluída.\n");
            }
        }

    } while (op != 0);

    free(territorios);
    return 0;
}
