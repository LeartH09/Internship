#include <stdio.h>

int main() {
    int start, end;
    int countCat1 = 0, countCat2 = 0;
    int sumCat1 = 0, sumCat2 = 0;

    printf("Enter the start of the interval: ");
    scanf("%d", &start);
    printf("Enter the end of the interval: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Error: Invalid interval! Start must be less than or equal to end.\n");
        return 1;
    }

    for (int i = start; i <= end; i++) {
        if (i % 3 == 0) {
            countCat1++;
            sumCat1 += i;
        } 
        else if (i % 5 == 0) {
            countCat2++;
            sumCat2 += i;
        }
    }

    printf("\n--- Comparison Results ---\n");
    printf("Category 1 (Divisible by 3): Count = %d, Sum = %d\n", countCat1, sumCat1);
    printf("Category 2 (Divisible by 5 but not 3): Count = %d, Sum = %d\n", countCat2, sumCat2);

    if (sumCat1 > sumCat2) {
        printf("Result: Category 1 has a larger sum.\n");
    } else if (sumCat2 > sumCat1) {
        printf("Result: Category 2 has a larger sum.\n");
    } else {
        printf("Result: Both sums are equal.\n");
    }

    return 0;
}