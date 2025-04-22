// Quick Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    while(1){
        // left: looks for smaller values than pivot
        // right: looks for larger values than pivot

        while (i<=high && arr[i]<=pivot){
            i++;
        }
        while (arr[j]>pivot){
            j--;
        }

        if (i < j){
            swap(&arr[i], &arr[j]);
        } else{
            swap(&arr[low], &arr[j]);
            return j;
        }
    }
}

void quick_sort(int arr[], int low, int high){
    if (low<high){
        int p = partition(arr, low, high);
        quick_sort(arr, low, p-1);
        quick_sort(arr, p+1, high);
    }
}

int main() {
    srand(time(0));
    
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    clock_t start = clock();
    quick_sort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for Quick Sort: %f seconds\n", time_taken);

    return 0;
}