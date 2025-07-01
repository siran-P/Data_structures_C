#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node* head=NULL;//global
void insertAtBeginning(int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));//dynamic memory allocation
    newNode->data=value; //store data to the new node
    newNode->next=head; //point head to newnodes next
    head=newNode; //make newNode as the head
}

void insertAtEnd(int value)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));//dynamic memory allocation
    newNode->data=value;//store data
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node* temp=head;//traversing pointer
        while(temp->next!=NULL){
            temp=temp->next;
        }
     temp->next=newNode; 
    }
}

void insertAtMiddle(int value,int pos){
    if(pos==1){
        insertAtBeginning(value);
    }
    else{
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));//create a newNode
        newNode->data=value;
        struct Node* temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void deleteAtBeginning()
{   
    struct Node* temp=head; 
    head=head->next;
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

void deleteAtMiddle(int pos){
    if(pos==1){
        deleteAtBeginning();
    }
    else{
         struct Node* temp=head;
         for(int i=1;i<pos-1;i++){
            temp=temp->next;
         }
         temp->next=temp->next->next;
         free(temp->next->next);
    }
    
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
    insertAtEnd(30);//400
    insertAtEnd(40);//500
    display();
    insertAtMiddle(50,3);//600
    display();
    deleteAtBeginning();
    display();
    insertAtMiddle(20,1);//700
    display();
    deleteAtEnd();
    display();
  //  deleteAtMiddle(3);
   // display();
  // return 0;
}