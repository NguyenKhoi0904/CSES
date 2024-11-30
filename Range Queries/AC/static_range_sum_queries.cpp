#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
vector<ll> a;
vector<ll> t;
void build(int node, int s, int e){
    if(s == e) t[node] = a[s];
    else{
        int m = (s+e)/2;
        build(2*node,s,m);
        build(2*node+1,m+1,e);
        t[node] = t[2*node] + t[2*node+1];
    }
}
ll get(int node, int s, int e, int L, int R){
    if(R < s || L > e) return 0;

    if(L <= s && e <= R) return t[node];

    int mid = (s+e)/2;
    ll leftSum = get(2*node,s,mid,L,R);
    ll rightSum = get(2*node+1,mid+1,e,L,R);
    return leftSum + rightSum;
}
void Solve(){
    int n,q; cin >> n >> q;
    a.resize(n+1);
    t.resize(4*(n+1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while(q--){
        int a,b; cin >> a >> b;
        cout << get(1,1,n,a,b) << ln;
    }
}
int main(){
    IO
    Solve();
    return 0;
}

