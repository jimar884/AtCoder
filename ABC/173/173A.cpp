#include <iostream>
using namespace std;

int main(void){
    int N;

    cin >> N;

    int count = 0;
    while (1000*count < N){
        ++count;
    }

    cout << 1000*count - N << endl;
    
}
