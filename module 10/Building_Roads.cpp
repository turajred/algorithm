#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
vector<bool>visited(N);
vector<int>cc;
void dfs(int u,int flg=-1){
    if(flg==-1) cc.push_back(u);
    visited[u]=true;
    for(int v:adj[u]){
        if(visited[v]) continue;
        dfs(v,0);
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
    int ccn=0;
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        dfs(i);
        ccn++;
    }
    cout<<(ccn-1)<<endl;
    int v=cc.size()-1;
    for(int i=0;i<v;i++){
        cout<<cc[i]<<" "<<cc[i+1]<<endl;
    }
    return 0;
}