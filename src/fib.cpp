//
// Created by Chaipat Jainan on 29/2/2024 AD.
//

#include "fib.h"

ll fib(ll n) {
    if (n <= 1)
        return n;

    ll a = 0, b = 1, c;
    for (ll i = 0; i < n - 1; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    ll n;
    cin >> n;
    cout << fib(n) % 8 << endl;
    return 0;
}