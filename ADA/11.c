// Merge Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 999999

void merge(int A[], int low, int mid, int high){
    int n1 = mid-low+1;
    int n2 = high-mid;

    int L[n1+1], R[n2+1];
    
    for(int k=0; k<n1; k++){
        L[k] = A[low+k];
    }
    for(int k=0; k<n2; k++){
        R[k] = A[mid+1+k];
    }
    L[n1] = INF;
    R[n2] = INF;

    int i=0, j=0;
    for (int k=low; k<=high; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int A[], int low, int high){
    if (low<high){
        int mid = (low+high)/2;
        merge_sort(A, low, mid);
        merge_sort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}


int main(){
    clock_t start, end;
    srand(time(0));

    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int A[n];

    printf("Array before sorting\n");
    for (int i = 0; i < n; i++){
        A[i] = rand()%100;
        printf("%d ", A[i]);
    }
    printf("\n\n");

    start = clock();
    merge_sort(A, 0, n-1);
    end = clock();

    printf("Array after sorting\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken for Merge Sort: %f", time_taken);
    
    return 0;
}