#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
vector<ll> a,t,lazy1,lazy2;
void build(int node, int s, int e){
    if(s == e) t[node] = a[s];
    else{
        int mid = (s+e)/2;
        build(node*2,s,mid);
        build(node*2+1,mid+1,e);
        t[node] = t[node*2] + t[node*2+1];
    }
}

// Lazy 1
void down1(int node, int s, int e){
    if(lazy1[node]){
        t[node] += (e-s+1)*lazy1[node];
        if(s != e){
            if(lazy2[node<<1]){
                lazy2[node<<1] += lazy1[node];
            }else lazy1[node<<1] += lazy1[node];

            if(lazy2[node<<1|1]){
                lazy2[node<<1|1] += lazy1[node];
            }else lazy1[node<<1|1] += lazy1[node];
        }
        lazy1[node] = 0;
    }
}

// Lazy 2
void down2(int node, int s, int e){
    if(lazy2[node]){
        t[node] = (e-s+1)*lazy2[node];
        if(s != e){
            lazy2[node<<1] = lazy2[node];
            lazy2[node<<1|1] = lazy2[node];
            lazy1[node<<1] = 0;
            lazy1[node<<1|1] = 0;
        }
        lazy2[node] = 0;
    }
}

void update_range(int node, int s, int e, int L, int R, ll val, int type){
    down2(node,s,e);
    down1(node,s,e);
    if(e < L || s > R) return;
    if(L <= s && e <= R){
        if(type == 1){
            lazy1[node] = val;
            down1(node,s,e);
        }else{
            lazy2[node] = val;
            down2(node,s,e);
        }
        return;
    }
    int  mid = (s+e)>>1;
    update_range(node<<1,s,mid,L,R,val,type);
    update_range(node<<1|1,mid+1,e,L,R,val,type);
    t[node] = t[node<<1]+t[node<<1|1];
}

ll get_range(int node, int s, int e, int L, int R){
    down2(node,s,e);
    down1(node,s,e);
    if(e < L || s > R) return 0;
    if(L <= s && e <= R) return t[node];
    int mid = (s+e)>>1;
    return get_range(node<<1,s,mid,L,R) + get_range(node<<1|1, mid+1, e, L, R);
}

void Solve(){
    int n,q; cin >> n >> q;
    a.resize(n+1);
    t.resize(4*(n+1));
    lazy1.resize(4*(n+1));
    lazy2.resize(4*(n+1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while(q--){
        int t; cin >> t;
        if(t == 3){
            int a,b; cin >> a >> b;
            cout << get_range(1,1,n,a,b) << ln;
        }else{
            int a,b,x; cin >> a >> b >> x;
            update_range(1,1,n,a,b,x,t);
        }
    }
}
int main(){
    IO
    Solve();
    return 0;
}
/*
6 5
2 3 1 1 5 3
3 3 5
1 2 4 2
3 3 5
2 2 4 5
3 3 5
*/

/*
4 5
1 2 3 4
3 1 3
1 2 4 2
3 1 3
2 2 4 5
3 1 3
*/
