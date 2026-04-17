#include <stdio.h>

#define MAX_STUDENTS 5

struct Student {
    int id;
    char name[50];
    int progress;
    char status[20];
};

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    int i;

    while (1) {
        printf("\n--- Student Progress Tracker ---\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Max students reached!\n");
                } else {
                    printf("ID: ");
                    scanf("%d", &students[count].id);

                    printf("Name: ");
                    scanf("%s", students[count].name);

                    printf("Progress: ");
                    scanf("%d", &students[count].progress);

                    printf("Status: ");
                    scanf("%s", students[count].status);

                    count++;
                    printf("Added!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No students yet.\n");
                } else {
                    for (i = 0; i < count; i++) {
                        printf("\nStudent %d\n", i + 1);
                        printf("ID: %d\n", students[i].id);
                        printf("Name: %s\n", students[i].name);
                        printf("Progress: %d\n", students[i].progress);
                        printf("Status: %s\n", students[i].status);
                    }
                }
                break;

            case 3:
                printf("Exit...\n");
                return 0;

            default:
                printf("Wrong choice.\n");
        }
    }

    return 0;
}