#include <stdio.h>

void printPermutation(int p[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", p[i]);
    printf("\n");
}

int getMobile(int p[], int dir[], int n)
{
    int mobile = 0, mobilePos = -1;

    for(int i=0;i<n;i++)
    {
        if(dir[p[i]-1] == -1 && i!=0)
        {
            if(p[i] > p[i-1] && p[i] > mobile)
            {
                mobile = p[i];
                mobilePos = i;
            }
        }

        if(dir[p[i]-1] == 1 && i!=n-1)
        {
            if(p[i] > p[i+1] && p[i] > mobile)
            {
                mobile = p[i];
                mobilePos = i;
            }
        }
    }

    return mobilePos;
}

void johnsonTrotter(int n)
{
    int p[n], dir[n];

    for(int i=0;i<n;i++)
    {
        p[i] = i + 1;
        dir[i] = -1;
    }

    printPermutation(p,n);

    while(1)
    {
        int pos = getMobile(p,dir,n);

        if(pos == -1)
            break;

        int mobile = p[pos];

        if(dir[mobile-1] == -1)
        {
            int temp = p[pos];
            p[pos] = p[pos-1];
            p[pos-1] = temp;
            pos--;
        }
        else
        {
            int temp = p[pos];
            p[pos] = p[pos+1];
            p[pos+1] = temp;
            pos++;
        }

        for(int i=0;i<n;i++)
        {
            if(p[i] > mobile)
                dir[p[i]-1] *= -1;
        }

        printPermutation(p,n);
    }
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d",&n);

    johnsonTrotter(n);

    return 0;
}
