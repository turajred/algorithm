#include<bits/stdc++.h>
using namespace std;

bool reach(long long x, long long i) {
    if (i == x) return true;
    if (i > x) return false;

    bool ch1 = reach(x, i * 10);
    bool ch2 = reach(x, i * 20);

    return ch1 || ch2;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;

        if (reach(x, 1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

