#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
class DSU{
private:
    vector<int> parent,size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 1; i <= n; i++) parent[i] = i; // Mỗi phần tử là đại diện của chính nó
    }
    // Tìm đại diện của tập hợp chứa x với path compression
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Đệ quy tìm cha và gán trực tiếp cha là root
    }

    // Hợp hai tập hợp chứa x và y
    void Union(int x, int y){
        int root_x = find(x);
        int root_y = find(y);

        if(root_x != root_y){
            if(root_x < root_y) swap(root_x, root_y);

            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        }
    }

};

void Solve(){
    int n,m; cin >> n >> m;
    DSU dsu(n);
    int tmp = m;
    set<int> s;
    while(tmp--){
        int a,b; cin >> a >> b;
        dsu.Union(a,b);
    }
    for(int i = 1; i <= n; i++) s.insert(dsu.find(i));
    cout << s.size() - 1 << ln;
    vector<int> t(s.begin(), s.end());
    for(int i = 0; i < t.size()-1; i++) cout << t[i] << " " << t[i+1] << ln;
}
int main(){
    IO
    Solve();
    return 0;
}
/*
4 2
1 2
3 4
*/

/*
10 10
2 5
5 6
1 4
6 8
2 6
3 6
1 10
8 9
2 3
5 8
*/
