#define MAX_STUDENTS 5

// 1. Enum i qartë për kategoritë e progresit
enum Status {
    NEW = 1,
    ACTIVE,
    GRADUATED
};

int main() {
    int ids[MAX_STUDENTS];
    char emrat[MAX_STUDENTS][50];
    int progresat[MAX_STUDENTS];
    enum Status statuset[MAX_STUDENTS]; // Lidhim enum me array-n

    int studentCount = 0;
    int zgjedhja;
    int running = 1;

    printf("--- Student Tracker v3.0 (Me Validim & Enum) ---\n");

    while (running) {
        printf("\nMENUJA KRYESORE:\n");
        printf("1. Shto Student\n");
        printf("2. Shfaq Listen\n");
        printf("3. Dil\n");
        printf("Zgjedhja: ");

        // Validimi i inputit: scanf kthen 1 nese merr numer
        if (scanf("%d", &zgjedhja) != 1) {
            printf("!!! Gabim: Shkruaj vetem numra !!!\n");
            while(getchar() != '\n'); // Pastron buffer-in qe programi mos te beje loop pafund
            continue;
        }

        switch (zgjedhja) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    printf("Emri i studentit: ");
                    scanf("%s", emrat[studentCount]);
                    
                    printf("ID: ");
                    scanf("%d", &ids[studentCount]);
                    
                    progresat[studentCount] = 0; // Fillon me 0

                    // 2. NË-MENU me Switch për të zgjedhur Statusin (Enum)
                    int zgjedhjaStatusi;
                    int statusValid = 0;

                    while (!statusValid) {
                        printf("\nZgjidh Statusin:\n");
                        printf("1. NEW (Fillestar)\n");
                        printf("2. ACTIVE (Ne proces)\n");
                        printf("3. GRADUATED (I diplomuar)\n");
                        printf("Zgjedhja: ");
                        scanf("%d", &zgjedhjaStatusi);

                        switch (zgjedhjaStatusi) {
                            case NEW:
                            case ACTIVE:
                            case GRADUATED:
                                statuset[studentCount] = (enum Status)zgjedhjaStatusi;
                                statusValid = 1;
                                break;
                            default:
                                printf("!!! Status i pavlefshem! Zgjidh 1, 2 ose 3 !!!\n");
                        }
                    }

                    studentCount++;
                    printf("Studenti u shtua me sukses!\n");
                } else {
                    printf("Kapaciteti eshte plot!\n");
                }
                break;

            case 2:
                if (studentCount == 0) {
                    printf("\nLista eshte boshe.\n");
                } else {
                    printf("\n%-15s | %-10s | %-15s\n", "EMRI", "ID", "STATUSI");
                    printf("--------------------------------------------\n");
                    for (int i = 0; i < studentCount; i++) {
                        // Përkthejmë vlerën e Enum në tekst për përdoruesin
                        char *statusText;
                        switch (statuset[i]) {
                            case NEW: statusText = "New"; break;
                            case ACTIVE: statusText = "Active"; break;
                            case GRADUATED: statusText = "Graduated"; break;
                            default: statusText = "Unknown";
                        }
                        printf("%-15s | %-10d | %-15s\n", emrat[i], ids[i], statusText);
                    }
                }
                break;

            case 3:
                running = 0;
                break;

            default:
                printf("!!! Opsion i pavlefshem !!!\n");
        }
    }
    return 0;
}