#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100

int stack[MAXSTACK];
int top=-1;

void push(int n);
int isEmpty();
int pop();
int main() {
    int data;
    printf("Enter 10 number int to stack:\n");
    for(int i=0; i<10; i++){
        scanf("%d",&data);
        push(data);
    }
    printf("===========================\n");
    while(isEmpty()!=1){
        printf("pop of the stack:%d\n",pop() );
    }
    pop();

    return 0;
}
int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}
void push(int n){
    if(top>=MAXSTACK){
        printf("The stack is full\n");
    }else{
        top++;
        stack[top]=n;
    }
}
int pop(){
    int data;
    if(isEmpty()==1){
        printf("The stack is empty\n");
    }else{
        data=stack[top];
        top--;
        return data;
    }
}