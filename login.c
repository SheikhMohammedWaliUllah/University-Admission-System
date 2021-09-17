
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
            char ans2,user_name2[20],user_name3[20];
            int pass_3,pass_4,k;


            printf("\n now you want to login:(y/n) ");
            scanf(" %c",&ans2);

            if(ans2=='y' || ans2=='Y'){
            printf("\nLogin for question bank: ");

            do{

            FILE *fp3=fopen("LoginDATA202.txt","r");
            gets(stdin);
            printf("\nEnter username: ");
            gets(user_name2);
            printf("\nEnter PIN: ");
            scanf("%d",&pass_3);

            while(fscanf(fp3,"%s %d",user_name3,&pass_4)!=EOF){
                int m= strcmp(user_name2,user_name3);
                if(m==0){
                    if(pass_3==pass_4){
                    printf("\nLogin successful: ");
                        k=1;
                    }
                else{
                        printf("\nPassword wrong. Enter again:");

                    }
                }
                else{
                    printf("\nWrong User name. Please try again: ");
                }
            }

            }while(k!=1);


    }
}
