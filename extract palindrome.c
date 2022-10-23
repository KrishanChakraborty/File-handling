#include<stdio.h>
#include<string.h>

int palindrome(char a[1000])
{
    int i,n,mid,c=1;
    n=strlen(a);
    mid=(n-1)/2;
    if(n==3)
    {
        if(a[0]==a[2])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(n<2)
    {
        return 1;
    }
    for(i=0;i<=mid;i++)
    {
        if(a[i]!=a[n-1-i])
        {
            c=0;
            return 0;
        }
    }
    if(c==1)
    {
        return 1;
    }
}
int main()
{
    FILE *fp,*temp;
    char take[20],y[30],word[100],ch;
    int i=0,count=0,j=0;
    printf("Give the file name :");
    gets(take);
    for(j=0;j<100;j++)
        word[j]=0;
    strcpy(y,"palindrome in ");
    strcat(y,take);
    fp=fopen(take,"r");
    temp=fopen(y,"w");
    if(fp==NULL)
    {
        printf("The file can't be opened. Try again.");
        fclose(temp);
        return 2;
    }

    while((i<65 || i>90) && (i<97 || i>122))
    {
        ch=fgetc(fp);
        if(ch==EOF)
        {
            printf("There is no word");
            fclose(fp);
            fclose(temp);
            return 2;
        }
        i=ch;
    }
    word[0]=ch;
    count=count+1;

    while(1)
    {
        if(ch==EOF)
        {
            if(palindrome(word)==1)
            {
                fprintf(temp,"%s ",word);
            }
            fclose(fp);
            fclose(temp);
            return 2;

        }
        else if((i<65 || i>90) && (i<97 || i>122))
        {
             if(palindrome(word)==1)
             {
                 fprintf(temp,"%s ",word);
             }
             for(j=0;j<100;j++)
                word[j]=0;
             count=0;
             while((i<65 || i>90) && (i<97 || i>122))
             {
                 ch=fgetc(fp);
                 if(ch==EOF)
                 {
                     fclose(fp);
                     fclose(temp);
                     return 2;
                 }
                 i=ch;
             }
             word[0]=ch;
             count=count+1;
        }
        else
        {
            ch=fgetc(fp);
            i=ch;
            if((i>=65 && i<=90) || (i>=97 && i<=122))
            {
                word[count]=ch;
                count=count+1;
            }
        }
    }
    return 2;


}
