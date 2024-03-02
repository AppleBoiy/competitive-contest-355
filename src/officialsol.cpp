#include <iostream>

#define ll long long

ll fib_fast(ll n, ll m) {
    if (n <= 1)
        return n;

    // Pisano period
    ll remainder = 0;

    ll a = 0, b = 1, c;
    for (ll i = 0; i < n - 1; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) {
            remainder = i + 1;
            break;
        }
    }

    ll new_n = n % remainder;
    if (new_n <= 1)
        return new_n;

    a = 0, b = 1, c = a + b;
    for (ll i = 0; i < new_n - 1; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
    }

    return c % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << fib_fast(n, m) << '\n';
}