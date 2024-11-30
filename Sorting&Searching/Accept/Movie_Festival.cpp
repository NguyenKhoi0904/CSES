#include <iostream>
#include <algorithm>

#define ln "\n"
#define ll long long
#define ii pair<int,int>

using namespace std;

const int maxn = 2e5+5;
int n;
ii a[maxn];

bool compare(ii a, ii b){
    return a.second < b.second;
}

void Solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a+n, compare);
    int ans = 0;
    for(int i = 0, j = 1; i < n && j < n;){
        if(a[i].second <= a[j].first && a[i].second < a[j].second){
            ans++;
            i = j;
//            cout << "(" << a[j].first << "," << a[j].second << ")" << ln;
        }
        j++;
    }
    cout << ans+1 << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
