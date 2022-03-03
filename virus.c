#include <stdio.h>
#include <stdlib.h>

void print_tab(int nb_col, int nb_lig, int **tab)
{
    for(int i = 0; i < nb_lig; i ++)
    {
        for (int j = 0; j < nb_col; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int defense_immunitaire(int nb_col, int nb_lig, int **tab, int *coord_x, int *coord_y, int *virulence)
{
    for(int i = 0; i < nb_lig; i ++)
    {
        for (int j = 0; j < nb_col; j++)
        {
            scanf("%d ", &tab[i][j]);
        }
        
    }

    scanf("%d %d", coord_x, coord_y);
    scanf("%d", virulence);

    printf("Taille = %d x %d\n", nb_lig, nb_col);
    print_tab(nb_col,nb_lig,tab);
    printf("Foyer = (%d, %d)\n", *coord_x, *coord_y);
    printf("Virulence = %d\n\n", *virulence);
    return 0;
}

void init(int nb_col, int nb_lig, int **tab)
{
    for(int i; i < nb_lig; i ++)
    {
        for (int j = 0; j < nb_col; j++)
        {
            tab[i][j] = 0;
        }
        
    }
}

int VIRUS(int nb_lin, int nb_col,int **tab, int **virus, int virulence, int coord_x, int coord_y)
{  
       for(int i = -1; i <= 1; i++)
       {
           for(int j = -1; j <= 1; j++)
           {    
                if( ((coord_y+j) >= 0 && (coord_y+j) < nb_lin && (coord_x+ i) >= 0 && (coord_x+i )< nb_col )&& ( i!=0 || j!=0 ))
                {

                    if( tab[coord_x +i][coord_y +j] <= virulence )
                    {
                        virus[coord_x][coord_y]= -1;
                        VIRUS(nb_lin,nb_col,tab,virus,virulence,coord_x +i,coord_y +j);
                    }
                }
            }
        
        }
    
    
    return 0;
}

int main()
{
    int nb_col;
    int nb_lig;
    scanf("%d %d", &nb_lig, &nb_col);
    
    int (**population) =  malloc(nb_lig * sizeof(int*));
    int (**virus) =  malloc(nb_lig * sizeof(int*));
    
    //init(nb_col, nb_lig, virus);
    if(population == NULL || virus == NULL)
        {
            exit(-1);
        }

    for (int i = 0; i < nb_lig; i++)
    {
        
        population[i] = malloc(nb_col * sizeof(int));
        virus[i] = malloc(nb_col * sizeof(int));

        if(population[i] == NULL || virus == NULL)
        {
            for (i = i-1; i >= 0; i--)
            {
                free(population[i]);
                free(virus[i]);

            }
            free(population);
            free(virus);

            exit(-1);
        }
    }
    

    

    int coord_x = 0, coord_y = 0;
    int virulence = 0;
    defense_immunitaire(nb_col,nb_lig,population,&coord_x,&coord_y,&virulence);
    
    virus[coord_x][coord_y] = -2;
    VIRUS(nb_lig,nb_col,population,virus,virulence,coord_x,coord_y);
    
    printf("PROPAGATION DU VIRUS\n");
    print_tab(nb_col,nb_lig,virus);

    
    for (int i = 0; i < nb_lig; i++)
    {
        free(population[i]);
        free(virus[i]);

    }

    free(population);
    free(virus);

    
    return 0;
}