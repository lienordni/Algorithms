#include <bits/stdc++.h>

using namespace std;
 
long long inverse_modulo(long long a, long long m){ // a^(-1) (mod m)

    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
 
    if (m == 1)
        return 0;
 
    while (a>1){
        q = a/m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
 
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}

// Assumption: Numbers in rem[] are pairwise coprime
long long crt(vector<long long> a, vector<long long> n){



    long long k=n.size();
    long long prod = 1;
    for (long long i = 0; i < k; i++)
        prod *= n[i];
 
    long long result = 0;
    long long yi,zi;

    for (long long i = 0; i < k; i++){
        yi = prod / n[i];
        zi = inverse_modulo(yi,n[i]);
        result += a[i]*yi*zi;
        result%=prod;
    }
 
    return result;
}
 
int main(){
    vector<long long> num = {2,3};
    vector<long long> rem = {3,4};
    cout << (crt(num,rem)) <<endl;
    return 0;
}