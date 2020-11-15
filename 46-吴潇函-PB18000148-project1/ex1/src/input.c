//make the input dates
//store the dates into "input/input_3","input/input_6"
//,"input/input_9","input/input_12","input/input_15",
//"input/input_18"
#include<stdio.h>
#include<stdlib.h>
int n;
int factorial(int k)//计算2的k次方
{
    int j = 1;
    for(int i = 1; i <= k; i++)
        j = j * 2;
    return j;
}

void rand_input(int k)
{
    FILE *fp;
    switch(k)
    {
        case 3:fp = fopen("../input/input_3.txt","w+");break;
        case 6:fp = fopen("../input/input_6.txt","w+");break;
        case 9:fp = fopen("../input/input_9.txt","w+");break;
        case 12:fp = fopen("../input/input_12.txt","w+");break;
        case 15:fp = fopen("../input/input_15.txt","w+");break;
        case 18:fp = fopen("../input/input_18.txt","w+");break;
    } 
    for(int i = 1; i <= n; i++)
    {
        fprintf(fp,"%d\n",rand());
    } 
    fclose(fp);
}
void main()
{
    for(int i = 3; i <= 18; i += 3)
    {
        n = factorial(i);
        rand_input(i);
    }
    
}