#include <stdio.h>
#include <stdlib.h>

struct node{
    int rollno;
    char name[20];
    int data;
    struct node *next;
};


void createLinkedlist(struct node *head){
    struct node *current, *temp;
    int choice;
    temp = head;

    do
    {
        choice = 1;
        current = (struct node*)malloc(sizeof(struct node));
        current->next = NULL;
        printf("Enter the Roll no: ");
        scanf("%d", &current->rollno);
        printf("Enter the name: ");
        scanf("%s", current->name);
        temp->next = current;
        temp = current;

        printf("Do you wish to continue?: Enter 1 for yes or 0 for no: ");
        scanf("%d", &choice);

    } while (choice != 0);
    
}


void printLinkedlist(struct node *head) {
    struct node *temp;

    if (head == NULL){
        printf("The list is empty!");
        return;
    }
    printf("The Elements of the list are: \n");
    temp = head;
    while (temp != NULL) {
        printf("%d      %s\n", temp->rollno, temp->name);
        // printf("%s\n", temp->name);
        temp = temp->next;
    }
}


int main(){
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    head -> next = NULL;

    createLinkedlist(head);
    printLinkedlist(head->next);

    return 0;
    
}