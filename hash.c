#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int size=0;
int ele =0;

struct node{
    int id;
    int age;
    char name[100];
    int marker;
};

struct node *hash=NULL;

void insert(int id,char name[100],int age){
    int hashindex = id%size;
    while (hash[hashindex].marker == 1) {
        hashindex = (hashindex+1)%size;
    }
    hash[hashindex].marker = 1;
    hash[hashindex].id = id;
    hash[hashindex].age = age;
    strcpy(hash[hashindex].name,name);
    ele++;
}

void delete(int id){
    if (ele ==0 ) {
        printf("there are no elements to delete\n");
        return;
    }
    int hashindex = id % size;
    int count =0;
    int flag=0;
    while (count <= ele && hash[hashindex].marker!= 0) {
        if (hash[hashindex].id == id) {
            hash[hashindex].marker = -1;
            hash[hashindex].id = 0;
            hash[hashindex].age = 0;
            strcpy(hash[hashindex].name,"none");
            ele--;
            flag=1;
            break;
        }
        hashindex = (hashindex+1)%size;
        count++;
    }
    if (flag == 1) {
        printf("item deleated\n");
    }
    else{
        printf("item not found\n");
    }
}

void search(int id){
    if (ele ==0 ) {
        printf("there are no elements to search\n");
        return;
    }
    int hashindex = id % size;
    int count =0;
    int flag=0;
    while (count <= ele && hash[hashindex].marker!= 0) {
        if (hash[hashindex].id == id) {
            printf("ID=%d",hash[hashindex].id);
            printf("    AGE=%d",hash[hashindex].age);
            printf("    NAME=%s\n",hash[hashindex].name);
            flag=1;
            break;
        }
        hashindex = (hashindex+1)%size;
        count++;
        
    }
    if (flag != 1) {
        printf("item not present\n");
    }

}

void display(){
    if (ele == 0 ) {
        printf("there are no elements to display\n");
        return;
    }
    for (int i=0; i<size; i++) {
        if (hash[i].marker == 1) {
            printf("INDEX = %d\n",i);
            printf("    ID = %d",hash[i].id);
            printf("    AGE = %d",hash[i].age);
            printf("    NAME = %s\n",hash[i].name);
        }
    }
}
int main(){
    int id;
    int age;
    char name[100];
    int s,i=0;
    char c;
    printf("enter the size of hash table\n");
    scanf("%d",&size);
    hash = (struct node *)calloc(size, sizeof(struct node));
    while (1) {
        printf("1 . insertion\n");
        printf("2 . deletion\n");
        printf("3 . search\n");
        printf("4 . display\n");
        printf("5 . exit\n");
        scanf("%d",&s);
        switch(s){
            case 1:
                printf("enter the id \n");
                scanf("%d",&id);
                printf("enter age \n");
                scanf("%d",&age);
                printf("enter name \n");
                c = getchar();
                fgets(name, 100, stdin);
                name[strlen(name) - 1] = '\0';
                insert(id,name,age);
                break;
            case 2:
                printf("enter the id to be deleted\n");
                scanf("%d",&id);
                delete(id);
                break;
            case 3:
                printf("enter the id to be searched\n");
                scanf("%d",&id);
                search(id);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("enter correct integer\n");
        }
    }
}




