//Making a stack through Linked List
#include <stdio.h>
#include<stdlib.h>
struct node {
	int d;
	struct node *next;
};

struct node *newNode(int d) {
	struct node *new  = malloc(sizeof(struct node));
	new->d = d;
	new->next = NULL;
	return new;
}

void push(struct node** t, int d) {
	struct node *new = newNode(d);
	if(*t == NULL) {
		//printf("Case 1 for push\n");
		*t = new;
	}
	else {
		//printf("Case 2 for push\n");
		new->next = *t;
		*t = new;
	}
}

void printStack(struct node** t) {
	struct node *temp = *t;
	while(temp != NULL) {
		printf("%d\n", temp->d);
		temp = temp->next;
	}
}

int pop(struct node **t) {
	struct node *temp = *t;
	struct node *temp2 = *t;
	int d = 0;
	if(temp == NULL) {
		printf("Stack Undeflow");
		return 0;
	}
	else {
		d = temp->d;
		temp = temp->next;
		*t = temp;
		free(temp2);
	}
	return d;
}

int main(void) {
	struct node *top = NULL;
	push(&top, 5);
	push(&top, 99);
	push(&top, 13);
	
	pop(&top);
	//printf("\n%d\n\n", pop(&top));
	
	printStack(&top);
	
	return 0;
}
