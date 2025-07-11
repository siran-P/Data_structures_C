// Congo line :It is just like a queue ,people dance as a formatiom of queue.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char *name;
    struct Node* next;
    struct Node* prev;
};

struct Node* head=NULL;
struct Node* tail=NULL;

void enqueue(char *s){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->name = malloc(strlen(s) + 1);
    strcpy(newNode->name, s);
    newNode->next=NULL;
    newNode->prev=tail;
    if(tail==NULL)
        head=newNode;
    else
        tail->next=newNode;
    tail=newNode;
}

void dequeue(){
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        struct Node* temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    
}

void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%s ",temp->name);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int choice;
    char name[50];

    do {
        printf("\n--- Congo Line Menu ---\n");
        printf("1. Join the line\n");
        printf("2. Leave the line\n");
        printf("3. Show Congo line\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter name to join: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                enqueue(name);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Congo line ends.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}