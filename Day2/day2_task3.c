#include <stdio.h>
int main() 
{
    printf("Shkruani nje numer (7-10):");
    scanf("%d", &dita);

    switch(dita)
    {
        case 1:
        printf("E hene- dite pune\n");
        break;

        case 2:
        printf("E marte- dite pune\n");
        break;  

        case 3:
        printf("E merkure- dite pune\n");
        break;
        
        case 4:
        printf("E enjte- dite pune\n");
        break;
        
        case 5:
        printf("E premte- dite pune\n");
        break;

        case 6:
        printf("E shtune- fundjave\n");
        break;

        case 7:
        printf("E diele- fundjave\n");
        break;
//test
        default:
        printf("Ju lutem shkruani nje numer nga 1 deri ne 7\n");
    }
    
    return 0;
}

