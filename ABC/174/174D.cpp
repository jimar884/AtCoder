#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(void){
    string stone;
    int N;
    int r, w;
    char ch;
    int ans = 0;

    cin >> N;

    cin >> stone;

    r = N - 1;
    w = 0;

    while(r > w){
        while(stone[r] != 'R' && r != w){
            --r;
        }
        while(stone[w] != 'W' && r != w){
            ++w;
        }
        if(r == w) break;
        stone[r] = 'W';
        stone[w] = 'R';
        --r;
        ++w;
        ++ans;
    }

    cout << ans << endl;
}