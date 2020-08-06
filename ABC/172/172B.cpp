#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    string S, T;
    int ans = 0;
    char s, t;

    cin >> S;
    cin >> T;

    for(int i = 0; i < S.length(); ++i){
        s = S[i];
        t = T[i];
        if(s != t) ++ans;
    }

    cout << ans << endl;
}