#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

queue<struct node *> myqueue;

struct node{
    int data;
    struct node *l;
    struct node *r;
};



struct node * newnode(int a){
    struct node *newn = (struct node *)(malloc(sizeof(struct node)));
    newn->data = a;
    newn->l=NULL;
    newn->r = NULL;
    
    return newn;
}

void levelordertraversal(struct node * p){
    if (p != NULL) {
        cout<<p->data<<" ";
        if (p->l != NULL) {
            myqueue.push(p->l);
        }
        if (p->r != NULL) {
            myqueue.push(p->r);
        }
        myqueue.pop();
        
        levelordertraversal(myqueue.front());
    }
}
int main(){
    struct node * root = NULL;
    root= newnode(1);
    root->l = newnode(2);
    root->r = newnode(3);
    root->l->l = newnode(4);
    root->l->r = newnode(5);
    root->r->r = newnode(7);
    root->r->l = newnode(6);
    myqueue.push(root);
    cout<<"..........level order traversal ........"<<endl;
    levelordertraversal(root);
    cout<<endl;
}