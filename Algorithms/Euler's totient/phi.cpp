
/*
Euler's totient function, also known as phi-function ϕ(n), 
counts the number of integers between 1 and n inclusive, which are coprime to n.

*/
#include <bits/stdc++.h>

using namespace std;


// calculate Phi, O(sqrt(n))
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


//  all the totient (phi) of all numbers between 1 and n O(nloglogn)
vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }

    return phi;
}