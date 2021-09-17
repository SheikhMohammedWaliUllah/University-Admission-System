#include<stdio.h>
int main()
{

    char ques[300],ans;
    FILE *fp= fopen("question bank  hM.txt","r");
    FILE *otp= fopen("answersing.txt","w");
    while(fgets(ques,300,fp)!=NULL){
        printf("\n%s",ques);
        scanf(" %c",&ans);
        fprintf(otp,"%c\n",ans);
    }
    return 0;
}
