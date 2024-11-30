#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

const int MAXN = 1e5+10;
vector<vector<int>> arr(MAXN);
int colored[MAXN];
int n,m;
int RED = 1, BLUE = 2;
bool flag = true;

void BFS(int i){
    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int e : arr[u]){
            if(!colored[e]){
                colored[e] = (colored[u]==1?2:1);
                q.push(e);
            }else if(colored[e] == colored[u]){
                flag = false;
                return;
            }
        }
    }
}

void Solve(){
    cin >> n >> m;
    while(m--){
        int a,b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for(int i = 1; i <= n && flag; i++){
        if(!colored[i]){
            colored[i] = 1;
            BFS(i);
        }
    }
    if(flag){
        for(int i = 1; i <= n; i++) cout << colored[i] << " ";
    }else cout << "IMPOSSIBLE\n";
}
int main(){
    IO
    Solve();
    return 0;
}

/*
10 20
3 4
8 10
3 7
1 8
2 8
9 10
2 4
6 9
1 4
3 5
1 9
6 7
2 9
2 7
1 7
4 10
5 6
4 6
3 8
7 10
*/
