#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;


int main(void){
    int N, M;
    long long K;
    vector<long long>A;
    vector<long long>B;

    long long value;

    cin >> N >> M >> K;

    A.push_back(0);
    B.push_back(0);
    for(int i = 0; i < N; ++i){
        cin >> value;
        A.push_back(value + A[i]);
    }
    for(int i = 0; i < M; ++i){
        cin >> value;
        B.push_back(value + B[i]);
    }

    int ans = 0;
    int i, j;
    i = 0;
    j = M;
    while(i < N + 1){
        if(A[i] > K){
            break;
        }
        while(B[j] > K - A[i]){
            --j;
        }
        ans = max(ans, i + j);
        ++i;
    }

    cout << ans << endl;
    
}