#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
}s1;
struct Node *head=NULL;

void insert(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}

void search(int n){
    struct Node* temp=head;
    while(temp!=NULL){
        if(temp->data==n){
            printf("Found");
            return;
        }
        temp=temp->next;
    }
    printf("Not Found");
    
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int d;
        scanf("%d",&d);
        insert(d);
    }
    int x;
    scanf("%d",&x);
    search(x);
    

    return 0;
}
