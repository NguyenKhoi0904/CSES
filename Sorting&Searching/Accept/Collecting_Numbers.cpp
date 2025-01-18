#include <bits/stdc++.h>

#define ln "\n"
#define ii pair<int,int>

using namespace std;

const int maxn = 2e5+5;

int n;
ii a[maxn];

bool compare(ii a, ii b){
    return a.first < b.first;
}

void Solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i].second > a[i+1].second) ans++;
    }
    cout << ans + 1 << ln;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}

/*
5
5 4 2 3 1
*/
/*
5
1 2 3 5 4
*/
