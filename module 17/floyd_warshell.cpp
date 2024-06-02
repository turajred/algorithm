#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+5;
int main(){
    int n,m;
    cin>>n>>m;
    int dist[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=inf;
            if(i==j) dist[i][j]=0;
        }
    }
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==inf) cout<<"INF"<<" ";
            else cout<<dist[i][j]<<" ";
        }

        cout<<endl;
    }
    return 0;
}