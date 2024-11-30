/*
    map<int,int> tmp;
    int s = 1;
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        if(!tmp[t]){
            tmp[t] = s;
            s++;
        }
    }
    for(int i = 1; i <= n; i++){
        a[i] =
    }
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
vector<ll> a,t,p;
map<int,int> m;
void build(int node, int s, int e){
    if(s == e) t[node] = a[s];
    else{
        int m = (s+e)>>1;
        build(node<<1,s,m);
        build(node<<1+1,m+1,e);
        t[node] = t[node<<1] + t[node<<1+1];
    }
}
ll get(int node, int s, int e, int L, int R){
    if(R < s || L > e) return 0;

    if(L <= s && e <= R) return t[node];

    int mid = (s+e)>>1;
    ll leftSum = get(node<<1,s,mid,L,R);
    ll rightSum = get(node<<1+1,mid+1,e,L,R);
    return leftSum + rightSum;
}

void update(int node, int s, int e, int pos, int val){
    if(s == e){
        if(!m[a[s]]){
            t[node] = 0;
        }else{
            t[node] = 1;
            m[a[s]] = s;
        }
    }else{
        int mid = (s+e)/2;
        if(s <= pos && pos <= mid) update(2*node,s,mid,pos,val);
        else update(node<<1+1,mid+1,e,pos,val);
        t[node] = t[node<<1] + t[node<<1+1];
    }
}
void Solve(){
    int n,q; cin >> n >> q;
    a.resize(n+1);
    t.resize(4*(n+1));
    p.resize(n+1,0);
    build(1,1,n);
    for(int i = 1; i <= n; i++) cin >> a[i];

    while(q--){
        int a,b; cin >> a >> b;
        update()
    }
}
int main(){
    IO
    Solve();
    return 0;
}
