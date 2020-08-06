#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MOD 1000000007

//逆元
long long modinv(long long a) {
    long long b = MOD, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

int main(void){
    int N, K;
    long long ans = 1;
    long long value;
    vector<long long> Vp, Vm; //Vpに正,Vmに負の数を
    
    cin >> N >> K;

    for(int i = 0; i < N; ++i){
        cin >> value;
        if(value < 0) Vm.push_back(value);
        else Vp.push_back(value);
    }

    //絶対値からみて降順になるようにソート
    sort(Vm.begin(), Vm.end());
    sort(Vp.begin(), Vp.end(), greater<long long>() );

   if(K == N){ //K=Nなら一意に定まる
       for(int i = 0; i < int(Vp.size()); ++i){
           ans = (ans*Vp[i]) % MOD;
       }
       for(int i = 0; i < int(Vm.size()); ++i){
           ans = (ans*Vm[i]) % MOD;
           ans += MOD;
       }
   } else if(Vp.empty()){ //全部負の数の時
       if(K % 2 == 0){ //Kが偶数なら絶対値が大きい数優先
           for(int i = 0; i < K; ++i){
               ans = (ans*Vm[i]) % MOD;
               ans += MOD;
           }
       } else{ //Kが奇数なら絶対値が小さい数優先
           for(int i = Vm.size()-K; i < int(Vm.size()); ++i){
               ans = (ans*Vm[i]) % MOD;
               ans += MOD;
           }
       }
   } else{
       int indexVp = 0;
       int indexVm = 0;
       while((indexVp+indexVm) < K){
           if(indexVp == int(Vp.size())){ //Vpが尽きたとき残りはVm
               while((indexVp+indexVm) < K){
                   ans = (ans*Vm[indexVm]) % MOD;
                   ans += MOD;
                   ++indexVm;
               }
               break;
           } else if(indexVm == int(Vm.size())){ //Vmが尽きたとき残りはVp
               while((indexVp+indexVm) < K){
                   ans = (ans*Vp[indexVp]) % MOD;
                   ++indexVp;
               }
               break;
           } else{
               if(Vp[indexVp] > -Vm[indexVm]){ //Vp,Vmどっちもあるとき絶対値大きいほうが優先
                   ans = (ans*Vp[indexVp]) % MOD;
                   ++indexVp;
               } else{
                   ans = (ans*Vm[indexVm]) % MOD;
                   ans += MOD;
                   ++indexVm;
               }
           }
       }
       if(indexVm % 2 == 1){ //積が負の時
           if(indexVp == int(Vp.size())){ //Vpが尽きていたとき
               ans = (ans*modinv(Vp[indexVp-1])) % MOD;
               ans = (ans*Vm[indexVm]) % MOD;
               ans += MOD;
           } else if(indexVm == int(Vm.size())){ //Vmが尽きているとき
               ans = (ans*modinv(Vm[indexVm-1]+MOD)) % MOD;
               ans = (ans*Vp[indexVp]) % MOD;
           } else {
               if(Vp[indexVp-1]*Vp[indexVp] > Vm[indexVm-1]*Vm[indexVm]){
                   ans = (ans*modinv(Vm[indexVm-1]+MOD)) % MOD;
                   ans = (ans*Vp[indexVp]) % MOD;
               } else{
                   ans = (ans*modinv(Vp[indexVp-1])) % MOD;
                   ans = (ans*Vm[indexVm]) % MOD;
                   ans += MOD;
               }
           }
       }
   }

   cout << ans << endl;
}