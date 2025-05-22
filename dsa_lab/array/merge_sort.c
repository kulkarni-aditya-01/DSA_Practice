#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge_sort(int *arr, int lb, int ub);
void merge_two_sorted_array(int *arr, int lb, int mid, int ub);

void merge_two_sorted_array(int *arr, int lb, int mid, int ub ){
    int i=lb;
    int j=mid+1 ;
    int num[50];
    int k=0;
    while(i <= mid && j<=ub){
        if(arr[i]<arr[j]){
            num[k]=arr[i];
            i++;
        }
        else {
            num[k] = arr[j];
            j++ ;
        }
        k++ ;
    }
    while(i<=mid){
        num[k]=arr[i] ;
        k++ ;
        i++ ;
    }
    while(j<=ub){
        num[k]=arr[j];
        j++;
        k++;
    }
    for(int i=0; i<k ;i++){
        arr[lb+i]=num[i];
    }
}

void merge_sort(int *arr, int lb, int ub){
    int mid ;
    if(lb<ub){
        mid=(lb+ub)/2;
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid+1, ub);
        merge_two_sorted_array(arr, lb, mid, ub);
    }
}

int main(){
    int *arr ;
    int n ;
    printf("Enter the size of thee array : ");
    scanf(" %d",&n);

    arr=(int *)malloc(sizeof(int )*n);
    for(int i=0 ; i<n ; i++){
        printf("Enter the element %d : ",i+1);
        scanf(" %d",&arr[i]);
    }

    for(int i=0 ; i<n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    merge_sort(arr, 0, n-1);
    for(int i=0 ; i<n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}