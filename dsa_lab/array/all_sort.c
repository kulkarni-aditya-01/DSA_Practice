#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertion_sort(int *arr, int n);
void selection_sort(int *arr, int n);
void bubble_sort(int *arr, int n);
void display(int *arr, int n);


void display(int *arr, int n){
    for(int i=0 ; i<n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubble_sort(int *arr, int n){
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=0 ; j<i ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j+1]= arr[j];
                arr[j] = temp ;
            }
        }
    }
}
void selection_sort(int *arr, int n){
    int i , j ;
    for(i=0 ; i<n-1 ; i++){
        int min = i ;
        for(j=i+1; j< n ; j++){
            if(arr[j] < arr[min]){
                min = j ;
            }
        }
        int temp = arr[i] ; 
        arr[i] = arr[min] ;
        arr[min] = temp ;
    }
}
void insertion_sort(int *arr, int n){
    int i , j ;
    for(i=1 ;i<n ; i++){
        int temp = arr[i];
        j =i-1 ;
        while(j>=0 && arr[j] > temp){
            arr[j+1]=arr[j] ;
            j-- ;
        }
        arr[j+1]=temp;
    }
}

int main()
{
    int *arr;
    int n;
    printf("Enter the size of the array : ");
    scanf(" %d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element : ", i + 1);
        scanf(" %d", &arr[i]);
    }
    printf("USer enters the array : ");
    display(arr, n);
    insertion_sort(arr, n);
    printf("After the insrtion sort : ");
    display(arr,n) ;
    return 0;
}




