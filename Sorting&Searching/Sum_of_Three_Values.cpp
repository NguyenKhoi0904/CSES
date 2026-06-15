#include <bits/stdc++.h>

#define int long long
#define ln "\n"
#define el cout<<ln;
#define pii pair<int,int>
#define f1n for(int i = 1; i <= n; i++)

using namespace std;

const int maxn = 5005;
int n,x;
pii a[maxn];

bool compare(pii a, pii b){
    return a.first > b.first ? true : false;
}

void Solve(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    if(n < 3){
        cout << "IMPOSSIBLE" << ln;
        return;
    }
    sort(a, a+n+1);
//    f1n cout << a[i].first << " ";
    for(int i=1,j=n; i < j;){
        if(a[i] + a[j] >=)
        int left = i+1, right = j - 1;
        while(left <= right){
            int mid =
        }
    }

}
 int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
 }
