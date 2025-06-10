#include <stdio.h>
#define MAX 100

typedef struct {
    int value;
    int weight;
    float ratio;
} Item;

void displayItems(Item items[MAX], int n){
    printf("\nVALUE\tWEIGHT\tRATIO\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%.2f\n", items[i].value, items[i].weight, items[i].ratio);
    }
}

void swap(Item *a, Item *b){
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortByRatio(Item items[MAX], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if (items[j].ratio < items[j+1].ratio){
                swap(&items[j], &items[j+1]);
            }
        }
    }
}

int discreteKnapsack(Item items[MAX], int n, int W){
    int totalValue = 0;

    for (int i=0; i<n && W>0; i++){
        if (items[i].weight <= W){
            W -= items[i].weight;
            totalValue += items[i].value;
        }
    }

    return totalValue;
}

float fractionalKnapsack(Item items[MAX], int n, int W){
    float totalValue = 0.0;

    for (int i=0; i<n && W>0; i++){
        if (items[i].weight <= W){
            W -= items[i].weight;
            totalValue += items[i].value;
        } else{
            totalValue += ((float)W/items[i].weight)*items[i].value;
            W = 0;
        }
    }

    return totalValue;
}

int main(){
    int W, n;
    Item items[MAX];

    printf("Enter the capacity of the Knapsack: ");
    scanf("%d", &W);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the value and weight of the items\n");
    for(int i=0; i<n; i++){
        printf("Item %d: ", i+1);
        scanf("%d%d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value/items[i].weight;
    }

    displayItems(items, n);
    sortByRatio(items, n);
    displayItems(items, n);

    int discreteKnapsackMax = discreteKnapsack(items, n, W);  // 0/1 Knapsack
    float fractionalKnapsackMax = fractionalKnapsack(items, n, W);

    printf("Discrete Knapsack (Greedy Approx): %d\n", discreteKnapsackMax);
    printf("Fractional Knapsack (Greedy Optimal): %.2f\n", fractionalKnapsackMax);

    return 0;
}