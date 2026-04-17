#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

// --- STRUKTURAT DHE ENUMS ---
enum Status { AKTIV = 1, I_DIPLOMUAR, NE_REVIZION, I_SUSPENDUAR };

struct Nxenesi {
    int id;
    char emri[50];
    float nota;
    enum Status statusi;
};

// --- PROTOTIPET E FUNKSIONEVE (Task 8: Organizimi) ---
void shfaqMenu();
void shtoNxenes(struct Nxenesi nx[], int *count);
void shfaqListen(struct Nxenesi nx[], int count);
void kerkoDheAnalizo(struct Nxenesi nx[], int count);
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
            printf("\n[!] GABIM: Input i pavlefshem. Shenoni nje numer.\n");
            while(getchar() != '\n'); continue;
        }

        if (zgjedhja == 0) break;

        switch (zgjedhja) {
            case 1: shtoNxenes(nxenesit, &count); break;
            case 2: shfaqListen(nxenesit, count); break;
            case 3: kerkoDheAnalizo(nxenesit, count); break;
            case 4: perditesoNxenesin(nxenesit, count); break;
            case 5: fshijNxenesin(nxenesit, &count); break;
            case 6: rankoNxenesit(nxenesit, count); break;
            default: printf("\n[!] Ky opsion nuk ekziston.\n");
        }
    }
    printf("\nProgrami u mbyll me sukses. Suksese ne test!\n");
    return 0;
}

// --- IMPLEMENTIMI I FUNKSIONEVE ---

void shfaqMenu() {
    printf("\n========================================");
    printf("\n   STUDENT TRACKER V6.0 - FINAL BGT");
    printf("\n========================================");
    printf("\n1. Regjistro Nxenes te ri");
    printf("\n2. Shfaq Listen e nxenesve");
    printf("\n3. Kerko & Analizo Performance (ID)");
    printf("\n4. Modifiko te dhenat (Update)");
    printf("\n5. Fshij nje regjistrim (Delete)");
    printf("\n6. Ranko sipas Notave (Sort)");
    printf("\n0. Dil nga programi");
    printf("\nZgjedhja juaj: ");
}

void shtoNxenes(struct Nxenesi nx[], int *count) {
    if (*count < MAX_STUDENTS) {
        printf("\nSheno ID: "); scanf("%d", &nx[*count].id);
        printf("Sheno Emrin: "); scanf("%s", nx[*count].emri);
        printf("Sheno Noten: "); scanf("%f", &nx[*count].nota);
        nx[*count].statusi = AKTIV;
        (*count)++;
        printf("-> Sukses: Nxenezi u shtua ne sistem.\n");
    } else printf("\n[!] Gabim: Kapaciteti eshte plot!\n");
}

void shfaqListen(struct Nxenesi nx[], int count) {
    if (count == 0) printf("\nLista eshte e zbrazet.\n");
    else {
        printf("\n%-5s %-15s %-10s %-10s", "ID", "EMRI", "NOTA", "STATUSI");
        printf("\n--------------------------------------------");
        for (int i = 0; i < count; i++) {
            printf("\n%-5d %-15s %-10.2f %-10d", nx[i].id, nx[i].emri, nx[i].nota, nx[i].statusi);
        }
        printf("\n");
    }
}

// TASK 7: MODIFIKIMI (UPDATE)
void perditesoNxenesin(struct Nxenesi nx[], int count) {
    int idK, gjetur = 0;
    printf("\nID e nxenesit per modifikim: "); scanf("%d", &idK);
    for (int i = 0; i < count; i++) {
        if (nx[i].id == idK) {
            printf("Emri i ri: "); scanf("%s", nx[i].emri);
            printf("Nota e re: "); scanf("%f", &nx[i].nota);
            gjetur = 1;
            printf("-> Te dhenat u ndryshuan me sukses.\n");
            break;
        }
    }
    if (!gjetur) printf("\n[!] Nxenezi me ID %d nuk u gjet.\n", idK);
}

// TASK 7: FSHIRJA (DELETE)
void fshijNxenesin(struct Nxenesi nx[], int *count) {
    int idK, gjetur = 0;
    printf("\nID e nxenesit per fshirje: "); scanf("%d", &idK);
    for (int i = 0; i < *count; i++) {
        if (nx[i].id == idK) {
            // Zhvendosja e elementeve (Shifting) per te mbushur vrimen ne array
            for (int j = i; j < *count - 1; j++) {
                nx[j] = nx[j + 1];
            }
            (*count)--; // Zvogelojme numrin aktual te nxenesve
            gjetur = 1;
            printf("-> Nxenezi u fshi nga sistemi.\n");
            break;
        }
    }
    if (!gjetur) printf("\n[!] Nuk u gjet asnje nxenes me kete ID.\n");
}

// TASK 6: RANKIMI (BUBBLE SORT)
void rankoNxenesit(struct Nxenesi nx[], int count) {
    if (count < 2) {
        printf("\nNuk ka mjaftueshem nxenes per rankim.\n");
        return;
    }
    struct Nxenesi temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (nx[j].nota < nx[j+1].nota) { // Nga nota me e larte te me e ulta
                temp = nx[j];
                nx[j] = nx[j+1];
                nx[j+1] = temp;
            }
        }
    }
    printf("\n-> Rankimi u krye. Zgjidhni opsionin 2 per te pare listen e re!\n");
}

void kerkoDheAnalizo(struct Nxenesi nx[], int count) {
    int idK;
    printf("\nKerkoni sipas ID: "); scanf("%d", &idK);
    for (int i = 0; i < count; i++) {
        if (nx[i].id == idK) {
            printf("\nU gjet: %s | Nota: %.2f", nx[i].emri, nx[i].nota);
            if (nx[i].nota >= 9.0) printf("\n[ANALIZA]: Student i shkelqyer!\n");
            else if (nx[i].nota < 6.0) printf("\n[ANALIZA]: Nevojitet tutorial.\n");
            return;
        }
    }
    printf("\nRegjistrimi nuk ekziston.\n");
}