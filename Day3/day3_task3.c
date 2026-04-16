int main()
{
    int start, end;
    int count3 = 0, sum3 = 0;
    int count5 = 0, sum5 = 0;

    printf("Shkruani vleren fillestare: ");
    scanf("%d", &start);
    
    printf("Shkruani vleren perfundimtare: ");
    scanf("%d", &end);

    if(start>end) 
    {
        printf("Interval i pavlefshem.\n");
        return 1;
    }

    for(int i = start; i <= end; i++)
    {
        if(i % 3 == 0)
        {
            count3++;
            sum3 += i;
        }
        if(i % 5 == 0)
        {
            count5++;
            sum5 += i;
        }
    }

    printf("\nNumrat qe pjestohet me 3: %d | Shuma: %d\n", count3, sum3);
    printf("Numrat qe pjestohet me 5 (jo me 3): %d | Shuma: %d\n", count5, sum5);

    if (sum3 > sum5) {
        printf("Shuma e numrave qe pjestohet me 3 eshte me e madhe.\n");
    } else if (sum5 > sum3) {
        printf("Shuma e numrave qe pjestohet me 5 eshte me e madhe.\n");
    } else {
        printf("Shumat jane te barabarta.\n");
    }

    return 0;

}