#include<bits/stdc++.h>

#define LL long long
using namespace std;

const int nMatrix = 2;

struct Mat{
    LL a[nMatrix][nMatrix];
    Mat(){
        memset(a, 0, sizeof(a));
    }

};

Mat operator *(Mat A, Mat B){
    Mat ret;
    for(int i=0; i<nMatrix; i++)
        for(int j=0; j<nMatrix; j++)
            for(int k=0; k<nMatrix; k++)
                ret.a[i][j] = (ret.a[i][j] + (A.a[i][k] * B.a[k][j] ));
    return ret;
}

Mat operator +(Mat A, Mat B){
    Mat ret;
    for(int i=0; i<nMatrix; i++)
        for(int j=0; j<nMatrix; j++)
            ret.a[i][j] = (A.a[i][j] + B.a[i][j]);
    return ret;
}

Mat operator -(Mat A, Mat B){
    Mat ret;
    for(int i=0; i<nMatrix; i++)
        for(int j=0; j<nMatrix; j++){
        ret.a[i][j] = (A.a[i][j] - B.a[i][j]);
    }
    return ret;
}

int main()
{
    cout << 1;
}
