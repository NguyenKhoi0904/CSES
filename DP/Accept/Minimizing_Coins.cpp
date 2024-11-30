#include <iostream>

#define ll long long
#define ln "\n"
using namespace std;

const int maxn = 1e6+5;
const int inf = 1e6+5;
int n,x;
int c[maxn];
ll dp[maxn];

void Solve(){
    cin >> n >> x;
    dp[0] = 0;
    for(int i = 1; i <= maxn; i++) dp[i] = inf;
    for(int i = 1; i <= n; i++) cin >> c[i];

    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= n; j++){
            if(i < c[j]) continue;
            dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }
    cout << (dp[x]==inf?-1:dp[x]) << ln;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
