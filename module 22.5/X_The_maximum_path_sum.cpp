#include<bits/stdc++.h>
int n,m;
int dp[11][11];
using namespace std;
int maxvalue(int i,int j){
    if(i==n&&j==m) return dp[i][j];
    if(i>n||j>m) return INT_MIN;

    int ch1=maxvalue(i+1,j);
    int ch2=maxvalue(i,j+1);
    return dp[i][j]+max(ch1,ch2);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>dp[i][j];
        }
    }
    cout<<maxvalue(1,1);
    return 0;
}