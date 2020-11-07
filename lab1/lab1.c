#include<stdio.h>
#include<stdlib.h>
int N;
int n = 1;
int a[500000];
int MAX;//元素取值范围
int factorial(int K)
{
    int j = 1;
    for(int i = 1; i <= K; i++)
        j = j * 2;
    return j;
}

int rand_input()
{
    FILE *fp;
    fp = freopen("input.txt","w+",stdout);
    for(int i = 0; i < n; i++)
        a[i] = rand();
    for(int i = 0; i < n; i++)
        printf("%d\n",a[i]);
    fclose(fp);
}

int main()
{
    printf("输入N: ");
    printf("%d",RAND_MAX);
    scanf("%d",&N);
    MAX = factorial(31);
    n = factorial(N);//get the 'n'
    printf("%d\n",n);
    rand_input();//produce the input
}