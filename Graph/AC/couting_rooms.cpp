#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

vector<vector<char>> v;
vector<vector<int>> visted;
void BFS(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visted[i][j] = 1;
    while(!q.empty()){
        pair<int,int> u = q.front();
        int x = u.first, y = u.second;
        q.pop();

        if(v[x+1][y] == '.' && !visted[x+1][y]){
            q.push({x+1,y});
            visted[x+1][y] = 1;
        }
        if(v[x-1][y] == '.' && !visted[x-1][y]){
            q.push({x-1,y});
            visted[x-1][y] = 1;
        }
        if(v[x][y+1] == '.' && !visted[x][y+1]){
            q.push({x,y+1});
            visted[x][y+1] = 1;
        }
        if(v[x][y-1] == '.' && !visted[x][y-1]){
            q.push({x, y-1});
            visted[x][y-1] = 1;
        }
    }
}

void Solve(){
    int n, m; cin >> n >> m;
    v.resize(n+2, vector<char> (m+2,'#'));
    visted.resize(n+2, vector<int> (m+2,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> v[i][j];
    }
    int c = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(v[i][j] == '.' && !visted[i][j]){
                c++;
                BFS(i,j);
            }
        }
    }
    cout << c << ln;
}
int main(){
    IO
    Solve();
    return 0;
}

