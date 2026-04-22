#include <stdio.h>
#include <stdlib.h>


struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;

    double r1 = (double)item1->value / item1->weight;
    double r2 = (double)item2->value / item2->weight;

    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    else return 0;
}

double fractionalKnapsack(int W, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];


    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapsack(W, items, n);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
