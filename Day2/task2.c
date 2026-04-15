#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short nr_kepuces = 43;
    long id_studenti = 123456789;

    printf("Mosha: ");
    scanf("%d", &mosha);

    printf("Iniciali: ");
    scanf(" %c", &iniciali);

    printf("Gjatesia: ");
    scanf("%f", &gjatesia);

    printf("Mesatarja: ");
    scanf("%lf", &mesatarja);

    printf("\n PROFILI I STUDENTIT (DITA 2)\n");
    printf("Emri (Iniciali): %c\n", iniciali);
    printf("Mosha: %d vjec\n", mosha);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Numri i kepuceve (short): %hd\n", nr_kepuces);
    printf("ID-ja unikale (long): %ld\n", id_studenti);

    return 0;
}