// Merge Sort
#include <stdio.h>
#define INF 999

void merge(int A[], int low, int mid, int high){
    int n1 = mid-low+1;
    int n2 = high-mid;
    int L[n1+1], R[n2+1];
    for (int k=0; k<n1; k++) L[k] = A[low + k];
    for (int k=0; k<n2; k++) R[k] = A[mid + 1 + k];
    L[n1] = INF, R[n2] = INF;
    
    int i=0, j=0;
    for (int k=low; k<=high; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else{
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int A[], int low, int high){
    if (low < high){
        int mid = (low+high)/2;
        merge_sort(A, low, mid);
        merge_sort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int main() {
    int n = 7;

    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    merge_sort(arr, 0, n-1);

    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}