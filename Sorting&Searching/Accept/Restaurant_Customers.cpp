#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
#define ii pair<int,int>
#define ln "\n"

using namespace std;

const int maxn = 2e5+5;

int n;
int a[maxn], b[maxn];

void Solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int ans = 0, g = 0;
    for(int i = 0, j = 0; i < n && j < n;){
        if(a[i] < b[j]){
            ans = max(ans, ++g);
            i++;
        }else{
            --g;
            j++;
        }
    }
    cout << ans << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}

/*
4
1 10
2 4
3 5
7 9
*/
/*
10
45 84
2 43
34 64
42 99
50 80
12 21
72 82
39 86
33 89
47 97
*/
/* TESTCASE LÀM CODE SAI
10
5 75
10 67
15 70
18 65
20 55
25 45
30 39
37 60
39 50
40 80
*/
