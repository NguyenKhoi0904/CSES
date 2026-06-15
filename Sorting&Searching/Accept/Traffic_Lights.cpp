#include <bits/stdc++.h>

#define ln "\n"

using namespace std;

const int maxn = 2e5+5;

int x,n;
int p[maxn];

set<int> tl;
multiset<int> l;



void Solve(){
    cin >> x >> n;
    for(int i = 0; i < n; i++) cin >> p[i];

    tl.insert(0);
    tl.insert(x);
    tl.insert(p[0]);

    l.insert(x - p[0]);
    l.insert(p[0] - 0);

    cout << max(x - p[0], p[0] - 0) << " ";

    for(int i = 1; i < n; i++){
        auto upper = tl.upper_bound(p[i]);
        auto tmp = upper;
        auto lower = --tmp;

        l.erase(l.find(*upper - *lower));
        l.insert(p[i] - *lower);
        l.insert(*upper - p[i]);
        cout << *prev(l.end()) << " ";

        tl.insert(p[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
