#include<bits/stdc++.h>
using namespace std;
bool recurse(int n,int ar[],long long sum,long long x,int idx){
    if(idx==n){
        return sum==x;
    }
    
    bool ch1=recurse(n,ar,sum+ar[idx],x,idx+1);
    bool ch2=recurse(n,ar,sum-ar[idx],x,idx+1);
    return ch1||ch2;

}
int main(){
    int n;cin>>n;
    long long x;cin>>x;
    int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    if(recurse(n,ar,ar[0],x,1)) cout<<"YES";
    else cout<<"NO";
    return 0;
}