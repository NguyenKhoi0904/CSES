#include <bits/stdc++.h>

#define el "\n"
#define ll long long
#define null NULL
using namespace std;

struct Node{
    int depth;
    int parent;
    int jump;

    Node(int _depth, int _parent, int _jump): depth(_depth), parent(_parent), jump(_jump){};
    Node():depth(0), parent(0), jump(0){};
};

const int MAXN = 2e5+5;

int n,q;
vector<vector<int>> adj(MAXN);
Node A[MAXN];

void dfs(int i){
    stack<int> st;
    st.push(i);

    while(!st.empty()){
        int u = st.top();
        st.pop();

        for(int v : adj[u]){
            st.push(v);
            A[v] = Node();
            A[v].parent = u;
            A[v].depth = A[u].depth+1;
            if(A[u].depth - A[A[u].jump].depth == A[A[u].jump].depth - A[A[A[u].jump].jump].depth){
                A[v].jump = A[A[u].jump].jump;
            }else{
                A[v].jump = u;
            }
        }
    }
}

int find(int x, int d){
    while(A[x].depth > d){

        if(A[A[x].jump].depth < d){
            x = A[x].parent;
        }else{
            x = A[x].jump;
        }
    }
    return x;
}

void Solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    A[1] = Node(0,0,1);
    for(int i = 2; i <= n; i++){
        int c; cin >> c;
        adj[c].push_back(i);
    }

//    for(int i = 1; i <= n; i++){
//        cout << i << ": ";
//        for(int e : adj[i]) cout << e << " ";
//        cout << el;
//    }
    dfs(1);
//    for(int i = 1; i <= 10; i++){
//        cout << i << ": ";
//        cout << A[i].depth << el;
//    }
    while(q--){
        int x,k; cin >> x >> k;
        if(A[x].depth < k){
            cout << -1 << el;
        }else cout << find(x, A[x].depth-k) << el;
    }
}
int main(){
    Solve();
    return 0;
}
