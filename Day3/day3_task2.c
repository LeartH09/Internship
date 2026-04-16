int main()
{
    int start, end;
    int countEven = 0, countOdd = 0;
    int sumEven = 0, sumOdd = 0;

    printf("Shkruani vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruani vleren perfundimtare: ");
    scanf("%d", &end);

    if (start > end)
    {
        printf("Interval i pavlefshem! Fillimi duhet te jete me i vogel ose i barabarte me fundin.\n");
        return 1;
    }

    for(int i = start; i <= end; i++)
    {
        if (i % 2 == 0)
        {
            countEven++;
            sumEven += i;
        }
        else
        {
            countOdd++;
            sumOdd += i;
        }
    }

    int totalNumbers = countEven + countOdd;

    printf("\nIntervali: %d deri %d\n", start, end);
    printf("Total numra: %d\n", totalNumbers);

    printf("Numra çift: %d | Shuma: %d\n", countEven, sumEven);
    printf("Numra tek: %d | Shuma: %d\n", countOdd, sumOdd);

    if(countEven > countOdd)
    {
        printf("Ka me shume numra çift se tek.\n");
    }
    else if(countOdd > countEven)
    {
        printf("Ka me shume numra tek se çift.\n");
    }
    else
    {
        printf("Ka te njejten sasi numrash çift dhe tek.\n");
    }

    return 0;
}