#include <iostream>
#include <vector>
using namespace std;

int main(void){
    long long N;
    long long ans;

    long long X, Y;

    cin >> N;

    ans = 0;
    for(int i = 1; i < N + 1; ++i){
        X =  i;
        Y = N / X;
        ans += Y*(Y + 1)*X / 2;
    }

    cout << ans << endl;
}