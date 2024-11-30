#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"

using namespace std;

const int MAXN = 1e5+10;
const int MOD = 1e9+7;
vector<int> dp(MAXN, 0);
vector<vector<int>> v(MAXN);
int sum[MAXN] = {0};
int visted[MAXN] = {0};

int dfs(int i){
    if(!visted[i]){
        visted[i] = 1;
        for(int e : v[i]){
            int tmp = dfs(e);
            sum[i] = ((sum[i]%MOD) + (tmp%MOD)) % MOD;
        }
    }
    return sum[i];
}
void Solve(){
    int n,m; cin >> n >> m;
    sum[n] = 1;
    for(int i = 1; i <= m; i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
    }
    cout << dfs(1) << ln;
}
int main(){
    IO
    Solve();
    return 0;
}
