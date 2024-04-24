#include <stdio.h>

int main(void)
{
    int L[50] = {4, 26, 57, 76, 81, 93, 96, 107, 118, 148, 151, 161, 178, 180, 200, 218, 252, 263, 273, 298, 322, 327, 363, 375, 412, 440, 451, 471, 489, 500, 503, 526, 557, 574, 592, 611, 621, 633, 651, 675, 696, 698, 701, 719, 742, 766, 778, 786, 817};
    int valeur_cherche = 701;
    int a = 0;
    int b = 49;
    int milieu = 0;
    int trouve = 0;
    while(trouve == 0 && a <= b)
    {
        milieu = (a + b)/2;
        if(L[milieu] == valeur_cherche)
        {
            trouve = 1;
        }
        else
        {
            if(valeur_cherche > L[milieu])
            {
                a = milieu + 1;
            }
            else
            {
                b = milieu - 1;
            }
        }
    }
    if(trouve == 1)
    {
        printf("La valeur cherche est a la position %d\n", milieu);
    }
    else
    {
        printf("La valeur cherche n'est pas dans le tableau\n");
    }
    return 0;
}