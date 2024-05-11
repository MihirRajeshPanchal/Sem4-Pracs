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

int LOOK(int n, int p, int m[], int ans[], int u)
{
    int total = 0;
    int a, x;
    for (int i = 0; i < n; i++)
    {
        if (p < m[i])
        {
            a = x = i;
            break;
        }
    }
    if (u == 0)
    {
        a--;
    }

    for (int i = 0; i < n; i++)
    {
        if (u == 1)
        {
            if (a < n && a >= x)
            {
                ans[i] = m[a];
                a++;
                if (a == n)
                {
                    a = a - x;
                }
            }
            else
            {
                ans[i] = m[a];
                a--;
            }
        }
        else
        {
            if (a >= 0 && a < x)
            {
                ans[i] = m[a];
                a--;
                if (a == -1)
                {
                    a = x;
                }
            }
            else
            {
                ans[i] = m[a];
                a++;
            }
        }
    }

    if (u == 1)
    {
        total = absolute(m[n - 1], p) + absolute(m[n - 1], m[0]);
    }
    else
    {
        total = absolute(m[0], p) + absolute(m[0], m[n - 1]);
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
    int u = 1;
    total = LOOK(n, p, m, ans, u);
    print(n, p, ans, total);
}