// Design and implement C program to find Minimum Cost Spanning Tree of a given connected undirected graph using Prim's algorithm

#include <stdio.h>

int main(){
    int n, count=0;
    int cost[20][20], visited[20];
    int u, v, a, b;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix\n");
    for(int i = 0; i<n; i++){
        visited[i] = 0;
        for (int j = 0; j<n; j++){
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1;
    int min_cost = 0;

    while(count < n-1){
        int min = 999;

        for (int i = 0; i<n; i++){
            if (visited[i]){
                for (int j = 0; j<n; j++){
                    if (i!=j && !visited[j] && cost[i][j]<min){
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        printf("Edge %d (%d -> %d) = %d\n", count, u, v, min);
        min_cost += min;
        count++;
    }

    printf("Total cost of MST = %d", min_cost);

    return 1;
}