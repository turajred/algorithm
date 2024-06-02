#include<bits/stdc++.h>
using namespace std;
const long long int inf=1e18;
class Edge{
    public:
        long long int u;
        long long int v;
        long long int w;
        Edge(long long int u,long long int v,long long int w){
            this->u=u;
            this->v=v;
            this->w=w;
        }
};
int main(){
    long long int n,m;
    cin>>n>>m;
    vector<Edge> v;
    while(m--){
        long long int a,w,i;
        cin>>a>>w>>i;
        Edge ed(a,w,i);
        v.push_back(ed);
    }
    long long int dist[n+1];
    for(long long int i=1;i<=n;i++){
        dist[i]=inf;
    }
    long long int s;cin>>s;
    long long int t;cin>>t;
    dist[s]=0;
    long long int x=v.size();
    for(long long int i=1;i<=n-1;i++){
        for(long long int j=0;j<x;j++){
            Edge ed=v[j];
            long long int a=ed.u;
            long long int b=ed.v;
            long long int c=ed.w;
            if(dist[a]!=inf && dist[b]>dist[a]+c){
                dist[b]=dist[a]+c;
            }
        }
    }
    bool flag=true;
    for(long long int j=0;j<x;j++){
        Edge ed=v[j];
        long long int a=ed.u;
        long long int b=ed.v;
        long long int c=ed.w;
        if(dist[a]!=inf && dist[b]>dist[a]+c){
            flag=false;
            break;
        }
    }
    while(t--){
        long long int d;cin>>d;
        if(flag){
            if(dist[d]==inf) cout<<"Not Possible"<<endl;
            else cout<<dist[d]<<endl;
        }
        else{
            cout<<"Negative Cycle Detected";
            break;
        }
    }
    return 0;
}