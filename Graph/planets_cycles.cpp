#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const int MAXN = 2e5 + 10;
int n;
int a[MAXN];
int visted[MAXN];
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
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int idx = 1, e = 0;
    for(int i = 1; i <= n; i++){
        if(!visted[i]){
            visted[i] = 1;
            while(!visted[e])
        }
    }
}
int main(){
    IO
    Solve();
    return 0;
}

