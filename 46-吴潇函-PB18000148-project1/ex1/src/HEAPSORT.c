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
void time_print(double t[6])
{
    FILE *fp;
    fp = fopen("../output/HEAPSORT/time.txt", "w");
    for (int i = 0; i < 6; i++)
        fprintf(fp, "%lf ms\n", t[i]);
    fclose(fp);
}
void output_HEAPSORT()
{
    FILE *fp;
    switch (N)
    {
    case 3:
        fp = fopen("../output//HEAPSORT_3.txt", "w");
        break;
    case 6:
        fp = fopen("../output/HEAPSORT/HEAPSORT_6.txt", "w");
        break;
    case 9:
        fp = fopen("../output/HEAPSORT/HEAPSORT_9.txt", "w");
        break;
    case 12:
        fp = fopen("../output/HEAPSORT/HEAPSORT_12.txt", "w");
        break;
    case 15:
        fp = fopen("../output/HEAPSORT/HEAPSORT_15.txt", "w");
        break;
    case 18:
        fp = fopen("../output/HEAPSORT/HEAPSORT_18.txt", "w");
        break;
    }
    for (int i = 1; i <= n; i++)
        fprintf(fp, "%d\n", a[i]);
    fclose(fp);
}

/*--------------------------HEAPSORT-------------------------*/
int parent(int i)
{
    return i / 2;
}
int left(int i)
{
    return i * 2;
}
int right(int i)
{
    return (2 * i + 1);
}
void MAX_HEAPIFY(int size, int i)
{
    int largest, temp;
    int l = left(i);
    int r = right(i);
    if ((l <= size) && (a[l] > a[i]))
        largest = l;
    else
        largest = i;
    if ((r <= size) && (a[r] > a[largest]))
        largest = r;
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        MAX_HEAPIFY(size, largest);
    }
}
void BUILD_MAX_HEAP(int size)
{
    for (int i = n / 2; i >= 1; i--)
        MAX_HEAPIFY(size, i);
}
void HEAPSORT()
{
    int temp;
    int size = n;
    BUILD_MAX_HEAP(size);
    for (int i = n; i >= 2; i--)
    {
        temp = a[1]; //exchange a[i] with a[1]
        a[1] = a[i];
        a[i] = temp;
        size--;
        MAX_HEAPIFY(size, 1);
    }
}

int main()
{
    clock_t start, finish;
    double Total[6];
    for (N = 3; N <= 18; N += 3)
    {
        n = factorial(N); //get the 'n'
        get_input();      //produce the input
        start = clock();
        HEAPSORT();
        finish = clock();
        Total[N / 3 - 1] = (double)(finish - start) * 1000 / CLOCKS_PER_SEC;
        output_HEAPSORT();
    }
    time_print(Total);
}