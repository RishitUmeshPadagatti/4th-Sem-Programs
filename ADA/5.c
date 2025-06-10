#include <stdio.h>
#define MAX 100
int main()
{
    int i, j;
    int n, m;                // n = number of vertices, m = number of edges
    int adj[MAX][MAX] = {0}; // Adjacency matrix
    int indegree[MAX] = {0}; // Array to store in-degrees
    int queue[MAX];
    int front = 0, rear = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (start end):\n");
    for (i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for (i = 0; i < n; i++){
        if (indegree[i] == 0){
            rear++;
            queue[rear] = i;
        }
    }

    printf("Topological Sort: ");
    int count = 0;
    while (front <= rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (j = 0; j < n; j++)
        {
            if (adj[node][j])
            {
                indegree[j]--;
                if (indegree[j] == 0)
                {
                    rear++;
                    queue[rear] = j;
                }
            }
        }
    }

    if (count != n)
    {
        printf("\nCycle detected! Topological sort not possible.\n");
        printf("count: %d", count);
        return 0;
    }
}