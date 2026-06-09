#include <stdio.h>

int main()
{
    int n, i, j;
    float capacity, profit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    float w[20], p[20], ratio[20];

    printf("Enter weights and profits:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%f%f", &w[i], &p[i]);
        ratio[i] = p[i] / w[i];
    }

    
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(ratio[i] < ratio[j])
            {
                float t;
                t = ratio[i]; ratio[i] = ratio[j]; ratio[j] = t;
                t = w[i]; w[i] = w[j]; w[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }

    printf("Enter Capacity: ");
    scanf("%f", &capacity);

    
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

    printf("Maximum Profit = %.2f", profit);

    return 0;
}
