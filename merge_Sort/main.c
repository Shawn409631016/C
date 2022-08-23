#include <stdio.h>
#define length 5

void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);
int main() {
    int a[length];
    for(int i=0; i<length; i++){
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,length-1);
    for(int i=0; i<length; i++){
        printf(" %d",a[i]);
    }
    return 0;
}
void mergeSort(int a[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[], int low, int mid, int high){
    int leftIndex=low;
    int rightIndex=mid+1;
    int combinedLength=high-low+1;
    int combined[combinedLength];
    int combinedIndex=0;

    while(leftIndex<=mid && rightIndex<=high){
        if(a[leftIndex]<=a[rightIndex]){
            combined[combinedIndex++]=a[leftIndex++];
        }else{
            combined[combinedIndex++]=a[rightIndex++];
        }
    }

    if(leftIndex>mid){
        while(rightIndex<=high){
            combined[combinedIndex++]=a[rightIndex++];
        }
    }else{
        while(leftIndex<=mid){
            combined[combinedIndex++]=a[leftIndex++];
        }
    }
    leftIndex=low;
    for(combinedIndex=0; combinedIndex<combinedLength; combinedIndex++){
        a[leftIndex]=combined[combinedIndex];
        leftIndex++;
    }
}