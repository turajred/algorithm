#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> list_edge;
bool check(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        if(a.second<b.second) return true;
        else return false;
    }
    else{
        if(a.first<b.first) return true;
        else return false;
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        list_edge.push_back({a,b});
    }
    sort(list_edge.begin(),list_edge.end(),check);
    for(pii v:list_edge){
        cout<<v.first<<" "<<v.second<<endl;
    }
    return 0;
}