#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define F first
#define S second
#define PB push_back

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)

const int MAXN = 35005;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("code.in", "r", stdin);
        freopen("code.ou", "w", stdout);
    #endif
    vector<int> phi = phi_1_to_n(1000000);
    int T;
    cin >> T;
    int a;
    for(int t = 0; t < T; t++) {
        cin >> a;
        cout << phi[a] << endl;
    }

    return 0;

}
