

#include <stdio.h>
#include <stdlib.h>

struct node{
	int a;
	struct node *next;
};

struct node *top;
struct node *trav;
struct node *temp;
struct node *flag;

void push(int var){

	if (top == NULL){
		top = (struct node *)(malloc(sizeof(struct node)));
		top->a=var;
		top->next=NULL;
		return;
	}

	temp=(struct node *)(malloc(sizeof(struct node)));
	temp->a=var;
	temp->next=top;
	top=temp;

}
void pop(){
	if (top==NULL){
		printf("no node is there so we cammot pop");
        return;
	}


	trav=top;
	trav=trav->next;
	free(top);
	top=trav;
}


void print(){
	flag = top;
	while(flag != NULL){

		printf("%d %p",flag->a,flag);
		printf("   ");
		flag=flag->next;
	}
	printf("\n");

}

int main(void){
	top=NULL;


	push(10);
	print();

	push(20);
	print();

	push(30);
	print();

	push(40);
	print();
	
	pop();
	print();



}
