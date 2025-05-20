#include <stdio.h>
void subset(int, int, int);
int x[10], w[10], d, count = 0;
void main()
{
    int i, n, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements in ascending order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("\nEnter the required sum: ");
    scanf("%d", &d);
    for (i = 0; i < n; i++)
        sum += w[i];
    if (sum < d)
    {
        printf("No solution\n");
        return;
    }
    subset(0, 0, sum);
    if (count == 0)
    {
        printf("No solution\n");
    }
}
void subset(int cs, int k, int r)
{
    int i;
    x[k] = 1; // include w[k] in subset
    // If including w[k] gives the required sum
    if (cs + w[k] == d)
    {
        printf("\nSubset %d:\n", ++count);
        for (i = 0; i <= k; i++)
        {
            if (x[i] == 1)
                printf("%d\t", w[i]);
        }
        printf("\n");
    }
    else if (cs + w[k] + w[k + 1] <= d)
    {
        subset(cs + w[k], k + 1, r - w[k]);
    }
    // Explore excluding w[k] if possible
    if (cs + r - w[k] >= d && cs + w[k] <= d)
    {
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);
    }
}