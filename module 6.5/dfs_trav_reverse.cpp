#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> arr[N];
bool visited[N];
void dfs(int u){
    visited[u]=true;
    for(int v:arr[u]){
        if(visited[v]==true) continue;
        dfs(v);
    }
    cout<<u<<" ";
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1);
    return 0;
}