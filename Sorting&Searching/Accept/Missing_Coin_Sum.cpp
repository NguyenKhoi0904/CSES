#include <bits/stdc++.h>

#define ln "\n"
#define int long long

using namespace std;

const int maxn = 2e5+5;

int n;
int a[maxn];

void Solve(){
    cin >> n;
    bool flag = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) flag = true;
    }
    if(!flag){
        cout << 1 << ln;
        return;
    }
    sort(a, a+n);

    int sum = a[0];
    for(int i = 0; i < n-1; i++){
        if(a[i+1] > sum+1){
            break;
        }
        sum += a[i+1];
    }
    cout << sum + 1 << ln;

}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
