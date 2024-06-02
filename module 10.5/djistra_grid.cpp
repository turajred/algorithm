#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e3+10;
const int inf=1e9+10;
vector<pii>adj[N];
vector<int> dist(N,inf);
bool visited[N];
void dji(int s){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dist[s]=0;
    pq.push({dist[s],s});
    while(!pq.empty()){
        int u=pq.top().second;
        visited[u]=true;
        pq.pop();
        for(pii vpair:adj[u]){
            int v=vpair.first;
            int w=vpair.second;
            if(visited[v]) continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int k,s;
    cin>>k>>s;
    dji(k);
    cout<<dist[s];
    return 0;
}