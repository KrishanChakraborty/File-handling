#include<stdio.h>
// Program to count and show the number of english words present in a given .txt file
int main()
{
    FILE *fp;
    char name[20],ch;
    int i=0,j=0;
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
    while(1)
    {
        if(ch==EOF)
        {
            j=j+1;
            printf("The number of words is %d",j);
            fclose(fp);
            return 2;
        }

        else if((i<65 || i>90) && (i<97 || i>122))
        {
            j=j+1;
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
        }
        else
        {
            ch=fgetc(fp);
            i=ch;
        }
    }

    return 2;

}
