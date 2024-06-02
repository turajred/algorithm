#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int nums[N];
void merge(int l,int r,int mid){
    int left_size=(mid-l)+1;
    int LR[left_size+1];
    for(int i=l,j=0;i<=mid;i++,j++) LR[j]=nums[i];
    int right_size=(r-(mid+1))+1;
    int RR[right_size+1];
    for(int i=mid+1,j=0;i<=r;i++,j++) RR[j]=nums[i];
    LR[left_size]=INT_MAX;
    RR[right_size]=INT_MAX;
    int lp=0,rp=0;
    for(int i=l;i<=r;i++){
        if(LR[lp]<=RR[rp]){
            nums[i]=LR[lp];
            lp++;
        }
        else{
            nums[i]=RR[rp];
            rp++;
        }
    }
}
void mergesort(int l,int r){
    if(l==r) return;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,r,mid);
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    mergesort(0,n-1);
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";

    return 0;
}