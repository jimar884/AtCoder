#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    vector<long> v;
    long value;
    int N;
    long long answer;

    cin >> N;

    for(int i = 0; i < N; ++i){
        cin >> value;
        v.push_back(value);
    }

    sort(v.begin(), v.end());

    int i = 1; //到着した人の人数
    int index = N - 1; //フレンドリー最大
    answer = 0; //心地よさの初期値
    answer += v[index]; //２人目が来た時の心地よさ
    --index;
    ++i;
    while(true){
        if(i == N) break;
        answer += v[index];
        ++i;
        if(i == N) break;
        answer += v[index];
        ++i;
        --index;
    }

    cout << answer << endl;
    
}