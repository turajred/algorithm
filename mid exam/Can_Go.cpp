#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e3+5;
const int inf=1e9+5;
vector<pii> g[N];
vector<int>cost(N,inf);
bool visited[N];
void djisktra(int s){
    priority_queue<pii,vector<pii>,greater<pii>>q;
    cost[s]=0;
    q.push({cost[s],s});
    while(!q.empty()){
        pii upair=q.top();
        int u=upair.second;
        visited[u]=true;
        q.pop();
        for(pii vpair:g[u]){
            int v=vpair.first;
            int w=vpair.second;
            if(!visited[v]){
                if(cost[v]>cost[u]+w){
                    cost[v]=cost[u]+w;
                    q.push({cost[v],v});
                }
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    int k;cin>>k;

    djisktra(k);
    
    int t;cin>>t;

    while(t--){
        int x;cin>>x;
        long long int dw;cin>>dw;

        if(cost[x]<=dw) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}