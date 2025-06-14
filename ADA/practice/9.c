// Selection Sort

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selection_sort(int a[], int num){
    int min_pos;

    for (int i=0; i<num-1; i++){
        min_pos=i;
        for (int j=i+1; j<num; j++){
            if (a[j] < a[min_pos]){
                min_pos=j;
            }
        }

        int temp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = temp;
    }
}

void mainThing(int num){
    clock_t start, end;
    srand(time(0));

    int a[num];
    for(int i=0; i<num; i++){
        a[i] = rand()%100;
    }

    start = clock();
    selection_sort(a, num);
    end = clock();

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("%d\t%f\n", num, time_taken);
}

int main(){
    for (int i=1; i<=1000; i++){
        mainThing(i);
    }

    return 0;
}