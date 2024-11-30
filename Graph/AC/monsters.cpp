#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <climits>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#define ii pair<int,int>
using namespace std;

const int MAXN = 1005, MAXM = 1005;
const int MAX_INT = 1e6+10;

char arr[MAXN][MAXM];
int visited[MAXN][MAXM];
int vis[MAXN][MAXM];
int monster_path[MAXN][MAXM];

vector<char> result;
queue<ii> mp; // monster point
ii ap; // A point
bool flag = false;
int n,m;

struct Path{
    int x,y, distance;
    Path(int _x, int _y, int _distance):x(_x), y(_y), distance(_distance){}
};


struct Way_out{
    int x, y, valid;
    char direction;
    Way_out* prev;

    Way_out(int _x, int _y, int _valid, char _direction, Way_out* _prev): x(_x), y(_y), valid(_valid), direction(_direction), prev(_prev) {}
};


void BFS1(){
    while(!mp.empty()){
        int u = mp.front().first;
        int v = mp.front().second;
        mp.pop();

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int i = 0;  i < 4; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            if(monster_path[x][y] == -1){
                monster_path[x][y] = monster_path[u][v] + 1;
                mp.push({x,y});
            }
            else{
                if(monster_path[x][y] > monster_path[u][v] + 1){
                    monster_path[x][y] = monster_path[u][v] + 1;
                    mp.push({x,y});
                }
            }

        }
    }
}

bool BFS2(ii v){
    queue<Way_out*> q;
    q.push(new Way_out(v.first, v.second, 0, ' ', NULL));
    visited[v.first][v.second] = 1;

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    while(!q.empty()){
        Way_out* u = q.front();
        q.pop();
        if(u->x == 1 || u->x == n || u->y == 1 || u->y == m){
            cout << "YES\n" << u->valid << ln;
            stack<char> st;
            while(u->prev){
                st.push(u->direction);
                u = u->prev;
            }

            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            return true;
        }
        for(int i = 0; i < 4; i++){

            int x = u->x + dx[i];
            int y = u->y + dy[i];

            if(!visited[x][y] && arr[x][y] != '#' && ((monster_path[x][y] - (u->valid+1)) > 0) || (monster_path[x][y] == -1)){
                visited[x][y] = 1;
                char c;
                if(dx[i] == 1) c = 'D';
                else if(dx[i] == -1) c = 'U';
                else if(dy[i] == 1) c = 'R';
                else if(dy[i] == -1) c = 'L';

                q.push(new Way_out(x,y, u->valid+1, c, u));
            }
        }
    }

    return false;
}

void Solve(){
    cin >> n >> m;

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXM; j++) {
            arr[i][j] = '#';
        }
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXM; j++) {
            monster_path[i][j] = -2;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            monster_path[i][j] = -1;
            if(arr[i][j] == 'M'){
                mp.push({i,j});
                monster_path[i][j] = 0;
            }
            else if(arr[i][j] == 'A') ap.first = i, ap.second = j;
            else if(arr[i][j] == '#') monster_path[i][j] = -2;
        }
    }

    BFS1();

//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= m; j++){
//            cout << monster_path[i][j] << " ";
//        }
//        cout << ln;
//    }

    if(!BFS2(ap)){
        cout << "NO\n";
    }
}
int main(){
    IO
    Solve();
    return 0;
}
