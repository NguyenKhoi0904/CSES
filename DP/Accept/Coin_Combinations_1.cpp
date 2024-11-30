#include <iostream>
//#include <algorithm>

#define ln "\n"
#define int long long
using namespace std;

const int mod = 1e9+7;
const int maxn = 1e6+5;
int n,x;
int c[maxn], dp[maxn];

void Solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> c[i];

//    sort(c, c+n);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - c[j] >= 0){
                dp[i] += dp[i - c[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[x] << ln;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie(0);
    Solve();
    return 0;
}

const int INF = INT_MAX;
const int MAXN = 100; // Số đỉnh tối đa trong đồ thị

void FloydWarshall(int n, vector<vector<int>> &dist) {
    // Duyệt qua tất cả các đỉnh trung gian k
    for (int k = 0; k < n; k++) {
        // Duyệt qua tất cả các đỉnh bắt đầu i
        for (int i = 0; i < n; i++) {
            // Duyệt qua tất cả các đỉnh kết thúc j
            for (int j = 0; j < n; j++) {
                // Kiểm tra nếu khoảng cách qua k ngắn hơn khoảng cách hiện tại từ i đến j
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n, m; // n là số đỉnh, m là số cạnh
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Khoảng cách từ một đỉnh đến chính nó là 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Đọc vào các cạnh
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;

        // Nếu đồ thị là vô hướng, cần thêm dòng sau
        // dist[v][u] = w;
    }

    // Chạy thuật toán Floyd-Warshall
    FloydWarshall(n, dist);

    // In ra kết quả
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
