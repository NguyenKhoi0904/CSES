#include <bits/stdc++.h>

#define ln "\n"
#define int long long

using namespace std;

const int mod = 1e9+7;
const int maxn = 1e5+5;
const int maxm = 105;

int n;
int m;
int x[maxn], dp[maxn][maxm];

void Solve(){
    cin >> n >> m;
//    FILE *f = fopen("test_input.txt", "r");
//    fscanf(f, "%d %d", &n, &m);
    for(int i = 1; i <= n; i++) cin >> x[i];
//    for(int i = 1; i <= n; i++) fscanf(f, "%d", &x[i]);

    if(x[1] == 0){
        for(int i = 1; i <= m; i++) dp[1][i] = 1;
    }else dp[1][x[1]] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i] != 0){
                dp[i][x[i]] = (dp[i-1][x[i]-1]%mod + dp[i-1][x[i]]%mod + dp[i-1][x[i]+1]%mod)%mod;
                break;
            }
            dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j]%mod + dp[i-1][j+1]%mod)%mod;
        }

    }

    int ans = 0;
    if(x[n] != 0){
        for(int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
        cout << ans << ln;
    }else{
        for(int i = 1; i <= m; i++) ans = (ans%mod + dp[n][i]%mod)%mod;
        cout << ans << ln;
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
