#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int unbound_knap(int n,int s,int a[],int w[]){
    if(n==0||s==0) return 0;

    if(dp[n][s]!=-1) return dp[n][s];
    
    if(w[n-1]<=s){
        return dp[n][s]=max(a[n-1]+unbound_knap(n,s-w[n-1],a,w),unbound_knap(n-1,s,a,w));
    }
    else{
        return dp[n][s]=unbound_knap(n-1,s,a,w);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n],w[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>w[i];

    int s;cin>>s;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            dp[i][j]=-1;
        }
    }
    cout<<unbound_knap(n,s,a,w);
    return 0;
}