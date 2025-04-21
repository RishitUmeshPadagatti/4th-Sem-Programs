#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selection_sort(int a[], int num){
    int min_pos;

    for (int i=0; i<num-1; i++){
        min_pos = i;
        for (int j=i+1; j<num; j++){
            if (a[j] < a[min_pos]){
                min_pos = j; 
            }
        }

        int temp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = temp;
    }
}

int main(){
    clock_t start, end;
    srand(time(0)); // seed the random number generator

    int num;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    int a[num];
    for(int i=0; i<num; i++){
        a[i] = rand()%100;
    }

    printf("Array before sorting\n");
    for (int i=0; i<num; i++){
        printf("%d ", a[i]);
    }
    printf("\n\n");

    start = clock();
    selection_sort(a, num);
    end = clock();

    printf("Array after sorting\n");
    for (int i=0; i<num; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken for selection sort: %fs", time_taken);

    return 0;
}