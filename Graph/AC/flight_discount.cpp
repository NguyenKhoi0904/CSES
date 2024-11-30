#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long
#define el "\n"
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define il pair<int,ll>

using namespace std;

const int MAXN = 1e5+10;
const ll INF = 1e15;

int n,m;

vector<vector<il>> adj;

struct Edge{
    ll d;
    int v,state;
    Edge(ll _d, int _v, int _state): d(_d), v(_v), state(_state) {}
    bool operator<(const Edge &b) const{
        return d > b.d;
    }
};

void Solve(){
    scanf("%d %d", &n, &m);
    adj.resize(n+1);

    while(m--){
        int a,b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        adj[a].push_back({b,c});
    }

    priority_queue<Edge, vector<Edge>> pq;
    vector<vector<ll>> dist (n+1, vector<ll> (2, INF));
    dist[1][0] = dist[1][1] = 0;
    pq.push(Edge(0,1,0));

    while(!pq.empty()){
        Edge tmp = pq.top();

        ll cur_dist = tmp.d;
        int cur_node = tmp.v;
        int state = tmp.state;

        pq.pop();
        if(dist[cur_node][state] < cur_dist) continue;

        for(auto e : adj[cur_node]){
            int neighbor = e.first;
            ll distance = e.second;
            if(!state){
                if(dist[neighbor][1] > cur_dist + distance/2){
                    dist[neighbor][1] = cur_dist + distance/2;
                    Edge p(dist[neighbor][1], neighbor, 1);
                    pq.push(p);
                }
                if(dist[neighbor][0] > cur_dist + distance){
                    dist[neighbor][0] = cur_dist + distance;
                    Edge p(dist[neighbor][0], neighbor, 0);
                    pq.push(p);
                }
            }else{
                if(dist[neighbor][1] > cur_dist + distance){
                    dist[neighbor][1] = cur_dist + distance;
                    Edge p(dist[neighbor][1], neighbor, 1);
                    pq.push(p);
                }
            }
        }
    }

    printf("%lld\n", min(dist[n][0], dist[n][1]));
//    for(int i = 1; i <= n; i++){
//        cout << i << ":\n";
//        cout << dist[i][0] << " " << dist[i][1] << el;
//    }
}

int main(){
    IO;
    Solve();
    return 0;
}

/*
4 4
1 2 100
2 4 100
1 3 10
3 4 200
*/
