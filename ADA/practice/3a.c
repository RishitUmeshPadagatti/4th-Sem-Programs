// 3a: Flyod Warshall

#include <stdio.h>
#define INF 999
#define MAX 100

int n, dist[MAX][MAX], path[MAX][MAX];

void printPath(int src, int dest){
    int stk[MAX], top = -1;
    int curr = dest;

    while(curr != src){
        stk[++top] = curr;
        curr = path[src][curr];
    }
    printf("%d ", src);
    while(top >= 0){
        printf(" -> %d", stk[top--]);
    }
    printf("\n");
}

int main(){
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix\n");
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == INF) path[i][j] = -1;
            else path[i][j] = i;
        }
    }

    // Floyd's Algorithm
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    printf("\nShortest Distance Matrix\n");
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nShortest distance and paths between every pair of vertices");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i!=j){
                printf("\nFrom %d to %d", i, j);
                printf("\n Distance: %d", dist[i][j]);
                printf("\n Path: ");
                printPath(i, j);
            }
        }
    }

    return 0;
}