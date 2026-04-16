#include <stdio.h>

// Deklarimi i enum-it me 4 kategori stervitjeje
enum Stervitja {CHEST = 1, BACK, LEGS, ARMS};

int main() {
    int zgjedhja;
    int saktesia = 0;
    int gabime = 0;

    printf("--- Planifikuesi i Stervitjes (Dita 3 - Task 5) ---\n");
    printf("Kategorite: 1: Chest, 2: Back, 3: Legs, 4: Arms\n\n");

    // For loop per te bere 3 zgjedhje radhazi
    for (int i = 1; i <= 3; i++) {
        printf("Dita %d - Zgjidh kategorine (1-4): ", i);
        scanf("%d", &zgjedhja);

        // Perdorim enum-in ne switch
        enum Stervitja dita_aktuale = (enum Stervitja)zgjedhja;

        switch (dita_aktuale) {
            case CHEST:
                printf("-> Fokusimi: Bench Press (Synimi 115kg!).\n");
                saktesia++;
                break;
            case BACK:
                printf("-> Fokusimi: Pull-ups dhe Rows.\n");
                saktesia++;
                break;
            case LEGS:
                printf("-> Fokusimi: Squats dhe Leg Press.\n");
                saktesia++;
                break;
            case ARMS:
                printf("-> Fokusimi: Biceps dhe Triceps.\n");
                saktesia++;
                break;
            default:
                printf("-> Input i pavlefshem! Kjo kategori nuk ekziston.\n");
                gabime++;
                break;
        }
        printf("\n");
    }

    // Statistikat ne fund
    printf("--- Statistikat Perfundimtare ---\n");
    printf("Zgjedhje valide: %d\n", saktesia);
    printf("Zgjedhje te pavlefshme: %d\n", gabime);

    if (saktesia == 3) {
        printf("Rezultati: Jave perfekte! Te gjitha ditet u planifikuan.\n");
    } else {
        printf("Rezultati: Planifikimi ka nevoje per rishikim.\n");
    }

    return 0;
}