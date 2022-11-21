#include<stdio.h>
#include<string.h>

struct node{

  char name[20];
  int age;
  char Class[20];
  int marks;
  struct node *link;

};

int partition(int arr[1000],int l,int h)
{
    int pivot,i,j,x;
    pivot=arr[l];
    i=l;j=h;
    while(i<j)
    {
        do
        {
            i=i+1;
        }while(arr[i]<pivot);

        do
        {
            j=j-1;
        }while(arr[j]>pivot);

        if(i<j)
        {
            x=arr[i];
            arr[i]=arr[j];
            arr[j]=x;
        }
    }
    x=arr[l];
    arr[l]=arr[j];
    arr[j]=x;
    return j;

}

void quicksort(int arr[1000],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(arr,l,h);
        quicksort(arr,l,j);
        quicksort(arr,j+1,h);
    }

}


int main()
{
    FILE *fp,*gp;
    int i=0,j;
    struct node *move,*head,*temp,*newhead,*newmove,*store;
    char take[50],ch='u';
    printf("Give the input file:");
    gets(take);
    fp=fopen(take,"r");
    gp=fopen("Sorted_Records.txt","w");
    if(fp==NULL)
    {
        printf("File doesn't exist");
        return 2;
    }
    while(ch!=EOF)
    {
        ch=fgetc(fp);
        fgets(take,49,fp);
        i=i+1;
    }
    i=i-1;
    rewind(fp);
    if(i==0)
    {
        printf("There is no record in the file");
        return 2;
    }

    head=NULL;
    move=NULL;
    int age[i+1];
    for(j=0;j<i;j++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        fscanf(fp,"%s %d  %s  %d",&temp->name,&temp->age,&temp->Class,&temp->marks);
        temp->link=NULL;
        age[j]=temp->age;
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

    age[i]=120;
    quicksort(age,0,i);
    newhead=NULL;
    newmove=NULL;
    for(j=0;j<i;j++)
    {
        move=head;
        store=NULL;
        while(move!=NULL)
        {
            if(move->age==age[j])
            {
               temp=(struct node*)malloc(sizeof(struct node));
               strcpy(temp->name,move->name);
               temp->age=move->age;
               strcpy(temp->Class,move->Class);
               temp->marks=move->marks;
               temp->link=NULL;
               if(newhead==NULL)
               {
                   newhead=temp;
                   newmove=temp;
               }
               else
               {
                   newmove->link=temp;
                   newmove=newmove->link;
               }

               if(move==head)
               {
                   head=head->link;
               }
               else if(move->link==NULL)
               {
                   store->link=NULL;
               }
               else
               {
                   store->link=move->link;
               }
               break;
            }
            else
            {
                store=move;
                move=move->link;
            }
        }
    }

    fclose(fp);
    newmove=newhead;
    while(newmove!=NULL)
    {
        fprintf(gp,"%s %d  %s  %d\n",newmove->name,newmove->age,newmove->Class,newmove->marks);
        newmove=newmove->link;
    }
    fclose(gp);
    printf("Records have been put in the ascending order of ages in file Sorted_Records.txt");
    return 2;

}
