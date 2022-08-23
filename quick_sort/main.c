#include <stdio.h>
#define MAX 5
void quickSort(int a[], int left, int right);

int main() {
    int n[MAX]={0};
    for(int i=0; i<MAX; i++){
        scanf("%d",&n[i]);
    }
    quickSort(n,0,MAX-1);

    for(int i=0; i<MAX; i++){
        printf(" %d",n[i]);
    }
    return 0;
}

void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int n[], int left, int right){
    int s=n[right];
    int i=left-1;
    for(int j=left; j<right; j++){
        if(n[j]<s){
            i++;
            swap(&n[i],&n[j]);
        }
    }
    i++;
    swap(&n[i],&n[right]);
    return i;
}
void quickSort(int n[], int left, int right){
    if(left<right){
        int s=partition(n,left,right);
        quickSort(n,left,s-1);
        quickSort(n,s+1,right);
    }
}

