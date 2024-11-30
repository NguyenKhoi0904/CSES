#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
vector<int> tree;
vector<int> a;
void build(int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
    }else{
        int mid = (start+end)>>1;
        build(2*node, start, mid);
        build(2*node+1, mid+1,end);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int value){
    if(start > idx || end < idx) return;
    if(start == end){
        tree[node] = value;
        a[idx] = value;
        return;
    }
    int mid = (start+end)/2;
    if(start <= idx && idx <= mid) update(2*node, start, mid, idx, value);
    else update(2*node+1, mid+1, end, idx, value);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

int get(int node, int start, int end, int value){
    if(start == end){
        tree[node] -= value;
        return start;
    }
    int tmp = 0, mid =(start+end)>>1;
    if(tree[2*node] >= value) tmp = get(2*node, start, mid, value);
    else tmp = get(2*node+1, mid+1, end, value);
    tree[node]=max(tree[node*2],tree[node*2+1]);
    return tmp;
}
void Solve(){
    int n,m; cin >> n >> m;
    a.resize(n+1);
    tree.resize(4*(n+1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    for(int i = 0; i < m; i++){
        int tmp; cin >> tmp;
        cout << (tree[1]<tmp?0:get(1,1,n,tmp)) << " ";
    }
}
int main(){
    IO
    Solve();
    return 0;
}
/*
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1
*/


