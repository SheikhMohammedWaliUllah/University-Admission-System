#include<stdio.h>
int main()
{

    FILE *fp3,*fp4;
    int ans;
    char ques[100];
    fp3=fopen("D:\\Mahir NSU\\Code files\\Programming MCQ.txt","r");
    fp4=fopen("Answersheet1.txt","w");
    int count=1;
    while(fgets(ques,100,fp3)!=NULL){
            printf("%s",ques);
            scanf("%d",&ans);
            fprintf(fp4,"%d\n",ans);




            }
    }

