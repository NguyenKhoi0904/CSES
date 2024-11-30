#include <iostream>
#include <queue>

#define ll long long
#define ln "\n"
using namespace std;

const int MAXN = 510;
const ll INF = 1e15+10;
int n,m,q,a,b;
ll dist[MAXN][MAXN];

void FloydWarshall() {
    // Duyệt qua tất cả các đỉnh trung gian k
    for (int k = 1; k <= n; k++) {
        // Duyệt qua tất cả các đỉnh bắt đầu i
        for (int i = 1; i <= n; i++) {
            // Duyệt qua tất cả các đỉnh kết thúc j
            for (int j = 1; j <= n; j++) {
                // Kiểm tra nếu khoảng cách qua k ngắn hơn khoảng cách hiện tại từ i đến j
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
// dist[i][k] != INF && dist[k][j] != INF &&
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        fill(dist[i], dist[i] + MAXN, INF);
    }

    for(int i = 1; i <= n; i++) dist[i][i] = 0ll;

    while(m--){
        ll c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }
    FloydWarshall();
    while(q--){
        cin >> a >> b;
        if(dist[a][b] == INF) cout << -1 << ln;
        else cout << dist[a][b] << ln;
    }
}

/*
10 20 10
2 4 5
2 7 8
1 2 3
9 10 6
8 9 6
8 10 9
1 6 6
2 5 7
6 9 7
3 4 9
4 8 2
5 6 2
7 8 5
5 9 8
7 9 7
4 6 8
2 3 6
6 7 10
4 9 3
4 5 4
3 2
9 8
10 4
5 9
6 10
8 9
4 10
1 2
10 2
6 10
*/

// ans
/*
6
5
9
7
13
5
9
3
14
13
*/
