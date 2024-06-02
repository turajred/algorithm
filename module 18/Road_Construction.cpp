#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int parentSize[N];
int mx=0;
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
            mx=max(parentSize[leaderA],mx);
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
            mx=max(parentSize[leaderB],mx);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    int num_c=n;
    int max_size=1;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int ldrA=dsu_find(a);
        int ldrB=dsu_find(b);
        if(ldrA!=ldrB){
            n--;
            dsu_union(a,b);
        }
        cout<<n<<" "<<mx<<endl;
    }
    
    
    return 0;
}