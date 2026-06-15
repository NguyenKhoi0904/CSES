#include <bits/stdc++.h>

#define int long long
#define ln "\n"
#define cln cout << ln;

using namespace std;

const int maxn = 2e5+5;
int a[maxn];
int preffix[maxn];

void Solve(){
    int n,x; cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        preffix[i] = preffix[i-1] + a[i];
    }
    int c = 0;
    int l = 0, r = 1;
    while(l <= n && r <= n){
        if(preffix[r]<= preffix[r-1]){
            if(preffix[r] == x) c++;
        }
        if(preffix[r] - preffix[l] == x){
            c++;
            r++;
        }else if(preffix[r] - preffix[l] > x){
            l++;
        }else r++;
    }
    cout << c << ln;
}


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
}

/*
6 7
2 -1 3 5 -2 4
*/
