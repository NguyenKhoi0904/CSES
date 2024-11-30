#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
vector<vector<char>> a;
vector<vector<int>> t;

// Hàm xây dựng cây phân đoạn 1D cho từng hàng
void buildY(int nodeX, int sx, int ex, int nodeY, int sy, int ey){
    if(sy == ey){
        if(sx == ex){
            t[nodeX][nodeY] = (a[sx][sy] == '*' ? 1 : 0);
        } else {
            t[nodeX][nodeY] = t[(nodeX << 1)][nodeY] + t[(nodeX << 1) + 1][nodeY];
        }
    } else {
        int mid_y = (sy + ey) >> 1;
        buildY(nodeX, sx, ex, nodeY << 1, sy, mid_y);
        buildY(nodeX, sx, ex, (nodeY << 1) + 1, mid_y + 1, ey);
        t[nodeX][nodeY] = t[nodeX][nodeY << 1] + t[nodeX][(nodeY << 1) + 1];
    }
}

// Hàm xây dựng cây phân đoạn 2D
void buildX(int nodeX, int sx, int ex, int sy, int ey){
    if(sx != ex){
        int mid_x = (sx + ex) >> 1;
        buildX(nodeX << 1, sx, mid_x, sy, ey);
        buildX((nodeX << 1) + 1, mid_x + 1, ex, sy, ey);
    }
    buildY(nodeX, sx, ex, 1, sy, ey);
}

// Truy vấn trên cây phân đoạn 1D
int getY(int nodeX, int nodeY, int sy, int ey, int y1, int y2){
    if(ey < y1 || sy > y2) return 0;
    if(y1 <= sy && ey <= y2) return t[nodeX][nodeY];
    int mid_y = (sy + ey) >> 1;
    return getY(nodeX, nodeY << 1, sy, mid_y, y1, y2) + getY(nodeX, (nodeY << 1) + 1, mid_y + 1, ey, y1, y2);
}

// Truy vấn trên cây phân đoạn 2D
int getX(int nodeX, int sx, int ex, int sy, int ey, int x1, int x2, int y1, int y2){
    if(ex < x1 || sx > x2) return 0;
    if(x1 <= sx && ex <= x2) return getY(nodeX, 1, sy, ey, y1, y2);
    int mid_x = (sx + ex) >> 1;
    return getX(nodeX << 1, sx, mid_x, sy, ey, x1, x2, y1, y2) + getX((nodeX << 1) + 1, mid_x + 1, ex, sy, ey, x1, x2, y1, y2);
}

// Cập nhật trên cây phân đoạn 1D
void updateY(int nodeX, int sx, int ex, int nodeY, int sy, int ey, int x, int y, int val){
    if(sy == ey){
        if(sx == ex) t[nodeX][nodeY] = val;
        else t[nodeX][nodeY] = t[nodeX << 1][nodeY] + t[(nodeX << 1) + 1][nodeY];
    } else {
        int mid_y = (sy + ey) >> 1;
        if(y <= mid_y) updateY(nodeX, sx, ex, nodeY << 1, sy, mid_y, x, y, val);
        else updateY(nodeX, sx, ex, (nodeY << 1) + 1, mid_y + 1, ey, x, y, val);
        t[nodeX][nodeY] = t[nodeY << 1][nodeY] + t[(nodeY << 1) + 1][nodeY];
    }
}

// Cập nhật trên cây phân đoạn 2D
void updateX(int nodeX, int sx, int ex, int sy, int ey, int x, int y, int val){
    if(sx != ex){
        int mid_x = (sx + ex) >> 1;
        if(x <= mid_x) updateX(nodeX << 1, sx, mid_x, sy, ey, x, y, val);
        else updateX((nodeX << 1) + 1, mid_x + 1, ex, sy, ey, x, y, val);
    }
    updateY(nodeX, sx, ex, 1, sy, ey, x, y, val);
}

void Solve(){
    int n, q; cin >> n >> q;
    a.resize(n + 1, vector<char>(n + 1));
    t.resize(4 * (n + 1), vector<int>(4 * (n + 1)));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    buildX(1, 1, n, 1, n);
    while(q--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << getX(1, 1, n, 1, n, x1, x2, y1, y2) << ln;
    }
}

int main(){
    IO
    Solve();
    return 0;
}
