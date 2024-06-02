#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int lcs(int n,string a,int m,string b){
    if(n==0||m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];

    if(a[n-1]==b[m-1]){
        int ans=lcs(n-1,a,m-1,b);
        dp[n][m]=ans+1;
    }
    else{
        int ans1=lcs(n-1,a,m,b);
        int ans2=lcs(n,a,m-1,b);
        return dp[n][m]=max(ans1,ans2);
    }
}
int main(){
    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    cout<<lcs(n,a,m,b);
    return 0;
}