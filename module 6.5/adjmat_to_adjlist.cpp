#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int adjmt[N][N];
vector<int> adj[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int y;cin>>y;
            adjmt[i][j]=y;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           if(adjmt[i][j]==1){
            adj[i].push_back(j);
           }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"List "<<i<<" : ";
        for(int j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}