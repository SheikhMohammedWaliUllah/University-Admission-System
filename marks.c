#include<stdio.h>
int main()
{
    int i=0,j,k=0,temp1,temp2,roll,marks,list[5],marks2[5];
    FILE *fp=fopen("markslist.txt","r");
    FILE *fp2=fopen("Marksdepends.txt","w");
    while(fscanf(fp,"%d %d",&roll,&marks)!=EOF){
        list[i]=roll;
        marks2[i]=marks;
        i++;
        k++;
    }
    for(i=0;i<k;i++){
            for(j=i+1;j<k-1;j++){
        if(marks2[i]<marks2[j]){
            temp1=marks2[j];
            marks2[j]=marks2[i];
            marks2[i]=temp1;
            temp2=list[j];
            list[j]=list[i];
            list[i]=temp2;}

        }
        }
    for(i=0;i<k;i++){
        fprintf(fp2,"%d %d\n",list[i],marks2[i]);
    }
    fclose(fp);
    fclose(fp2);
    return 0;

}
