#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dp[N][N];
int knapsack(int n,int s,int v[],int w[]){
    if(n==0||s==0) return 0;

    if(dp[n][s]!=-1) return dp[n][s];
    
    if(w[n]<=s){
        int op1=knapsack(n-1,s-w[n],v,w)+v[n];
        int op2=knapsack(n-1,s,v,w);
        return dp[n][s]=max(op1,op2);
    }
    else return dp[n][s]=knapsack(n-1,s,v,w);
}
int main(){
    int n;
    cin>>n;
    int v[n+1],w[n+1];
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    int s;cin>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(n,s,v,w);
    return 0;
}