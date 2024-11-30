#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"

using namespace std;

const int MAXN = 1010;
const char U = 'U';
const char D = 'D';
const char L = 'L';
const char R = 'R';

int n,m;
char arr[MAXN][MAXN];
int visited[MAXN][MAXN];

struct Point{
    int x, y, distance;
    char path;
    Point* father;
    Point(int _x, int _y, int _distance, char _path, Point* _father):x(_x), y(_y), distance(_distance), path(_path), father(_father){};
};
Point* ans = NULL;
bool flag = false;

void BFS(int i, int j){
    queue<Point*> q;
    Point* tmp = new Point(i,j,0,' ', NULL);
    q.push(tmp);
    visited[i][j] = 1;
    while(!q.empty()){
        Point* u = q.front();
        q.pop();

        if(arr[u->x+1][u->y] == 'B'){
            Point* p = new Point(u->x+1, u->y, u->distance+1, D, u);
            flag = true;
            ans = p;
            return;
        }

        if(arr[u->x-1][u->y] == 'B'){
            Point* p = new Point(u->x-1, u->y, u->distance+1, U, u);
            flag = true;
            ans = p;
            return;
        }

        if(arr[u->x][u->y+1] == 'B'){
            Point* p = new Point(u->x, u->y+1, u->distance+1, R, u);
            flag = true;
            ans = p;
            return;
        }

        if(arr[u->x][u->y-1] == 'B'){
            Point* p = new Point(u->x, u->y-1, u->distance+1, L, u);
            flag = true;
            ans = p;
            return;
        }

        // DOWN
        if(arr[u->x+1][u->y] == '.' && !visited[u->x+1][u->y]){
            visited[u->x+1][u->y] = 1;
            Point* p = new Point(u->x+1, u->y, u->distance+1, D, u);
            q.push(p);
        }

        // UP
        if(arr[u->x-1][u->y] == '.' && !visited[u->x-1][u->y]){
            visited[u->x-1][u->y] = 1;
            Point* p = new Point(u->x-1, u->y, u->distance+1, U, u);
            q.push(p);
        }

        // RIGHT
        if(arr[u->x][u->y+1] == '.' && !visited[u->x][u->y+1]){
            visited[u->x][u->y+1] = 1;
            Point* p = new Point(u->x, u->y+1, u->distance+1, R, u);
            q.push(p);
        }

        // LEFT
        if(arr[u->x][u->y-1] == '.' && !visited[u->x][u->y-1]){
            visited[u->x][u->y-1] = 1;
            Point* p = new Point(u->x, u->y-1, u->distance+1, L, u);
            q.push(p);
        }
    }
}

void Solve(){
    cin >> n >> m;
    int x,y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'A') x = i, y = j;
        }
    }
    BFS(x, y);
//    cout << (flag?("YES\n" + to_string(ans.distance) + "\n" + ans.path + "\n"):"NO\n");
    if(flag){
        cout << "YES\n" << ans->distance << ln;
        stack<char> r;
        while(ans->father != NULL){
            r.push(ans->path);
            ans = ans->father;
        }
        while(!r.empty()){
            cout << r.top();
            r.pop();
        }
        cout << ln;
    }else cout << "NO\n";
}
int main(){
    IO
    Solve();
    return 0;
}
/*
5 8
########
B.A#...#
#.##.#.#
#......#
########
*/
/*
YES
9
LDDRRRRRU
*/

/*
10 10
...#..A.#.
....B...##
...#......
..........
...#.#....
..##..#...
.......#..
#.......#.
...#....#.
#......#..
*/
/*
YES
3
LLD
*/
