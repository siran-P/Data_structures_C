#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *tail=NULL;


void isEmpty(){
    if(head==NULL){
        printf("Stack Empty\n");
    }
    else{
        printf("Not Empty\n");
    }
}

void push(int value){
    struct Node* newNode =(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=head;
    if(head!=NULL){
        head->prev=newNode;
    }else{
        tail=newNode;
    }
    head=newNode;
}

void pop(){
    if(head==NULL){
        isEmpty();
    }
    else
    {
       struct Node *temp=head;
       printf("%d is poped\n",head->data);
       head=head->next;
       head->prev=NULL;
       free(temp);
    }
}

void peek(){
    printf("%d \n",head->data);
}


void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse(){
    struct Node *temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void middleUsingHeads(){
    struct Node *temp1=head;
    struct Node *temp2=head;
    while(temp2->next!=NULL && (temp2->next->next)!=NULL){
        temp1=temp1->next;
        temp2=temp2->next->next;
    }
    printf("%d\n",temp1->data);
}

void middleUsingHeadTail(){
    struct Node *temp1=head;
    struct Node *temp2=tail;
    while(temp2!=temp1 && temp2!=temp1->next){
        temp1=temp1->next;
        temp2=temp2->prev;
    }
    printf("%d",temp1->data);
}

int main(){
    pop();
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    isEmpty();
    display();
    push(40);
  //  push(50);
    push(30);
    push(35);
    display();
    reverse();
    display();
    middleUsingHeads();
    middleUsingHeadTail();
    
}
