#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,e,root;
vector<int> adj[10];
queue<int> myqueue;

void initialize(){
    cout<<"enter edges respectively"<<endl;
    
    int x,y;
    for (int i=0 ; i<e ; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i=1; i<=n ; i++) {
        cout<<"adj["<<i<<"] =  ";
        for (int j=0 ; j<adj[i].size(); j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void fun(bool *a){
    int temp =root;
    while (temp) {
        for (int j=0 ; j<adj[temp].size(); j++) {
            if (a[adj[temp][j]] != 1 ) {
                myqueue.push(adj[temp][j]);
                a[adj[temp][j]] = 1;
            }
        }
        myqueue.pop();
        temp = myqueue.front();
    }
}
int main(){
    cout<<"this is undirectes graph"<<endl;
    cout<<"enter no of nodes"<<endl;
    cin>>n;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    
    bool a[n+1];
    for (int i=0 ; i<= n ; i++) {
        a[i] = 0;
    }
    initialize();
    
    cout<<"enter root"<<endl;
    cin>>root;
    
    myqueue.push(root);
    a[root] = 1;
    fun(a);
    
    cout<<"the nodes connected with the root are"<<endl;
    for (int i=0 ; i<=n ; i++) {
        if (a[i]==1 ) {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}


