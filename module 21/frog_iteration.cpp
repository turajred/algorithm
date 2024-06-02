#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    ar[1]=0;
    ar[2]=ar[2]-ar[1];
    int mini=0;
    for(int i=3;i<=n;i++){
        int choice1=ar[i]+abs(ar[i]-ar[i-1]);
        int choice2=ar[i]+abs(ar[i]-ar[i-2]);
        mini=min(choice1,choice2);
    }
    cout<<mini;
    return 0;
}