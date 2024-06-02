#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dist[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            dist[i][j]=w;
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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}