#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int n;
int a[500000];
int B[500000];
int L[500000];//for 归并排序
int R[500000];//for 归并排序
int factorial(int k)//计算2的k次方
{
    int j = 1;
    for(int i = 1; i <= k; i++)
        j = j * 2;
    return j;
}

void get_input(int k)
{
    FILE *fp;
    switch(k)
    {
        case 3:fp = fopen("input/input_3","r");break;
        case 6:fp = fopen("input/input_6","r");break;
        case 9:fp = fopen("input/input_9","r");break;
        case 12:fp = fopen("input/input_12","r");break;
        case 15:fp = fopen("input/input_15","r");break;
        case 18:fp = fopen("input/input_18","r");break;
    } 
    for(int i = 1; i <= n; i++)
    {
        fscanf(fp,"%d",&a[i]);
    } 
    fclose(fp);
}

void output()
{
    FILE *fp;
    fp = fopen("output/output.txt","w");
    for(int i = 1; i <= n; i++)
        fprintf(fp,"%d\n",a[i]);
    fclose(fp);
}

// /*--------------------------插入排序-------------------------*/
// void INSERTION_SORT()
// {
//     int key;
//     int i;
//     for(int j = 2; j <= n; j++)
//     {
//         key = a[j];
//         i = j - 1;
//         while((i > 0) && (a[i] > key))
//         {
//             a[i + 1] = a[i];
//             i--;
//         }
//         a[i+1] = key;   
//     }
// }



// /*--------------------------堆排序-------------------------*/
// int parent(int i)
// {
//     return i/2;
// }
// int left(int i)
// {
//     return i*2;
// }
// int right(int i)
// {
//     return (2*i+1);
// }
// void MAX_HEAPIFY(int size, int i)
// {
//     int largest,temp;
//     int l = left(i);
//     int r = right(i);
//     if((l <= size) && (a[l] > a[i]))
//         largest = l;
//     else
//         largest = i;
//     if((r <= size) && (a[r] > a[largest]))
//         largest = r;
//     if(largest != i)
//     {
//         temp = a[i];
//         a[i] = a[largest];
//         a[largest] = temp;
//         MAX_HEAPIFY(size,largest);
//     }
// }
// void BUILD_MAX_HEAP(int size)
// {
//     for(int i = n/2; i >= 1; i--)
//         MAX_HEAPIFY(size,i);
// }
// void HEAPSORT()
// {
//     int temp;
//     int size = n;
//     BUILD_MAX_HEAP(size);
//     for(int i = n; i >= 2; i--)
//     {
//         temp = a[1];//exchange a[i] with a[1]
//         a[1] = a[i];
//         a[i] = temp;
//         size--;
//         MAX_HEAPIFY(size,1);
//     }
// }

// /*--------------------------快速排序-------------------------*/
// int PAETITION(int p, int r)
// {
//     int temp;
//     int x = a[r];
//     int i = p - 1;
//     for(int j = p; j <= r - 1; j++)
//     {
//         if(a[j] < x)
//         {
//             i++;
//             temp = a[i];//exchange a[i] with a[j]
//             a[i] = a[j];
//             a[j] = temp;
//         }
//     }
//     temp = a[i+1];
//     a[i+1] = a[r];
//     a[r] = temp;
//     return (i + 1);
// }
// void QUICKSORT(int p, int r)
// {
//     int q;
//     if(p < r)
//     {
//         q = PAETITION(p,r);
//         QUICKSORT(p, q-1);
//         QUICKSORT(q+1, r);
//     }        
// }

// /*--------------------------归并排序-------------------------*/
// int cmp(int a, int b)//compare a and b
// {
//     if (a < 0)
//         return 1;
//     else if (b < 0)
//         return 0;
//     else
//         return (a > b ? 1 : 0);
// }
// void MERGE(int p, int q, int r)
// {
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     int i, j;
//     for (i = 1; i <= n1; i++)
//         L[i] = a[p + i - 1];
//     L[n1 + 1] = -1;
//     for (i = 1; i <= n2; i++)
//         R[i] = a[q + j];
//     R[n2 + 1] = -1;
//     i = 1;
//     j = 1;
//     for (int k = p; k <= r; k++)
//     {
//         if (cmp(R[j],L[i]))
//         {
//             a[k] = L[i];
//             i++;
//         }
//         else
//         {
//             a[k] = R[j];
//             j++;
//         }
//     }
// }
// void MERGE_SORT(int p, int r)
// {
//     int q;
//     if (p < r)
//     {
//         q = (p + r) / 2;
//         MERGE_SORT(p, q);
//         MERGE_SORT(q + 1, r);
//         MERGE(p, q, r);
//         printf("pqr:%d %d %d",p,q,r);
//     }
// }

/*--------------------------计数排序-------------------------*/
void COUNTING_SORT()
{
    int C[32768];
    memset(C, 0, sizeof(C));
    for (int i = 1; i <= n; i++)
        C[a[i]]++;
    for (int i = 1; i <= 32768; i++)
        C[i] = C[i] + C[i - 1];
    for (int i = n; i >= 1; i--)
    {
        B[C[a[i]]] = a[i];
        C[a[i]] = C[a[i]] - 1;
    }
    memcpy(a,B,sizeof(a));
    
}

int main()
{
    printf("inputN: ");
    scanf("%d",&N);
    n = factorial(N);//get the 'n'
    get_input(N);//produce the input
    //INSERTION_SORT();
    //HEAPSORT();
    //QUICKSORT(1,n);
    //*MERGE_SORT(1,n);
    //printf("merge");
    COUNTING_SORT();
    output();
}