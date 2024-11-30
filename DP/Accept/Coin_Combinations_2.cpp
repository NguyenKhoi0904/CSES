#include <bits/stdc++.h>

#define ln "\n"
#define int long long

using namespace std;

const int maxn = 1e6+5;
const int mod = 1e9+7;
int n,x;
int coin[maxn], dp[maxn];

void Solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> coin[i];

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j < coin[i]) continue;
            dp[j] = (dp[j] + dp[j - coin[i]])%mod;
        }
    }
//    for(int i = 1; i <= x; i++){
//        cout << i << ": " << dp[i] << ln;
//    }
    cout << dp[x] << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
