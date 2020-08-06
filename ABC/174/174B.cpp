#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    long long N, D;
    long long x, y;
    int ans = 0;

    cin >> N >> D;

    for(int i = 0; i < N; ++i){
        cin >> x >> y;
        if(sqrt(x*x+y*y) <= D) ++ans;
    }

    cout << ans << endl;
    
}