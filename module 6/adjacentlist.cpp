#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
vector<int> adj[N];
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cout<<"List "<<i<<":";
        for(int j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}