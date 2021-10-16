/*
https://www.spoj.com/problems/NKMOBILE/

BIT2D
*/

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

struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;

    
    FenwickTree2D() {
    }

    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        bit.assign(n+1, vector<int>(m+1, 0));
    }

    FenwickTree2D(vector<vector<int>> a) : FenwickTree2D(a.size(), a[0].size()) {
        for (size_t i = 1; i < a.size(); i++)
            for(size_t j = 1; j < a[0].size(); j++)
                add(i, j, a[i][j]);
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i <= n;  i += i & -i)
            for (int j = y; j <= m;  j += j & -j)
                bit[i][j] += delta;
    }
};

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    #ifndef ONLINE_JUDGE
        freopen("code.in", "r", stdin);
        freopen("code.ou", "w", stdout);
    #endif

    int ct, x, y, z, t;
    FenwickTree2D tree;

    while(true) {
        cin >> ct;
        if(ct == 3) break;
        if (ct == 0) {
            cin >> n;
            tree = FenwickTree2D(n, n);
        } else
        if(ct == 1) {
            cin >> x >> y >> z;
            tree.add(x+1, y+1, z);
        } else {
            cin >> x >> y >> z >> t;
            x += 1;
            y += 1;
            z += 1;
            t += 1;

            int sum1 = tree.sum(z, t);
            int sum2 = tree.sum(x-1, y-1);
            int sum3 = tree.sum(x-1, t);
            int sum4 = tree.sum(z, y-1);
            cout << sum1 - sum3 + sum2 - sum4 << "\n";
        }
    }

    return 0;

}
