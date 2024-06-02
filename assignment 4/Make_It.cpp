#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N];
bool reach(long long x, long long i) {
    if (i == x) return true;
    if (i > x) return false;
    if(dp[i]!=-1) return dp[i];
    bool ch1 = reach(x, i + 3);
    bool ch2 = reach(x, i * 2);

    return dp[i]=ch1 || ch2;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        for(int i=0;i<=x;i++) dp[i]=-1;
        if (reach(x, 1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

