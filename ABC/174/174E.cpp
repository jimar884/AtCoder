#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000000

int main(void){
    long long N, K;
    vector<long long> A;
    int a;

    cin >> N >> K;
    for(int i = 0; i < N; ++i){
        cin >> a;
        A.push_back(a);
    }

    /*
    これがダメな理由どなたか教えてください。
    long long max = *max_element(A.begin(), A.end()) + 1;
    long long min = *min_element(A.begin(), A.end());
    */
    long long max = MAX + 1;
    long long min = 0;
    long long mid;
    int d, CountCut;
    while(max - min > 1){
        CountCut = 0;
        mid = (max + min) / 2;
        for(int i = 0; i < N; ++i){
            d = (A[i] +mid - 1) / mid - 1;
            if(d > 0) CountCut += d;
        }
        if (CountCut <= K) max = mid;
        else min = mid;
    }

    cout << max << endl;
}
