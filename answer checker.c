#include<stdio.h>
int main()
{
    char ansb1,ansb[50],ans1,ansr[50];
    int count1=0,count2=0,count3=0;
    FILE *in = fopen("Answer HM.txt","r");
    FILE *ans=fopen("answersing.txt","r");
    while(fscanf(in," %c",&ansb1)!=EOF){
        ansb[count1]=ansb1;
        count1++;
    }
    while(fscanf(ans," %c",&ans1)!=EOF){
        ansr[count2]=ans1;
        count2++;
    }
    for(int i=0;i<50;i++){
        if(ansb[i]==ansr[i]){
            count3++;
        }
    }
    printf("Correct answers %d",count3);
}
