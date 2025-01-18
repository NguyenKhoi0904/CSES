#include <iostream>
#include <algorithm>

#define ln "\n"
#define int long long
using namespace std;

const int mod = 1e9+7;
const int maxn = 1e6+5;
int n,x;
int c[maxn], dp[maxn];

void Solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> c[i];

    sort(c, c+n);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - c[j] >= 0){
                dp[i] += dp[i - c[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[x] << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie(0);
    Solve();
    return 0;
}

