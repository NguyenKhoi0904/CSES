#include <bits/stdc++.h>

#define ln "\n"
#define el cout << ln;
#define int long long

using namespace std;

const int maxn = 2e5+5;
const int maxt = 1e9;
const int inf = 1e18;

int n,t;
int k[maxn];

void Solve(){

//    FILE *f = fopen("test_input.txt", "r");
//    if(f == NULL){
//        cout << "Can not open file" << ln;
//        return;
//    }
//    fscanf(f, "%d", &n);
//    fscanf(f, "%d", &t);
//
//    cout << n << " " << t << ln;
//
//    for(int i = 0; i < n; i++) fscanf(f, "%d", &k[i]);



    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> k[i];

    int l = 1, r = inf;
    int ans = inf;
    while(l <= r){
        int mid = (l+r)/2;
        int tmp = t;
        int flag = false;
        for(int i = 0; i < n; i++){
            tmp -= (mid/k[i]);
            if(tmp <= 0){
                ans = min(ans, mid);
                r = mid - 1;
                flag = true;
                break;
            }
        }
        if(!flag) l = mid + 1;
    }
    cout << ans << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
