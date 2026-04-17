#include <stdio.h>
#include <string.h>
// 1. Përdorimi i enum për Statusin e Studentit
enum Status 
{
    START = 1,
    IN_PROGRESS,
    COMPLETED
};

// Funksion që përdor POINTER për të përditësuar progresin
// Kjo plotëson kërkesën: "Përdorim bazik i pointer-it"
void updateProgress(int *p_progresi, int vlera_re) {
    *p_progresi = vlera_re; 
    printf("Progresi u përditësua me sukses!\n");
}

int main() 
{
    // Variablat për të ruajtur të dhënat e një studenti (Regjistrim bazë)
    int id = 101;
    char emri[50] = "Studenti Pare";
    int progresi = 0;
    enum Status statusi_aktual = START;

    int zgjedhja;
    int running = 1; // Kontrollon loop-in e menusë

    printf("--- Mirësevini në Student Progress Tracker ---\n");

    // 2. Loop për menunë kryesore
    while (running) 
    {
        printf("\nMENUJA KRYESORE:\n");
        printf("1. Shfaq të dhënat e studentit\n");
        printf("2. Përditëso progresin (me Pointer)\n");
        printf("3. Ndrysho Statusin (me Enum)\n");
        printf("4. Dil nga programi\n");
        printf("Zgjedhja juaj: ");
        scanf("%d", &zgjedhja);

        // 3. Switch për menunë
        switch (zgjedhja) 
        {
            case 1:
                printf("\n--- Te dhenat e Studentit ---\n");
                printf("ID: %d\n", id);
                printf("Emri: %s\n", emri);
                printf("Progresi: %d%%\n", progresi);
                
                // Kontroll me if/else për statusin
                if (statusi_aktual == START) printf("Statusi: Fillestar\n");
                else if (statusi_aktual == IN_PROGRESS) printf("Statusi: Ne Progres\n");
                else printf("Statusi: Perfunduar\n");
                break;

            case 2:
                int progres_i_ri;
                printf("Shkruaj progresin e ri (0-100): ");
                scanf("%d", &progres_i_ri);
                
                // Validim me if/else
                if (progres_i_ri >= 0 && progres_i_ri <= 100) {
                    updateProgress(&progresi, progres_i_ri); // Dërgimi i adresës (Pointer)
                } else {
                    printf("Vlerë e pavlefshme!\n");
                }
                break;

            case 3:
                printf("Zgjidh Statusin (1: Start, 2: Progres, 3: Perfunduar): ");
                int stat_input;
                scanf("%d", &stat_input);
                if (stat_input >= 1 && stat_input <= 3) {
                    statusi_aktual = (enum Status)stat_input;
                    printf("Statusi u ndryshua.\n");
                } else {
                    printf("Status i pavlefshëm!\n");
                }
                break;

            case 4:
                printf("Duke u mbyllur...\n");
                running = 0; // Ndalon loop-in
                break;

            default:
                printf("Zgjedhje e gabuar! Provo përsëri.\n");
        }
    }

    return 0;
}
