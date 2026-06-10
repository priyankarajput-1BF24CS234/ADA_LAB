#include <stdio.h>

int main()
{
    int n, i, j;
    float capacity, profit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    float w[20], p[20], ratio[20];

    printf("Enter weight and profit of each item:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &w[i], &p[i]);
        ratio[i] = p[i] / w[i];
    }

    // Sort items by decreasing profit/weight ratio
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                float temp;

                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Fill knapsack
    for(i = 0; i < n; i++)
    {
        if(capacity >= w[i])
        {
            profit += p[i];
            capacity -= w[i];
        }
        else
        {
            profit += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", profit);

    return 0;
}
