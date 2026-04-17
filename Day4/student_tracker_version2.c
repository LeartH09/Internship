#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

enum Progresi { SHKELQYESHEM = 1, MIRE, MBIFILLIM, DOBET };

struct Nxenesi {
    int id;
    char emri[50];
    float nota;
    enum Progresi statusi;
};

int main() {
    struct Nxenesi nxenesit[MAX_STUDENTS];
    int count = 0;
    int zgjedhja;

    while (1) {
        printf("\n--- STUDENT PROGRESS TRACKER V3.0 (Raporti Analitik) ---\n");
        printf("1. Regjistro nxenes te ri\n");
        printf("2. Shfaq listen e nxenesve\n");
        printf("3. Gjenero Raportin Analitik\n"); // Opsioni i ri
        printf("4. Mbyll programin\n");
        printf("Zgjedhja juaj: ");

        if (scanf("%d", &zgjedhja) != 1) {
            printf("!!! GABIM: Jepni numer.\n");
            while(getchar() != '\n'); 
            continue;
        }

        if (zgjedhja == 4) break;

        switch (zgjedhja) {
            case 1:
                if (count < MAX_STUDENTS) {
                    printf("\nID: "); scanf("%d", &nxenesit[count].id);
                    printf("Emri: "); scanf("%s", nxenesit[count].emri);
                    printf("Nota (1-10): "); scanf("%f", &nxenesit[count].nota);
                    
                    int zgjStatus;
                    printf("Kategoria (1:Shkelqyeshem, 2:Mire, 3:Mbifillim, 4:Dobet): ");
                    scanf("%d", &zgjStatus);
                    nxenesit[count].statusi = (zgjStatus >= 1 && zgjStatus <= 4) ? (enum Progresi)zgjStatus : DOBET;
                    
                    count++;
                    printf("-> Sukses: Nxenezi u shtua!\n");
                } else {
                    printf("!!! Limiti u arrit.\n");
                }
                break;

            case 2:
                if (count == 0) printf("\nLista eshte e zbrazet.\n");
                else {
                    printf("\nID\tEmri\t\tNota\tStatusi\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d\t%s\t\t%.2f\t", nxenesit[i].id, nxenesit[i].emri, nxenesit[i].nota);
                        if(nxenesit[i].statusi == SHKELQYESHEM) printf("Shkelqyeshem\n");
                        else if(nxenesit[i].statusi == MIRE) printf("Mire\n");
                        else if(nxenesit[i].statusi == MBIFILLIM) printf("Mbifillim\n");
                        else printf("Dobet\n");
                    }
                }
                break;

            case 3: // LOGJIKA E KERKESES 3
                if (count == 0) {
                    printf("\n[!] Nuk ka nxenes te regjistruar per te gjeneruar raport.\n");
                } else {
                    float shuma = 0, notaMax = 0;
                    int nxenesShkelqyeshem = 0;

                    // For loop per te kaluar neper te gjitha te dhenat
                    for (int i = 0; i < count; i++) {
                        shuma += nxenesit[i].nota; // Per mesataren
                        
                        if (nxenesit[i].nota > notaMax) {
                            notaMax = nxenesit[i].nota; // Gjetja e Max
                        }
                        
                        if (nxenesit[i].statusi == SHKELQYESHEM) {
                            nxenesShkelqyeshem++; // Numerimi sipas Enum
                        }
                    }

                    float mesatarja = shuma / count;

                    printf("\n======= RAPORTI ANALITIK =======");
                    printf("\nTotal nxenes: %d", count);
                    printf("\nNota mesatare: %.2f", mesatarja);
                    printf("\nNota me e larte: %.2f", notaMax);
                    printf("\nNxenes Shkelqyeshem: %d", nxenesShkelqyeshem);
                    printf("\n--------------------------------");
                    
                    // Klasifikimi me if/else me mesazhe kuptimplota
                    printf("\nSTATUSI I GRUPIT: ");
                    if (mesatarja >= 9.0) {
                        printf("Grup i jashtezakonshem!\n");
                    } else if (mesatarja >= 7.0) {
                        printf("Grup me progres stabil.\n");
                    } else {
                        printf("Grupi ka nevoje per rishikim te metodes se mesimit.\n");
                    }
                    printf("================================\n");
                }
                break;

            default:
                printf("!!! Zgjedhje e pavlefshme.\n");
        }
    }
    return 0;
}