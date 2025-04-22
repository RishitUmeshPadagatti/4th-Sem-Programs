// Topological Sorting

#include <stdio.h>
#define MAX 100

void print1dArray(int arr[MAX], int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

void print2dArray(int arr[MAX][MAX], int n){
    for (int i=0; i<n; i++){
        print1dArray(arr[i], n);
        printf("\n");
    }
}

int main() {
    int n, m;

    printf("Enter the number of verticies: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX] = {0};
    int front=0, rear=-1;

    printf("Enter edges (start end)\n");
    for (int i=0; i<m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for (int i=0; i<n; i++){
        if (indegree[i] == 0){
            rear++;
            queue[rear] = indegree[i];
        }
    }

    printf("Topological Sort\n");
    int count = 0;

    while(front<=rear){
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i=0; i<n; i++){
            if (adj[node][i]){
                indegree[i]--;

                if (indegree[i] == 0){
                    rear++;
                    queue[front] = i;
                }
            }
        }
    }

    return 0;
}
