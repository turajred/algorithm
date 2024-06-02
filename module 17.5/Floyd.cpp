#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main(){
    int n;
    cin>>n;
    int dist[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            if(w==-1) dist[i][j]=inf;
            else dist[i][j]=w;
        }
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
    int m=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]!=inf && dist[i][j]>m) m=dist[i][j];
        }
    }
    cout<<m;
    return 0;
}