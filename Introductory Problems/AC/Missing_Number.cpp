#include <bits/stdc++.h>

#define ln "\n"
#define el cout << ln;
#define FOR0(n) for(int i = 0; i < n; i++)
#define FOR1(n) for(int i = 1; i <= n; i++)

using namespace std;

const int maxn = 2e5;
int a[maxn];
void Solve(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int tmp; cin >> tmp;
        a[tmp-1]++;
    }
    for(int i = 0; i < n; i++){
        if (a[i] == 0){
            cout << i+1 << ln;
            return;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}

