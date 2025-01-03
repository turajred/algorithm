#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int parentSize[N];
vector<int>cc;
bool visited[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    for(int i=1;i<=n;i++){
        int ldr=dsu_find(i);
        if(visited[ldr] || ldr==-1) continue;
        else{
            cc.push_back(ldr);
            visited[ldr]=true;
        }
    }
    
    cout<<cc.size()-1<<endl;
    int x=cc.size()-1;
    for(int i=0;i<x;i++){
        cout<<cc[i]<<" "<<cc[i+1]<<endl;
    }
    return 0;
}