#include <stdio.h>
#include <stdlib.h>

struct node{
int a;
struct node *next;
};


struct node *head;
struct node *trav;
struct node *temp;


void add(int var){ 

if(head == NULL){
head = (struct node *)(malloc(sizeof(struct node)));
head->a=var;
head->next = NULL;
trav=head;
return;
}//if


temp=(struct node *)(malloc(sizeof(struct node)));
temp->a=var;
temp->next = NULL;
trav->next=temp;
trav=trav->next;
} //add

void print(){
	struct node *trav;
	trav=head;
	while(trav != NULL){
		printf("%d  %p     ",trav->a,trav);
		trav=trav->next;	
	}
	printf("\n");
}


int main(void){

    head=NULL;add(10);
    add(50);
    print();
    
    add(20);
    print();
    
    add(30);
    print();
    
    return 0;
}

