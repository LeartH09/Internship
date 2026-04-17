#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

// 1. ENUM: Kategorizimi i sakte i progresit (Roli praktik)
enum Progresi { SHKELQYESHEM = 1, MIRE, MBIFILLIM, DOBET };

struct Nxenesi {
    int id;
    char emri[50];
    float nota;
    enum Progresi statusi;
};

// 2. POINTER: Funksion praktik per perditesimin e notes
void perditesoNoten(float *notaVjeter, float notaRe) {
    if (notaRe >= 1.0 && notaRe <= 10.0) {
        *notaVjeter = notaRe;
        printf("-> Nota u perditesua me sukses permes pointer-it!\n");
    } else {
        printf("-> GABIM: Nota e re nuk eshte valide.\n");
    }
}

int main() {
    struct Nxenesi nxenesit[MAX_STUDENTS];
    int count = 0;
    int zgjedhja;

    while (1) {
        printf("\n--- STUDENT PROGRESS TRACKER V2.0 ---\n");
        printf("1. Shto nje regjistrim te ri\n");
        printf("2. Shfaq listen e nxenesve\n");
        printf("3. Perditeso noten (Pointer function)\n");
        printf("4. Mbyll programin\n");
        printf("Zgjedhja juaj: ");

        // Validimi i menus kryesore (Moslemi i karaktereve/gabimeve)
        if (scanf("%d", &zgjedhja) != 1) {
            printf("!!! GABIM: Ju lutem jepni nje numer valid (1-4).\n");
            while(getchar() != '\n'); 
            continue;
        }

        if (zgjedhja == 4) break;

        switch (zgjedhja) {
            case 1:
                if (count < MAX_STUDENTS) {
                    printf("\nID e nxenesit: ");
                    scanf("%d", &nxenesit[count].id);
                    printf("Emri: ");
                    scanf("%s", nxenesit[count].emri);
                    printf("Nota (1-10): ");
                    scanf("%f", &nxenesit[count].nota);

                    // --- DEGEZIMI I DYTE (Switch per Statusin/Enum) ---
                    int zgjedhjaStatusi;
                    printf("Zgjidhni Kategorine e Progresit:\n");
                    printf("1: Shkelqyeshem, 2: Mire, 3: Mbifillim, 4: Dobet\n");
                    printf("Zgjedhja: ");
                    scanf("%d", &zgjedhjaStatusi);

                    switch (zgjedhjaStatusi) {
                        case 1: nxenesit[count].statusi = SHKELQYESHEM; break;
                        case 2: nxenesit[count].statusi = MIRE; break;
                        case 3: nxenesit[count].statusi = MBIFILLIM; break;
                        case 4: nxenesit[count].statusi = DOBET; break;
                        default:
                            printf("-> Status i pavlefshem! Po vendoset: DOBET si default.\n");
                            nxenesit[count].statusi = DOBET;
                            break;
                    }
                    count++;
                    printf("-> Nxenezi u regjistrua!\n");
                } else {
                    printf("!!! GABIM: Kapaciteti maksimal u arrit (%d).\n", MAX_STUDENTS);
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\nNuk ka regjistrime.\n");
                } else {
                    printf("\nID\tEmri\t\tNota\tStatusi\n");
                    printf("--------------------------------------------\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d\t%s\t\t%.2f\t", nxenesit[i].id, nxenesit[i].emri, nxenesit[i].nota);
                        
                        // Konvertimi i Enum ne tekst te lexueshem
                        switch (nxenesit[i].statusi) {
                            case SHKELQYESHEM: printf("Shkelqyeshem\n"); break;
                            case MIRE: printf("Mire\n"); break;
                            case MBIFILLIM: printf("Mbifillim\n"); break;
                            case DOBET: printf("Dobet\n"); break;
                        }
                    }
                }
                break;

            case 3:
                if (count > 0) {
                    float notaRe;
                    printf("Jepni noten e re per nxenesin e fundit (%s): ", nxenesit[count-1].emri);
                    scanf("%f", &notaRe);
                    perditesoNoten(&nxenesit[count-1].nota, notaRe);
                } else {
                    printf("-> Nuk ka nxenes ne liste.\n");
                }
                break;

            default:
                printf("!!! GABIM: Zgjedhje e pavlefshme.\n");
                break;
        }
    }

    return 0;
}