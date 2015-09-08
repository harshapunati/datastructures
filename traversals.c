#include <stdio.h>
#include<stdlib.h>

int count=0;
struct node {
	int d;
	struct node *l;
	struct node *r;
};

struct node *root;

struct node *newNode(int a) {
	struct node *new = (struct  node *)malloc(sizeof(struct node));
	new->d = a;
	new->l = NULL;
	new->r = NULL;
	return new;
}

void printPreorder(struct node *root) {
	//struct node *temp = root;
	if(root != NULL) {
		printf("%d ", root->d);
        count++;
		printPreorder(root->l);
		printPreorder(root->r);
	}
    
}

void printInorder(struct node *root) {
	//struct node *temp = root;
	if(root != NULL) {
		printInorder(root->l);
		printf("%d ", root->d);
		printInorder(root->r);
	}
}

void printPostorder(struct node *root) {
	//struct node *temp = root;
	if(root != NULL) {
		printPostorder(root->l);
		printPostorder(root->r);
		printf("%d ", root->d);
	}
}

int main(void) {
	root = NULL;
	root = newNode(1);
	
	root->l = newNode(2);
	root->r = newNode(3);
	
	root->l->l = newNode(4);
	root->l->r = newNode(5);
	
	root->r->r = newNode(6);
	
	//printPreorder(root);
	printf("Preorder traversal : ");
	printPreorder(root);
	printf("\n\n");
    printf("%d\n",count);
	printf("In order traversal : ");
	printInorder(root);
	printf("\n\n");
	
	printf("Post order traversal : ");
	printPostorder(root);
	printf("\n\n");
	
	return 0;
}
