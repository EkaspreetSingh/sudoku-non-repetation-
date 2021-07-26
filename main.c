#include <stdio.h>
#include <stdlib.h>

int error_9=0;
int error_4=0;

int ev_row=0;
int ev_col=0;
int ev_square_i=0;
int ev_square_j=0;

int main()
{
    su_display();
    printf("\n\n");
    printf("\n\t\t\t **MENU**");
    printf("\n\t\t\t1.9x9 Sudoku");
    printf("\n\t\t\t2.4x4 Sudoku");
    printf("\n");
    int ch;
    printf("\n\t\t    Enter Choice :");
    scanf("%d",&ch);
    system("cls");
    su_display();
    printf("\n");
    if (ch==1)
    {

        int sudoku[9][9];
        FILE *fp;
        fp=fopen("sample.txt","r");

        if(fp==NULL)
        {
            printf("\n\n");
            printf("\n\t\t\t  Invalid File\n");
            exit(1);
        }

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                fscanf(fp,"%d",&sudoku[i][j]);
            }
        }
        display_9(sudoku);
        printf("\n");
        for (int i=0;i<9;i=i+1)
        {
            for (int j=0;j<9;j=j+1)
            {
                rowcheck_9(sudoku[i][j],i,j,sudoku);
                colcheck_9(sudoku[i][j],i,j,sudoku);
                squarecheck_9(sudoku[i][j],i,j,sudoku);
            }
        }
        if (error_9==0)
        {
            printf("\n\t\t\tVAILID\n");
        }
    }
    if(ch==2)
    {

    }

}

void su_display()
{
    printf("\n  *******   *      *   *****            *****       *    *   *      *");
    printf("\n  *         *      *   *     *        *       *     *   *    *      *");
    printf("\n  *         *      *   *       *     *         *    *  *     *      *");
    printf("\n  *         *      *   *        *   *           *   * *      *      *");
    printf("\n  *******   *      *   *        *   *           *   **       *      *");
    printf("\n        *   *      *   *        *   *           *   * *      *      *");
    printf("\n        *   *      *   *       *     *         *    *  *     *      *");
    printf("\n        *   *      *   *     *        *       *     *   *    *      *");
    printf("\n  *******   ********   *****            *****       *    *   ********");
}


void display_9(int sudoku[][9])
{
    int n=9;
    for(int i=0; i<n; i++)
    {
        printf("\t  ");
        for(int j=1; j<n; j++)
        {
            if(i%3==0)
            printf("  __ ");
        }
        printf("\n");
        printf("\t  |");
        for(int j=0; j<n; j++)
        {
            printf(" %d  ",sudoku[i][j]);
            if((j+1)%3==0)
            printf("|");
        }
        printf("\n");
    }

    printf("\t  ");
    for(int j=1; j<n; j++)
    {
        printf("  __ ");
    }
}




int rowcheck_9(int a,int row,int col,int sudoku[][9])
{
    for (int i=0;i<9;i=i+1)
    {
        if (col==i)
        {
            continue;
        }
        if(col==ev_row)
        {
            continue;
        }
        else
        {
            if (sudoku[row][i]==a)
            {
                printf("\n\t\t\tERROR");
                printf("\n\t\t%d repeated in %d%d and %d%d",a,row,col,row,i);
                error_9=error_9+1;
                ev_row=i;
                //printf("\nev==%d",ev);
            }
        }
    }
}



int colcheck_9(int a,int row,int col,int sudoku[][9])
{
    for (int i=0;i<9;i=i+1)
    {
        if (row==i)
        {
            continue;
        }
        if (row==ev_col)
        {
            continue;
        }
        else
        {
            if (sudoku[i][col]==a)
            {
                printf("\n\t\t\tERROR");
                printf("\n\t\t%d repeated in %d%d and %d%d",a,row,col,i,col);
                error_9=error_9+1;
                ev_col=i;
            }
        }
    }
}


int squarecheck_9(int a,int row,int col,int sudoku[][9])
{
    int rowcorner=3*(row/3);
    int colcorner=3*(col/3);
    int rl=rowcorner+3;
    int cl=colcorner+3;
    for (int i=rowcorner;i<rl;i=i+1)
    {
        for (int j=colcorner;j<cl;j=j+1)
        {
            if (row==i || col==j)
            {
                continue;
            }
            if (row==ev_square_i && col==ev_square_j)
            {
                continue;
            }
            else
            {
                if (sudoku[i][j]==a)
                {
                    printf("\n\t\t\tERROR");
                    printf("\n\t\t%d repeated in %d%d and %d%d",a,row,col,i,j);
                    error_9=error_9+1;
                    ev_square_i=i;
                    ev_square_j=j;
                }
            }
        }
    }
}

