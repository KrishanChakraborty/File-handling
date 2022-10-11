#include<stdio.h>
//Program to show frequency of each character present in a given file
int main()
{
    FILE *fp;
    int i,r,b[128];
    char ch='u',name[20];
    printf("Give the file name :");
    gets(name);
    fp=fopen(name,"r");
    if(fp==NULL)
    {
        printf("This File can't be opened, Try again ");
        return 2;
    }
    for(i=0;i<128;i++)
    {
        b[i]=0;
    }
    while(ch!=EOF)
    {
        ch=fgetc(fp);
        r=ch;
        b[r]=b[r]+1;

    }
    printf("The frequency of each character present in the file is given below: \n");
    for(i=0;i<128;i++)
    {
        if(b[i]!=0)
        {
            ch=i;
            printf("%c : %d",ch,b[i]);
            printf("\n");
        }
    }
    return 2;


}
