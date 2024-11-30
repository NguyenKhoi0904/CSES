#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#define ii pair<int,int>
using namespace std;

struct Edge{
    int u,v;
    ll w;
//    Edge(int _u, int _v, ll _w): u(_u), v(_v), w(_w){}
};

const int MAXN = 2510;
const ll INF = 1e17;

int n,m;
ll dist[MAXN];
vector<Edge> edges;

void BellmanFord(int x){
    dist[x] = 0;
    for(int i = 1; i <= n-1; i++){
        for(auto e : edges){
            int u = e.u;
            int v = e.v;
            ll w = e.w;
            if(dist[u] != INF && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }

    // KIỂM TRA CHU TRÌNH ÂM
    for(int i = 1; i <= n; i++){
        for(auto e : edges){
            int u = e.u;
            int v = e.v;
            ll w = e.w;
            if(dist[u] != INF && dist[u] + w < dist[v]) dist[v] = -INF;
        }
    }
}

void Solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) dist[i] = INF;
    edges.resize(m+1);
    while(m--){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        edges.push_back({a,b,-c});
    }
    BellmanFord(1);
    cout << ((dist[n]== -INF)?-1:-dist[n]) << ln;
//    for(int i = 1; i <= n; i++) cout << dist[i] << " ";
}

int main(){
    IO
    Solve();
    return 0;
}


cpp_BellmanFord
