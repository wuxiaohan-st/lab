#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int N;
int n;
int a[500000];
int factorial(int k) //caculate n;
{
    int j = 1;
    int i;
    for (i = 1; i <= k; i++)
        j = j * 2;
    return j;
}
/*--------------------------input_part-------------------------*/
void get_input()
{
    FILE *fp;
    switch (N)
    {
    case 3:
        fp = fopen("../input/input_3.txt", "r");
        break;
    case 6:
        fp = fopen("../input/input_6.txt", "r");
        break;
    case 9:
        fp = fopen("../input/input_9.txt", "r");
        break;
    case 12:
        fp = fopen("../input/input_12.txt", "r");
        break;
    case 15:
        fp = fopen("../input/input_15.txt", "r");
        break;
    case 18:
        fp = fopen("../input/input_18.txt", "r");
        break;
    }
    for (int i = 1; i <= n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
}
/*--------------------------output_part-------------------------*/

void output_QUICKSORT_SORT()
{
    FILE *fp;
    switch (N)
    {
    case 3:
        fp = fopen("../output/QUICKSORT/QUICKSORT_3.txt", "w");
        break;
    case 6:
        fp = fopen("../output/QUICKSORT/QUICKSORT_6.txt", "w");
        break;
    case 9:
        fp = fopen("../output/QUICKSORT/QUICKSORT_9.txt", "w");
        break;
    case 12:
        fp = fopen("../output/QUICKSORT/QUICKSORT_12.txt", "w");
        break;
    case 15:
        fp = fopen("../output/QUICKSORT/QUICKSORT_15.txt", "w");
        break;
    case 18:
        fp = fopen("../output/QUICKSORT/QUICKSORT_18.txt", "w");
        break;
    }
    for (int i = 1; i <= n; i++)
        fprintf(fp, "%d\n", a[i]);
    fclose(fp);
}

void time_print(double t[6])
{
    FILE *fp;
    fp = fopen("../output/QUICKSORT/time.txt", "w");
    for(int i = 0;i<6;i++)
        fprintf(fp,"%lf s\n",t[i]);
    fclose(fp);
}
/*--------------------------QUICKSORT-------------------------*/
int PAETITION(int p, int r)
{
    int temp;
    int x = a[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (a[j] < x)
        {
            i++;
            temp = a[i]; //exchange a[i] with a[j]
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return (i + 1);
}
void QUICKSORT(int p, int r)
{
    int q;
    if (p < r)
    {
        q = PAETITION(p, r);
        QUICKSORT(p, q - 1);
        QUICKSORT(q + 1, r);
    }
}

int main()
{
    int start, finish;
    double Total[6];
    for (N = 3; N <= 18; N += 3)
    {
        n = factorial(N); //get the 'n'
        get_input();      //produce the input
        start = clock();
        QUICKSORT(1, n);
        finish = clock();
        Total[N / 3 - 1] = (double)(finish - start) / CLOCKS_PER_SEC;
        output_QUICKSORT_SORT();
    }
    time_print(Total);
}
