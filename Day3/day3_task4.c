#include <stdio.h>

int main() {
    int reps;
    double weight;

    int *p_reps = &reps;
    double *p_weight = &weight;

    printf("--- Gym Progress Tracker (Pointer Edition) ---\n");
    printf("Enter number of reps: ");
    scanf("%d", &reps);
    printf("Enter weight (kg): ");
    scanf("%lf", &weight);

    double old_weight = weight;

    printf("\n--- Initial Memory Audit ---\n");
    printf("Reps Value: %d | Address: %p | Via Pointer: %d\n", reps, (void*)p_reps, *p_reps);
    printf("Weight Value: %.2f | Address: %p | Via Pointer: %.2f\n", weight, (void*)p_weight, *p_weight);

    // Modifying weight via pointer
    printf("\nUpdating weight via pointer...\n");
    *p_weight = *p_weight + 2.5; // Adding a small plate

    printf("\n--- Comparison Analysis ---\n");
    printf("Old Weight: %.2f kg\n", old_weight);
    printf("New Weight: %.2f kg\n", weight);

    if (weight > old_weight) {
        printf("Status: Performance increased! Weight is higher.\n");
    } else if (weight < old_weight) {
        printf("Status: Performance decreased! Weight is lower.\n");
    } else {
        printf("Status: Performance plateaued. Weight is the same.\n");
    }

    if (weight >= 100.0) {
        printf("Category: Heavy Lifting Range.\n");
    } else {
        printf("Category: Standard Training Range.\n");
    }

    return 0;
}