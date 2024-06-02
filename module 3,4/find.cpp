#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;cin>>k;
    bool flg=false;
    int idx;
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]==k){
            flg=true;
            idx=mid;
        }

        if(k>nums[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    if(flg==true) cout<<idx;
    else cout<<"Not Found";
    return 0;
}