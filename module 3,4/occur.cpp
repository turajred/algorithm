#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;cin>>k;
    int l=0,r=n-1;
    int count=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]==k){
            if((mid-1>=0 && nums[mid-1]==k)||(mid+1<n && nums[mid+1]==k)){
                count++;
                break;
            }
            break;
        }
        if(k>nums[mid]){
            l=mid+1;
        }
        else if(k<nums[mid]){
            r=mid-1;
        }
    }
    if(count>0) cout<<"Yes";
    else cout<<"No";
    return 0;
}