#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
vector<bool> is_prime(MAXN, true);

void SieveofEratosthenes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = false;
        }
    }
}