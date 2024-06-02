#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int>arr[N];
bool visited[N];
void dfs(int u){
    visited[u]=true;
    cout<<u<<" ";
    for(int v:arr[u]){
        if(visited[v]==true) continue;
        dfs(v);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
    }
    dfs(1);
    return 0;
}