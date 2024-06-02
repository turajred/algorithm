#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e3+5;
vector<string>g;
vector<pii> direc={{0,1},{0,-1},{1,0},{-1,0}};
int level[N][N];
bool visited[N][N];
int n,m;
bool isValid(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}
void bfs(int si,int sj){
    queue<pii> q;
    level[si][sj]=0;
    visited[si][sj]=true;
    q.push({si,sj});
    while(!q.empty()){
        pii upair=q.front();
        int i=upair.first;
        int j=upair.second;
        q.pop();
        for(auto d:direc){
            int ni=i+d.first;
            int nj=j+d.second;
            if(isValid(ni,nj) && !visited[ni][nj] && g[ni][nj]!='-'){
                q.push({ni,nj});
                visited[ni][nj]=true;
                level[ni][nj]=level[i][j]+1;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        g.push_back(s);
    }
    int si,sj,di,dj;
    cin>>si>>sj;
    cin>>di>>dj;
    bfs(si,sj);
    if(visited[di][dj]) cout<<"YES";
    else cout<<"NO";
    return 0;
}