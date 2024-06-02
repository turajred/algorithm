#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+7;
const int inf=1e9+10;
vector<pii>g[N];
// vector<pii,int>list_edge;
int d[N];
int n,m;
void bellman(int s){
    for(int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;
    for(int i=1;i<n;i++){
        for(int u=1;i<=n;u++){
            for(pii vpair:g[u]){
                int v=vpair.first;
                int w=vpair.second;
                if(d[u]!=inf && d[v]>d[u]+w){
                    d[v]=d[u]+w;
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    bellman(1);
    for(int i=1;i<=n;i++){
        cout<<"Dist of "<<i<<" is: "<<d[i]<<endl;
    }
    return 0;
}