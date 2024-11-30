#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
vector<int> a;
vector<int> t;
void build(int node, int s, int e){
    if(s == e) t[node] = 1;
    else{
        int m = (s+e)/2;
        build(node*2, s, m);
        build(node*2+1, m+1, e);
        t[node] = t[node*2] + t[node*2+1];
    }
}
int get(int node, int s, int e, int val){
    if(s == e){
        t[node] = 0;
        return a[s];
    }
    int mid = (s+e)/2;
    int tmp;
    if(t[2*node] >= val) tmp = get(node*2,s,mid,val);
    else tmp = get(node*2+1,mid+1,e,val-t[2*node]);
    t[node] = t[node*2] + t[node*2+1];
    return tmp;
}
void Solve(){
    int n; cin >> n;
    a.resize(n+1);
    t.resize(4*(n+1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    for(int i = 1; i <= n; i++){
        int tmp; cin >> tmp;
        cout << get(1,1,n,tmp) << " ";
    }

}
int main(){
    IO
    Solve();
    return 0;
}

