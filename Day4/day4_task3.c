#define MAX_STUDENTS 5

// Enum për statusin
enum Status {
    NEW = 1,
    ACTIVE,
    GRADUATED
};

int main() {

    int ids[MAX_STUDENTS];
    char emrat[MAX_STUDENTS][50];
    int progresat[MAX_STUDENTS];
    enum Status statuset[MAX_STUDENTS];

    int studentCount = 0;
    int zgjedhja;
    int running = 1;

    printf("--- Student Tracker v3.0 (Final Version) ---\n");

    while (running) {

        printf("\nMENUJA KRYESORE:\n");
        printf("1. Shto Student\n");
        printf("2. Shfaq Listen\n");
        printf("3. Raporti\n");
        printf("4. Dil\n");
        printf("Zgjedhja: ");

        if (scanf("%d", &zgjedhja) != 1) {
            printf("!!! Gabim: Shkruaj vetem numra !!!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (zgjedhja) {

            // ================= ADD STUDENT =================
            case 1:
                if (studentCount < MAX_STUDENTS) {

                    printf("Emri i studentit: ");
                    scanf("%s", emrat[studentCount]);

                    printf("ID: ");
                    scanf("%d", &ids[studentCount]);

                    printf("Progresi (0-100): ");
                    scanf("%d", &progresat[studentCount]);

                    if (progresat[studentCount] < 0)
                        progresat[studentCount] = 0;
                    if (progresat[studentCount] > 100)
                        progresat[studentCount] = 100;

                    // Zgjedhja e statusit
                    int zgjedhjaStatusi;
                    int valid = 0;

                    while (!valid) {

                        printf("\nZgjidh Statusin:\n");
                        printf("1. NEW\n");
                        printf("2. ACTIVE\n");
                        printf("3. GRADUATED\n");
                        printf("Zgjedhja: ");
                        scanf("%d", &zgjedhjaStatusi);

                        switch (zgjedhjaStatusi) {
                            case NEW:
                            case ACTIVE:
                            case GRADUATED:
                                statuset[studentCount] = (enum Status)zgjedhjaStatusi;
                                valid = 1;
                                break;
                            default:
                                printf("!!! Status i pavlefshem !!!\n");
                        }
                    }

                    studentCount++;
                    printf("Studenti u shtua me sukses!\n");

                } else {
                    printf("Kapaciteti eshte plot!\n");
                }
                break;

            // ================= DISPLAY =================
            case 2:

                if (studentCount == 0) {
                    printf("\nLista eshte boshe.\n");
                } else {

                    printf("\n%-15s | %-10s | %-10s | %-12s\n",
                           "EMRI", "ID", "PROGRES", "STATUSI");
                    printf("-----------------------------------------------------\n");

                    for (int i = 0; i < studentCount; i++) {

                        char *statusText;

                        switch (statuset[i]) {
                            case NEW:
                                statusText = "New";
                                break;
                            case ACTIVE:
                                statusText = "Active";
                                break;
                            case GRADUATED:
                                statusText = "Graduated";
                                break;
                            default:
                                statusText = "Unknown";
                        }

                        printf("%-15s | %-10d | %-10d | %-12s\n",
                               emrat[i], ids[i], progresat[i], statusText);
                    }
                }
                break;

            // ================= REPORT =================
            case 3: {

                if (studentCount == 0) {
                    printf("\nNuk ka te dhena per raport.\n");
                    break;
                }

                int graduatedCount = 0;
                int sum = 0;
                int max = progresat[0];
                int min = progresat[0];

                for (int i = 0; i < studentCount; i++) {

                    sum += progresat[i];

                    if (statuset[i] == GRADUATED) {
                        graduatedCount++;
                    }

                    if (progresat[i] > max)
                        max = progresat[i];

                    if (progresat[i] < min)
                        min = progresat[i];
                }

                float avg = (float)sum / studentCount;

                printf("\n===== RAPORT ANALITIK =====\n");

                printf("Total Students: %d\n", studentCount);
                printf("Graduated: %d\n", graduatedCount);

                printf("Average Progress: %.2f - ", avg);

                if (avg >= 80)
                    printf("Excellent\n");
                else if (avg >= 50)
                    printf("Medium\n");
                else
                    printf("Low\n");

                printf("Max Progress: %d\n", max);
                printf("Min Progress: %d\n", min);

                printf("===========================\n");

                break;
            }

            // ================= EXIT =================
            case 4:
                running = 0;
                break;

            default:
                printf("!!! Opsion i pavlefshem !!!\n");
        }
    }

    return 0;
}