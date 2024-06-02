#include<bits/stdc++.h>
using namespace std;
int parent[7]={-1,-1,1,1,6,4,-1};
int find(int node){
    while(parent[node]!=-1){
        node=parent[node];
    }
    return node;
}
int main(){
    int leader=find(5);
    cout<<leader;
    return 0;
}