#include<stdio.h>
int main()
{
    char ans1,ans2,user[20],user_name1[20],user_name2[20],user_name3[20];
    int i=0,pass,pass_1,pass_2,pass_3,pass_4,k=0,l=0,m,n=1;
    FILE *fp2;
    char userarray[100][20];

    FILE *fp5=fopen("LoginDATA202.txt","r");


    printf("You are a new student or not\(y/n)\: ");
    scanf(" %c",&ans1);

    if(ans1=='Y' || ans1=='y')
    {
        gets(stdin);
        while(fscanf(fp5,"%s %d",user,&pass)!=EOF && n!=0)
        {
            strcpy(userarray[i],user);
            i++;

        }



        while(l==0)
        {
            printf("\nEnter a user name: \n (Example: Mahir4290)");
            gets(user_name1);
            for(int j=0; j<=i; j++)
            {
                m = strcmp(user_name1,userarray[j]);
                if(m==0)
                {
                    n=0;
                }
            }

            if(n==0)
            {
                l=0;
                printf("\n********* Username Taken ************* ");

            }
            else
            {
                l=1;
            }
            n=1;

        }

        printf("\nEnter a PIN Code of 8 digits: \n(Example: 01020304)");
        scanf("%d",&pass_1);
        printf("\nConfirm PIN: (again enter previous pin) : ");
        scanf("%d",&pass_2);
        if(pass_1==pass_2)
        {
            fp2=fopen("LoginDATA202.txt","a");
            fprintf(fp2,"%s %d",user_name1,pass_1);


        }
        while(pass_1!=pass_2)
        {
            printf("\nPIN error: ");
            printf("\nEnter a PIN Code of 8 digits: \n(Example: 01020304)");
            scanf("%d",&pass_1);
            printf("\nConfirm PIN: (again enter previous pin) : ");
            scanf("%d",&pass_2);
            if(pass_1==pass_2)
            {
                fprintf(fp2,"%s %d\n",user_name1,pass_1);

            }
        }
        fclose(fp2);
        printf("\n now you want to login:(y/n) ");
        scanf(" %c",&ans2);
        gets(stdin);
        if(ans2=='y' || ans2=='Y')
        {
            printf("\nLogin for question bank: ");

            do
            {

                FILE *fp3=fopen("LoginDATA202.txt","r");
                printf("\nEnter username: ");
                gets(user_name2);
                printf("\nEnter PIN: ");
                scanf("%d",&pass_3);
                gets(stdin);
                while(fscanf(fp3,"%s %d",user_name3,&pass_4)!=EOF)
                {
                    m=strcmp(user_name2,user_name3);
                    if(m==0)
                    {
                        break;
                    }

                }
                if(m==0)
                {
                    if(pass_3==pass_4)
                    {
                        printf("\nLogin successful: ");
                        k=1;
                        return 1;

                    }
                    else
                    {
                        printf("\nPassword wrong. Enter again:");

                    }

                }
                else
                    printf("\nlogin again, wrong input: ");

//               if(m!=0)
//                continue;





            }
            while(k==0);


        }

    }


    else
    {
        do
        {

            FILE *fp3=fopen("LoginDATA202.txt","r");

            printf("\nEnter username: ");
            gets(stdin);
            gets(user_name2);
            printf("\nEnter PIN: ");

            scanf("%d",&pass_3);

            while(fscanf(fp3,"%s %d",user_name3,&pass_4)!=EOF)
            {
                m=strcmp(user_name2,user_name3);
                if(m==0)
                {
                    break;
                }

            }
            if(m==0)
            {
                if(pass_3==pass_4)
                {
                    printf("\nLogin successful: ");
                    k=1;

                    return 1;

                }
                else
                {
                    printf("\nPassword wrong. Enter again:");

                }

            }
            else
                printf("\nlogin again, wrong input: ");

//               if(m!=0)
//                continue;



        }
        while(k==0);



    }

}
