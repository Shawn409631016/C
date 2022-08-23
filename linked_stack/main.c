#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 5
typedef struct {
    int key;
}element;
typedef struct stack * stackPointer;
struct stack {
    int data;
    stackPointer link;
};
stackPointer top[MAX_STACKS];
stackPointer top[0] = NULL;
void push(int i, element item);
element pop(int i);
void printStack(stackPointer top);
int main() {
    element a;
    for(int i=0; i<MAX_STACKS; i++){
        scanf("%d",&a);
        push(i,a);
    }
    for(int i=0; i<MAX_STACKS; i++){
        a=pop(i);
        printStack(i);
    }

    return 0;
}
void push(int i, element item){
    stackPointer temp;
    malloc(temp, sizeof(*temp));
    temp->data = item;
    temp->link = top[i];
    top[i] = temp;
}
element pop(int i){
    stackPointer temp = top[i];
    element item;
    item = temp->data;
    top[i] = temp->link;
    free(temp);
    return item;
}
void printStack(stackPointer top){
    for(int i=0; i<MAX_STACKS; i++){
        printf("%d",top[i]);
    }
}