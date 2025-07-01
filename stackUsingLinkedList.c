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
    push(50);
    display();
    reverse();
    display();
}