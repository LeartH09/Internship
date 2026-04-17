#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

enum Status { AKTIV = 1, I_DIPLOMUAR, NE_REVIZION, I_SUSPENDUAR };

struct Nxenesi {
    int id;
    char emri[50];
    float nota;
    enum Status statusi;
};

// --- KERKESA 4: FUNKSIONI ME POINTER ---
// Ky funksion nuk kthen vlere (void), por e ndryshon statusin direkt ne memorie
void ndryshoStatusinMeReference(enum Status *statusiPtr, int zgjedhjaERe) {
    if (statusiPtr != NULL) {
        // Perdorim operatorin '*' per te hyre te vlera ne ate adrese
        *statusiPtr = (enum Status)zgjedhjaERe;
        printf("\n[SISTEMI]: Statusi u modifikua me sukses ne adresen: %p\n", (void*)statusiPtr);
    }
}

int main() {
    struct Nxenesi nxenesit[MAX_STUDENTS];
    int count = 0;
    int zgjedhja;

    while (1) {
        printf("\n--- STUDENT TRACKER V4 (Pointer Mastery) ---\n");
        printf("1. Regjistro nxenes\n");
        printf("2. Shfaq nxenesit\n");
        printf("3. Modifiko Statusin (Me Pointer)\n");
        printf("4. Mbyll programin\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        if (zgjedhja == 4) break;

        switch (zgjedhja) {
            case 1:
                if (count < MAX_STUDENTS) {
                    printf("ID: "); scanf("%d", &nxenesit[count].id);
                    printf("Emri: "); scanf("%s", nxenesit[count].emri);
                    printf("Nota: "); scanf("%f", &nxenesit[count].nota);
                    nxenesit[count].statusi = AKTIV; // Default
                    count++;
                }
                break;

            case 2:
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Emri: %s | Nota: %.2f | Statusi: %d\n", 
                            nxenesit[i].id, nxenesit[i].emri, nxenesit[i].nota, nxenesit[i].statusi);
                }
                break;

            case 3:
                if (count > 0) {
                    int idKerkuar, i, gjetur = 0, statusiRi;
                    printf("Jepni ID e nxenesit per modifikim: ");
                    scanf("%d", &idKerkuar);

                    for (i = 0; i < count; i++) {
                        if (nxenesit[i].id == idKerkuar) {
                            printf("Zgjidh statusin e ri (1:Aktiv, 2:Diplomuar, 3:Revizion): ");
                            scanf("%d", &statusiRi);

                            // THIRRJA E FUNKSIONIT DUKE PERDORUR OPERATORIN '&'
                            // Po i dergojme adresen e fushes 'statusi' te atij nxenesi
                            ndryshoStatusinMeReference(&nxenesit[i].statusi, statusiRi);
                            
                            gjetur = 1;
                            break;
                        }
                    }
                    if (!gjetur) printf("Nxenesi nuk u gjet!\n");
                }
                break;
        }
    }
    return 0;
}