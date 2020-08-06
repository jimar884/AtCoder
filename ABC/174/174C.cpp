#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int K;

    cin >> K;
    
    if(K % 5 == 0 || K % 2 == 0){
        cout << -1 << endl;
    } else{
        int mod;
        int ans = 0;
        int value = 1;
        if(K % 7 == 0) mod = K * 9 / 7;
        else mod = K * 9;

        while(true){
            value = (10*value) % mod;
            ++ans;
            if(value == 1){
                cout << ans << endl;
                break;
            }
        }
    }
}