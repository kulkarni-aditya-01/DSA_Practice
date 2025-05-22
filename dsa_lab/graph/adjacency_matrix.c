#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n, m;
void create_adj(int **adj, int **arr);
void print_adj(int **adj);


void create_adj(int **adj, int **arr){
    for(int i=0 ; i<n; i++){
        for(int j=0 ; j< n; j++){
            adj[i][j] = 0 ;
        }
    }

    for(int i=0 ; i<m ; i++){
        int x = arr[i][0] ;
        int y = arr[i][1];

        adj[x][y] = 1; 
        adj[y][x] = 1;
    }
}

void print_adj(int **adj){
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Enter the total no. of the vertices : ");
    scanf(" %d",&n);

    printf("Enter the no. of the edges : ");
    scanf(" %d",&m);
    int **arr;
    int **adj ;
    arr=(int **)malloc(sizeof(int)*m);
    adj=(int **)malloc(sizeof(int)*n);
    for(int i=0 ; i< m; i++){
        arr[i]=(int *)malloc(sizeof(int)*2);
    }
    for(int i=0 ; i<m; i++){
        printf("Enter the edge %d : ",i+1);
        scanf(" %d %d",&arr[i][0],&arr[i][1]);
    }
    printf("USer enter the edges :\n");
    for(int i=0 ; i<m ;i++){
        printf("%d %d\n",arr[i][0],arr[i][1]);
    }
    for(int i=0 ; i< n; i++){
        adj[i]=(int *)malloc(sizeof(int)*n);
    }

    create_adj(adj,arr);
    print_adj(adj);

    return 0;
    
}