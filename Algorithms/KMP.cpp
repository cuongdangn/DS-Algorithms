#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1000005;

string s1, s2;
int pre[MaxN]; // pre[i] là vị trí mà tiền tố dài nhất của xâu 0->i kết thúc tại pre[i] cũng là hậu tố của 0->i
int KMP(string s2, string s1)
{
    int result = 0;
    int n = s2.length();
    int m = s1.length();
    if (n > m)
        return 0;
    int j = -1;
    pre[0] = -1;

    for (int i = 1; i < n; i++)
    {
        while (j >= 0 && s2[j + 1] != s2[i])
            j = pre[j];
        if (s2[j + 1] == s2[i])
            j++;
        pre[i] = j;
    }
    cout << n << endl;

    j = -1;
    for (int i = 0; i < m; i++)
    {
        while (j >= 0 && s2[j + 1] != s1[i])
            j = pre[j];
        if (s2[j + 1] == s1[i])
            j++;
        if (j == n - 1)
        {
            cout << i - n + 1 << " ";
            result++;
            j = pre[n - 1];
        }
    }
    cout << endl;
    return result;
}
int main()
{
    // cin >> s1;
    // cin >> s2;
    cout << " cuongdn" << endl;
    cout << KMP("aaabaaabaaba", "ofofofossssddfdfaa"); // number s2 in s1
}
