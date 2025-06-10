#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int n;

int isSafe(int x[], int k, int i){
    for (int j=1; j<k; j++){
        if (x[j] == i || abs(i - x[j]) == abs(k - j)){
            return 0;
        }
    }
    return 1;
}

void printSolution(int x[], int n, int count){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (x[i] == j)
                printf("Q ");
            else
                printf(". ");
            }
        printf("\n");
    }
    printf("\n");
}

void nQueens(int n){
    int x[MAX], count = 0, k = 1;
    for (int i=0; i<=n; i++) x[i] = 0;

    while (k > 0){
        x[k] = x[k] + 1;

        while (x[k]<=n && !isSafe(x, k, x[k]))
            x[k] = x[k] + 1;
        
        if (x[k] <= n){
            if (k == n){
                count++;
                printSolution(x, n, count);
            } else{
                k++;
                x[k] = 0;
            }
        } else{
            k--;
        }
    }

    if (count == 0) printf("No solution for %d queens", n);
    else printf("Total solutions: %d", count);
}

int main(){
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n<0 || n>MAX){
        printf("Invalid n\n");
    }

    nQueens(n);

    return 0;
}