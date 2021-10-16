/*
    All of this tree is One-based indexing, 
    so input array should be one-base index (starting at 1)
*/

#include <bits/stdc++.h>

#define typeData int
using namespace std;

// sum tree
struct FenwickTree {
    vector<typeData> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<typeData> a)
        : FenwickTree(a.size()) {
        for (size_t i = 1; i <= a.size(); i++)
            add(i, a[i]);
    }

    typeData sum(int idx) {
        typeData ret = 0;
        while (idx > 0) {
            ret += bit[idx];
            idx -= idx & -idx;
        }
        return ret;
    }

    typeData sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, typeData delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }
};

// min tree (max)
struct FenwickTreeMin {
    vector<int> bit;
    int n;
    const int INF = (int)1e9;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n + 1, INF);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size()) {
        for (size_t i = 1; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmin(int idx) {
        int ret = INF;
        while (idx > 0) {
            ret = min(ret, bit[idx]);
            idx -= idx & -idx;
        }
        return ret;
    }

    void update(int idx, int val) {   
        while (idx <= n) {
            bit[idx] = min(bit[idx], val);
            idx += idx & -idx;
        }
    }
};

// sum 2D
struct FenwickTree2D {
    vector<vector<typeData>> bit;
    int n, m;

    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        bit.assign(n+1, vector<int>(m+1, 0));
    }

    FenwickTree2D(vector<vector<typeData>> a) : FenwickTree2D(a.size(), a[0].size()) {
        for (size_t i = 1; i < a.size(); i++)
            for(size_t j = 1; j < a[0].size(); j++)
                add(i, j, a[i][j]);
    }

    typeData sum(int x, int y) {
        typeData ret = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, typeData delta) {
        for (int i = x; i <= n;  i += i & -i)
            for (int j = y; j <= m;  j += j & -j)
                bit[i][j] += delta;
    }
};



// range add and range update
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