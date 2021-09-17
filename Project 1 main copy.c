#include<stdio.h>
#include<string.h>
void ansTaker();
int login();
int dataCollection();
int ansChecker();
void marksSorter();
int main()
{
    int roll,marksGot;
    FILE *fp=fopen("markslist.txt","a");   // opening markslist in append mode
    int a=login();    //calling loging function and taking return
    if(a==1)          // will continue if return from login is '1'
    {
        roll = dataCollection();   // calling dataCollection function and storing roll in variable from function return
        ansTaker();               // for taking answers of the questions
        marksGot=ansChecker();     // calling function for checking the answers and return the marks
        fprintf(fp,"%d %d\n",roll,marksGot);   // roll and marks stored in a FILE
        fclose(fp);                            //closing FILE pointer

        marksSorter();           //For sorting the marks in a FILE, its is for result publishing
        printf("\n*****************Thanks for participation******************");
        printf("\n************Result will be posted soon*************\n");
    }
    return 0;
}











int login()    // for sign up and login
{
    char ans1,ans2,user[20],user_name1[20],user_name2[20],user_name3[20];
    int i=0,pass,pass_1,pass_2,pass_3,pass_4,k=0,l=0,m,n=1;
    FILE *fp2;
    char userarray[100][20];

    FILE *fp5=fopen("LoginDATA202.txt","r");   //FILE opened in read mode


    printf("You are a new student or not\(y/n)\: ");
    scanf(" %c",&ans1);

    if(ans1=='Y' || ans1=='y')
    {
        gets(stdin);
        //storing all user name from file in string array for unique username
        while(fscanf(fp5,"%s %d",user,&pass)!=EOF && n!=0)
        {
            strcpy(userarray[i],user);   //storing user names in array
            i++;

        }



        while(l==0)    //if the user name is not unique loop will continue, if not terminated
        {
            printf("\nEnter a user name: \n (Example: Mahir4290)");
            gets(user_name1);    //taking user name from user
            for(int j=0; j<=i; j++)
            {
                m = strcmp(user_name1,userarray[j]); //checking user name if username is unique or not
                if(m==0)
                {
                    n=0;
                }
            }

            if(n==0)
            {
                l=0;
                printf("\n********* Username Taken ************* ");  //if user name is in the file before

            }
            else
            {
                l=1;   //user name is unique
            }
            n=1;

        }

        printf("\nEnter a PIN Code of 8 digits: \n(Example: 01020304)");
        scanf("%d",&pass_1);   //taking PIN for user
        printf("\nConfirm PIN: (again enter previous pin) : ");
        scanf("%d",&pass_2);   //confirming user
        if(pass_1==pass_2)     //SignUp
        {
            fp2=fopen("LoginDATA202.txt","a");    //FILE opened in append mode
            fprintf(fp2,"%s %d",user_name1,pass_1);   //printing user name and PIN in FILE


        }
        while(pass_1!=pass_2)    //IF PIN confirmation is wrong, the loop will continue till correct confirmation
        {
            printf("\nPIN error: ");
            printf("\nEnter a PIN Code of 8 digits: \n(Example: 01020304)");
            scanf("%d",&pass_1);    //again PIN user input
            printf("\nConfirm PIN: (again enter previous pin) : ");
            scanf("%d",&pass_2);    //again PIN confirmation
            if(pass_1==pass_2)
            {
                fprintf(fp2,"%s %d\n",user_name1,pass_1);   // printing in file

            }
        }
        fclose(fp2);
        printf("\n now you want to login:(y/n) ");   // login part
        scanf(" %c",&ans2);
        gets(stdin);
        if(ans2=='y' || ans2=='Y')
        {
            printf("\nLogin for question bank: ");

            do
            {

                FILE *fp3=fopen("LoginDATA202.txt","r");
                printf("\nEnter username: ");
                gets(user_name2);    //Entering Username for login
                printf("\nEnter PIN: ");
                scanf("%d",&pass_3);   //User input for PIN
                gets(stdin);
                while(fscanf(fp3,"%s %d",user_name3,&pass_4)!=EOF)
                {
                    m=strcmp(user_name2,user_name3);  //comparing user name with usernames of FILE
                    if(m==0)   // user name matched
                    {
                        break;   // after user name is matched
                    }

                }
                if(m==0)
                {
                    if(pass_3==pass_4)   //password check
                    {
                        printf("\nLogin successful: \n");  //if PIN is correct
                        k=1;    // loop terminating condition
                        return 1;

                    }
                    else
                    {
                        printf("\nPIN wrong. Enter again:");  //Wrong PIN input

                    }

                }
                else
                    printf("\nlogin again, wrong input: ");    //wrong username input







            }
            while(k==0);


        }

    }


    else     //login
    {
        do
        {

            FILE *fp3=fopen("LoginDATA202.txt","r");   //file opened in read mode

            printf("\nEnter username: ");     //entering user name
            gets(stdin);
            gets(user_name2);
            printf("\nEnter PIN: ");    //Entering PIN

            scanf("%d",&pass_3);

            while(fscanf(fp3,"%s %d",user_name3,&pass_4)!=EOF)   //scanning from file
            {
                m=strcmp(user_name2,user_name3);    //username comparing with file for correct user name
                if(m==0)      //user name matched
                {
                    break;    //terminating loop
                }

            }
            if(m==0)    //user name matched
            {
                if(pass_3==pass_4)   //if pin matched
                {
                    printf("\nLogin successful: ");
                    k=1;   //for terminating loop

                    return 1;   //to the caller

                }
                else
                {
                    printf("\nPassword wrong. Enter again:");   //PIN not matched

                }

            }
            else
                printf("\nlogin again, wrong input: ");   //Wrong user name





        }while(k==0);   //loop condition



    }

}
int dataCollection()
{
    FILE *fp1;
    char name[20],number[11];
    int ssc_roll,hsc_roll,ad_roll;
    fp1=fopen("Students.txt","a");   //opening file in append mode for storing student details in FILE

    printf("\nWrite your admission roll that sent in the phone: ");    //admission roll taking for exam
    scanf("%d",&ad_roll);
    fprintf(fp1,"%d",ad_roll);   // admission roll printing in a file
    gets(stdin);
    printf("Write your full name: ");   // students full name
    gets(name);
    fprintf(fp1," %s ",name); // printing name in file
    printf("\nEnter your Mobile No(11 digits): ");   //mobile no input from user
    gets(number);
    fputs(number,fp1);  // printing in file
    printf("\nEnter your SSC Roll No: ");  //user ssc roll no input
    scanf("%d",&ssc_roll);
    fprintf(fp1," %d",ssc_roll);   //printing in file
    printf("\nEnter your HSC Roll No: ");  //user hsc roll no input
    scanf("%d",&hsc_roll);
    fprintf(fp1," %d\n",hsc_roll);   //printing in a file


    fclose(fp1);
    return ad_roll;


}


int ansChecker()
{
    char ansb1,ansb[50],ans1,ansr[50];
    int count1=0,count2=0,count3=0;
    FILE *in = fopen("Answer HM.txt","r");     //opening ans bank in read mode
    FILE *ans=fopen("answersing.txt","r");      // opening students answer sheet in read mode
    while(fscanf(in," %c",&ansb1)!=EOF)
    {
        ansb[count1]=ansb1;    //storing answers from answer bank in an array
        count1++;             // storing in array, its index
    }
    while(fscanf(ans," %c",&ans1)!=EOF)
    {
        ansr[count2]=ans1;   // storing answers of students in array
        count2++;            // storing in array, its index
    }
    for(int i=0; i<50; i++)
    {
        if(ansb[i]==ansr[i])    //comparing given answers with answer bank
        {
            count3++;           // counting marks if ans matches
        }
    }
    return count3;
}
void marksSorter()
{
    int i=0,j,k=0,temp1,temp2,roll,marks,list[50],marks2[50];
    FILE *fp=fopen("markslist.txt","r");
    FILE *fp2=fopen("Marksdepends.txt","w");
    while(fscanf(fp,"%d %d",&roll,&marks)!=EOF)
    {
        list[i]=roll;          // storing rolls in array
        marks2[i]=marks;       // storing marks in array
        i++;
        k++;    // for counting the number of data(roll and mark) in file
    }
    for(i=0; i<k-1; i++)
    {
        for(j=i+1; j<k; j++)
        {
            if(marks2[i]<marks2[j])
            {  /* if greater marks are found that will be swapped with the smaller one along with the roll */
                temp1=marks2[j];
                marks2[j]=marks2[i];    //marks swapping using the condition (max >---> min)
                marks2[i]=temp1;
                temp2=list[j];
                list[j]=list[i];
                list[i]=temp2;
            }

        }
    }

    for(i=0; i<k; i++)
    {
        fprintf(fp2,"%d %d\n",list[i],marks2[i]);    //printimg sorted list in a file
    }
    fclose(fp);
    fclose(fp2);

}

void ansTaker()       //for taking answer and storing in a file
{

    char ques[300],ans;
    FILE *fp= fopen("question bank  hM.txt","r");   //Question bank in read mode
    FILE *otp= fopen("answersing.txt","w");          // for writing answers that given by user in FILE
    while(fgets(ques,300,fp)!=NULL)
    {
        printf("\n%s",ques);   //PRINTING EACH QUESTION
        printf("\nAns: ");
        scanf(" %c",&ans);    //taking answers
        fprintf(otp,"%c\n",ans);   //printing answers in a file
    }
    fclose(fp);
    fclose(otp);
}


