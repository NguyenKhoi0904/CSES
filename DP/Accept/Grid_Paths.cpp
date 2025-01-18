#include <bits/stdc++.h>

#define ln "\n"
//#define int long long

using namespace std;

const int mod = 1e9+7;
const int maxn = 1005;

int n;
char a[maxn][maxn];
int dp[maxn][maxn];

void Solve(){
    cin >> n;

    for(int i = 0; i <= n + 2; i++){
        for(int j = 0; j <= n + 2; j++) a[i][j] = '*';
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    if(a[1][1] == '*'){
        dp[1][1] = 0;
    }else dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] != '*'){
                if(a[i-1][j] != '*'){
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
                }
                if(a[i][j-1] != '*'){
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
                }
            }
        }
    }
    cout << dp[n][n] << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
