// Warshall's Algorithm for transitive closure

#include <stdio.h>
#define MAX 100

void warshall(int graph[MAX][MAX], int n){
    for(int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

void printMatrix(int graph[MAX][MAX], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int graph[MAX][MAX], n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix\n");
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("\nThe adjancency matrix is\n");
    printMatrix(graph, n);

    warshall(graph, n);

    printf("\nThe transitive closure matrix is\n");
    printMatrix(graph, n);

    return 0;
}