#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node *next;
    struct node *prev;
}nodes;

nodes *head=NULL;
nodes *tail=NULL;

void push(int num)
{
nodes *np=(nodes*)malloc(sizeof(nodes));
    np->num=num;
    np->prev=tail;
    np->next=NULL;
    if(head==NULL){
        head=np;
        tail=np;
    }
    else{
        tail->next=np;
    }
    tail=np;
}

void front(int num){
    nodes *np=(nodes*)malloc(sizeof(nodes));
    np->num=num;
    np->next=head;
    np->prev=NULL;
    if(head==NULL){
        np->next=NULL;
        np->prev=NULL;
        head=np;
        tail=np;
    }
    else{
        head->prev=np;
    }
     head=np;
}

void reverse()
{
    nodes* bef = NULL;
    nodes* current = head;
    nodes* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node pointer
        current->next = bef;
 
        // Move pointers one position ahead.
        bef = current;
        current = next;
    }
    head = bef;
}

void printdel_front(){
    if(head==NULL){printf("Yah gabut...");}
    nodes *temp= head;
    printf("%d ", head->num);
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void printdel_back(){
    if(head==NULL){printf("Yah gabut...");}
    nodes*temp= tail;
    printf("%d ", tail->num);
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}
void print_all(){
    nodes *current=head;
    while(current !=NULL){
        printf("%d\n",current->num);
        current=current->next;
    }
}
void print_tail(){
    nodes *current=tail;
    while(current !=NULL){
        printf("%d\n", current->num);
        current=current->prev;
    }
}
int main() {
int test;
    scanf("%d ", &test);
    while(test--){
        char cmd [15];
        char gkpntg[11]="GakPenting";
        char kBlgkg[11]="KeBelakang";
        char tDpn[11]="TaruhDepan";
        char urgnt[7]="Urgent";
        char pTr[6]="Putar";
        scanf("%s ", cmd);
            if(strcmp(cmd,kBlgkg)==0){int temp;scanf("%d ", &temp);push(temp); }
            else if(strcmp(cmd,tDpn)==0){int temp;scanf("%d ", &temp);front(temp);}
            else if(strcmp(cmd,pTr)==0){reverse();}
            else if(strcmp(cmd,urgnt)==0){printdel_front();}
            else if(strcmp(cmd,gkpntg)==0){printdel_back();}
            else if(cmd[0]=='p'){print_all();}
    }
  push(20);push(22);push(6);
  //front(30);front(67);front(55);
    //reverse();
    //print_all();
    //print_tail();
    //printdel_back();
    printdel_front();
    //print_all();
    return 0;
}
