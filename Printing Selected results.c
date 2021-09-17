#include<stdio.h>
int main()
{
    int roll,k=1,num;
    FILE *mz=fopen("Marksdepends.txt","r");
    printf("Serial\tRoll\n");
    while(fscanf(mz,"%d %d",&roll,&num)!=EOF && k<=10){
        printf("%4d \t%d\n",k,roll);
        k++;
    }
    fclose(mz);
    return 0;

}
