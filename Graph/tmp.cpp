#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#define ull unsigned long long
#define ii pair<int, int>
#define maxn 250005
#define fr front
#define re rear
#define fi first
#define se second
#define inf 1000000007
using namespace std;
int g;
int n, a[502][502], dp[502][502];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};


struct Node {
    int x, y, cost;
    Node(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};


int BFS(vector<vector<int>> p, int n){

    vector<vector<int>> dist(n + 5, vector<int> (n+5, INT_MAX));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push(Node(1,1, p[1][1]));
    dist[1][1] = p[1][1];

    vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!pq.empty()){
        Node c = pq.top();
        pq.pop();

        if(c.x == n && c.y == n) return c.cost;

        for(auto dir : d){
            int _x = c.x + dir.first;
            int _y = c.y + dir.second;

            int _c = c.cost + p[_x][_y];
            if(_c < dist[_x][_y]){
                dist[_x][_y] = _c;
                pq.push(Node(_x, _y, _c));
            }
        }
    }
    return -1;
}

int Solve1(){
    cin >>  n >> g;
    vector<vector<int>> arr(n + 10, vector<int>(n + 10, 100000));
    vector<vector<int>> dp(n + 10, vector<int>(n + 10, 100000));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dp[i][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int tmp; cin >> tmp;
            if(tmp >= g) arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }

    return BFS(arr,n);
}

bool bfs(int k) {
	if (a[1][1] < k) return false;
	queue<ii> q;
	bool v[502][502];
	memset(v, false, sizeof(v));
	q.push({1, 1});
	v[1][1] = true;
	while (q.size()) {
		ii tmp = q.fr();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = tmp.fi + dx[i], y = tmp.se + dy[i];
			if (v[x][y] || x < 1 || x > n || y < 1 || y > n || a[x][y] < k) continue;
			v[x][y] = true;
			q.push({x, y});
		}
	}
	return v[n][n];
}

int solve2() {
	int l = 1, r = 5003, ans = 0;
	while (l < r) {
		int m = (l + r) >> 1;
		if (bfs(m)) {
			ans = max(ans, m);
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return ans;
}

int main(){
    IO
    int t; cin >> t;
    if(t == 1){
        cout << Solve1() << ln;
    }else{

        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }
        cout << solve2() << ln;
    }
    return 0;
}

/*
1
5 6
7 1 3 4 6
6 2 1 7 5
2 6 7 2 3
4 2 1 1 7
9 1 6 1 6
*/

/*
1
5 4
5 6 3 2 6
6 2 1 7 5
2 6 7 2 3
4 5 9 1 10
9 1 4 1 6
*/
// ans = 2

/*
2
5
7 1 3 4 6
6 2 1 7 5
2 6 7 2 3
4 2 1 1 7
9 1 6 1 6
*/

/*
2
5
5 6 3 2 6
6 2 1 7 5
2 6 7 2 3
4 5 9 1 10
9 1 4 1 6
*/

