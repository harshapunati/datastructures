// level order traversal of a tree
//also, give the level of a tree for a given node
#include <stdio.h>
#include<stdlib.h>

struct treenode {
	int d;
	struct treenode *l;
	struct treenode *r;
};

struct queue {
	struct treenode *data;
	struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;

struct treenode *newTreeNode(int d) {
	struct treenode *new = malloc(sizeof(struct treenode));
	new->d = d;
	new->l = NULL;
	new->r = NULL;
	return new;
}

struct queue *newQueueNode() {
	struct queue *new = malloc(sizeof(struct queue));
	new->data = NULL;
	new->next = NULL;
	return new;
}

struct treenode *AddToTree(struct treenode **root, int d) {
	struct treenode *temp = *root;
	struct treenode *new = newTreeNode(d);
	if(temp == NULL) {
		*root = new;
		return *root;
	}
	else {
		if(d <= temp->d) {
			temp->l = AddToTree(&(temp->l), d);
		}
		else if(d > temp->d) {
			temp->r = AddToTree(&(temp->r), d);
		}
		return temp;
	}
}

void inOrderTree(struct treenode *root) {
	if(root == NULL) {
		return;
	}
	else {
		inOrderTree(root->l);
		printf("%d  ", root->d);
		inOrderTree(root->r);
	}
}

//returns 1 if queue is empty else return 0
int isEmptyQueue() {
	return (front == NULL && rear == NULL);
}  

void PrintQueue() {
	struct queue *front1 = front;
	struct queue *rear1 = rear;
	while(front1 != rear1->next) {
		printf("%d\n", front1->data->d);
		front1 = front1->next;
	}  
}   

void Enqueue(struct treenode *new) {
	//struct queue *front = *f;
	//struct queue *rear = *r;
	//struct treenode *root = *new;
	
	struct queue *newNode = newQueueNode();
	
	if(isEmptyQueue() != 0) {  //empty case
		rear = newNode;
		rear->data = new;
		rear->next = NULL;
		front = rear;
		//*r = rear;
		//*f = *r;
	}
	else {   //queue has some elements
		rear->next = newNode;
		rear->next->data = new;
		rear->next->next = NULL;
		rear = rear->next;
		//*r = rear->next;
	}   
}  

struct treenode *Dequeue() {
	struct queue *temp = front;
	struct queue *temp2 = front;
	struct treenode *t = temp2->data;
	//struct queue *rear = rear;
	
	if(isEmptyQueue() != 0) {
		printf("Queue underflow\n");
		return NULL;
	}
	else {
		temp = temp->next;
		if(temp == NULL) {
			front = temp;
			rear = front;
		}
		else {
			front = temp;
		}
		free(temp2);
	}
	return t;
}   

void LevelOrderTraversal(struct treenode *root) {
	//struct queue *front = *f;
	//struct queue *rear = *r;
	struct treenode *temp = NULL;
	Enqueue(root);
	while(!isEmptyQueue()) {
		printf("In while loop\n");
		temp = Dequeue();
		printf("%d\n", temp->d);
		
		if(temp->l != NULL) {
			printf("Enqueing left child\n");
			Enqueue(temp->l);
		}
		if(temp->r != NULL) {
			printf("Enqueing right child\n");
			Enqueue(temp->r);
		}
	}
}   

int GetHeight(struct treenode *root) {
	struct treenode *temp = NULL;
	int level = 0;
	Enqueue(root);
	Enqueue(NULL);
	while(!isEmptyQueue()) {
		temp = Dequeue();
		if(temp == NULL) {
			if(!isEmptyQueue()) {
				Enqueue(NULL);
			}
			level++;
		}
		else {
			if(temp->l != NULL) {
				Enqueue(temp->l);
			}
			if(temp->r != NULL) {
				Enqueue(temp->r);
			}
		}
	}
	return level;
}

int main(void) {
	struct treenode *root = NULL;
	AddToTree(&root, 6);
	AddToTree(&root, 4);
	AddToTree(&root, 1);
	AddToTree(&root, 2);
	AddToTree(&root, 3);
	AddToTree(&root, 5);  
	
	//prints the inorder traversal of the tree
 	//inOrderTree(root);
	//printf("\n");
	//printf("Queue is : %d", isEmptyQueue(front, rear));
	
	//LevelOrderTraversal(root);
	
	int h = GetHeight(root);
	printf("Height of tree is : %d\n",h);
	
	/*Enqueue(root);
	//printf("\n%d\n", (Dequeue())->d);
	Dequeue();
	Enqueue((root->l));
	Enqueue((root->l->l));
	Enqueue((root->l->r));
	Dequeue();
	PrintQueue();      */
	
	return 0;
}
