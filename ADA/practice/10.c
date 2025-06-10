// Quick Sort
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    while (1){
        // left: look for smaller values than pivot
        // right: look for greater values than pivot

        while(i<=high && arr[i]<=pivot)
            i++;

        while(arr[j]>pivot)
            j--;
        
        if (i<j){
            swap(&arr[i], &arr[j]);
        } else{
            swap(&arr[low], &arr[j]);
            return j;
        }
    }


}

void quick_sort(int arr[], int low, int high){
    if (low < high){
        int p = partition(arr, low, high);
        quick_sort(arr, low, p-1);
        quick_sort(arr, p+1, high);
    }
}

int main() {
    int n = 5;

    int arr[] = {29, 17, 42, 83, 50};

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    quick_sort(arr, 0, n-1);

    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}