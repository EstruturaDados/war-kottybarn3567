#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

Territorio *territorios;
int total = 0;

void atacar(int atk, int def) {
    int dadoAtk = rand() % 6 + 1;
    int dadoDef = rand() % 6 + 1;

    printf("\nDado atacante: %d\n", dadoAtk);
    printf("Dado defensor: %d\n", dadoDef);

    if (dadoAtk >= dadoDef) {
        territorios[def].tropas--;
        printf("Atacante venceu!\n");

        if (territorios[def].tropas <= 0) {
            printf("Território conquistado!\n");
            strcpy(territorios[def].cor, territorios[atk].cor);
            territorios[def].tropas = 1;
        }
    } else {
        territorios[atk].tropas--;
        printf("Defensor venceu!\n");
    }
}

int main() {
    srand(time(NULL));

    territorios = (Territorio*) calloc(5, sizeof(Territorio));

    int option;

    do {
        printf("\nSISTEMA WAR\n");
        printf("1 - Ver Territórios\n");
        printf("2 - Adicionar Território\n");
        printf("3 - Atacar\n");
        printf("4 - Sair\n");
        scanf("%d", &option);

        if (option == 1) {
            for (int i = 0; i < total; i++) {
                printf("\n[%d]\n", i);
                printf("Nome: %s", territorios[i].nome);
                printf("Cor: %s", territorios[i].cor);
                printf("Tropas: %d\n", territorios[i].tropas);
            }
        }

        if (option == 2) {
            if (total < 5) {
                getchar();

                printf("Nome: ");
                fgets(territorios[total].nome, 30, stdin);

                printf("Cor: ");
                fgets(territorios[total].cor, 10, stdin);

                printf("Tropas: ");
                scanf("%d", &territorios[total].tropas);

                total++;
            } else {
                printf("Limite atingido!\n");
            }
        }

        if (option == 3) {
            int atk, def;

            printf("\nEscolha o atacante:\n");
            for (int i = 0; i < total; i++) {
                printf("[%d] %s", i, territorios[i].nome);
            }
            scanf("%d", &atk);

            printf("\nEscolha o defensor:\n");
            for (int i = 0; i < total; i++) {
                printf("[%d] %s", i, territorios[i].nome);
            }
            scanf("%d", &def);

            if (atk != def && atk < total && def < total) {
                atacar(atk, def);
            } else {
                printf("Escolha inválida!\n");
            }
        }

    } while (option != 4);

    free(territorios);
    return 0;
}
