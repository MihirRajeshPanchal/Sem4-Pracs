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

int FCFS(int n, int p, int m[], int ans[])
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            total += absolute(p, m[i]);
        }
        else
        {
            total += absolute(m[i - 1], m[i]);
        }
        ans[i] = m[i];
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

    total = FCFS(n, p, m, ans);
    print(n, p, ans, total);
    return 0;
}