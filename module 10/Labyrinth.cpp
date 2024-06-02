#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
typedef pair<int,int> pii;
vector<string>g;
vector<pii>direc={{0,-1},{0,1},{-1,0},{1,0}};
int level[N][N];
pii parent[N][N];
bool visited[N][N];
int n,m;
bool isValid(int i,int j){
    return (i>=0&&i<n && j>=0&&j<m);
}
void bfs(int si,int sj){
    queue<pii>q;
    visited[si][sj]=true;
    level[si][sj]=0;
    q.push({si,sj});
    while(!q.empty()){
        pii upair=q.front();
        int i=upair.first;
        int j=upair.second;
        q.pop();
        for(auto d:direc){
            int ni=i+d.first;
            int nj=j+d.second;
            if(isValid(ni,nj)&& !visited[ni][nj] && g[ni][nj]!='#'){
                q.push({ni,nj});
                visited[ni][nj]=true;
                level[ni][nj]=level[i][j]+1;
                parent[ni][nj]={i,j};
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
            if(s[j]=='A'){
                si=i;sj=j;
            }
            if(s[j]=='B'){
                di=i;dj=j;
            }

        }
        g.push_back(s);
    }
    bfs(si,sj);
    if(level[di][dj]!=0){
        cout<<"YES"<<endl;
        cout<<level[di][dj]<<endl;
        vector<pii>path;
        pii curr={di,dj};
        while(!(curr.first==si && curr.second==sj)){
            path.push_back(curr);
            curr=parent[curr.first][curr.second];
        }
        path.push_back({si,sj});
        reverse(path.begin(),path.end());
        long int x=path.size();
        for(int i=1;i<x;i++){
            if(path[i].first==path[i-1].first){
                if(path[i-1].second==path[i].second-1){
                    cout<<"R";
                }
                else{
                    cout<<"L";
                }
            }
            else{
                if(path[i-1].first==path[i].first-1){
                    cout<<"D";
                }
                else{
                    cout<<"U";
                }
            }
        }
    }
    else cout<<"NO"<<endl;

    return 0;
}