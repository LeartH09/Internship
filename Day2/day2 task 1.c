
int main()
{
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short vleraShort = 12;
    long vleraLong = 123456;

    printf("Shkruani moshen tuaj: ");
    scanf("%d", &mosha);

    printf("Shkruani inicialin tuaj: ");
    scanf(" %c", &iniciali);    

    printf("Shkruani gjatesine tuaj: ");
    scanf("%f", &gjatesia); 

    printf("Shkruani mesataren tuaj: ");
    scanf("%lf", &mesatarja);

    printf("Shfaqja e te dhenave tuaja:\n");
    printf("Mosha juaj eshte: %d\n", mosha);
    printf("Iniciali juaj eshte: %c\n", iniciali);  
    printf("Gjatesia juaj eshte: %.2f\n", gjatesia);
    printf("Mesatarja juaj eshte: %.2lf\n", mesatarja);
    printf("Vlera e variablit short eshte: %d\n", vleraShort);
    printf("Vlera e variablit long eshte: %ld\n", vleraLong);
 
    return 0;
}
