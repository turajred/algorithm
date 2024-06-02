#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int>adj[N];
int height[N];
bool visited[N];
void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(visited[v]==true) continue;
        dfs(v);
        height[u]=max(height[u],height[v]+1);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int k;cin>>k;
    dfs(1);
    for(int i=1;i<=n;i++){
        if(i==k){
            cout<<"height of "<<i<<" = "<<height[i];
        }
    }
    return 0;
}