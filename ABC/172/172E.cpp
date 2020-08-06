#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MOD 1000000007

//逆元
inline long long modinv(long long a) {
    long long b = MOD, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

inline long long nPr(int n, int r){
    long long ans = 1;
    for(int i = 0; i < r; ++i){
        ans = (ans*(n-i)) % MOD;
    }
    return ans;
}

inline long long nCr(int n, int r){
    long long ans = 1;
    if(r == n || r == 0) return 1;
    for(int i = 0; i < r; ++i){
        ans = (ans*(n-i)) % MOD;
    }
    for(long long i = r; i > 0; --i){
        ans = (ans*modinv(i)) % MOD;
    }
    return ans;
}

//https://coonevo.hatenablog.com/entry/2020/06/28/165408
int main(void){
    int N, M;

    long long ans;
    long long sigma;

    cin >> N >> M;

    ans = (nPr(M, N)*nPr(M, N)) % MOD;

    sigma = 0;
    for(int i = 1; i < N + 1; ++i){
        if(i % 2 == 0){
            sigma = (sigma + nCr(N,i)*nPr(M-i,N-i)) % MOD;
        } else{
            sigma = (sigma - nCr(N,i)*nPr(M-i,N-i)) % MOD;
        }
    }
    sigma = (sigma*nPr(M,N)) % MOD;

    ans = (ans+sigma) % MOD;

    cout << ans << endl;

}
