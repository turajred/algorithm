#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
vector<bool>visited(N);
int dist[N];
int parent[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    parent[s]=-1;
    dist[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        visited[u]=true;
        for(int v:adj[u]){
            if(visited[v]) continue;
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
    // int k;cin>>k;
    // bfs(1);
    // cout<<"Distance of"<<k<<":";
    // cout<<dist[k]<<endl;
    // for(int i=1;i<N;i++){
    //     visited[i]=false;
    //     dist[i]=0;
    // }
    int s,t;cin>>s>>t;
    bfs(s);
    vector<int>path;
    int current=t;
    while(current!=-1){
        path.push_back(current);
        current=parent[current];
    }
    reverse(path.begin(),path.end());
    cout<<"The Path is: ";
    for(int c:path){
        if(c!=t) cout<<c<<"->";
        else cout<<c;
    }
    return 0;
}