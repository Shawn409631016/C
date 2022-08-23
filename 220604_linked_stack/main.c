#include <stdio.h>
#include <stdlib.h>

typedef struct stack * stackPointer;
struct stack{
    int data;
    stackPointer link;
};
stackPointer top=NULL;
void push(stackPointer *i);
void printStack(stackPointer *i);
void pop(stackPointer *i);
int main() {
    stackPointer top=NULL;
    printf("Enter:\n");
    push(&top);
    printStack(&top);
    push(&top);
    printStack(&top);
    push(&top);
    printStack(&top);
    push(&top);
    printStack(&top);
    push(&top);
    printStack(&top);
    printf("\nAfter pop:\n");
    pop(&top);
    printStack(&top);
    pop(&top);
    printStack(&top);
    pop(&top);
    printStack(&top);
    pop(&top);
    printStack(&top);pop(&top);
    printStack(&top);
    return 0;
}
void push(stackPointer *i){
    stackPointer temp;
    int a;
    scanf("%d",&a);
    temp=(stackPointer) malloc(sizeof(struct stack));
    temp->data = a;
    temp->link = *i;
    *i=temp;
}
void printStack(stackPointer *i){
    stackPointer temp;
    temp=*i;
    printf("the data in the stack:\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void pop(stackPointer *i){
    stackPointer temp;
    temp=*i;
    if(temp==NULL){
        printf("The stack is empty");
    }else{
        *i=temp->link;
        free(temp);
    }
}