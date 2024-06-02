#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int parentSize[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
class Edge{
    public:
        int a,b,c;
        Edge(int a,int b,int c){
            this->a=a;
            this->b=b;
            this->c=c;
        }
};
bool cmp(Edge x,Edge y){
    return x.c<y.c;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge>vii;
    vector<Edge>ans;
    dsu_set(n);
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        Edge ed(u,v,w);
        vii.push_back(ed);
    }
    sort(vii.begin(),vii.end(),cmp);
    long long sum=0;
    for(Edge val:vii){
        int u=val.a;
        int v=val.b;
        int w=val.c;
        int ldrA=dsu_find(u);
        int ldrB=dsu_find(v);
        if(ldrA==ldrB) continue;
        ans.push_back(val);
        dsu_union(u,v);
    }
    for(Edge val:ans){
        sum+=(long long)val.c;
    }
    if(ans.size()==n-1){
        cout<<sum;
    }
    else cout<<-1;
    return 0;
}