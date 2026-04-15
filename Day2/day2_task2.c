#include <stdio.h>

int main() {
    int rezultati;

    printf("Shkruani rezultatin tuaj (0-100): ");
    scanf("%d", &rezultati);

    if (rezultati < 0 || rezultati > 100) {
        printf("Gabim: Input-i nuk eshte valid!\n");
    } 
    else if (rezultati >= 90) {
        printf("Vleresimi: Shkelqyeshem!\n");
    } 
    else if (rezultati >= 80) {
        printf("Vleresimi: Shume mire!\n");
    } 
    else if (rezultati >= 70) {
        printf("Vleresimi: Mire!\n");
    } 
    else if (rezultati >= 50) {
        printf("Vleresimi: Ne permiresim.\n");
    } 
    else {
        printf("Vleresimi: Nuk kalon.\n");
    }

    return 0;
}