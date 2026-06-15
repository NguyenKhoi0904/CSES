#include <bits/stdc++.h>

#define ln "\n"
#define int long long

using namespace std;

const int maxn = 2e5+5;

int n;
int k[maxn];


void Solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> k[i];

    map<int,int> um;
    int ans = 1;
    int left = 1, right = 1;
    while(right <= n){
        if(um[k[right]] == 0){
            um[k[right]] = right;
            ans = max(ans,right - left + 1);
        }else{
            if(um[k[right]] < left){
                um[k[right]] = right;
                ans = max(ans,right - left + 1);
            }else{
                left = um[k[right]] + 1;
                um[k[right]] = right;
            }
        }
        right++;
    }
    cout << ans << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
/*
6
1 2 3 1 2 3
*/
// 3

/*
12
1 2 3 4 5 6 7 8 4 1 2 3
*/
// 8
