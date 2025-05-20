// All-Pairs Shortest Paths problem using Floyd's algorithm

#include <stdio.h>

#define INF 999
#define MAX 100

int dist[MAX][MAX], path[MAX][MAX], V;

void printPath(int src, int dest){
    if (path[src][dest] == -1){
        printf("No path exists\n");
        return;
    }

    int stk[MAX], top = -1;

    int curr = dest;
    while(curr != src){
        stk[++top] = curr;
        curr = path[src][curr];
    }

    printf("%d", src);
    while(top>=0){
        printf(" -> %d", stk[top--]);
    }
}

int main(){
    printf("Enter the number of nodes: ");
    scanf("%d", &V);

    printf("\nEnter the adjacency matrix, input %d for infinity\n", INF);
    for (int i=0; i<V; i++){
        for (int j=0; j<V; j++){
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == INF)
                path[i][j] = -1;
            else
                path[i][j] = i;
        }
    }

    // Floyd's algorithm
    for (int k=0; k<V; k++){
        for (int i=0; i<V; i++){
            for (int j=0; j<V; j++){
                if (dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    printf("\nShortest Distance Matrix\n");
    for (int i=0; i<V; i++){
        for (int j=0; j<V; j++){
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nShortest distance and pathes between every pair of vertices\n");
    for (int i=0; i<V; i++){
        for (int j=0; j<V; j++){
            if (i!=j){
                printf("\n\nFrom %d to %d", i, j);
                if (dist[i][j] == INF){
                    printf("No path exists");
                }

                printf("\n Distance: %d", dist[i][j]);
                printf("\n Path: ");
                printPath(i, j);
            }
        }
    }

    return 0;
}