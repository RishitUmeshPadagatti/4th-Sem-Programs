// Design and implement C program to find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal's algorithm

#include <stdio.h>

int main(){
    int cost[20][20], parent[20], min_cost = 0;
    int u, v, a, b;
    int ne = 1, n;

    printf("Number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix: \n");
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i++){
        parent[i] = 0;
    }

    while (ne < n){
        int min = 999;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (cost[i][j] < min && i!=j){
                    min = cost[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }

        while (parent[u])
            u = parent[u];

        while (parent[v])
            v = parent[v];

        if (u != v){
            printf("Edge %d (%d -> %d) = %d\n", ne++, a, b, min);
            min_cost += min;
            parent[v] = u;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum Cost: %d\n", min_cost);

    return 0;
}