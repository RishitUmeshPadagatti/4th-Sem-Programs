// Dijkstra Algorithm 

#include <stdio.h>

#define INF 9999

int n, cost[10][10], dist[10], visited[10], path[10], sv;

void dij(){
    int count = 1;
    for (int i=1; i<=n; i++){
        dist[i] = cost[sv][i];
        visited[i] = 0;
        if (cost[sv][i] == INF) path[i] = 0;
        else path[i] = sv;
    }
    visited[sv] = 1;

    while(count < n){
        int min=999, v;
        
        for (int w=1; w<=n; w++){
            if ((dist[w]<min) && (visited[w]==0)){
                min = dist[w];
                v = w;
            }
        }

        visited[v]=1;
        count++;

        for (int w=1; w<=n; w++){
            if (dist[w] > dist[v] + cost[v][w]){
                dist[w] = dist[v] + cost[v][w];
                path[w] = v;
            }   
        }
    }
}

void printPath(){
    for (int w=1; w<=n; w++){
        if (visited[w]==1 && w!=sv){
            printf("\nShortest distance between %d and %d is %d", sv, w, dist[w]);
            printf("\nPath: ");
            int t = path[w];
            printf("%d", w);
            while(t != sv){
                printf("<->%d", t);
                t = path[t];
            }
            printf("<->%d\n", sv);
        }
    }
}

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix\n");
    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nThe entered cost matrix is\n");
    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    printf("Enter the source vertex: ");
    scanf("%d", &sv);

    dij();
    printPath();

    return 0;
}