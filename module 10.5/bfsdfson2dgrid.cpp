#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e3+10;
vector<string>g;
vector<pii>direc={{0,-1},{0,1},{-1,0},{1,0}};
int n,m;
bool isValid(int i,int j){
    return (i>=0&&i<n && j>=0&&j<m);
}
bool visited[N][N];
int depth[N][N];
int level[N][N];
void dfs(int i,int j){
    if(!isValid(i,j)) return;
    if(visited[i][j]) return;
    if(g[i][j]=='x') return;
    for(auto d:direc){
        int ni=i+d.first;
        int nj=j+d.second;
        depth[ni][nj]=depth[i][j]+1;
        dfs(ni,nj);
    }
}
void bfs(int si,int sj){
    queue<pii>p;
    visited[si][sj]=true;
    level[si][sj]=0;
    p.push({si,sj});
    while(!p.empty()){
        pii upair=p.front();
        int i=upair.first;
        int j=upair.second;
        p.pop();
        for(auto d:direc){
            int ni=i+d.first;
            int nj=j+d.second;
            if(isValid(ni,nj)&& !visited[ni][nj] && g[ni][nj]!='x'){
                p.push({ni,nj});
                visited[ni][nj]=true;
                level[ni][nj]=level[i][j]+1;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    int si,sj,di=-1,dj=-1;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='s'){
                si=i;
                sj=j;
            }
            if(s[j]=='e'){
                di=i;
                dj=j;
            }
        }
        g.push_back(s);
    }
    bfs(si,sj);
    if(level[di][dj]!=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<N;j++){
            depth[i][j]=0;
        }
    }
    dfs(si,sj);
    if(depth[di][dj]!=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}