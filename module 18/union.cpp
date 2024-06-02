#include<bits/stdc++.h>
using namespace std;
int parent[1000];
void sett(int x){
    for(int i=1;i<=x;i++){
        parent[i]=-1;
    }
}
int find(int node){
    while(parent[node]!=-1){
        node=parent[node];
    }
    return node;
}
void d_union(int a,int b){
    int leaderA=find(a);
    int leaderB=find(b);
    if(leaderA != leaderB){
        parent[leaderB]=leaderA;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    sett(n);
    while(m--){
        int u,v;
        cin>>u>>v;
        d_union(u,v);
    }
    return 0;
}