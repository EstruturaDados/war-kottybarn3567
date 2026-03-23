#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

Territorio territorios[5]; // vetor com 5 posiçõe no máximo
int total = 0; // variavel para ver quantos paises já foram cadastrados

int main() {

    int option; // ver a opção

    do {
        printf("\nSISTEMA WAR\n");
        printf("=========================\n");
        printf("1 - Ver Territórios\n");
        printf("2 - Adicionar Território\n");
        printf("3 - Sair\n");
        printf("=========================\n");
        scanf("%d", &option); // pega a opção

        if (option == 1) {
            // mostra os resultados a partir de total
            for (int i = 0; i < total; i++) {
                printf("======================================\n");
                printf("Nome: %s", territorios[i].nome);
                printf("Cor: %s", territorios[i].cor);
                printf("Tropas: %d\n", territorios[i].tropas);
                printf("======================================\n\n");
            }
        }

        if (option == 2) {
            // add os campos de cada territorio
            if (total < 5) {
                getchar();
                printf("Nome: ");
                fgets(territorios[total].nome, 30, stdin);

                printf("Cor: ");
                fgets(territorios[total].cor, 30, stdin);

                printf("Tropas: ");
                scanf("%d", &territorios[total].tropas);

                total++;
            } else {
                printf("Limite atingido!\n");
            }
        }

    } while (option != 3);

    return 0;
}
