#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
void Solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int c = 1;
    for(int i = 0; i < n-1; i++){
        if(v[i] != v[i+1]) c++;
    }
    cout << c << ln;
}
int main(){
    IO
    Solve();
    return 0;
}

