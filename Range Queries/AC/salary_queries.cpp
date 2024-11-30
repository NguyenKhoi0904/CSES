#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

vector<int> a;

int main() {
    IO
    indexed_set s;
    int n, q;
    cin >> n >> q;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert({a[i], i});
    }
    while (q--) {
        char c;
        cin >> c;
        if (c == '!') {
            int k, x;
            cin >> k >> x;
            s.erase({a[k], k});
            a[k] = x;
            s.insert({a[k], k});
        } else {
            int a, b;
            cin >> a >> b;
            cout << s.order_of_key({b, INT_MAX}) - s.order_of_key({a-1, INT_MAX}) << '\n';
        }
    }
    return 0;
}
