#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SymTable_t{
    char pckey[100];
    void *pcvalue;
    struct SymTable_t *nextEntry;
}*head=NULL;

void SymTable_free(struct SymTable_t *head){
    if(head==NULL){
        exit(0);
    }
    struct SymTable_t *next=head;
    while(head!=NULL){
        next=head->nextEntry;
        free(head);
        head=next;
    }
}

int SymTable_getLength(struct SymTable_t *head){
    if (head==NULL){
        return 0;
    }
    int length;
    struct SymTable_t *next=head;
    while(next!=NULL){
        length++;
        next=next->nextEntry; 
    }
    return length;
}
int SymTable_contains(struct SymTable_t *head,char key[]){
    if(head==NULL){
        return 0;
    }
    struct SymTable_t *next=head;
    while(next!=NULL){
        printf("\n%s",next->pckey);
        if(strcmp(next->pckey,key)==0){
            return 1;
        }
    }
    return 0;
}
int SymTable_put(struct SymTable_t *head, char key[], int value){
    if(SymTable_contains(head,key)==1){
        return 0;
    }
    if(head==NULL){
        head=(struct SymTable_t*)malloc(sizeof(struct SymTable_t));
        strcpy(head->pckey,key);
        head->pcvalue=&value;
        head->nextEntry=NULL;
        printf("%s\n",head->pckey);
        printf("Head");
        return 1;
    }
    struct SymTable_t *new=(struct SymTable_t*)malloc(sizeof(struct SymTable_t));
    strcpy(new->pckey,key);
    new->pcvalue=&value;
    new->nextEntry=head;
    head=new;
    printf("New");
    return 1;
}

void main(){

    char key[]="a";
    int a=5;
    int put=SymTable_put(head,key,a);
    printf("%d",put);
    strcpy(key,"b");
    a=6;
    put=SymTable_put(head,key,a);
    printf("%d",put);
    strcpy(key,"c");
    a=7;
    put=SymTable_put(head,key,a);
    printf("%d",put);
    int con=SymTable_contains(&head,"a");
    printf("%d\n",con);
}