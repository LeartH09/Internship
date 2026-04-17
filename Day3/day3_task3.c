#include <stdio.h>

int main() {
    int start, end;
    int count1 = 0, sum1 = 0;
    int count2 = 0, sum2 = 0;

    printf("Jepni fillimin e intervalit: ");
    scanf("%d", &start);
    printf("Jepni fundin e intervalit: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Gabim: Fillimi nuk mund te jete me i madh se fundi!\n");
        return 1;
    }

    for (int i = start; i <= end; i++) {
        if (i % 3 == 0) {
            count1++;
            sum1 += i;
        } 
        else if (i % 5 == 0) {
            count2++;
            sum2 += i;
        }
    }

    printf("\nKategoria 1 (Pjestuesit e 3-shit): Numeruesi = %d, Shuma = %d\n", count1, sum1);
    printf("Kategoria 2 (Pjestuesit e 5-ses pa 3-shin): Numeruesi = %d, Shuma = %d\n", count2, sum2);

    if (sum1 > sum2) {
        printf("Rezultati: Shuma e Kategorise 1 eshte me e madhe.\n");
    } else if (sum2 > sum1) {
        printf("Rezultati: Shuma e Kategorise 2 eshte me e madhe.\n");
    } else {
        printf("Rezultati: Shumat jane te barabarta.\n");
    }

    return 0;
}