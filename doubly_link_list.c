#include<stdio.h>
#include<stdlib.h>

struct emp
{
    int empno,sal;
    struct emp *n,*p;
};
struct emp*head,*ptr,*k,*tail,*a;

void insert_front()
{
    ptr=(struct emp*)malloc(sizeof(struct emp));
    printf("\nEnter employee no. and salary\n");
    scanf("%d %d",&ptr->empno,&ptr->sal);
    ptr->p=NULL;
    ptr->n=NULL;

    if(head==NULL)
    {
        head=ptr;
        tail=ptr;
    }
    else
    {
        ptr->n=head;
        head->p=ptr;
        head=ptr;
    }
}

void delete_front()
{
   ptr=head;
   head=head->n;
   head->p=NULL;
   free(ptr);
}

void insert_rear()
{
    ptr=(struct emp*)malloc(sizeof(struct emp));
    printf("\nEnter employee no. and salary\n");
    scanf("%d %d",&ptr->empno,&ptr->sal);
    ptr->p=NULL;
    ptr->n=NULL;
    tail->n=ptr;
    ptr->p=tail;
    tail=ptr;
}

void delete_rear()
{
    k=head->n;
    ptr=head;
    while(k!=tail)
    {
        k=k->n;
        ptr=ptr->n;
    }
    ptr->n=NULL;
    free(k);
    tail=ptr;
}

void insert_spec_loc()
{
    ptr=(struct emp*)malloc(sizeof(struct emp));
    printf("\nEnter employee no. and salary\n");
    scanf("%d %d",&ptr->empno,&ptr->sal);
    int i,pos;
    a=head;
    printf("\nEnter the position where you want to insert your node\n");
    scanf("%d",&pos);
    for(i=1;i<pos-1;i++)
    {
        a=a->n;
    }
    ptr->n=a->n;
    a->n=ptr;
    ptr->p=a;
    ptr->n->p=ptr;
}

void delete_spec_loc()
{
    int i,pos;
    a=head;
    ptr=head->n;
    printf("\nEnter the position to delete node\n");
    scanf("%d",&pos);
    for(i=1;i<pos-1;i++)
    {
        a=a->n;
        ptr=ptr->n;
    }
    a->n=ptr->n;
    ptr->n->p=a;
    free(ptr);
}

void display()
{
                if(head==NULL)
        printf("\nEmpty list\n");
  else
  {
      ptr=head;
      while(ptr)
      {
          printf("\nempno. %d and sal %d",ptr->empno,ptr->sal);
          ptr=ptr->n;
      }
  }
}

int main()
{
    head=NULL;
    int choice=0;
    while(choice<8)
    {
        printf("\nEnter:\n 1 to insert from front\n 2 to insert from rear\n 3 to delete from front\n 4 to delete from rear\n 5 to insert at specific location \n 6 to delete from specific location \n 7 to display\n");
        scanf("%d",&choice);
        if(choice==1) insert_front();
        if(choice==2) insert_rear();
        if(choice==3) delete_front();
        if(choice==4) delete_rear();
        if(choice==5) insert_spec_loc();
        if(choice==6) delete_spec_loc();
        if(choice==7) display();
    }
    return 0;
}
