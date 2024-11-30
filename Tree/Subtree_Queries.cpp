#include <iostream>
#include <vector>

#define el "\n"
#define int long long

using namespace std;

const int MAXN = 2e5+10;
int sub[MAXN];
int pos[MAXN];
vector<int> arr;
int val[MAXN];
vector<vector<int>> adj(MAXN);
int t[4*MAXN];

int n,q;
int cur = 1;

void dfs(int u)
{
    pos[u] = cur++;
    arr.push_back(u);
    for(int v : adj[u]){
        dfs(v);
        sub[u] += sub[v];
    }
}

void build(int node, int s, int e){
    if(s == e){
        t[node] = arr[e];
    }else{
        int mid = (s+e)>>1;
        build(node<<1, s, mid);
        build(node<<1|1, mid+1, e);
    }
}

int get(int node, int s, int e, int l, int r){
    if(r < s || l > e) return 0;

    if(l <= s && e <= r && s == e) return val[t[node]];

    int mid = (s+e)>>1;
    return get(node<<1, s, mid, l, r) + get(node<<1|1, mid+1, e, l, r);
}

void update(int node, int s, int e, int idx, int val){
    if(s == e){
        t[node] = val;
        arr[idx] = val;
    }else{
        int mid = (s+e)>>1;
        if(idx <= mid) update(node<<1, s, mid, idx, val);
        else update(node<<1|1, mid+1, e, idx, val);
    }
}

void Solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    arr.push_back(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) sub[i] = 1;
    for(int i = 1; i <= n; i++) cin >> val[i];

    for(int i = 1; i <= n-1; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);
//    cout << "arr\n";
//    for(int i = 1; i <= n; i++)
//    {
//        cout << i << ": ";
//        cout << arr[i] << el;
//    }
//
//    cout << "pos\n";
//    for(int i = 1; i <= n; i++){
//        cout << i << ": ";
//        cout << pos[i] << el;
//    }
//
//    cout << "sub\n";
//    for(int i = 1; i <= n; i++){
//        cout << i << ": ";
//        cout << sub[i] << el;
//    }
    build(1,1,n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int s,x; cin >> s >> x;
//            update(1,1,n,pos[s], x);
            val[s] = x;
//            for(int i = 1; i <= n; i++) cout << val[i] << " ";
//            cout << el;
        }else{
            int s; cin >> s;
            cout << get(1,1,n, pos[s], pos[s]+sub[s]-1) << el;
        }
    }
}

int32_t main(){
    Solve();
    return 0;
}

/*
5 3
4 2 5 2 1
1 2
1 3
2 4
2 5
2 2
1 4 3
2 2
*/

