#include <bits/stdc++.h>

#define ln "\n"

using namespace std;

const int maxn = 2e5+5;

int n;
int k[maxn];

void Solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> k[i];

    multiset<int> ms;

    for(int i = 0; i < n; i++){
        auto it = ms.upper_bound(k[i]);
        if(it == ms.end()){
            ms.insert(k[i]);
        }else{
            ms.erase(it);
            ms.insert(k[i]);
        }
    }
    cout << ms.size() << ln;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}

/*
5
3 8 2 1 5
*/
//2
//3 2 1 - 8 5

/*
4
4 3 1 2
*/
//2
//4 3 - 1 2

/*
4
2 2 1 1
*/
//2
//2 1 - 2 1
