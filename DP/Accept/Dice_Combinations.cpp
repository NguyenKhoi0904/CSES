#include <iostream>

#define int long long
#define ln "\n";
using namespace std;

const int mod = 1e9+7;
const int MAXN = 1e6+5;
int dp[MAXN];
int n;

void Solve(){
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
//    for(int i = 2; i <= 6; i++){
//        dp[i] = (dp[i-1]*2);
//    }

    for(int i = 7; i <= n; i++){
        for(int j = i-1; j >= i-6; j--) dp[i] = (dp[i]%mod + dp[j]%mod)%mod;
    }
    cout << dp[n]%mod << ln;
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
