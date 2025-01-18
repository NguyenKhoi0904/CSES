#include <iostream>

#define ln "\n"

using namespace std;

const int maxn = 1e6+5;

int n;
int dp[maxn];

void Solve(){
    cin >> n;
    for(int i = 0; i <= 9; i++){
        dp[i] = 1;
    }
    for(int i = 10; i <= n; i++){
        int tmp = i, m = 1;
        while(tmp != 0){
            m = max(m, tmp%10);
            tmp /= 10;
        }
        dp[i] = dp[i-m] + 1;
    }
    cout << dp[n] << ln;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
