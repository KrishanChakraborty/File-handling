#include<stdio.h>
#include<string.h>
//this program removes all comments from a given .c program file and creates a dummy file containing the executable scripts.
int main()
{
    FILE *fp,*temp;
    char ch='i',take[600],y[100];
    printf("Give the program file to remove comments from there: ");
    gets(take);
    fp=fopen(take,"r");
    strcpy(y,"dummy_");
    strcat(y,take);
    temp=fopen(y,"w");
    if(fp==NULL)
    {
        printf("File can't be opened");
        return 1;
    }

    while(1)
    {
        ch=fgetc(fp);
        if(ch==EOF)
            break;
        else if(ch=='"' || ch=="'")
        {
            fputc(ch,temp);
            ch=fgetc(fp);
            while(ch!='"' && ch!="'")
            {
                fputc(ch,temp);
                ch=fgetc(fp);
            }
            fputc(ch,temp);
        }
        else if(ch=='/')
            {
                ch=fgetc(fp);
                if(ch=='/')
                {
                    fgets(take,599,fp);
                    fputc('\n',temp);
                }
                else if(ch=='*')
                {
                    while(ch!='/')
                    {
                        ch=fgetc(fp);

                    }
                }
                else
                {
                    fputc('/',temp);
                    fputc(ch,temp);
                }
            }
            else
            {
                fputc(ch,temp);
            }

    }
    fclose(fp);
    fclose(temp);
    return 2;
}
