#include <bits/stdc++.h>

using namespace std;

const int NumBase = 100000;
class BigNumber {

    public:
        vector<int> digit;
        int is_neg;
        BigNumber()
        {
            digit.clear();
            is_neg = 1;
        }
        BigNumber(const BigNumber& a)
        {
            digit = a.digit;
            is_neg = a.is_neg;
        }
        BigNumber(long long dim)
        {
            if (dim<0){
                is_neg = -1;
            }
            else
                is_neg = 1;
            dim = dim*is_neg;
            while(dim>0){
                int x = dim % NumBase;
                digit.push_back(x);
                dim /= NumBase;
            }
        }
        ~BigNumber()
        {
            digit.clear();
        }
        BigNumber & operator=(const BigNumber &a)
        {
            digit = a.digit;
            is_neg = a.is_neg;
        }
        string to_String()
        {
            if(digit.size()==0)
                return "0";
            int n = digit.size();
            string s = "";

            for(int i=n-2;i>=0;i--){

            }
        }
};
int main()
{

}
