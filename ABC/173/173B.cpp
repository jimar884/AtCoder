#include <iostream>
#include <string>
using namespace std;

#define MAX 100000

int main(void){
    int N;
    char S[MAX][2];
    int C[4] = {0, 0, 0, 0}; //AC, WA, TLE, RE
    int AC = 0;
    int WA = 1;
    int TLE = 2;
    int RE = 3;

    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> S[i];
    }
    
    for(int i = 0; i < N; ++i){
        char c = S[i][0];
        switch (c)
        {
        case 'A':
            ++C[AC];
            break;
        case 'W':
            ++C[WA];
            break;
        case 'T':
            ++C[TLE];
            break;
        case 'R':
            ++C[RE];
            break;
        default:
            break;
        }
    }

    cout << "AC x " << C[AC] << endl;
    cout << "WA x " << C[WA] << endl;
    cout << "TLE x " << C[TLE] << endl;
    cout << "RE x " << C[RE] << endl;
}