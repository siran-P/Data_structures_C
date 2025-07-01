#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *tail=NULL;

void enqueue(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=tail;
    if(tail!=NULL)
        tail->next=newNode;
    else
        head=newNode;
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
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
   enqueue(10);
   enqueue(20);
   display();
   enqueue(50);
   display();
   dequeue();
   display();
   // return 0;
}
