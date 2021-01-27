#include <stdio.h>
#include <stdlib.h>
#include "randomevents.h"

void main()
{
    int option;
    printf(" Mroczne Czasy.\n \n 1. Rozpoczêcie Gry. \n 2. Wyjœcie.\n\n Wybierz opcje : ");
    scanf("%d",&option);
    printf("\n");
    while(1)
    {
        if(option==1)
        {
            game();
            break;
        }
        else if(option==2)
        {
            break;
        }
        else
        {
            printf(" Wybierz jeszcze raz : ");
            scanf("%d",&option);
            printf("\n");
        }
    }
}
