//PlayList using Linked List
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char *song;
    struct Node* prev;
    struct Node* next;
};

struct Node* head=NULL;
struct Node* tail=NULL;

void AddToPlayist(char *s){
    
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->song = malloc(strlen(s) + 1);
    strcpy(newNode->song, s);
    newNode->next=head;
    newNode->prev=NULL;
    if(head==NULL)
        tail=newNode;
    else
        head->prev=newNode;
    head=newNode;
}

void removeSong(char *s){

    if (head == NULL) {
        printf("songs in your playlist.\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->song, s) == 0) {
            if (temp == head && temp == tail) {
                head = tail = NULL;
            } else if (temp == head) {
                head = head->next;
                head->prev = NULL;
            } else if (temp == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            printf("Removed: %s\n", s);
            free(temp->song);
            free(temp);
            return;
        }
        temp = temp->next;
    }

    printf("song not found: %s\n", s);
}

void displayPlayList(){
   
    if(head==NULL){
        printf("No songs in playList\n");
    }
    else{
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%s->",temp->song);
        temp=temp->next;
    }
    printf("NULL\n");
    }
}
void search(char *s){
    int i=0;
    if(head==0){
        printf("Play List is Empty.\n");
    }
    else{
        struct Node* temp1=head;
        struct Node* temp2=tail;
        while(temp1!=temp2 && temp1->next!=temp2){
            if(strcmp(temp1->song,s)==0){
                printf("Found:%s\n",temp1->song);
                return;
            }
            if(strcmp(temp2->song,s)==0){
                printf("Found:%s\n",temp2->song);
                return;
            }
            temp1=temp1->next;
            temp2=temp2->prev;
        }
        if (temp1 && strcmp(temp1->song, s) == 0) {
            printf("Found: %s\n", temp1->song);
            return;
        }
        if (temp2 && strcmp(temp2->song, s) == 0) {
            printf("Found: %s\n", temp2->song);
            return;
        }
        printf("Not found\n");
    }
    
}

int main(){
      int n;
       char *s=(char *)malloc(20*sizeof(char));
    do{
     printf("Enter 1:Insert\nEnter 2:Delete\nEnter 3:Display\nEnter 4:Search\nEnter 5:Exit\n");
    scanf("%d",&n);
    getchar();
        switch(n){
            case 1:
               
                fgets(s,20,stdin);
                s[strcspn(s, "\n")] = 0;
                AddToPlayist(s);
                break;
            case 2:
                //char *s1;
                fgets(s,20,stdin);
                s[strcspn(s, "\n")] = 0;
                removeSong(s);
                break;
            case 3:
                displayPlayList();
                break;
            case 4:
               // char *s2;
                fgets(s,20,stdin);
                s[strcspn(s, "\n")] = 0;
                search(s);
                break;
            case 5:
                break;
            default:
              break;
        }
    }while(n!=5);
}