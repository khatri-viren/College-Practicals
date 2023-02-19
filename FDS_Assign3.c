#include <stdio.h>
#include <stdlib.h>

struct stud
{
    int rollno;
    char name[20];
    int marks;
};

void accept(struct stud s[10], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("\nEnter the details of the student\n");
        printf("Enter the Roll. No. ");
        scanf("%d", &s[i].rollno);
        printf("Enter the Name: ");
        scanf("%s", s[i].name);
        printf("Enter the Marks: ");
        scanf("%d", &s[i].marks);
    }
}

void display(struct stud s[10], int n)
{
    printf("Roll No:\tName:\tMarks:\n");
    for (int i=0; i<n; i++ )
        printf("%d\t %s\t %d\n",s[i].rollno, s[i].name, s[i].marks);
}

int linear(struct stud s[10], int t, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (s[i].rollno == t)
        {
            printf("Target found!\n");
            return i;
        }
    }
    return -1;
}   

int nonresbinary(struct stud s[10], int l, int h, int t)
{
    int m;
    while (l<=h)
    {
        m = (l+h)/2;
        if (s[m].rollno == t)
        {
            return m;
        }
        else
        {
            if (t<s[m].rollno)
                h = m -1;
            else
                l = m + 1;
        }
    }
   
    return -1;
}

int resbinary(struct stud s[10], int l, int h, int t)
{
    int m;
    if (l <= h)
    {
        m = (l+h)/2;
        if(s[m].rollno==t)
            return m;
        else if (t<s[m].rollno)
            return resbinary(s, l, m-1, t);
        else 
            return resbinary(s, m+1, h, t);
    }
    return -1;
}

void selection_sort(struct stud s[10],int n)
{
    int minpos; 
    struct stud temp;

    for (int i=0; i<=n-2; i++)
    {
        minpos = i;
        for (int j=i+1; j<=n-1; j++)
        {
            if (s[j].rollno < s[minpos].rollno)
            {
                minpos = j;
            }
        }
        if (minpos != i)
        {
            temp = s[i];
            s[i] = s[minpos];
            s[minpos] = temp;
        }
        display(s,n);
    }
}

void insertion_sort(struct stud s[10], int n)
{
    struct stud key;
    int j=0;
    for (int i=0;i<n;i++)
    {
        key = s[i];
        j = i-1;
        while(j>=0&& s[j].rollno>key.rollno)
        {
            s[j+1] = s[j];
            j = j-1;
        }
        s[j+1] = key;
        display(s,n);
    }
}

void shell_sort(struct stud s[10], int n)
{
    int gap = 0;
    gap = n/2;
    int swapped = 0;
    struct stud temp;

    do
    {
        do
        {
            swapped =0;
            for (int i=0;i<n-gap;i++)
            {
                if(s[i].rollno > s[i+gap].rollno)
                {
                    temp = s[i];
                    s[i] = s[i+gap];
                    s[i+gap] = temp;
                    swapped = 1;
                }
                display(s,n);
            }
        } while (swapped == 1);
    } while ((gap=gap/2)>=1);
    
}

void target_display(struct stud s[10], int i)
{
    printf("%d, %s, %d\n", s[i].rollno, s[i].name, s[i].marks);
}

int main()
{
    int n, choice;
    int r, pos;
    int low=0, high;

    struct stud s[10];

    do
    {
        printf("Choose an option:\n");
        printf("==============================\n");
        printf("1. Linear Search\n");
        printf("2. Non-Recursive Binary Search\n");
        printf("3. Recursive Binary Search\n");
        printf("4. Selection Sort\n");
        printf("5. Insertion Sort\n");
        printf("6. Shell Sort\n");
        printf("7. Exit\n");
        printf("==============================\n");
        printf("Enter your choce:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: //Linear
            printf("Enter the number of students: ");
            scanf("%d", &n);
            accept(s,n);

            printf("The entered details are:\n");
            display(s, n);

            printf("Enter the roll no to be searched: ");
            scanf("%d", &r);
            pos = linear(s,r,n);
            if (pos != -1)
                target_display(s,pos);
            else
                printf("\nTarget Not Found!\n");            
            break;

            case 2: //Non Res Binary
            printf("Enter the number of students: ");
            scanf("%d", &n);
            accept(s,n);

            printf("The entered details are:\n");
            display(s, n);

            high = n;
            printf("Enter the roll no to be searched: ");
            scanf("%d", &r);
            selection_sort(s,n);
            pos = nonresbinary(s,low,high,r);
            if (pos != -1)
                target_display(s,pos); 
            else
                printf("\nTarget Not Found!\n");         
            break;

            case 3: //Res Binary
            printf("Enter the number of students: ");
            scanf("%d", &n);
            accept(s,n);

            printf("The entered details are:\n");
            display(s, n);
            
            high = n;
            printf("Enter the roll no to be searched: ");
            scanf("%d", &r);
            selection_sort(s,n);
            pos = resbinary(s,low,high,r);
            if (pos != -1)
                target_display(s,pos);
            else
                printf("\nTarget Not Found!\n");
            break;

            case 4: //Seleciton
            printf("Enter the number of students: ");
            scanf("%d", &n);
            accept(s,n);

            printf("The entered details are:\n");
            display(s, n);
            
            printf("Sorting using Selection Sort\n");
            selection_sort(s,n);
            //display(s,n);
            break;
            
            case 5: //Inseriton
            printf("Enter the number of students: ");
            scanf("%d", &n);
            accept(s,n);

            printf("The entered details are:\n");
            display(s, n);
            
            printf("Sorting using Insertion Sort");
            insertion_sort(s,n);
            //display(s,n);
            break;

            case 6: //Shell
            printf("Enter the number of students: ");
            scanf("%d", &n);
            accept(s,n);

            printf("The entered details are:\n");
            display(s, n);
            
            printf("Sorting using Shell Sort");
            shell_sort(s,n);
            //display(s,n);
            break;

            case 7:
            printf("Thank You!\n");
            exit(0);

            default:
            printf("Invalid input!\n");
            printf("Please enter the correct input.\n");
        }
    } while (1);
    
    return 0;
}