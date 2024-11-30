#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
        t[node] = min(t[2*node],t[2*node+1]);
    }
}

int get(int node, int s, int e, int L, int R){
    if(L > e || R < s) return INT_MAX;
    if(L <= s && e <= R) return t[node];

    int mid = (s+e)/2;
    return  min(get(2*node,s,mid,L,R),get(2*node+1,mid+1,e,L,R));
}
void update(int node, int s, int e, int pos, int val){
    if(s == e){
        a[pos] = val;
        t[node] = val;
    }else{
        int mid = (s+e)/2;
        if(s <= pos && pos <= mid) update(2*node,s,mid,pos,val);
        else update(2*node+1,mid+1,e,pos,val);
        t[node] = min(t[2*node], t[2*node+1]);
    }
}
void Solve(){
    int n,q; cin >> n >> q;
    a.resize(n+1);
    t.resize(4*(n+1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while(q--){
        int a,b,c; cin >> a >> b >> c;
        if(a==2) cout << get(1,1,n,b,c) << ln;
        else update(1,1,n,b,c);
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
2 1 4
2 5 6
1 2 3
2 1 4
*/

