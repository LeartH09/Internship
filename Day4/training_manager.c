#include <stdio.h>

#define MAX_RECORDS 5

// Struktura per te mbajtur te dhenat e organizuara
struct Progresi {
    int reps;
    double weight;
};

int main() {
    struct Progresi regjistrimet[MAX_RECORDS];
    int count = 0; // Numeruesi aktual
    int zgjedhja;

    while (1) {
        printf("\n--- MENUJA E PROGRESIT (Max: %d) ---\n", MAX_RECORDS);
        printf("1. Shto nje regjistrim te ri\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Mbyll programin\n");
        printf("Zgjedhja juaj: ");
        scanf("%d", &zgjedhja);

        if (zgjedhja == 3) {
            printf("Duke u mbyllur... Pune te mbare ne palester!\n");
            break;
        }

        switch (zgjedhja) {
            case 1:
                if (count < MAX_RECORDS) {
                    printf("\nRegjistrimi #%d\n", count + 1);
                    printf("Jepni perseritjet (reps): ");
                    scanf("%d", &regjistrimet[count].reps);
                    printf("Jepni peshen (kg): ");
                    scanf("%lf", &regjistrimet[count].weight);
                    
                    count++;
                    printf("-> Sukses: Regjistrimi u rregullua!\n");
                } else {
                    printf("\n!!! GABIM: Kapaciteti maksimal u arrit (%d/%d) !!!\n", count, MAX_RECORDS);
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\nNuk ka asnje regjistrim per te shfaqur.\n");
                } else {
                    printf("\n--- LISTA E PROGRESIT ---\n");
                    printf("ID\tPerseritjet\tPesha\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d\t%d\t\t%.2f kg\n", i + 1, regjistrimet[i].reps, regjistrimet[i].weight);
                    }
                }
                break;

            default:
                printf("\nZgjedhje e pavlefshme. Provoni perseri.\n");
        }
    }

    return 0;
}