#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#define ii pair<int,int>

using namespace std;

const int MAXN = 1e5 + 10;
int n,m;
int visited[MAXN];
vector<vector<int>> v;

struct Point{
    int p, parent, distance;
    Point* prev;
    Point(int _p, int _parent, int _distance, Point* _prev) : p(_p), parent(_parent), distance(_distance), prev(_prev){};
};

Point* ans = NULL;

bool DFS(int i, int parent){
    stack<Point*> st;
    st.push(new Point(i,parent, 1, NULL));

    while(!st.empty()){
        Point* u = st.top();
        st.pop();
        visited[u->p] = 1;

        for(int e : v[u->p]){
            if(!visited[e]){
                st.push(new Point(e, u->p, u->distance+1, u));
            }else if(e != u->parent){
                ans = new Point(e, u->p, u->distance+1, u);
                return true;
            }
        }
    }
    return false;
}


void Solve(){
    cin >> n >> m;
    v.resize(n+1);
    while(m--){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool flag = false;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(DFS(i,-1)){
                flag = true;
                break;
            }
        }
    }
    if(flag){
        int pause = ans->p, c = 1;
        ans = ans->prev;
        queue<int> q;
        while(ans->p != pause){
            q.push(ans->p);
            c++;
            ans = ans->prev;
        }
        cout << c+1 << ln;
        cout << ans->p << " ";
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
        cout << pause;
    }else cout << "IMPOSSIBLE\n";
}
int main(){
    IO
    Solve();
    return 0;
}

/*
10 20
8 5
6 10
3 6
3 1
8 6
9 10
2 1
6 7
4 3
1 9
3 7
2 6
4 1
2 5
8 4
1 8
10 8
5 4
7 1
7 9
*/



//stack<int> path;
//struct Point{
//    int p, parent, distance;
//    Point(int _p, int _parent, int _distance):p(_p), parent(_parent), distance(_distance){};
//};
//
//bool DFS(int i, int parent){
//    stack<Point> st;
//    st.push(Point(i, parent, 1));
//    path.push(i);
//    while(!st.empty()){
//        Point u = st.top();
//        st.pop();
//
//        for(int e : v[u.p]){
//            if(!visited[e]){
//                st.push(Point(e, u.parent, u.distance+1));
//                path.push(e);
//            }else if(e != u.parent){
//
//            }
//        }
//    }
//}
