#include <iostream>

#define ln "\n"

using namespace std;

const int maxn = 1e3+5;
const int maxx = 1e5+5;

int n,x;
int h[maxn], s[maxn];
int dp[maxn][maxx];

void Solve(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> s[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(h[i] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], s[i] + dp[i-1][j - h[i]]);
            }
        }
    }
    cout << dp[n][x] << ln;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
