#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
struct Spe{
    ll prefix,suffix,sum,sum_max;
};
vector<int> a;
vector<Spe> t;
void build(int node, int s, int e){
    if(s == e){
        t[node].prefix = a[s];
        t[node].suffix = a[s];
        t[node].sum = a[s];
        t[node].sum_max = a[s];
    }
    else{
        int mid = (s+e)/2;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);
        t[node].prefix = max(t[2*node].prefix, t[2*node].sum + t[2*node+1].prefix);
        t[node].suffix = max(t[2*node+1].suffix, t[2*node].suffix+t[2*node+1].sum);
        t[node].sum = t[2*node].sum + t[2*node+1].sum;
        t[node].sum_max = max(t[2*node].sum_max, max(t[2*node+1].sum_max, t[2*node].suffix + t[2*node+1].prefix));
    }
}
void update(int node, int s, int e, int pos, int val){
    if(s == e){
        t[node].prefix = val;
        t[node].suffix = val;
        t[node].sum = val;
        t[node].sum_max = val;
    }else{
        int m = (s+e)/2;
        if(pos <= m) update(2*node,s,m,pos,val);
        else update(2*node+1,m+1,e,pos,val);
        t[node].prefix = max(t[2*node].prefix, t[2*node].sum + t[2*node+1].prefix);
        t[node].suffix = max(t[2*node+1].suffix, t[2*node].suffix+t[2*node+1].sum);
        t[node].sum = t[2*node].sum + t[2*node+1].sum;
        t[node].sum_max = max(t[2*node].sum_max, max(t[2*node+1].sum_max, t[2*node].suffix + t[2*node+1].prefix));
    }
}
void Solve(){
    int n,m; cin >> n >> m;
    a.resize(n+1);
    t.resize(4*(n+1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while(m--){
        int k,x; cin >> k >> x;
        update(1,1,n,k,x);
        if(t[1].sum_max < 0) cout << 0 << ln;
        else cout << t[1].sum_max << ln;
    }
}
int main(){
    IO
    Solve();
    return 0;
}


