#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
typedef pair<int,int> pii;
vector<string>g;
vector<pii>direc={{0,-1},{0,1},{-1,0},{1,0}};
bool visited[N][N];
int n,m;
bool isValid(int i,int j){
    return (i>=0&&i<n && j>=0&&j<m);
}
void dfs(int i,int j){
    if(!isValid(i,j)) return;
    if(visited[i][j]) return;
    if(g[i][j]=='#') return;

    visited[i][j]=true;

    for(auto d:direc){
        dfs(i+d.first,j+d.second);
    }
    // dfs(i,j-1);
    // dfs(i,j+1);
    // dfs(i-1,j);
    // dfs(i+1,j);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        g.push_back(s);
    }
    int ct=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='#') continue;
            if(visited[i][j]) continue;
            dfs(i,j);
            ct++;
        }
    }
    cout<<ct;
    return 0;
}