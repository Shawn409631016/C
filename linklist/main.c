#include <stdio.h>
#include <stdlib.h>

typedef struct list_node * list_pointer;
struct list_node{
    int data;
    list_pointer* next;
};
void insert(list_pointer * p, int num);
void delete_data(list_pointer * p, int num);
void printList(list_pointer *p);

int main() {
    list_pointer head=NULL;
    int a;
    scanf("%d",&a);
    while(a != 0){
        insert(&head,a);
        scanf("%d",&a);
    }
    printList(&head);
    scanf("%d",&a);
    delete_data(&head,a);
    printList(&head);

    return 0;
}
void insert(list_pointer * p, int num){
    list_pointer prev, newnode, current;
    newnode=(list_pointer)malloc(sizeof(struct list_node));
    newnode->data = num;
    newnode->next = NULL;
    if(*p == NULL){
        *p=newnode;
    }else{
        if(num < (*p)->data){
            newnode->next = *p;
            *p = newnode;
        }else{
            prev = *p;
            current = (*p)->next;
            while(current!=NULL && current->data < num){
                prev = current;
                current = current->next;
            }
            newnode->next = current;
            prev->next = newnode;
        }
    }
}
void delete_data(list_pointer * p, int num){
    list_pointer prev, current, oldhead;
    int found = 0;
    if( (*p)->data == num ){
        oldhead = *p;
        *p = (*p)->next;
        free(oldhead);
    }else{
        prev = *p;
        current = (*p)->next;
        while(current != NULL && found == 0){
            if(current->data != num){
                prev = current;
                current = current->next;
            }else{
                found = 1;
            }
        }
        if(found == 1){
            prev->next = current->next;
            free(current);
        }else{
            printf("%d is not in the list\n",num);
        }
    }
}
void printList(list_pointer *p){
    list_pointer current;
    current=*p;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}