#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n==1 || n==0) return 1;

    int ans1=fibo(n-1);
    int ans2=fibo(n-2);
    return ans1+ans2;
}
int main(){
    int c;cin>>c;
    int ans=fibo(c);
    cout<<ans;
    return 0;
}