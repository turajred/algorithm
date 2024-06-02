#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e3+5;
vector<string>g;
vector<pii> direc={{0,1},{0,-1},{1,0},{-1,0}};
int cnt=0;
bool visited[N][N];
vector<int>comp;
int n,m;
bool isValid(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}
void dfs(int i,int j){
    if(!isValid(i,j)) return;
    if(g[i][j]=='-') return;
    if(visited[i][j]) return;

    cnt++;
    visited[i][j]=true;
    
    for(auto d:direc){
        dfs(i+d.first,j+d.second);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        g.push_back(s);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='-') continue;
            if(visited[i][j]) continue;
            dfs(i,j);
            comp.push_back(cnt);
            cnt=0;
        }
    }
    sort(comp.begin(),comp.end());
    if(!comp.empty()) cout<<comp[0];
    else cout<<"-1";
    return 0;
}