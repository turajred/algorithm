#include<bits/stdc++.h>
using namespace std;
void merge(int m,int n,vector<int>&ar,vector<int>&ar1,vector<int>&main){
    ar.push_back(INT_MIN);
    ar1.push_back(INT_MIN);
    int lp=0,rp=0;
    for(int i=0;i<(m+n);i++){
        if(ar[lp]>=ar1[rp]){
            main[i]=ar[lp];
            lp++;
        }
        else{
            main[i]=ar1[rp];
            rp++;
        }
    }
}

int main(){
    int n;cin>>n;
    vector<int>nums1(n);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    int k;cin>>k;
    vector<int>nums2(k);
    for(int i=0;i<k;i++){
        cin>>nums2[i];
    }
    vector<int>nums(n+k);
    merge(n,k,nums1,nums2,nums);
    for(int x:nums){
        cout<<x<<" ";
    }
    return 0;
}