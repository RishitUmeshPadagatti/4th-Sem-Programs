// Sum of Subset

#include <stdio.h>
int w[10], x[10], d, sum=0, n, count = 0;

// cs: current sum, k: current index, r: remaining sum of unused elements
void subset(int cs, int k, int r){
    x[k] = 1;

    if (cs+w[k] == d){
        printf("\nSolution %d\n", ++count);
        for (int i=0; i<n; i++){
            if (x[i] == 1){
                printf("%d\t", w[i]);
            }
        }
        printf("\n");
    }
    else if (cs+w[k]+w[k+1] <= d){
        subset(cs+w[k], k+1, r-w[k]);
    }

    // excluding w[i]
    if (cs+r-w[k]>=d && cs+w[k]<=d){
        x[k] = 0;
        subset(cs, k+1, r-w[k]);
    }
}

int main(){
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements\n");
    for(int i=0; i<n; i++){
        scanf("%d", &w[i]);
        sum += w[i];
    }

    printf("Enter the required sum: ");
    scanf("%d", &d);

    subset(0, 0, sum);
    if (count == 0){
        printf("No solution");
    }

    return 0;
}