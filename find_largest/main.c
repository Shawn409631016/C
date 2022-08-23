#include <stdio.h>
#define SIZE 8
int find_largest(int list[],int* *p);
int main(void) {
    int list[]={1,2,3,4,5,6,7,8,};
    int* p;
    find_largest(list,&p);
    printf("%d",*p);
    return 0;
}
int find_largest(int list[],int* *p){
    int* largest;
    largest=list;
    for(int i=0; i<SIZE; i++){
        if(*(list+i) > *largest){
            largest=(list+i);
        }
    }
    *p=largest;
}
