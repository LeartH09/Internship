#define MAX_STUDENTS 10 // Kufiri maksimal i regjistrimeve

enum Status { START = 1, IN_PROGRESS, COMPLETED };

int main() {
    // Array-t për të ruajtur të dhënat e disa studentëve
    int ids[MAX_STUDENTS];
    char emrat[MAX_STUDENTS][50]; // Listë me emra (deri ne 50 karaktere per emer)
    int progresat[MAX_STUDENTS];
    enum Status statuset[MAX_STUDENTS];

    int studentCount = 0; // Sa studentë kemi aktualisht
    int zgjedhja;
    int running = 1;

    printf("--- Student Progress Tracker v2.0 ---\n");

    while (running) {
        printf("\nMENUJA KRYESORE (%d/%d studentë):\n", studentCount, MAX_STUDENTS);
        printf("1. Shto një student të ri\n");
        printf("2. Shfaq të gjithë studentët\n");
        printf("3. Dil nga programi\n");
        printf("Zgjedhja juaj: ");
        scanf("%d", &zgjedhja);

        switch (zgjedhja) {
            case 1:
                // Kontrolli nëse kemi arritur kufirin maksimal
                if (studentCount < MAX_STUDENTS) {
                    printf("\nRegjistrimi i studentit te ri:\n");
                    
                    printf("ID: ");
                    scanf("%d", &ids[studentCount]);
                    
                    printf("Emri: ");
                    scanf("%s", emrat[studentCount]); // Lexon emrin pa hapesira
                    
                    printf("Progresi fillestar (0-100): ");
                    scanf("%d", &progresat[studentCount]);
                    
                    statuset[studentCount] = START; // Automatikisht fillon si START
                    
                    studentCount++; // Rritim numrin e studentëve të ruajtur
                    printf("Studenti u shtua me sukses!\n");
                } else {
                    printf("\n!!! Gabim: Eshte arritur kapaciteti maksimal (%d) !!!\n", MAX_STUDENTS);
                }
                break;

            case 2:
                // Kontrolli nëse ka studentë për të shfaqur
                if (studentCount == 0) {
                    printf("\nLista është boshe. Shtoni një student fillimisht.\n");
                } else {
                    printf("\n%-5s | %-15s | %-10s | %-10s\n", "ID", "EMRI", "PROGRESI", "STATUSI");
                    printf("----------------------------------------------------------\n");
                    
                    // Loop-i që shëtit nëpër të gjithë studentët e regjistruar
                    for (int i = 0; i < studentCount; i++) {
                        char *statusStr = (statuset[i] == START) ? "Start" : 
                                         (statuset[i] == IN_PROGRESS) ? "Progres" : "Mbaruar";
                        
                        printf("%-5d | %-15s | %-10d%% | %-10s\n", 
                               ids[i], emrat[i], progresat[i], statusStr);
                    }
                }
                break;

            case 3:
                printf("Duke u mbyllur...\n");
                running = 0;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }
    }

    return 0;
}