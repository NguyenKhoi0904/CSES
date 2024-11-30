#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#define ii pair<int,int>
using namespace std;

const int MAXN = 1e5+10;
const ll INF = 1e17+10;
int n, m;

void Dijkstra(int start, vector<vector<ii>> &adj, ll dist[]) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[start] = 0LL;
    pq.push({0LL, start});

    while (!pq.empty()) {
        ll current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // Nếu khoảng cách hiện tại lớn hơn khoảng cách đã lưu, bỏ qua
        if (current_distance > dist[current_node]) {
            continue;
        }

        for (auto &edge : adj[current_node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            // Nếu tìm thấy khoảng cách ngắn hơn
            if (dist[current_node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[current_node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}

int main() {
    IO
    cin >> n >> m;
    vector<vector<ii>> adj(n + 1);
    ll dist[n + 1];
    fill(dist, dist + n + 1, INF);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    Dijkstra(1, adj, dist);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << 0 << " "; // Nếu không có đường đi đến đỉnh i
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << ln;

    return 0;
}
