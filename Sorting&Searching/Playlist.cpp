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

    unordered_map<int,int> um, tmp;
    int ans = 1;
    int i = 1, j = 1;
    int f = 1;
    while(j <= n){
        if(um[k[j]] == 0){
            um[k[j]] = j;
            j++;
        }else{
            ans = max(ans, j-i);
            i = um[k[j]] + 1;
            j = i;
            um = tmp;
        }
    }
    cout << max(ans, j-i) << ln;
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
