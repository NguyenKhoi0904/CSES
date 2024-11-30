#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

struct Point{
    int x, distance;
    Point* father;
    Point(int _x, int _distance, Point* _father):x(_x), distance(_distance), father(_father){};
};

const int MAXN = 1e5+10;
int arr[MAXN], visited[MAXN];
int n, m;
vector<vector<int>> v;
Point* ans = nullptr;
bool flag = false;

void BFS(int i){
    queue<Point*> q;
    q.push(new Point(i,1,NULL));
    visited[i] = 1;
    while(!q.empty()){
        Point* u = q.front();
        q.pop();
        if(u->x == n){
            ans = u;
            flag = true;
            return;
        }
        for(int e : v[u->x]){
            if(!visited[e]){
                visited[e] = 1;
                q.push(new Point(e, u->distance+1, u));
            }
        }
    }
}

void Solve(){
    cin >> n >> m;
    v.resize(n+1);
    while(m--){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    BFS(1);
    if(flag){
        cout << ans->distance << ln;
        stack<int> st;
        while(ans != NULL){
            st.push(ans->x);
            ans = ans->father;
        }
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }else cout << "IMPOSSIBLE\n";
}

int main(){
    IO
    Solve();
    return 0;
}
