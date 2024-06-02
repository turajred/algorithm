#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];
vector<bool>visited(N);
vector<int>dist(N);
vector<int>parent(N);
void bfs(int s){
    queue<int>q;
    dist[s]=0;
    parent[s]=-1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        visited[u]=true;
        for(int v:adj[u]){
            if(visited[v]) continue;
            visited[v]=true;
            dist[v]=dist[u]+1;
            parent[v]=u;
            q.push(v);
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
    if(visited[n]){
        int current=n;
        vector<int> path;
        while(current != -1){
            path.push_back(current);
            current=parent[current];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(int c:path) cout<<c<<" ";
    }
    else cout<<"IMPOSSIBLE";
    return 0;
}