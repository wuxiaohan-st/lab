#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int N;
int n;
int a[500000];
int L[500000];//for MERGE_SORT
int R[500000];//for MERGE_SORT
int factorial(int k)//caculate n;
{
    int j = 1;
    int i;
    for(i = 1; i <= k; i++)
        j = j * 2;
    return j;
}
/*--------------------------input_part-------------------------*/
void get_input()
{
    FILE *fp;
    switch(N)
    {
        case 3:fp = fopen("../input/input_3.txt","r");break;
        case 6:fp = fopen("../input/input_6.txt","r");break;
        case 9:fp = fopen("../input/input_9.txt","r");break;
        case 12:fp = fopen("../input/input_12.txt","r");break;
        case 15:fp = fopen("../input/input_15.txt","r");break;
        case 18:fp = fopen("../input/input_18.txt","r");break;
    } 
    for(int i = 1; i <= n; i++)
    {
        fscanf(fp,"%d",&a[i]);
    } 
    fclose(fp);
}
/*--------------------------output_part-------------------------*/
void output_MERGE_SORT()
{
    FILE *fp;
    switch(N)
    {
        case 3:fp = fopen("../output/MERGE_SORT/MERGE_SORT_3.txt","w");break;
        case 6:fp = fopen("../output/MERGE_SORT/MERGE_SORT_6.txt","w");break;
        case 9:fp = fopen("../output/MERGE_SORT/MERGE_SORT_9.txt","w");break;
        case 12:fp = fopen("../output/MERGE_SORT/MERGE_SORT_12.txt","w");break;
        case 15:fp = fopen("../output/MERGE_SORT/MERGE_SORT_15.txt","w");break;
        case 18:fp = fopen("../output/MERGE_SORT/MERGE_SORT_18.txt","w");break;
    } 
    for(int i = 1; i <= n; i++)
        fprintf(fp,"%d\n",a[i]);
    fclose(fp);
}
void time_print(double t[6])
{
    FILE *fp;
    fp = fopen("../output/MERGE_SORT/time.txt", "w");
    for(int i = 0;i<6;i++)
        fprintf(fp,"%lf ms\n",t[i]);
    fclose(fp);
}

/*--------------------------MERGE_SORT-------------------------*/
int cmp(int a, int b)//compare a and b
{
    if (a < 0)
        return 1;
    else if (b < 0)
        return 0;
    else
        return (a > b ? 1 : 0);
}
void MERGE(int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j;
    for (i = 1; i <= n1; i++)
        L[i] = a[p + i - 1];
    L[n1 + 1] = -1;
    for (j = 1; j <= n2; j++)
        R[j] = a[q + j];
    R[n2 + 1] = -1;
    i = 1;
    j = 1;
    for (int k = p; k <= r; k++)
    {
        if (cmp(R[j],L[i]))
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}
void MERGE_SORT(int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        MERGE_SORT(p, q);
        MERGE_SORT(q + 1, r);
        MERGE(p, q, r);
        
    }
}


int main()
{
    clock_t start,finish;
     double Total[6];
     
     
    for(N = 3;N<=18;N+=3)
    {
        n = factorial(N);//get the 'n'
        get_input();//produce the input
        start = clock();
        MERGE_SORT(1,n);
        finish = clock(); 
        Total[N/3-1] = (double)(finish-start) * 1000 / CLOCKS_PER_SEC ;
        output_MERGE_SORT();
    }
    time_print(Total);
    
}
