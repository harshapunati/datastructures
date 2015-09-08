#include <stdio.h>
#include <stdlib.h>
typedef struct node node;

struct node
{
	int data;
	node *next;
}*front1=NULL,*front2=NULL,*rear1=NULL,*rear2=NULL,*curr=NULL,*curr2=NULL;

void push(int data)
{
	node *new=(node*)malloc(sizeof(node));
	new->data=data;
	new->next=NULL;
	if(front1==NULL)
	front1=rear1=new;
	else
	{
		rear1->next=new;
		rear1=new;
	}
}

void pop()
{
	curr=front1;
	while(front1->next!=NULL)
	{
		node *new=(node*)malloc(sizeof(node));
		new->data=front1->data;
		new->next=front1->next;
		if(front2==NULL)
		front2=rear2=new;
		else
		{
			rear2->next=new;
			rear2=new;
		}
		curr2=front1;
		free(curr2);
		front1=front1->next;
	}
	rear2->next=NULL;
	printf("Popped %d\n",front1->data);
	free(front1);
	while(front2!=NULL)
	{
		push(front2->data);
		curr=front2;
		front2=front2->next;
		free(curr);
	}
}

int main()
{
	int i,j;
	for(i=1;i<=10;i++)
	push(i);
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	return 0;
}


