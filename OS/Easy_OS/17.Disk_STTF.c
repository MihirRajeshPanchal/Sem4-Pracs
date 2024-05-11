#include <stdio.h>

int absolute(int x, int y)
{
    if (x >= y)
    {
        return x - y;
    }
    else
    {
        return y - x;
    }
}

int SSTF(int n, int p, int m[], int ans[])
{
    int total = 0;
    int current, v[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            current = p;
        }
        else
        {
            current = ans[i - 1];
        }
        int min = 199, j, x;
        for (j = 0; j < n; j++)
        {
            if (absolute(current, m[j]) <= min && v[j] == 0)
            {
                min = absolute(current, m[j]);
                x = j;
            }
        }
        v[x] = 1;
        total += min;
        ans[i] = m[x];
    }

    return total;
}

void print(int n, int p, int ans[], int total)
{
    printf("\nTrack movements are as follows : \n");
    printf("%d -> %d", p, ans[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" -> %d", ans[i]);
    }

    printf("\nTotal seek time is : %d\n", total);
}

int main()
{

    // int n, p;
    // printf("\nEnter the number of movements : ");
    // scanf("%d", &n);

    // int m[n];
    // printf("\nEnter %d movements (0 - 199) : ", n);
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &m[i]);
    // }

    // printf("\nEnter the current head location : ");
    // scanf("%d", &p);


    int n=5,p=65;
    int m[]={25,51,60,132,189};
    int total, ans[n];
    total = SSTF(n, p, m, ans);
    print(n, p, ans, total);
}