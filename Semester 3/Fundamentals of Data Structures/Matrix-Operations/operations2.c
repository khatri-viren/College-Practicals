#include <stdio.h>
#include <stdlib.h>

void accept( int matrix[][100],int row,int col)
{
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("Enter the values [%d]{%d]:",i ,j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void compact( int a[100][100], int b[100][100], int row, int col)
{
    b[0][0]=row;
    b[0][1]=col;
    int k=1;
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2] = a[i][j];
                k++ ;
            }
        }
    }
    b[0][2] = k-1;
    int elm = b[0][2];

    if(elm <=0)
    {
        printf("Zero Matrix\n");
    }
    else
    {  //Printing Compact Form
        printf("Entered matrix:\n");
        for (int i=0; i<elm+1; i++)
        {
            for(int j=0; j<3; j++)
            {
                printf("%d\t",b[i][j]);
            }
            printf("\n");
        }
    }
}


void simptrans(int a[100][100],int res[100][3])
{
    int row, col, t; 
    row = a[0][0];
    col = a[0][1];
    t = a[0][2];
    res[0][0] = col;
    res[0][1] = row;
    res[0][2] = t;
    
    int q=1;
    for (int i=0; i<a[0][1]; i++)
    {
        for (int j=1; j<a[0][2]+1; j++)
        {
            if (a[j][1] == i)
            {
                res[q][0] = a[j][1];
                res[q][1] = a[j][0];
                res[q][2] = a[j][2];
                q += 1;
            } 
        }
    }
    
    if(t<=0)
    {
        ;
    }
    else
    {    //Printing
        printf("Simple Transpose:\n");
        for (int k=0; k<a[0][2]+1; k++)
        {
            for(int l=0; l<3; l++)
            {
                printf("%d\t",res[k][l]);
            }
            printf("\n");
        }
    }
}

void fasttrans(int a[100][100])
{
    int s[a[0][1]], t[a[0][1]+1];
    int row, col, elm;
    int res[100][3];
    
    row = a[0][0];
    col = a[0][1];
    elm = a[0][2];
    
    for (int i=0; i<a[0][1]; i++)
    {
        s[i] = 0;
    }

    for(int i=1; i<a[0][2]+1; i++)
    {
        s[a[i][1]] += 1;
    }

    
    t[0]=1;
    for(int i=1; i<=a[0][1]; i++)
    {
        t[i] = t[i-1] + s[i-1];
    }

    res[0][0] = col;
    res[0][1] = row;
    res[0][2] = elm;

    int j;
    for(int i=1; i<=a[0][2]; i++)
    {
        j = a[i][1];
        res[t[j]][0] = a[i][1];
        res[t[j]][1] = a[i][0];
        res[t[j]][2] = a[i][2];
        t[j]++;
    }

    if(a[0][2]<=0)
    {
        ;
    }
    else
    {    //Printing 
        printf("Fast Transpose:\n");
        for (int k=0; k<a[0][2]+1; k++)
        {
           for(int l=0; l<3; l++)
            {
                printf("%d\t",res[k][l]);
            }
            printf("\n");
        }
    }
}

void display(int matrix[100][100], int row, int col)
{
    printf("Your Entered Matrix is:\n");
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
			printf("%d\t",matrix[i][j]);
		}
        printf("\n");
    }
}


int main()
{
    int a [100][100], b[100][100], res[100][3], r1, c1, elm, choice,k,l;
    
    printf("Enter the number of rows for the Matrix:");
    scanf("%d", &r1);
    printf("Enter the number of columns for the Matrix:");
    scanf("%d", &c1);

    printf("Enter the values for the matrix:\n");
    accept(a, r1, c1);
    display(a, r1, c1);

    do
    {
        printf("Choose an option:\n");
        printf("==============================\n");
        printf("1. Convert to Compact\n");
        printf("2. Simple Transpose\n");
        printf("3. Fast Transpose\n");
        printf("4. Exit\n");
        printf("==============================\n");
        printf("Enter your choce:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            compact(a,b, r1, c1);
            break;
            
            case 2:
            compact(a,b, r1, c1);
            printf("\n");
            simptrans(b, res);
            break; 

            case 3:
            compact(a ,b, r1, c1);
            printf("\n");
            fasttrans(b);
            break;

            case 4:
            printf("Thank You!\n");
            exit(0);

            default:
            printf("Invalid input!\n");
            printf("Please enter the correct input.\n");

        }
    } while (1);
    


    return 0;
}