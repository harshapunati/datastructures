#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char heap[100][100];
int heapsize;


void heapify(int m){
    int l1 = (2*m)+1;
    int l2 = (2*m)+2;
    char temp[100];
    int max =m;
    if (l1 < heapsize && strcmp(heap[m],heap[l1]) > 0 ) {
        max= l1;
    }
    
    if (l2 < heapsize && strcmp(heap[max],heap[l2]) >0) {
        max= l2;
    }
    
    if (max != m) {
        strcpy(temp,heap[m]);
        strcpy(heap[m],heap[max]);
        strcpy(heap[max],temp);
        heapify(max);
    }
}

void pop(){
    strcpy(heap[0],heap[heapsize-1]);
    heapify(0);
    heapsize--;
}

void build(char a[100][100], int i){
    
    heapsize= i+1;
    for (int k=0; k<=i ; k++) {
        strcpy(heap[k],a[k]);
    }
    int l = i/2;
    while (l>=0) {
        heapify(l);
        l--;
    }
}

int main(){
    char a[100][100];
    char c;
    int i=0,j=0;
    printf("enter the string \n");
    c = getchar();
    while (c != '\n') {
        if (c == ' ') {
            a[i][j] = '\0';
            i=i+1;
            j=0;
        }
        else{
            a[i][j] = c;
            j++;
        }
        c = getchar();
    }
    int size =i;
    a[i][j] = '\0';
    printf("words in given order\n");
    for (int k=0; k<=i ; k++) {
        printf("%s\n",a[k]);
    }
    build(a,i);
    printf("order after sorting\n");
    for (int i=0 ; i<size; i++) {
        printf("%s\n",heap[0]);
        pop();
    }
    printf("%s\n",heap[0]);

    
}






