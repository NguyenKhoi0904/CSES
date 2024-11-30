#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"

using namespace std;
class DSU{
private:
    vector<int> parent,size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 1; i <= n; i++) parent[i] = i; // Mỗi phần tử là đại diện của chính nó
    }
    // Tìm đại diện của tập hợp chứa x với path compression
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Đệ quy tìm cha và gán trực tiếp cha là root
    }

    // Hợp hai tập hợp chứa x và y
    bool Union(int x, int y){
        int root_x = find(x);
        int root_y = find(y);

        if(root_x == root_y) return false;
        parent[root_y] = root_x;
        return true;
    }

};

struct Edge{
    int u,v,c;
    Edge(int _u, int _v, int _c): u(_u), v(_v), c(_c){}
};

bool compare(Edge a, Edge b){
    return a.c < b.c;
}

void Solve(){
    int n,m; cin >> n >> m;
    vector<Edge> edges;
    for(int i = 1; i <= m; i++){
        int a,b,c; cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }
    sort(edges.begin(), edges.end(), compare);
    int tplt = n;
    DSU dsu(n);
    ll ans = 0ll; // Tổng của cây khung nhỏ nhất
    for(auto e : edges){
        if(!dsu.Union(e.u, e.v)) continue;
        ans += e.c;
        tplt--;
    }
    if(tplt > 1){
        cout << "IMPOSSIBLE\n";
    }else cout << ans << ln;
}

int main(){
    IO
    Solve();
    return 0;
}

