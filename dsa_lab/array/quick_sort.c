#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct student{
    int id;
    char name[20];
    int marks;
};
int count=0 ;

void quick_sort(struct student *strudent,int lb, int ub);
void display(struct student *student, int n) ;
int partition(struct student *student, int lb, int ub);

void display(struct student *student, int n){
    printf("Markwise details :\n");
    printf("Id\t| Name\t| Marks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t| %s\t| %d\n",student[i].id, student[i].name, student[i].marks);
    }
}
int partition(struct student *student, int lb, int ub){
    int pivot= student[lb].marks ;
    int strt=lb;
    int end=ub;

    while(strt<end){
        while(student[strt].marks <= pivot){
            strt++ ;
        }
        while(student[end].marks > pivot){
            end-- ;
        }
        if(strt<end){
            struct student swap = student[strt];
            student[strt]=student[end];
            student[end]=swap ;
            count++;
        }
    }
    if(strt > end){
        struct student swap = student[lb];
        student[lb]=student[end];
        student[end]=swap;
        count++ ;
    }
    return end ;    
}

void quick_sort(struct student *student, int lb, int ub){
    int loc ;
    if(lb<ub){
        loc= partition(student, lb, ub);
        quick_sort(student, lb, loc-1);
        quick_sort(student, loc+1, ub);
    }

}


int main(){
    int n ;
    printf("Enter the total student : ");
    scanf(" %d",&n);
    struct student *student ;
    student=(struct student *)malloc(sizeof(struct student)*n);
    for(int i=0 ; i<n ; i++){
        printf("Enter the details of the %d :",i+1);
        scanf(" %d %s %d",&student[i].id,student[i].name,&student[i].marks);
    }
    printf("details of the student : ");
    display(student, n);
    quick_sort(student,0, n-1);
    printf("%d are the swapping done in the function :) \n",count);
    printf("after the quick_sort :\n");
    display(student, n);
    return 0 ;
}