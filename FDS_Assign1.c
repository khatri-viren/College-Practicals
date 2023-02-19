#include <stdio.h>
#include <stdlib.h>

void accept(int matrix[10][10], int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
            printf("Enter the value [%d][%d]:", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}

void add(int a[10][10], int b[10][10], int result[10][10], int r1, int c1, int r2, int c2)
{
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++)
        {
            result[i][j]= a[i][j]+b[i][j];
        }
    }

}

void sub(int a[10][10], int b[10][10], int result[10][10], int r1, int c1, int r2, int c2)
{
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++)
        {
            result[i][j]= a[i][j]-b[i][j];
        }
    }

}

void multiply(int a[10][10], int b[10][10], int result[10][10], int r1, int c1, int r2, int c2)
{
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++)
        {
            result[i][j]=0;
            for(int k=0; k<c1; k++)
            {
                result[i][j]=a[i][k]*b[k][j];
            }
        }
    }

}

void trans(int matrix[10][10], int result[10][10], int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			result[i][j]= matrix[j][i];
		}
	}
}

void display(int matrix[10][10], int row, int col)
{
    for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d\t",matrix[i][j]);
		}
        printf("\n");
	}
}

int main()
{
    int a[10][10], b[10][10], result[10][10], r1, c1, r2, c2, choice;
    printf("Enter the number of rows of the first matrix: ");
    scanf("%d", &r1);
    printf("Enter the number of columns of the first matrix: ");
    scanf("%d",&c1);
    printf("Enter the number of rows of the second matrix: ");
    scanf("%d", &r2);
    printf("Enter the number of columns of the second matrix: ");
    scanf("%d",&c2);


    while( c1 != r2)
    {
        printf("Error! Number of columns of the first matrix does not match the number of rows of second matrix\n");
        printf("Enter the number of rows of the first matrix: ");
        scanf("%d", &r1);
        printf("Enter the number of columns of the first matrix: ");
        scanf("%d",&c1);
        printf("Enter the number of rows of the second matrix: ");
        scanf("%d", &r2);
        printf("Enter the number of columns of the second matrix: ");
        scanf("%d",&c2);
    }

    printf("Enter the values of the First Matrix:\n");
    accept(a, r1, c1);

    printf("Enter the values of the Second Matrix:\n");
    accept(b, r2, c2);
    
    printf("The First Matrix is:\n");
    display(a, r1, c1);

    printf("The Second Matrix is:\n");
    display(b, r2, c2);

    do
    {
        printf("\nChoose the matrix operation,\n");
        printf("============================\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose\n");
        printf("5. Exit\n");
        printf("============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            add(a,b,result,r1,c1,r2,c2);
            printf("The Addition of the given two matrices is:\n");
            display(result, r1,c2);
            break;
            case 2:
            sub(a,b,result,r1,c1,r2,c2);
            printf("The Subtraction of the two matrices is:\n");
            display(result,r1,c2);
            break;
            case 3:
            multiply(a,b,result,r1,c1,r2,c2);
            printf("The Multiplication of the two matrices is:\n");
            display(result,r1,c2);
            break;
            case 4:
            trans(a,result,r1,c1);
            printf("The Transpose of the first matrix is:\n");
            display(result,r1,c1);
            trans(b,result,r2,c2);
            printf("The Transpose of the second matrix is:\n");
            display(result,r2,c2);
            break;
            case 5:
            printf("Thank You.\n");
            exit(0);
            default:
            printf("Invalid input.\n");
            printf("Please enter the correct input.\n");
        }
    } while (1);
    return 0;
}


