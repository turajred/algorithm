#include<bits/stdc++.h>
using namespace std;
const long long int inf=1e18;
int main(){
    long long int n,m;
    cin>>n>>m;
    long long int dist[n+1][n+1];
    for(long long int i=1;i<=n;i++){
        for(long long int j=1;j<=n;j++){
            dist[i][j]=inf;
            if(i==j) dist[i][j]=0;
        }
    }
    while(m--){
        long long int u,v,w;
        cin>>u>>v>>w;
        if(dist[u][v]>w) dist[u][v]=w;
    }
    long long int t;cin>>t;
    for(long long int k=1;k<=n;k++){
        for(long long int i=1;i<=n;i++){
            for(long long int j=1;j<=n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    while(t--){
        long long int s,d;cin>>s>>d;
        if(dist[s][d]==inf) cout<<-1<<endl;
        else cout<<dist[s][d]<<endl;
    }
    return 0;
}