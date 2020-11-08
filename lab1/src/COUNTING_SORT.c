#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int N;
int n;
int a[500000];
int B[500000];
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
void output_COUNTING_SORT()
{
    FILE *fp;
    switch(N)
    {
        case 3:fp = fopen("../output/COUNTING_SORT/COUNTING_SORT_3.txt","w");break;
        case 6:fp = fopen("../output/COUNTING_SORT/COUNTING_SORT_6.txt","w");break;
        case 9:fp = fopen("../output/COUNTING_SORT/COUNTING_SORT_9.txt","w");break;
        case 12:fp = fopen("../output/COUNTING_SORT/COUNTING_SORT_12.txt","w");break;
        case 15:fp = fopen("../output/COUNTING_SORT/COUNTING_SORT_15.txt","w");break;
        case 18:fp = fopen("../output/COUNTING_SORT/COUNTING_SORT_18.txt","w");break;
    } 
    for(int i = 1; i <= n; i++)
        fprintf(fp,"%d\n",a[i]);
    fclose(fp);
}
void time_print(double t[6])
{
    FILE *fp;
    fp = fopen("../output/COUNTING_SORT/time.txt", "w");
    for(int i = 0;i<6;i++)
        fprintf(fp,"%lf ms\n",t[i]);
    fclose(fp);
}
/*--------------------------COUNTING_SORT-------------------------*/
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
     clock_t start,finish;
     double Total[6];
    for(N = 3;N<=18;N+=3)
    {
        n = factorial(N);//get the 'n'
        get_input();//produce the input
        start = clock();
        COUNTING_SORT();
        finish = clock();
        Total[N/3-1] = (double)(finish-start) *1000 / CLOCKS_PER_SEC;
        output_COUNTING_SORT();
    }
    time_print(Total);
}
