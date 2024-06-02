#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int adjmt[N][N];
vector<int> adj[N];
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        for(int j:adj[i]){
            adjmt[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<adjmt[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}