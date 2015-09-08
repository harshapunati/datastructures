#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

vector <int> adj[10];
int n,e;

void initialize(){
    cout<<"ENTER EDGES"<<endl;
    int x,y;
    for (int i=0 ; i<e ; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i=1 ; i<=n ; i++) {
        cout<<"adj["<<i<<"] =   ";
        for (int j=0 ; j<adj[i].size(); j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int fun(bool *a,int i){
    int j=0;
    if (a[i] == 1) {
        return 1;
    }
    if (a[i] != 1) {
        a[i] = 1;
    }
    while (  j<adj[i].size()  ) {
        if (a[adj[i][j] == 1]) {
            j++;
        }
        else{
            fun(a,adj[i][j]);
            j++;
        }
    }
    return 1;
}

int main(){
    cout<<"this is undirected graph"<<endl;
    cout<<"enter number of nodes"<<endl;
    cin>>n;
    cout<<"enter number of edges"<<endl;
    cin>>e;
    
    initialize();
    bool a[n+1];
    for (int i=1 ; i<=n ; i++) {
        a[i] = 0;
    }
    
    int i;
    cout<<"enter root"<<endl;
    cin>>i;
    
    fun(a,i);
    
    cout<<"connected nodes with root are"<<endl;
    for (int i=1  ; i<=n ; i++) {
        if (a[i] == 1) {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}







