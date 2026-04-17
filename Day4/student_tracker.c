#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

// 1. Enum per statusin e nxenesit (Kerkese e Dites 4)
enum Status { AKTIV, I_DIPLOMUAR, NE_REVIZION, I_SUSPENDUAR };

// 2. Struktura per te mbajtur te dhenat e organizuara
struct Nxenesi {
    int id;
    char emri[50];
    float nota;
    enum Status statusi;
};

// 3. Funksion me Pointer (Kerkese praktike e Dites 4)
// Ky funksion perditeson noten duke perdorur pointer per efikasitet
void shtoBonus(float *notaPtr, float bonusi) {
    if (notaPtr != NULL) {
        *notaPtr += bonusi;
        if (*notaPtr > 10.0) *notaPtr = 10.0; // Limiti i notes
    }
}

int main() {
    struct Nxenesi nxenesit[MAX_STUDENTS];
    int count = 0;
    int zgjedhja;

    while (1) {
        // Menuja kryesore me Switch
        printf("\n--- STUDENT PROGRESS TRACKER ---\n");
        printf("1. Regjistro nje nxenes te ri\n");
        printf("2. Shfaq listen e nxenesve\n");
        printf("3. Shto bonus per nje nxenes (Pointer Test)\n");
        printf("4. Mbyll programin\n");
        printf("Zgjedhja juaj: ");
        scanf("%d", &zgjedhja);

        if (zgjedhja == 4) break;

        switch (zgjedhja) {
            case 1:
                if (count < MAX_STUDENTS) {
                    printf("\nID e nxenesit: ");
                    scanf("%d", &nxenesit[count].id);
                    printf("Emri: ");
                    scanf("%s", nxenesit[count].emri);
                    printf("Nota fillestare: ");
                    scanf("%f", &nxenesit[count].nota);
                    
                    // Caktimi i statusit fillestar me Enum
                    nxenesit[count].statusi = AKTIV;
                    
                    count++;
                    printf("-> Sukses: Nxenezi u regjistrua!\n");
                } else {
                    printf("\n!!! GABIM: Nuk ka hapesire per regjistrime te reja (%d/%d) !!!\n", count, MAX_STUDENTS);
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\nLista eshte e zbrazet.\n");
                } else {
                    printf("\n--- LISTA E PROGRESIT ---\n");
                    printf("ID\tEmri\t\tNota\tStatusi\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d\t%s\t\t%.2f\t%s\n", 
                                nxenesit[i].id, 
                                nxenesit[i].emri, 
                                nxenesit[i].nota,
                                nxenesit[i].statusi == AKTIV ? "Aktiv" : "Tjeter");
                    }
                }
                break;

            case 3:
                if (count > 0) {
                    // Shembull praktik i perdorimit te pointerit
                    // Marrim nxenesin e fundit te shtuar dhe i japim bonus
                    printf("\nDuke i dhene 0.5 bonus nxenesit te fundit (%s)...\n", nxenesit[count-1].emri);
                    shtoBonus(&nxenesit[count-1].nota, 0.5);
                    printf("Nota e re: %.2f\n", nxenesit[count-1].nota);
                } else {
                    printf("\nNuk ka nxenes per te modifikuar.\n");
                }
                break;

            default:
                printf("\nZgjedhje e pavlefshme!\n");
        }
    }

    return 0;
}