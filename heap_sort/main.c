#include <stdio.h>
#define MAX 6
void swap(int* a, int* b);
void adjust(int a[], int root, int n);
void heapSort(int a[], int n);
void changeIndex(int a[],int n);
int main() {
    int a[MAX];
    for(int i=0; i<MAX; i++){
        scanf("%d",&a[i]);
    }
    printf("Before Sort:");
    for(int i=0; i<MAX; i++){
        printf(" %d",a[i]);
    }
    printf("\n");
    printf("After Sort:");

    heapSort(a,MAX);
    for(int i=1; i<MAX+1; i++){
        printf(" %d",a[i]);
    }
    return 0;
}


void changeIndex(int a[], int n){
    for(int i=n; i>=0; i--){
        a[i]=a[i-1];
    }
}
void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void adjust(int a[], int root, int n){
    int child=root*2;
    int largest;

    if(child<=n && a[child]>a[root]){
        largest=child;
    }else{
        largest=root;
    }

    if(child+1<=n && a[child+1]>a[largest]){
        largest=child+1;
    }

    if(largest!=root){
        swap(&a[largest],&a[root]);
        adjust(a,largest,n);
    }

}

void heapSort(int a[], int n){
    changeIndex(a,n);
    for(int i=n/2; i>0; i--){
        adjust(a,i,n);
    }
    for(int i=n-1; i>0; i--){
        swap(&a[1], &a[i+1]);
        adjust(a,1,i);
    }
}