#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* head=NULL;//global
struct Node* tail=NULL;

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        // First node in the list
        head = tail = newNode;
        newNode->next = newNode->prev = newNode;  // circular links
    } else {
        // Insert at end
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}

void display()
{
    struct Node *temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
       
    }
    printf("%d ",temp->data);
    printf("\n");
}

int eliminatingKthElement(int k){
    struct Node* temp=head;
    while(head!=tail){
        for(int i=1;i<k;i++){
            temp=temp->next;
        }
         struct Node* t=temp;
         temp->prev->next=temp->next;
         temp->next->prev=temp->prev;
         if(temp==head){
             head=temp->next;
         }
          if(temp==tail){
             tail=temp->prev;
         }
         temp=temp->next;
         free(t);
         
         display();
    }
    return head->data;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        insertAtEnd(i);
    }
    display();
    printf("%d",eliminatingKthElement(k));
}
