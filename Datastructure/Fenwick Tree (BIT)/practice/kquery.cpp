/*
    https://vn.spoj.com/problems/KQUERY/

sol: use fenwick tree 1D
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

const int MAXN = 30005;

int n, q;
int a[MAXN];
vector<int> query[200001];
vector<pair<int, int>> mixx;


struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(this->n+1, 0);
    }

    FenwickTree(vector<int> a): FenwickTree(a.size()) {
        for (size_t i = 1; i <= a.size(); i++)
            add(i, a[i]);
    }

    // ~FenwickTree() {
    //     bit.clear();
    // }

    int sum(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret += bit[idx];
            idx -= idx & -idx;
        }
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }
};

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mixx.push_back({a[i], -i-1});
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        query[i] = vector<int>(3, 0);
        cin >> query[i][0] >> query[i][1] >> query[i][2];
        mixx.push_back({query[i][2], i+1});
    }
}

void solve() {
    sort(mixx.begin(), mixx.end(), std::greater<pair<int, int>>()); 
    FenwickTree mtree(n);

    vector<int> res(q, 0);
    for(pair<int, int>& b : mixx) {
        //cout << b.second << endl;
        if(b.second > 0) { // query
            int idxQr = b.second - 1;
            res[idxQr] = mtree.sum(query[idxQr][0], query[idxQr][1]);
        } else {
            int idxA = -b.second;
            mtree.add(idxA, 1);
        }
    }
    // cout << "bug" << endl;
    for(int i : res) {
        cout << i << '\n';
        // cout << "bug" << " " <<i <<endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("code.in", "r", stdin);
        freopen("code.ou", "w", stdout);
    #endif

    input();
    solve();

    return 0;

}
