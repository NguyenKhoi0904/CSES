#include <bits/stdc++.h>

#define ln "\n"
#define el cout << ln;
#define FOR0(n) for(int i = 0; i < n; i++)
#define FOR1(n) for(int i = 1; i <= n; i++)
#define int long long
using namespace std;



void Solve(){
    int n; cin >> n;
    cout << n << " ";
    while(n != 1){
        if (n & 1) n = n*3 + 1;
        else n = n / 2;
        cout << n << " ";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
