#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		printf("the pushed element is %d \n ",top->a );
		return;
	}

	temp=(struct node *)(malloc(sizeof(struct node)));
	temp->a=var;
	temp->next=top;
	printf("the pushed element is %d \n", temp->a);
	top=temp;

}
int pop(){
	if (top==NULL){
		printf("no node is there so we cammot pop \n");
	}


	trav=top;
	printf("the poped element is %d \n" , trav->a);
	top=top->next;
	free(trav);
	return trav->a;
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

	int i = 0;
	char b[100];
	int var1,var2;
	char a;
	printf("enter the question \n");
	a = getchar();
	while(a != '\n'){
		b[i] = a;
		i++;
		a = getchar();
	}
	b[i] = '\0';

	printf("you have entered     :      %s \n" , b);
	printf("the length of string you entered is  :%d \n",strlen(b));
	printf("your answer is the last pushed element \n");

	for(i=0;i<strlen(b);i++){
		if(b[i]== '*'){
			var1 = pop();
			var2 = pop();
			push(var2*var1);

		}
		if(b[i]== '+'){
			var1 = pop();
			var2 = pop();
			push(var2+var1);

		}
		if(b[i]== '-'){
			var1 = pop();
			var2 = pop();
			push(var2-var1);

		}
		if(b[i]== '/'){
			var1 = pop();
			var2 = pop();
			push(var2/var1);

		}
		if(b[i]>49 && b[i]<58){
			push(b[i]-48);
		}



	}


	


	

}

