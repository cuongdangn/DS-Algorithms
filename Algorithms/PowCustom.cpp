const int BASE = 10000007;

long long poww(int x, int y) {
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    long long t = poww(x, y / 2);
    t = (t * t) % BASE;
    if(y % 2)
        t = (t*x) % BASE;
    return t;
}

long long power(long long a, long long b){
    long long ans = 1;
    while(b){
        if(b&1){
            ans *= a;
        }
        a = a*a;
        b /= 2;
    }
    return ans;
}
