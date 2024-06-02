#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
vector<int> cnt[N];
bool visited[N];
void dfs(int u,int p){
    visited[u]=true;
    cnt[p].push_back(u);
    for(int v:adj[u]){
        if(visited[v]) continue;
        dfs(v,p);
    }
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
    int cc=0;
    int k=0;
    for(int i=0;i<N;i++){
        if(visited[i]) continue;
        dfs(i,k);
        k++;
        cc++;
    }
    vector<int>v;
    for(int i=0;i<cc;i++){
       if(cnt[i].size()>1) v.push_back(cnt[i].size());
    }
    sort(v.begin(),v.end());
    for(int c:v) cout<<c<<" ";
    return 0;
}