/*
    https://www.spoj.com/problems/HORRIBLE/

BIT with range update

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
#define typeData long long

const int MAXN = 35005;

struct FenwickTreeRupdate {
    vector<typeData> B1;  // binary indexed tree
    vector<typeData> B2;
    int n;

    FenwickTreeRupdate(int n) {
        this->n = n;
        B1.assign(n+1, 0);
        B2.assign(n+1, 0);
    }

    FenwickTreeRupdate(vector<typeData> a) : FenwickTreeRupdate(a.size()) {
        for (size_t i = 1; i <= a.size(); i++) {
            add_range(i, i, a[i]);
        }
    }

    typeData sum(vector<typeData>& b, int idx) {
        typeData ret = 0;
        while(idx > 0) {
            ret += b[idx];
            idx -= idx & -idx;
        }
        return ret;
    }

    typeData prefix_sum(int idx){
        return (typeData)sum(B1, idx)*idx -  sum(B2, idx);
    }

    typeData range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l-1);
    }


    void add(vector<typeData>& b, int idx, typeData x) {
        while(idx <= n) {
            b[idx] += x;
            idx += idx & -idx;
        }
    }

    void add_range(int l, int r, typeData x) {
        add(B1, l, x);
        add(B1, r+1, -x);
        add(B2, l, x*(l-1));
        add(B2, r+1, -x*r);
    }
};

int n, m;

void solve() {
    cin >> n >> m;
    FenwickTreeRupdate tree(n);

    int x, y, z, t;
    for(int i = 0; i < m; i++) {
        cin >> x;
        if(x == 0) {
            cin >> y >> z >> t;
            tree.add_range(y, z, t);
        } else {
            cin >> y >> z;
            cout << tree.range_sum(y, z) << "\n";
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("code.in", "r", stdin);
        freopen("code.ou", "w", stdout);
    #endif

    int test;
    cin >> test;
    for(int t = 0; t < test; t++) {
        solve();
    }

    return 0;

}
