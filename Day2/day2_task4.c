int main()
{
    int mosha, opsioni;
    char iniciali;
    double pike;

    printf("Shkruani moshen tuaj: ");
    scanf("%d", &mosha);

    printf("Shkruani inicialin: ");
    scanf("%c", &iniciali);

    printf("Zgjidhni puntorine (1, 2 ose 3) ");
    scanf(" %d", &opsioni);

    if (mosha < 15 || mosha > 25) 
    {
         printf("\nNuk plotesoni kushtin e moshes per pjesemarrje.\n");
    } 
    else 
    {
        printf("\nMosha eshte ne rregull per pjesemarrje.\n");
    }

    if (pike < 50) 
    {
        printf("Statusi: Nevojitet me shume ushtrim\n");
    }
    else if (pike < 80) 
    {
        printf("Statusi: Gati per vazhdim\n");
    }
    else 
    {
        printf("Statusi: Gati per sfide\n");
    }

    printf("Punetoria: ");
    switch(opsioni) 
    {
        case 1:
            printf("Programim bazik\n");
            break;
        case 2:
            printf("Algoritme\n");
            break;
        case 3:
            printf("Struktura te dhenash\n");
            break;
        default:
            printf("Opsion i pavlefshem\n");
    }

    printf("\nPermbledhje\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2lf\n", pike);
    printf("Opsioni: %d\n", opsioni);

    return 0;
    
}
