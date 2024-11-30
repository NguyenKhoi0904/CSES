#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
struct Prefix_max{
    ll sum,prefix;
    Prefix_max(): sum(0), prefix(0) {}
    Prefix_max(ll s, ll p):sum(s),prefix(p){}
};
vector<ll> a;
vector<Prefix_max> t;
void build(int node, int s, int e){
    if(s == e){
        t[node].sum = a[s];
        t[node].prefix = a[s];
    }else{
        int mid = (s+e)/2;
        build(node*2, s, mid);
        build(node*2+1, mid+1, e);
        t[node].sum = t[node*2].sum + t[node*2+1].sum;
        t[node].prefix = max(t[2*node].prefix, t[2*node].sum + t[2*node+1].prefix);
    }
}

Prefix_max get(int node, int s, int e, int L, int R){
    if(e < L || s > R) return Prefix_max(0, 0);
    if(L <= s && e <= R) return t[node];

    int mid = (s+e)/2;
    Prefix_max p = get(node*2,s, mid, L, R);
    Prefix_max q = get(node*2+1, mid+1, e, L, R);
    return Prefix_max(p.sum + q.sum,max(p.prefix, p.sum + q.prefix));
}

void update(int node, int s, int e, int k, int u){
    if(s == e){
        t[node].sum = u;
        t[node].prefix = u;
    }else{
        int mid = (s+e)/2;
        if(k <= mid) update(2*node, s, mid, k, u);
        else update(2*node+1, mid+1, e, k, u);
        t[node].sum = t[2*node].sum + t[2*node+1].sum;
        t[node].prefix = max(t[node*2].prefix, t[node*2].sum + t[node*2+1].prefix);
    }
}
void Solve(){
    int n,q; cin >> n >> q;
    a.resize(n+1);
    t.resize(4*(n+1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
//    for(Prefix_max e : t) cout << e.prefix << " ";
    while(q--){
        int ts; cin >> ts;
        if(ts == 1){
            int k,u; cin >> k >> u;
            update(1,1,n,k,u);
        }else{
            int a,b; cin >> a >> b;
            Prefix_max ans = get(1,1,n,a,b);
            cout << (ans.prefix < 0?0:ans.prefix) << ln;
        }
    }
}
int main(){
    IO
    Solve();
    return 0;
}

