#include <stdio.h>

int main() {
    int start, end;
    int countEven = 0, countOdd = 0;
    int sumEven = 0, sumOdd = 0;

    printf("Enter start of interval: ");
    scanf("%d", &start);
    printf("Enter end of interval: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Error: Invalid interval! Start must be less than or equal to end.\n");
        return 1;
    }

    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            countEven++;
            sumEven += i;
        } else {
            countOdd++;
            sumOdd += i;
        }
    }

    printf("\n--- Interval Analysis ---\n");
    printf("Interval: [%d, %d]\n", start, end);
    printf("Total values checked: %d\n", (end - start) + 1);
    printf("Even numbers: %d (Sum: %d)\n", countEven, sumEven);
    printf("Odd numbers: %d (Sum: %d)\n", countOdd, sumOdd);

    if (countEven > countOdd) {
        printf("Category with more numbers: Even\n");
    } else if (countOdd > countEven) {
        printf("Category with more numbers: Odd\n");
    } else {
        printf("Bth categories have the same amount of numbers.\n");
    }

    return 0;
}