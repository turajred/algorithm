#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int>adj[N];
bool visited[N];
void bfs(int u){
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(int v:adj[i]){
            if(visited[v]) continue;
            cout<<v<<" ";
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
    bfs(1);
    return 0;
}