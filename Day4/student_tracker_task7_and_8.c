#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

// --- Task 4: Strukturat dhe Enums ---
enum Status { AKTIV = 1, I_DIPLOMUAR, NE_REVIZION, I_SUSPENDUAR };

struct Nxenesi {
    int id;
    char emri[50];
    float nota;
    enum Status statusi;
};

// --- Task 8: Prototipet e Funksioneve (Organizimi) ---
void shfaqMenu();
void shtoNxenes(struct Nxenesi nx[], int *count);
void shfaqListen(struct Nxenesi nx[], int count);
void perditesoNxenesin(struct Nxenesi nx[], int count); // Task 7
void fshijNxenesin(struct Nxenesi nx[], int *count);    // Task 7
void rankoNxenesit(struct Nxenesi nx[], int count);    // Task 6

int main() {
    struct Nxenesi nxenesit[MAX_STUDENTS];
    int count = 0;
    int zgjedhja;

    while (1) {
        shfaqMenu();
        if (scanf("%d", &zgjedhja) != 1) {
            printf("\n[!] Error: Jepni numer.\n");
            while(getchar() != '\n'); continue;
        }

        if (zgjedhja == 0) break;

        switch (zgjedhja) {
            case 1: shtoNxenes(nxenesit, &count); break;
            case 2: shfaqListen(nxenesit, count); break;
            case 3: perditesoNxenesin(nxenesit, count); break;
            case 4: fshijNxenesin(nxenesit, &count); break;
            case 5: rankoNxenesit(nxenesit, count); break;
            default: printf("\n[!] Opsion i gabuar.\n");
        }
    }
    return 0;
}

// --- Task 8: Implementimi i Funksioneve ---

void shfaqMenu() {
    printf("\n--- BGT STUDENT TRACKER V6.0 ---");
    printf("\n1. Regjistro Nxenes");
    printf("\n2. Shfaq Listen");
    printf("\n3. Modifiko (Update ID)");
    printf("\n4. Fshij (Delete ID)");
    printf("\n5. Ranko (Sort by Grade)");
    printf("\n0. Dil");
    printf("\nZgjedhja: ");
}

void shtoNxenes(struct Nxenesi nx[], int *count) {
    if (*count < MAX_STUDENTS) {
        printf("\nID: "); scanf("%d", &nx[*count].id);
        printf("Emri: "); scanf("%s", nx[*count].emri);
        printf("Nota: "); scanf("%f", &nx[*count].nota);
        nx[*count].statusi = AKTIV;
        (*count)++;
        printf("-> U shtua!\n");
    } else printf("\n[!] Array is full!\n");
}

void shfaqListen(struct Nxenesi nx[], int count) {
    if (count == 0) printf("\nLista eshte boshe.\n");
    else {
        printf("\n%-5s %-15s %-7s", "ID", "EMRI", "NOTA");
        for (int i = 0; i < count; i++) {
            printf("\n%-5d %-15s %-7.2f", nx[i].id, nx[i].emri, nx[i].nota);
        }
        printf("\n");
    }
}

// --- Task 7: Modifikimi i 2 fushave ---
void perditesoNxenesin(struct Nxenesi nx[], int count) {
    int idK, gjetur = 0;
    printf("\nID e nxenesit per modifikim: "); scanf("%d", &idK);
    for (int i = 0; i < count; i++) {
        if (nx[i].id == idK) {
            printf("Emri i ri: "); scanf("%s", nx[i].emri); // Fusha 1
            printf("Nota e re: "); scanf("%f", &nx[i].nota); // Fusha 2
            gjetur = 1;
            printf("-> Te dhenat u ndryshuan.\n");
            break;
        }
    }
    if (!gjetur) printf("\n[!] Nuk u gjet.\n");
}

// --- Task 7: Fshirja me Array Shifting ---
void fshijNxenesin(struct Nxenesi nx[], int *count) {
    int idK, gjetur = 0;
    printf("\nID per fshirje: "); scanf("%d", &idK);
    for (int i = 0; i < *count; i++) {
        if (nx[i].id == idK) {
            // Logjika e zhvendosjes (Shifting)
            for (int j = i; j < *count - 1; j++) {
                nx[j] = nx[j + 1];
            }
            (*count)--; // Zvogelojme numrin total permes pointer-it
            gjetur = 1;
            printf("-> Nxenezi u fshi.\n");
            break;
        }
    }
    if (!gjetur) printf("\n[!] Nuk u gjet.\n");
}

void rankoNxenesit(struct Nxenesi nx[], int count) {
    struct Nxenesi temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (nx[j].nota < nx[j+1].nota) {
                temp = nx[j]; nx[j] = nx[j+1]; nx[j+1] = temp;
            }
        }
    }
    printf("\n-> Renditja u krye!\n");
}