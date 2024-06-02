#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool count_sub(int n,int ar[],int s){
    if(n==0){
        if(s==0) return true;
        else return false;
    }

    if(dp[n][s]!=-1) return dp[n][s];
    if(ar[n-1]<=s){
        int ch1=count_sub(n-1,ar,s-ar[n-1]);
        int ch2=count_sub(n-1,ar,s);
        return dp[n][s]=ch1||ch2;
    }
    else return dp[n][s]=count_sub(n-1,ar,s);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int s;cin>>s;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            dp[i][j]=-1;
        }
    }
    if(count_sub(n,a,s)) cout<<"YES";
    else cout<<"NO";
    return 0;
}