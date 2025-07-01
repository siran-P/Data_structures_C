#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* head=NULL;//global
struct Node* tail=NULL;//global
void insertAtBeginning(int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));//dynamic memory allocation
    newNode->data=value; //store data to the new node
    newNode->prev=NULL;
    newNode->next=head; //point head to newnodes next
    if(head==NULL)
       tail=newNode;
    else
       head->prev=newNode;
    head=newNode; //make newNode as the head
}

void insertAtEnd(int value)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));//dynamic memory allocation
    newNode->data=value;//store data
    newNode->next=NULL;
    newNode->prev=tail;
    if(tail==NULL)
        head=newNode;
    else
        tail->next=newNode;
    tail=newNode;
}

void deleteAtBeginning()
{   
    struct Node* temp=head; 
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void deleteAtEnd(){
    struct Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    free(temp->next->next);
}

void display()
{
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
       
    }
    printf("\n");
}

int main()
{
    insertAtBeginning(5);//100
    insertAtBeginning(10);//200
    insertAtBeginning(20);//300
    display();
    insertAtEnd(25);
    display();
    deleteAtBeginning();
  //  deleteAtMiddle(3);
    display();
  // return 0;
}
