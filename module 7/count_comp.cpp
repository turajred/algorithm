#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj[N];
vector<int> cnt[N];
bool visited[N];
void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(visited[v]==true) continue;
        dfs(v);

    }
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
        }
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
    for(int i=1;i<=n;i++){
        if(visited[i]==true) continue;
        cnt[i].push_back(i);
        dfs(i);
    }
    for(int i=1;i<=n;i++){
        cout<<"Component "<<i<<" : ";
        for(int v:cnt[n]){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}