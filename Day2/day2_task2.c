#include <stdio.h>
int main() 
{
    int rezultati;

    printf("Shkruani rezultatin (0-100): ");
    scanf("%d", &rezultati);

    if (rezultati < 0 || rezultati > 100) 
    {
    printf("Rezultati i pavlefshem. Ju lutem shkruani nje numer midis 0 dhe 100.\n");
    }
    else if(rezultati >= 90) 
    {
        printf("Shkelqyeshem.\n");
    }
    else if(rezultati >= 75)  
    {
        printf("Shume mire.\n");
    } 
    else if(rezultati >= 50)
    {
        printf("Mire.\n");
    } 
    else 
    {
        printf("Ne permiresim.\n");
    }

    return 0;
}
