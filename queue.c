#include <stdio.h>
#include <stdlib.h>

struct node {
	int a;
	struct node *next;
};


struct node *top;
struct node *trav;
struct node *temp;
struct node *flag;
struct node *run;


void enqueue(int var){

	if (top==NULL){

		top=(struct node *)(malloc(sizeof(struct node)));
		top->a=var;
		top->next=NULL;
        trav=top;
		return;
	}


	temp=(struct node *)(malloc(sizeof(struct node)));
	temp->a = var;
    temp->next=NULL;
    trav->next=temp;
    trav = temp;

}

void dequeue(){

	temp = top;

	if (top == NULL){
		printf("we cannot dequeue because there is no node\n");
        return;
	}
    top = top->next;
    free(temp);


}



void print(){
	run = top;
	while(run != NULL){
		printf("%d  %p",run->a,run);
		printf("   ");
		run = run->next;
	}
	printf("\n");

}


int main(void){

	top=NULL;

	enqueue(10);
	print();


	enqueue(20);
	print();

	enqueue(30);
	print();

	enqueue(40);
	print();
    
	dequeue();
    print();
    
    enqueue(50);
    print();
}












