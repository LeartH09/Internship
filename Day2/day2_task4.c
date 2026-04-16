#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double piket;
    int opsioni;

    printf("--- Regjistrimi ne Punetori ---\n");
    
    printf("Jepni inicialin tuaj: ");
    scanf(" %c", &iniciali);

    printf("Jepni moshen tuaj: ");
    scanf("%d", &mosha);

    printf("Jepni piket paraprake (0-100): ");
    scanf("%lf", &piket);

    printf("Zgjidhni punetorine (1-Coding, 2-Design, 3-Marketing): ");
    scanf("%d", &opsioni);

    printf("\n--- Permbledhja e Regjistrimit ---\n");
    printf("Iniciali: %c\n", iniciali);
    printf("Mosha: %d\n", mosha);
    printf("Piket: %.2f\n", piket);

    if (mosha < 15) {
        printf("Statusi i moshes: Nen limitin per pjesemarrje.\n");
    } else {
        printf("Statusi i moshes: Brenda kufirit.\n");
    }

    if (piket < 50) {
        printf("Klasifikimi: Nevojitet me shume ushtrim.\n");
    } else if (piket <= 80) {
        printf("Klasifikimi: Gati per vazhdim.\n");
    } else {
        printf("Klasifikimi: Gati per sfide.\n");
    }

    switch (opsioni) {
        case 1:
            printf("Punetoria e zgjedhur: Coding\n");
            break;
        case 2:
            printf("Punetoria e zgjedhur: Design\n");
            break;
        case 3:
            printf("Punetoria e zgjedhur: Marketing\n");
            break;
        default:
            printf("Punetoria: Opsion i pavlefshem.\n");
            break;
    }

    return 0;
}