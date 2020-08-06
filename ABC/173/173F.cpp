#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
    long long N, u, v, ans;

    cin >> N;

    //https://noimin.hatenablog.com/entry/2020/07/07/235034
    //ans = N*(N+1)*(N+2)/6;
    ans = (N*(N+1)*(2*N+1)/6 + N*(N+1)/2) / 2;
    
    //N-1本の辺を取得
    for(int i = 0; i < N - 1; ++i)
    {
        cin >> u >> v;
        if(u < v) ans -= u*(N-v+1);
        else ans -= v*(N-u+1);
    }
    cout << ans << endl;
}