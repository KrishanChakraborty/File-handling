#include<stdio.h>
/* Program to count and show the number of english words present in a given .txt file and the program will print the non
zero frequencies of the different word lengths of words present in the file.*/
int main()
{
    FILE *fp;
    char name[20],ch;
    int i=0,j=0,word[100],count=0,p=0;
    printf("Give the file name:");
    gets(name);
    fp=fopen(name,"r");
    if(fp==NULL)
    {
        printf("This file can't be opened, Try again.");
        return 2;
    }
    while((i<65 || i>90) && (i<97 || i>122))
    {
        ch=fgetc(fp);
        if(ch==EOF)
        {
            printf("The number of words is %d",j);
            fclose(fp);
            return 2;
        }
        i=ch;
    }
    for(p=0;p<100;p++)
    {
        word[p]=0;
    }
    while(1)
    {
        if(ch==EOF)
        {
            j=j+1;
            word[count]=word[count]+1;
            count=0;
            printf("The number of words is %d and ",j);
            printf("the non zero frequencies of different word lengths in the file are: \n");
            for(p=0;p<100;p++)
            {
                if(word[p]!=0)
                {
                    printf("%d \t %d",p,word[p]);
                    printf("\n");
                }
            }
            fclose(fp);
            return 2;
        }

        else if((i<65 || i>90) && (i<97 || i>122))
        {
            j=j+1;
            word[count]=word[count]+1;
            count=0;
            while((i<65 || i>90) && (i<97 || i>122))
            {
                ch=fgetc(fp);
                if(ch==EOF)
                {
                    printf("The number of words is %d and ",j);
                    printf("the non zero frequencies of different word lengths are: \n");
                    for(p=0;p<100;p++)
                    {
                        if(word[p]!=0)
                        {
                            printf("%d \t %d",p,word[p]);
                            printf("\n");
                        }
                    }
                    fclose(fp);
                    return 2;
                }
                i=ch;
            }
        }
        else
        {
            ch=fgetc(fp);
            i=ch;
            count=count+1;
        }
    }

    return 2;

}
