#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fib(ll n) {
    if (n <= 1) {
        return n;
    }
    ll a = 0, b = 1, c;
    for (ll i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    ll n, m;

    cin >> n >> m;

    cout << fib(n) % m << endl;

    return 0;
}