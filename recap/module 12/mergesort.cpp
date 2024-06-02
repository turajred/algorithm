#include<bits/stdc++.h>
using namespace std;
void merge(int ar[],int l,int r,int mid){
    int lsize=mid-l+1;
    int rsize=r-mid;
    int L[lsize],R[rsize];
    int k=0;
    for(int i=l;i<=mid;i++){
        L[k]=ar[i];
        k++;
    }
    k=0;
    for(int i=mid+1;i<=r;i++){
        R[k]=ar[i];
        k++;
    }
    int i=0,j=0;
    int curr=l;
    while(i<lsize && j<rsize){
        if(L[i]<=R[j]){
            ar[curr]=L[i];
            i++;
        }
        else{
            ar[curr]=R[j];
            j++;
        }
        curr++;
    }
    while(i<lsize){
        ar[curr]=L[i];
        curr++;
        i++;
    }
    while(j<lsize){
        ar[curr]=R[j];
        curr++;
        j++;
    }
}
void merge_sort(int ar[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(ar,l,mid);
        merge_sort(ar,mid+1,r);
        merge(ar,l,r,mid);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}