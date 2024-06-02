#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(visited[v]==true) continue;
            level[v]=level[u]+1;
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
    }
    int k;cin>>k;
    bfs(1);
    cout<<"Level of "<<k<<" = "<<level[k]<<endl;
    return 0;
}