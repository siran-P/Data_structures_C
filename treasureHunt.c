#include <stdio.h>
#include<stdlib.h>
struct Node{
    char *clue;
    int ans;
    struct Node* next;
    struct Node* prev;
};

struct Node* head=NULL;
struct Node* tail=NULL;
void addClues(char *s,int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->clue=s;
    new->ans=data;
    new->prev=tail;
    if(head!=NULL){
        tail->next=new;
    }
    else{
        head=new;
    }
    tail=new;
    
}
void treasureHunt(){
    struct Node* temp=head;
    int c=3;
    while(temp!=NULL){
        printf("%s\n",temp->clue);
        int n;
        scanf("%d",&n);
        if(n==temp->ans){
            temp=temp->next;
            c=3;
        }
        else{
            c--;
            if(c==0)
            printf("Better luck next time!\n");
            printf("%d chances more\n",c);
        }
    }
    printf("Won the treasure :)\n");
}
int main()
{
    addClues("Even Prime",2);
    addClues("Number of River",6);
    addClues("Invert of six",9);
    addClues("Top half of 8",0);
    addClues("I'm an odd number.Take away one letter,and I become even",7);
    treasureHunt();
    return 0;
}
