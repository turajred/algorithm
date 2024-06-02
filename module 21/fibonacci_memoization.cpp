#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long save[N];
int fibo(int n){
    if(n==1 || n==0) return 1;
    if(save[n]!=-1) return save[n];
    long long ans1=fibo(n-1);
    long long ans2=fibo(n-2);
    save[n]=ans1+ans2;
    return save[n];
}
int main(){
    int c;cin>>c;
    for(int i=0;i<=c;i++) save[i]=-1;
    long long ans=fibo(c);
    cout<<ans;
    return 0;
}