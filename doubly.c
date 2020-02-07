#include <stdio.h>
#include<stdlib.h>

typedef struct dblnk
{
    int info;
    struct dblnk *prev;
    struct dblnk *nex;

}node;

node *head, *tail;
void insert_beg(int);
void insert_end(int);
void insert_after(int ,int);
void insert_before(int ,int);
void display(void);
void exit(int);
node* search(int);

int main() {
    int ch, item,nod;

    do{
        printf("\n\n 1 for insert at beganing");
        printf("\n\n 2 for insert at end");
        printf("\n\n 3 for insert  after any node");
        printf("\n\n 4 for insert before any node");
        printf("\n\n 5 for display");
        printf("\n\n 7 for search");
        printf("\n\n 6 for exit...");

        printf("\n\n please enter your choice");
        scanf("%d",&ch);

        switch(ch)

        {
          case 1:
            printf("\n\n enter any number..");
            scanf("%d",&item);
            insert_beg( item);
            break;
          case 2:
            printf("\n\n enter any number..");
            scanf("%d",&item);
            insert_end( item);
            break;
          case 3:
            printf("\n\n enter any number..");
            scanf("%d",&item);
            printf("\n\n enter any number after item should insert..");
            scanf("%d",&nod);
            insert_after(item,nod);
                break;

            case 4:

            printf("\n\n enter any number..");
            scanf("%d",&item);
            printf("\n\n enter any number after item should insert..");
            scanf("%d",&nod);
            insert_before( item,nod);
                break;
            case 5:
                display();
                break;

            case 6:
                exit(0);
                break;
            case 7:
                printf("\n\n enter any num to search");
                scanf("%d",&nod);
              node *r= search(nod);
                printf("node is %d ",r->info);
        }

    }while(1);

    return 0;
}

void insert_beg(int item)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;

    if(head==NULL)
    {
        ptr->prev=ptr->nex=NULL;
        head=tail=ptr;
    }
    else
    {
        ptr->prev=NULL;
        ptr->nex=head;
        head->prev=ptr;
        head=ptr;

    }
}

void insert_end(int item)
{
        node *ptr;
        ptr=(node*)malloc(sizeof(node));
        ptr->info=item;

        if(head==NULL)
        {
            ptr->prev=ptr->nex=NULL;
            head=tail=ptr;
        }
       else
       {
           ptr->nex=NULL;
           tail->nex=ptr;
           ptr->prev=tail;
           tail=ptr;

       }
}

void insert_after(int item, int nod)
{
    node *ptr,*loc = NULL, *aloc;
    ptr=(node*)malloc(sizeof(node));
    loc=search(nod);
    if(loc==NULL)
    {
        printf("loc not found\n");
    }

    else if(loc->nex==NULL)
    {
        ptr->nex=NULL;
        tail->nex=ptr;
        ptr->prev=tail;
        tail=ptr;

    }
    else
    {
        aloc=loc->nex;
        ptr->prev=loc;
        ptr->nex=aloc;
        loc->nex=aloc->prev=ptr;
    }


}

void insert_before(int item, int nod)
{
    node *loc, *ptr,*bloc;
    ptr=(node*)malloc(sizeof(node));

    loc=search(nod);
    if(loc==NULL)
    {
        printf("not found!!!");
    }

    else if(loc->nex=NULL)
    {
        ptr->info=item;
        ptr->prev=NULL;
        ptr->nex=head;
        head->prev=ptr;
        head=ptr;
    }
    else
    {
        ptr->info=item;
        bloc=loc->prev;
        ptr->prev=bloc;
        ptr->nex=loc;
        bloc->nex=loc->prev=ptr;

    }

}

node* search(int nod)
{   //int i;
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(nod==ptr->info)
           //printf("%d " , nod);
        return ptr;
        ptr=ptr->nex;
    }
    return NULL;
}

void display()
{

    node *ptr;

    for(ptr=head; ptr!=NULL; ptr=ptr->nex)
    {
        printf("%d  ",ptr->info);
    }
}

