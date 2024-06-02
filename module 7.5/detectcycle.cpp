#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj[N];
bool visited[N];
bool dfs(int u,int p=-1){
    visited[u]=true;
    bool detectCyle=false;
    for(int v:adj[u]){
        if(v==p) continue;
        if(visited[v]) return true;
        detectCyle|=dfs(v,u);
    }
    return detectCyle;
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool dtcy=false;
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        dtcy|=dfs(i,i);
    }
    if(dtcy) cout<<"Yes";
    else cout<<"No";
    return 0;
}