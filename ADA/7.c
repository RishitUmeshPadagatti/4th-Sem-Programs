// Discrete Knapsack and Continous Knapsack using Greedy

#include <stdio.h>
#define MAX 100

typedef struct {
    int value;
    int weight;
    float ratio;
} Item;

void swap(Item *a, Item *b){
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void displayItems(Item items[], int n){
    printf("\nVALUE\tWEIGHT\tRATIO");
    for(int i=0; i<n; i++){
        printf("\n%d\t%d\t%.3f", items[i].value, items[i].weight, items[i].ratio);
    }
    printf("\n");
}

void sortByRatio(Item items[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (items[j].ratio < items[j+1].ratio){
                swap(&items[j], &items[j+1]);
            }
        }
    }
}

int discreteKnapsack(Item items[], int n, int W){
    int totalValue = 0;

    for (int i=0; i<n && W>0; i++){
        if (items[i].weight <= W){
            W -= items[i].weight;
            totalValue += items[i].value;
        }
    }

    return totalValue;
}

float fractionalKnapsack(Item items[], int n, int W){
    float totalValue = 0;

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

    printf("Enter the number of the items: ");
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

    int discreteKnapsackMax = discreteKnapsack(items, n, W);
    float fractionalKnapsackMax = fractionalKnapsack(items, n, W);

    printf("Discrete Knapsack (Greedy Approx): %d\n", discreteKnapsackMax);
    printf("Fractional Knapsack (Greedy Optimal): %.3f\n", fractionalKnapsackMax);

    return 0;
}