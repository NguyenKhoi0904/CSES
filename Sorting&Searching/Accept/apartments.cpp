#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
bool binary_search(vector<int> &b,vector<int> &checked, int val, int k){
    int left = 0, right = b.size()-1;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if(val - k <= b[mid] && b[mid] <= val + k){
            b.erase(b.begin()+mid);
            return true;
        }
        if(b[mid] > val+k) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}
void Solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> checked(m,1);
    int ans = 0;
    for(int i = 0, j = 0; i < n && j < m;){
        if(b[j] - k <= a[i] && a[i] <= b[j] + k){
            ans++;
            i++,j++;
        }else if(b[j] - k > a[i]) i++;
        else if(b[j] + k < a[i]) j++;
    }
    cout << ans << ln;
}
int main(){
    IO
    Solve();
    return 0;
}

