#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+5;
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
    vector<Edge> v;
    while(m--){
        int a,w,i;
        cin>>a>>w>>i;
        Edge ed(a,w,i);
        v.push_back(ed);
    }
    int dist[n+1];
    for(int i=1;i<=n;i++){
        dist[i]=inf;
    }
    dist[1]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<v.size();j++){
            Edge ed=v[j];
            int a=ed.u;
            int b=ed.v;
            int c=ed.w;
            if(dist[b]>dist[a]+c){
                dist[b]=dist[a]+c;
            }
        }
    }
    for(int j=0;j<v.size();j++){
            Edge ed=v[j];
            int a=ed.u;
            int b=ed.v;
            int c=ed.w;
            if(dist[b]>dist[a]+c){
                cout<<"Cycle Exist"<<endl;
                return 0;
                dist[b]=dist[a]+c;
            }
    }
    cout<<"Cycle does not exist";
    return 0;
}