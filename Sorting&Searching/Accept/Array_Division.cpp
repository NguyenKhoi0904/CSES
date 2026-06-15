#include <bits/stdc++.h>

#define int long long
#define ln "\n"
#define el cout << ln;
#define FOR0(qnn) for(int i = 0; i < qnn; i++)
#define FOR1(qnn) for(int i = 1; i <= qnn; i++)

using namespace std;

const int maxn = 2e5+5;
const int maxk = 2e5+5;
const int maxv = 1e15;

int n,k;
int x[maxn];

bool check(int mid){
    int c = 1;
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        if(x[i] > mid) return false;
        else if(tmp + x[i] <= mid){
            tmp += x[i];
        }else{
            c++;
            tmp = x[i];
        }
    }
    return c <= k;
}

void Solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> x[i];

//    FILE *f = fopen("test_input.txt", "r");
//    if(f == NULL){
//        cout << "Can not open" << ln;
//        return;
//    }
//    fscanf(f, "%d", &n);
//    fscanf(f, "%d", &k);
//
//    cout << n << " " << k << ln;
//    for(int i = 1; i <= n; i++) fscanf(f, "%d", &x[i]);

    int ans = maxv;

    int l = 1, r = maxv;
    while(l <= r){
        int mid = (l+r)/2;
//        cout << "Mid: " << mid << ln;
        if(check(mid)){
            ans = min(ans, mid);
//            cout << "Ans: " << ans << ln;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
