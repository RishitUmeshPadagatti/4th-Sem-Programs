// Topological Sorting

#include <stdio.h>
#define MAX 100

int main(){
    int n, m;
    int adj[MAX][MAX] = {0}, indegree[MAX] = {0};
    int queue[MAX], front=0, rear=-1;

    printf("Input the number of vertices: ");
    scanf("%d", &n);

    printf("Input the number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (start end)\n");
    for(int i=0; i<m; i++){
        int u, v;
        scanf("%d%d", &u, &v);

        adj[u][v] = 1;
        indegree[v]++;
    }

    for (int i=0; i<n; i++){
        if (indegree[i] == 0){
            queue[++rear] = i;
        }
    }

    printf("Topological Sort: ");
    int count = 0;
    while(front <= rear){
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int j=0; j<n; j++){
            if (adj[node][j]){
                indegree[j]--;

                if (indegree[j] == 0){
                    queue[++rear] = j;
                }
            }
        }
    }

    if (count!=n){
        printf("\nCycle detected! Topological sort not possible");
        return 0;
    }

    return 0;
}