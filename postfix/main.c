#include <stdio.h>
#include <stdlib.h>

typedef enum{ lparen, rparen, plus, minus, times, divide, mod, eos, operand }precedence;
int in_stack_p[] = {0, 3, 1, 1, 2, 2, 2, 0};
int incoming_p[] = {4, 3, 1, 1, 2, 2, 2, 0};
char expr[20] = "a+b*c ";
int top;
precedence operator_stack[20];
precedence getToken(char* symbol, int* n);
void printToken(precedence symbol);
void postfix(void);

int main(void){
    printf("%s\n",expr);
    postfix();

    return 0;
}

precedence getToken(char* symbol, int* n){
    *symbol=expr[(*n)++];
    switch(*symbol){
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '*' : return times;
        case '/' : return divide;
        case '%' : return mod;
        case ' ' : return eos;
        default  : return operand;
    }
}
void push(precedence item){
    operator_stack[++top]=item;
}
precedence pop(){
    return operator_stack[top--];
}
void printToken(precedence symbol){
    switch(symbol){
        case lparen :printf("(");
            break;
        case rparen :printf(")");
            break;
        case plus   : printf("+");
            break;
        case minus  : printf("-");
            break;
        case times  : printf("*");
            break;
        case divide : printf("/");
            break;
        case mod    : printf("%");
            break;
        case eos : printf(" ");
    }
}
void postfix(void){
    char symbol;
    int n = 0;
    int top = 0;
    precedence token;
    operator_stack[0]=eos;

    for( token=getToken(&symbol,&n); token!=eos; token=getToken(&symbol,&n) ){
        if(token == operand){
            printf("%c",symbol);
        }else if(token == rparen){
            while(operator_stack[top] != lparen){
                printToken(pop());
            }
            pop();
        }
        else{
            while( in_stack_p[operator_stack[top]] >= incoming_p[token] ){
                printToken(pop());
            }
            push(token);
        }
    }
    while( (token=pop()) != eos ){
        printToken(token);
    }
    printf("\n");
}
