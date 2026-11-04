#include <stdio.h>

int main() {
    int n, i;
    int estados[10];
    int ativos = 0, inativos = 0;
    float percentual;

    printf("=== RADAR DE DISPOSITIVOS DA REDE ===\n");

    do {
        printf("\nDigite a quantidade de dispositivos (1 a 10): ");
        scanf("%d", &n);

        if (n < 1 || n > 10) {
            printf("Quantidade invalida! Tente novamente.\n");
        }
    } while (n < 1 || n > 10);

    for (i = 0; i < n; i++) {
        do {
            printf("Estado do dispositivo %d (1 = ativo, 0 = inativo): ", i + 1);
            scanf("%d", &estados[i]);

            if (estados[i] != 0 && estados[i] != 1) {
                printf("Estado invalido! Digite 0 ou 1.\n");
            }
        } while (estados[i] != 0 && estados[i] != 1);
    }

    for (i = 0; i < n; i++) {
        if (estados[i] == 1) {
            ativos++;
        } else {
            inativos++;
        }
    }

    percentual = (float) ativos / n * 100;

    printf("\n=== PAINEL DA REDE ===\n");

    printf("Total de dispositivos: %d\n", n);
    printf("Dispositivos ativos: %d\n", ativos);
    printf("Dispositivos inativos: %d\n", inativos);
    printf("Disponibilidade: %.1f%%\n", percentual);

    if (inativos >= 2) {
        printf("\nALERTA: 2 ou mais dispositivos indisponiveis!\n");
    }

    return 0;
}
