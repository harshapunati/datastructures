#include <stdio.h>
#include <stdlib.h>

int *heap,heap_size;
void heapify(int i);
void build(int ar[],int n)
{
	heap=ar;
	heap_size=n;
    for (int i=n/2-1 ; i>=0; i--) {
        heapify(i);
    }
}

void heapify(int i)
{
	int tmp,l=2*i+1,r=2*i+2;
	int mx=i;
	if(l<heap_size && heap[l]>heap[i])
	mx=l;
	if(r<heap_size && heap[r]>heap[mx])
	mx=r;
	if(mx!=i)
	{
		tmp=heap[i];
		heap[i]=heap[mx];
		heap[mx]=tmp;
		heapify(mx);
	}
}

void pop()
{
    heap[0]=heap[heap_size-1];
	heapify(0);
	heap_size--;
}

int main()
{
	int ar[]={5,6,1,2,3,19,4,7,8};
	build(ar,9);
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]); i++) {
        printf("%d\n",heap[0]);
        pop();
    }
   
	
}