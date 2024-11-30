#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
vector<int> a,t;
void build(int node, int s, int e){
    if(s == e) t[node] = a[s];
    else{
        int mid = (s+e)/2;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);
        t[node] = t[2*node]^t[2*node+1];
    }
}
int get(int node, int s, int e, int L, int R){
    if(L > e || R < s) return 0;

    if(L <= s && e <= R) return t[node];
    int mid = (s+e)/2;
    int left_xor = get(2*node,s,mid,L,R);
    int right_xor = get(2*node+1,mid+1,e,L,R);
    return left_xor^right_xor;
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
/*
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
*/


