#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	int n, item, i;
	struct node *p, *head;
	printf("How many numbers want to insert");
	scanf("%d",&n);
	printf("Insert the data into head");
	scanf("%d",&item);
	p=(struct node*)malloc(sizeof(struct node*));
	if(p==NULL)
	{
		printf("overflow /n");
	}
	else
	{
		p->data=item;
		p->next=NULL;
		head=p;
		for(i=1;i<n;i++)
		{
			printf("Insert the data into Next node");
			scanf("%d",&item);
			p=(struct node*)malloc(sizeof(struct node*));
			p->data=item;
			p->next=NULL;
			
		}
	}
	return 0;
	
	
}
