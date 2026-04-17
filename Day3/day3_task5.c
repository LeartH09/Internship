#include <stdio.h>
int main() 
{
    enum Level 
    {
        BEGINNER = 1, 
        INTERMEDIATE, 
        ADVANCED,     
        EXPERT        
    };

    int choice;
    int validCount = 0;
    int invalidCount = 0;

    for (int i = 1; i <= 3; i++) 
    {
        printf("\nZgjedh nje nivel (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case BEGINNER: 
                printf("Ti je fillestar.\n");
                validCount++;
                break;
            case INTERMEDIATE:
                printf("Ti je mesatar.\n");
                validCount++;
                break;
            case ADVANCED: 
                printf("Ti je i avancuar.\n");
                validCount++;
                break;
            case EXPERT:
                printf("Ti je ekspert.\n");
                validCount++;
                break;
            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalidCount++;
                break;
        }
    }

    printf("\nStatistikat\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje pavlefshme: %d\n", invalidCount);

    return 0;
}
/*
Ky program përdor enum për të përfaqësuar nivelet e një përdoruesi.
Përdoruesi zgjedh një vlerë dhe programi përdor switch për të shfaqur mesazh.
Një for loop përdoret për të testuar disa raste dhe në fund programi
numëron dhe shfaq zgjedhjet valide dhe të pavlefshme.
*/
