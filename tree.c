#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int a;
	struct node* l;
	struct node* r;
};

struct node *root;
struct node *temp;
 
struct node* createnode(int var){

 	root = (struct node *)(malloc(sizeof(struct node)));
 	root->a= var;
 	root->l= NULL;
 	root->r = NULL;
 	return (root);
}


int main(void){

	root = NULL;

	root = createnode(1);
	root->l = createnode(2);
	root->r = createnode(3);
	root->l->l = createnode(4);
	root->l->r = createnode(5);
	printf("%d %d %d %d %d  \n", root->a,root->l->a,root->l->l->a,root->l->r->a, root->r->a)

}





