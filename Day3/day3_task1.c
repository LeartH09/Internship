#include <stdio.h>

int main() {
    int madhesia, opsioni, i, j;

    printf("Jepni madhesine e pattern-it (1-12): ");
    scanf("%d", &madhesia);

    if (madhesia < 1 || madhesia > 12) {
        printf("Input i pavlefshem! Ju lutem jepni nje numer midis 1 dhe 12.\n");
        return 1;
    }

    printf("Zgjidhni llojin e pattern-it (1 per yje, 2 per numra): ");
    scanf("%d", &opsioni);

    printf("\n");

    if (opsioni == 1) {
        for (i = 1; i <= madhesia; i++) {
            for (j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } 
    else if (opsioni == 2) {
        for (i = 1; i <= madhesia; i++) {
            for (j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    } 
    else {
        printf("Opsion i pavlefshem!\n");
    }

    return 0;
}