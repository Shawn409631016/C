#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100

typedef struct{
    int coef;
    int expon;
}polynomial;

polynomial terms[MAX_TERMS];
int avail;

void inputPoly(int start, int finish);
void printPoly(int start, int finish);
void polyAdd(int startA, int finishA, int startB, int finishB, int* startC, int* finishC);

int main(void){
    int startA,finishA;
    int startB,finishB;
    int numA,numB;
    int startC,finishC;

    printf("Enter the length of polynomial A:\n");
    scanf("%d",&numA);
    printf("Enter the length of polynomial B:\n");
    scanf("%d",&numB);

    startA=0;
    finishA=numA-1;
    startB=numA;
    finishB=startB+numB-1;
    avail=finishB+1;

    printf("輸入多項式A的值:\n");
    inputPoly(startA,finishA);
    printf("輸入多項式B的值:\n");
    inputPoly(startB,finishB);

    printf("PolyA:");
    printPoly(startA,finishA);
    printf("\n");
    printf("PolyB:");
    printPoly(startB,finishB);
    printf("\n");
    printf("===============================\n");

    polyAdd(startA,finishA,startB,finishB,&startC,&finishC);
    printf("PolyC:");
    printPoly(startC,finishC);

    return 0;
}


void inputPoly(int start, int finish){
    int termCoef;
    int termExpon;
    for(int i=start; i<=finish; i++){
        printf("Enter the coefficient and exponent:");
        scanf("%d %d",&termCoef,&termExpon);
        terms[i].coef=termCoef;
        terms[i].expon=termExpon;
    }
}

void printPoly(int start, int finish){
    int i;
    for(i=start; i<finish; i++){
        printf("%dX^%d+",terms[i].coef,terms[i].expon);
    }
    printf("%dX^%d",terms[i].coef,terms[i].expon);
}

int compare(int a, int b){
    if(a>b){
        return 1;
    }else if(a==b){
        return 0;
    }else{
        return -1;
    }
}
void attach(int coefficient,int exponent){
    terms[avail].coef=coefficient;
    terms[avail].expon=exponent;
    avail++;
}
void polyAdd(int startA, int finishA,int startB,int finishB,int* startC,int* finishC){
    *startC=avail;
    while(startA<=finishA && startB<=finishB){
        switch ( compare(terms[startA].expon, terms[startB].expon) ) {
            case 1:
                attach(terms[startA].coef, terms[startA].expon);
                startA++;
                break;
            case 0:
                attach(terms[startA].coef + terms[startB].coef, terms[startA].expon);
                startA++;
                startB++;
                break;
            case -1:
                attach(terms[startB].coef, terms[startB].expon);
                startB++;
        }
    }
    for(; startA<=finishA; startA++){
        attach(terms[startA].coef,terms[startA].expon);
    }
    for(; startB<=finishB; startB++){
        attach(terms[startB].coef,terms[startB].expon);
    }
    *finishC=avail-1;
}
