#include <iostream>
using namespace std;

#define SIZE 6

int main(void){
    int answer = 0;
    int H, W, K;
    char V[SIZE][SIZE];

    cin >> H >> W >> K;

    for(int i = 0; i < H; ++i){
        cin >> V[i];
    }

    for(int maskH = 0; maskH < (1 << H); ++maskH){
        for(int maskW = 0; maskW < (1 << W); ++maskW){
            int black = 0;
            for(int i = 0; i < H; ++i){
                for(int j = 0; j < W; ++j){
                    if((((maskH >> i) & 1) == 0) && (((maskW >> j) & 1) == 0) && V[i][j] == '#'){
                        ++black;
                    }
                }
            }
            if(black == K) ++answer;
        }
    }

    cout << answer << endl;

}