#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj[N];
int depth[N];
int visited[N];
void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        depth[v]=depth[u]+1;
        if(visited[v]==true) continue;
        dfs(v);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int k;cin>>k;
    dfs(1);
    for(int i=1;i<=n;i++){
        if(i==k){
            cout<<"Depth of "<<i<<" = "<<depth[i];
        }
    }
    return 0;
}