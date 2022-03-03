#include <stdio.h>
#include <stdlib.h>

int getSumOfEightNeighbors (int nbLin, int nbCol, int iArray[nbLin][nbCol], int eltLin, int eltCol)
{
    int somme = 0;

    for (int i = 0; i < nbLin; i++)    
    {
        for (int j = 0; j < nbCol; j++)
        {
            if( eltCol >= 0 && eltCol < nbCol && eltLin >= 0 && eltLin < nbLin)
            {
                if( (j == (eltCol +1) || j == (eltCol -1)) && i == eltLin )
                {
                    somme += iArray[i][j];

                }
                if ((i == (eltLin + 1) || i == (eltLin -1)) && j == eltCol)
                {
                    somme += iArray[i][j];

                }
                if( (i == (eltLin +1) || i == (eltLin -1)) && (j == (eltCol +1)|| j == (eltCol -1)))
                {
                    somme += iArray[i][j];

                }
            }
        }
        
    }
    return somme;
}

int init(int nb_col, int nb_lig, int **tab)
{
    for(int i; i < nb_lig; i ++)
    {
        for (int j = 0; j < nb_col; j++)
        {
            tab[i][j] = 0;
        }
        
    }
}

int main()
{
    int nb_col;
    int nb_lig;
    scanf("%d %d", &nb_lig, &nb_col);
    
    int **tab = NULL;
    tab = malloc(nb_lig * sizeof(int*));

    if(tab == NULL)
        {
            exit(0);
        }

    for (int i = 0; i < nb_lig; i++)
    {
        tab[i] = malloc(nb_col * sizeof(int));
        if(tab[i] == NULL)
        {
            exit(0);
        }
    }
    

    int coord_x, coord_y;
    int virulence;
    init(nb_lig,nb_col, tab);
    scanf("%d %d", &nb_lig, &nb_col);
    for(int i; i < nb_lig; i ++)
    {
        for (int j = 0; j < nb_col; j++)
        {
            scanf("%d ", &tab[i][j]);
        }
        
    }

    scanf("%d %d", &coord_x, &coord_y);
    scanf("%d", &virulence);

    printf("Taille = %d x %d\n", nb_lig, nb_col);
    for(int i; i < nb_lig; i ++)
    {
        for (int j = 0; j < nb_col; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("Foyer = (%d, %d)", coord_x, coord_y);
    printf("Virulence = %d", virulence);

    for (int i = 0; i < nb_lig; i++)
    {
        free(tab[i]);
    }

    free(tab);
    
    return 0;
}