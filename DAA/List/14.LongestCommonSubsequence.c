#include <stdio.h>
#include <string.h>
void longest_common_subsequence_algorithm();
void print_sequence(int a, int b);
int a, b, c, d;
int temp[30][30];
char first_sequence[30], second_sequence[30], longest_sequence[30][30];
int main()
{
    printf("\nEnter the First String : ");
    scanf("%s", first_sequence);
    printf("\nEnter the Second String : ");
    scanf("%s", second_sequence);
    printf("\nLongest Common Subsequence : ");
    longest_common_subsequence_algorithm();
    print_sequence(c, d);
    printf("\n");
    return 0;
}
void longest_common_subsequence_algorithm()
{
    c = strlen(first_sequence);
    d = strlen(second_sequence);
    for (a = 0; a <= c; a++)
    {
        temp[a][0] = 0;
    }
    for (a = 0; a <= d; a++)
    {
        temp[0][a] = 0;
    }
    for (a = 1; a <= c; a++)
    {
        for (b = 1; b <= d; b++)
        {
            if (first_sequence[a - 1] == second_sequence[b - 1])
            {
                temp[a][b] = temp[a - 1][b - 1] + 1;
                longest_sequence[a][b] = 'c';
            }
            else if (temp[a - 1][b] >= temp[a][b - 1])
            {
                temp[a][b] = temp[a - 1][b];
                longest_sequence[a][b] = 'u';
            }
            else
            {
                temp[a][b] = temp[a][b - 1];
                longest_sequence[a][b] = 'l';
            }
        }
    }
}
void print_sequence(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return;
    }
    if (longest_sequence[a][b] == 'c')
    {
        print_sequence(a - 1, b - 1);
        printf("%c", first_sequence[a - 1]);
    }
    else if (longest_sequence[a][b] == 'u')
    {
        print_sequence(a - 1, b);
    }
    else
    {
        print_sequence(a, b - 1);
    }
}