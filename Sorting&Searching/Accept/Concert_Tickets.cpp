#include <iostream>
#include <algorithm>
#include <set>

#define ll long long
#define ln "\n"
using namespace std;

const int maxn = 2e5+5;
int n,m;
multiset<int> h;
int t[maxn];

void Solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        h.insert(tmp);
    }
    for(int i = 0; i < m; i++) cin >> t[i];
    for(int i = 0; i < m; i++){
        auto it  = h.upper_bound(t[i]);
        if(it != h.begin()){
            it--;
            cout << *it << ln;
            h.erase(it);
        }else cout << -1 << ln;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
