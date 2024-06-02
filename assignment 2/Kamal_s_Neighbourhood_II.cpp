#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
bool visited[N];
int cnt=0;
void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(visited[v]) continue;
        cnt++;
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
    dfs(k);
    cout<<cnt;
    return 0;
}