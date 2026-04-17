#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

// Enum for student status
typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS = 2,
    COMPLETED = 3
} Status;

// Struct for student record
typedef struct {
    int id;
    char name[50];
    int progress;
    Status status;
} Student;

Student students[MAX_STUDENTS];
int count = 0;

// Function to show status as text
void printStatus(Status status) {
    switch (status) {
        case NOT_STARTED:
            printf("Not Started");
            break;
        case IN_PROGRESS:
            printf("In Progress");
            break;
        case COMPLETED:
            printf("Completed");
            break;
        default:
            printf("Unknown");
    }
}

// Function to add student
void addStudent() {
    int statusChoice;

    if (count >= MAX_STUDENTS) {
        printf("Lista eshte e mbushur. Nuk mund te shtoni me shume regjistrime.\n");
        return;
    }

    printf("Shkruaj ID: ");
    scanf("%d", &students[count].id);

    printf("Shkruaj emrin: ");
    scanf(" %[^\n]", students[count].name);

    printf("Shkruaj progresin (0 - 100): ");
    scanf("%d", &students[count].progress);

    if (students[count].progress < 0 || students[count].progress > 100) {
        printf("Progres i pavlefshem. Duhet te jete nga 0 deri ne 100.\n");
        return;
    }

    printf("Zgjidh statusin:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Zgjedhja: ");
    scanf("%d", &statusChoice);

    switch (statusChoice) {
        case 1:
            students[count].status = NOT_STARTED;
            break;
        case 2:
            students[count].status = IN_PROGRESS;
            break;
        case 3:
            students[count].status = COMPLETED;
            break;
        default:
            printf("Status i pavlefshem.\n");
            return;
    }

    count++;
    printf("Regjistrimi u shtua me sukses.\n");
}

// Function to show students
void showStudents() {
    int i;

    if (count == 0) {
        printf("Nuk ka regjistrime per te shfaqur.\n");
        return;
    }

    printf("\n--- Lista e Studenteve ---\n");
    for (i = 0; i < count; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %d\n", students[i].progress);
        printf("Statusi: ");
        printStatus(students[i].status);
        printf("\n--------------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n===== Student Progress Tracker =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq regjistrimet\n");
        printf("3. Dil\n");
        printf("Zgjedh nje opsion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                showStudents();
                break;
            case 3:
                printf("Programi u mbyll.\n");
                break;
            default:
                printf("Zgjedhje e pavlefshme. Provo perseri.\n");
        }

    } while (choice != 3);

    return 0;
}


