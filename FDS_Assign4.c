#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int marks[10], int n)
{
    int bucket[100];
    for (int i=0;i<100;i++)
        bucket[i]=0;
    
    for (int j=0;j<n;j++)
    {
        ++bucket[(int)marks[j]];
    }

    for (int i=0, j=0; i<100; i++)
        for (;bucket[i]>0; --bucket[i])
        {
            marks[j] = i;
            j++;
        }
}

int main()
{
    int n,i;
    int marks[10];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    for ( i=0;i<n;i++)
    {
        printf("Enter the marks of the student: ");
        scanf("%d", &marks[i]);
        //printf("%f\n", marks[i]);
    }


    printf("The marks entered are:\n");
    for ( i=0; i<n; i++)
    {
        printf("%d ", marks[i]);
    } 

    //  for ( i=0;i<n-1;i++)
    // {
    //     // Convert float to int by multiplying by 100 
    //     marks[i] = marks[i] *100;
    //     marks[i] = (int)marks[i];
    // }

    bucket_sort(marks, n);
    // for ( i=0;i<n-1;i++)
    // {
    //     // Convert float to int by multiplying by 100 
    //     marks[i] = marks[i]/100;
    // }

    printf("\nSorted:\n");
    for (int i=0; i<n; i++)
    {
        printf("%d ", marks[i]);
    }

    
}