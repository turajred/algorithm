#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int N=1e5+5;
vector<pi>vii[N];
bool visited[N];
class Edge{
    public:
        int a,b,c;
        Edge(int a,int b,int c){
            this->a=a;
            this->b=b;
            this->c=c;
        }
};
class Cmp{
    public:
        bool operator()(Edge x,Edge y){
            return x.c>y.c;
        }
};
long long int min_cost=0;
void prims(int s,int n){
    priority_queue<Edge,vector<Edge>,Cmp>pq;
    vector<Edge>edgelist;
    pq.push(Edge(s,s,0));
    int cnt=0;
    while(!pq.empty()){
        Edge ed=pq.top();
        pq.pop();
        int u=ed.a;
        int v=ed.b;
        int w=ed.c;
        if(visited[v]) continue;
        visited[v]=true;
        cnt++;
        edgelist.push_back(ed);
        for(pi x:vii[v]){
            int s=x.first;
            int t=x.second;
            if(visited[s]) continue;
            pq.push(Edge(v,s,t));
        }
    }
    edgelist.erase(edgelist.begin());
    for (Edge val : edgelist)
    {
        min_cost+=(long long)val.c;
    }
    if(cnt==n){
        cout<<min_cost;
    }
    else cout<<"IMPOSSIBLE";
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        vii[u].push_back({v,w});
        vii[v].push_back({u,w});
    }
    prims(1,n);
    return 0;
}