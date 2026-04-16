#include <stdio.h>

int main() 
{
    int mosha, opsioni;
    char iniciali;
    double pike;
    char *punetoria; 
}
    
    printf("Shkruani moshen: ");
    scanf("%d", &mosha);

    printf("Shkruani inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruani piket: ");
    scanf("%lf", &pike);

    printf("Zgjidhni punetorine (1-3): ");
    scanf("%d", &opsioni);

    switch(opsioni) 
    {
        case 1:
            punetoria = "Programim bazik";
            break;
        case 2:
            punetoria = "Algoritme";
            break;
        case 3:
            punetoria = "Struktura te dhenash";
            break;
        default:
            punetoria = "Opsion i pavlefshem";
    }

    printf("\n--- Permbledhje ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2lf\n", pike);
    printf("Punetoria: %s\n", punetoria);

    return 0;
}
