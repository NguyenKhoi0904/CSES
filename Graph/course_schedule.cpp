#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

const int MAXN = 1e5+10;

int n,m;
vector<vector<int>> adj;
int visited[MAXN];
vector<int> ans;

bool dfs(int i){
    stack<int> st;
    st.push(i);
    visited[i] = -1;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        for(auto e : adj[u]){
            if(visited[e] == -1){
                return false;
            }
            if(visited[e] == 0){
                visited[e] = -1;
                ans.push_back(e);
                st.push(e);
            }
        }
    }
    ans.push_back(i);
    for(int i = 1; i <= MAXN; i++){
        if(visited[i] == -1) visited[i] = 1;
    }
    return true;
}

void Solve(){
    cin >> n >> m;
    adj.resize(n+1);
    bool flag = true;

    while(m--){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }

//    for(int i = 1; i <= n; i++){
//        cout << i << ": ";
//        for(int e : adj[i]){
//            cout << e << " ";
//        }
//        cout << ln;
//    }

    for(int i = 1; i <= n && flag; i++){
        if(visited[i] == 0){
            flag = dfs(i);
            cout << i << "\n";
            for(int e : ans) cout << e << " ";
            cout << ln;
        }
    }
//    if(flag){
//        reverse(ans.begin(), ans.end());
//        for(int e : ans) cout << e << " ";
//        cout << ln;
//    }else cout << "IMPOSSIBLE\n";

}
int main(){
    IO
    Solve();
    return 0;
}


/* INPUT
5 3
1 2
3 1
4 5
*/

/* OUTPUT
3 4 1 5 2
*/


/*
10 20
5 2
2 4
8 9
6 4
7 6
8 4
5 3
9 4
8 3
10 8
3 9
1 8
2 9
7 4
7 2
9 6
3 4
2 6
1 9
10 1
*/
// 5 7 10 2 1 8 3 9 6 4
