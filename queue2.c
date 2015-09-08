//making a Queue using a linked list
#include <stdio.h>

/*struct queue {
	struct node *f;
	struct node *r;
};  */

struct node {
	int d;
	struct node *next;
};

struct node *newNode(int d) {
	struct node *new = malloc(sizeof(struct node));
	new->d = d;
	new->next = NULL;
	return new;
}

void EnQueue(struct node **f, struct node **r, int d) {
	struct node *temp = *r;
	struct node *new = newNode(d);
	if(isEmptyQueue(f, r)) {
		*r = new;
		*f = *r;
	}
	else {
		temp->next = new;
		*r = new;
	}
}

//returns 1 if empty else returns 0
int isEmptyQueue(struct node **f, struct node **r) {
	return *f == NULL && *r == NULL;
}

void PrintQueue(struct node **f, struct node **r) {
	struct node *front = *f;
	struct node *rear = *r;
	while(front != rear->next) {
		printf("%d\n", front->d);
		front = front->next;
	}
}

int DeQueue(struct node **f, struct node **r) {
	struct node *temp = *f;
	struct node *temp2 = *f;
	int d = 0;
	if(isEmptyQueue(f, r)) {
		printf("Queue underflow\n");
		return;
	}
	else {
		d = temp->d;
		temp = temp->next;
		*f = temp;
		free(temp2);
	}
	return d;
}

int main(void) {
	struct node *f = NULL;
	struct node *r = NULL;

	EnQueue(&f, &r, 1);
	EnQueue(&f, &r, 4);
	EnQueue(&f, &r, 6);
	EnQueue(&f, &r, 7);
	EnQueue(&f, &r, 10);
	
	DeQueue(&f, &r);
	
	PrintQueue(&f, &r);
	
	return 0;
}
