#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int>arr[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u){
    visited[u]=true;
    // cout<<u<<" ";
    for(int v:arr[u]){
        depth[v]=depth[u]+1;
        if(visited[v]==true) continue;
        dfs(v);
        height[u]=max(height[u],height[v]+1);
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
for(int i=1;i<=n;i++){
    cout<<"Depth for "<<i<<": ";
    cout<<depth[i]<<endl;
}
cout<<"________"<<endl;
for(int i=1;i<=n;i++){
    cout<<"Height for "<<i<<": ";
    cout<<height[i]<<endl;
}
    return 0;
}