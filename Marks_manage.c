#include<stdio.h>

struct node
{
    char name[20];
    int age;
    char Class[20];
    int marks;
    struct node *link;
};

int main()
{
    FILE *fp,*gp;
    struct node *head,*temp,*move,*store;
    head=NULL;
    int n,i=0,j;
    char take[20],line[100],ch='o';
    printf("Give the file containing the records of marks: ");
    gets(take);
    fp=fopen(take,"r");
    gp=fopen("Output_File.txt","w");
    if(fp==NULL)
    {
        printf("File can't be opened. Try again");
        return 2;
    }
    while(ch!=EOF)
    {
        fgets(line,56,fp);
        i=i+1;
        ch=fgetc(fp);
    }

    rewind(fp);
    for(j=0;j<i;j++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        fscanf(fp,"%s %d  %s  %d",&temp->name,&temp->age,&temp->Class,&temp->marks);
        temp->link=NULL;
        if(head==NULL)
            head=temp;
        else
        {
            move=head;
            while(move->link!=NULL)
            {
                move=move->link;
            }
            move->link=temp;
        }
    }

    move=head;
    if(move==NULL)
    {
        printf("No records present there in file");
        return 2;
    }
    else
    {
        n=move->marks;
        while(move!=NULL)
        {
            if(move->marks>n)
                n=move->marks;
            move=move->link;
        }
    }
    fclose(fp);
    printf("The students who scored the highest marks are listed below: \n");
    move=head;
    store=NULL;
    while(move->link!=NULL)
    {
        if(move->marks==n)
            {
                printf("\n %s",move->name);
                if(move==head)
                {
                    head=head->link;
                    move=head;
                }
                else
                {
                    store->link=move->link;
                    move=move->link;
                }
            }
        else
        {
            store=move;
            move=move->link;
        }
    }
    if(move->marks==n && store==NULL)
    {
        printf("\n %s",move->name);
        head=NULL;
    }
    else if(move->marks==n && store!=NULL)
    {
        printf("\n %s",move->name);
        store->link=NULL;
    }

    move=head;
    while(move!=NULL)
    {
        fprintf(gp,"%s %d  %s  %d\n",move->name,move->age,move->Class,move->marks);
        move=move->link;
    }
    printf("\n Records of the remaining students have been put in file Output_File.txt ");

    fclose(gp);

    return 2;


}

