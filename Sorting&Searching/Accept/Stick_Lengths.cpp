#include<bits/stdc++.h>

#define ln "\n"
#define int long long

using namespace std;

const int maxn = 2e5+5;
const int maxv = 1e9;

int n;

void Solve(){
    cin >> n;
    int arr[n+5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int index = (n/2);
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = ans + (abs(arr[index] - arr[i]));
    }
    cout << ans << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}

/*
7
3 4 4 4 4 4 4
*/

/*
5
2 3 1 5 2
*/
