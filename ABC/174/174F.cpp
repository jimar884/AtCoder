#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N, Q;
    int l, r;
    
    int c, ans;

    cin >> N >> Q;

    vector<vector<int>> color(N + 1);

    for(int i = 0; i < N + 1; ++i){
        color[0].push_back(0);
    }
    for(int i = 1; i < N + 1; ++i){
        cin >> c;
        copy(color[i - 1].begin(), color[i - 1].end(), back_inserter(color[i]));
        ++color[i][c];
    }

    for(int i = 0; i < Q; ++i){
        cin >> l >> r;
        ans = 0;
        for(int j = 1; j < N + 1; ++j){
            if(color[r][j] != color[l - 1][j]) ++ans;
        }
        cout << ans << endl;
    }
}