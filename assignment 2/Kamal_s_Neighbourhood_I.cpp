#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k;cin>>k;
    int house_cnt=adj[k].size();
    cout<<house_cnt;
    return 0;
}