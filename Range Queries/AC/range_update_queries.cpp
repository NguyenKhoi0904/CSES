#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
vector<ll> a,t,lazy;
void build(int node, int s, int e){
    if(s == e) t[node] = a[s];
    else{
        ll mid = (s+e)/2;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);
        t[node] = t[2*node] + t[2*node+1];
    }
}
void update_range(int node, int s, int e, int L, int R, int val){
    if(lazy[node] != 0){
        t[node] += (e-s+1)*lazy[node];
        if(s != e){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(s > e || s > R || e < L) return;
    if(s >= L && e <= R){
        t[node] += (e-s+1)*val;
        if(s != e){
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }

    ll mid = (s+e)/2;
    update_range(2*node,s,mid,L,R,val);
    update_range(2*node+1,mid+1,e,L,R,val);
    t[node] = t[2*node]+t[2*node+1];
}

ll get_index(int node, int s, int e, int idx){
    if(lazy[node] != 0){
        t[node] += (e-s+1)*lazy[node];
        if(s != e){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(s > e || idx < s || idx > e) return 0;
    if(s == e) return t[node];
    ll mid = (s+e)/2;
    if(idx <= mid) return get_index(2*node,s,mid,idx);
    return get_index(2*node+1,mid+1,e,idx);
}
void Solve(){
    int n,q; cin >> n >> q;
    a.resize(n+1);
    t.resize(4*(n+1));
    lazy.resize(4*(n+1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
//    for(int e : t) cout << e << " ";
    while(q--){
        int temp; cin >> temp;
        if(temp == 1){
            int a,b,u; cin >> a >> b>> u;
            update_range(1,1,n,a,b,u);
        }else{
            int k; cin >> k;
            cout << get_index(1,1,n,k) << ln;
        }
    }
}
int main(){
    IO
    Solve();
    return 0;
}
