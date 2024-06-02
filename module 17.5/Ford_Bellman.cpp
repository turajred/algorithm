#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
class Edge{
    public:
        int u;
        int v;
        int w;
        Edge(int u,int v,int w){
            this->u=u;
            this->v=v;
            this->w=w;
        }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<Edge>v;
    int dist[n+1];
    while(m--){
        int a,b,i;
        cin>>a>>b>>i;
        Edge ed(a,b,i);
        v.push_back(ed);
    }
    for(int i=1;i<=n;i++){
        dist[i]=inf;
    }
    dist[1]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<v.size();j++){
            Edge ed=v[j];
            int a=ed.u;
            int b=ed.v;
            int x=ed.w;
            if(dist[a]!=inf && dist[b]>dist[a]+x){
                dist[b]=dist[a]+x;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]==inf) cout<<"30000"<<" ";
        else cout<<dist[i]<<" ";
    }
    return 0;
}