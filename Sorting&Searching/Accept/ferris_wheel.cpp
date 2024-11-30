#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define ln "\n"
using namespace std;

const int maxn = 2e5+5;
const int mod = 1e9+7;
int n,x;
int arr[maxn];

void Solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int ans = 0;
    for(int i = 0, j = n-1; i <= j;){
        if(i == j){
            ans++;
            break;
        }

        if(arr[i] + arr[j] > x){
            j--;
            ans++;
        }else{
            i++; j--;
            ans++;
        }
    }
    cout << ans << ln;
}
int32_t main(){
    IO
    Solve();
    return 0;
}

