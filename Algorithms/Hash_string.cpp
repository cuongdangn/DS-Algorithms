//Substr
typedef long long ll;

const ll MOD=1000000003;
const ll maxn=1000111;

using namespace std;

ll POW[maxn], hashT[maxn];


ll getHashT(int i,int j) {
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}


int main() {
    // Input
    string T, P;
    cin >> T >> P;

    // Initialize
    int m=T.size(), n=P.size();
    T = " " + T;
    P = " " + P;
    POW[0] = 1;

    // Precalculate 26^i
    for(i = 1; i <= m; i++)
    	POW[i] = (POW[i - 1] * 26) % MOD;

    // Calculate hash value of T[1..i]
    for(i = 1; i <= m; i++)
    	hashT[i] = (hashT[i - 1] * 26 + T[i] - 'a') % MOD;

    // Calculate hash value of P
    ll hashP=0;
    for(i = 1; i <= n; i++)
    	hashP = (hashP * 26 + P[i] - 'a') % MOD;

    // Finding substrings of T equal to string P
    for(i = 1; i <= m - n + 1; i++)
    	if (hashP==getHashT(i, i + n - 1))
    		printf("%d ", i);
}
