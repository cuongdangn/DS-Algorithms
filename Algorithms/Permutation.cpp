#include <bits/stdc++.h>

using namespace std;

void dequy(vector<int>& s, int l, int r) // permutation of s from l->r;
{
    if (l == r) {
        // check(s);
        for(int t : s)
            cout << t << " ";
        cout << endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            dequy(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
}

int main() {
    vector<int> a = {1,2,3,4};
    dequy(a, 0, a.size()-1);
}
