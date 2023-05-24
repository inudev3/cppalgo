
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,  0,1,-1 };
struct Cell {
    int x, y;
    int garbage, adjGarbage;
};

auto cmp = [](Cell a, Cell b) {
    if (a.garbage != b.garbage)
        return a.garbage > b.garbage;
    return a.adjGarbage > b.adjGarbage;
};
vector<vector<char>> map;
vector<vector<int>> dist;

int fy, fx, ey, ex;
int main() {
    int n, m;
    cin >> n >> m;
    map.resize(m,vector<char>(n));
    dist.resize(m,vector<int>(n,-1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                fx = i;
                fy = j;
            } else if (map[i][j] == 'F') {
                ex = i;
                ey = j;
            }
        }

    //쓰레기수, 쓰레기 옆에 수 , y좌표 , x좌표
    priority_queue<Cell, vector<Cell>,decltype(cmp)> pq(cmp);
    pq.push(Cell{fx,fy,0,0});

    dist[fx][fy] = 0;
    int ans1 = 0, ans2 = 0;

    while (!pq.empty()) {
        int g = pq.top().garbage; //밟은 쓰레기
        int gg = pq.top().adjGarbage; //인접 쓰레기
        int x = pq.top().x;
        int y = pq.top().y;

        pq.pop();

        bool end = false;
        for (int k = 0; k < 4; ++k) {

            int nx = x + dx[k];
            int ny = y + dy[k];

            int ng = g;
            int ngg = gg;

            if (nx == ex && ny == ey) {
                ans1 = g;
                ans2 = gg;
                end = true;
                break;
            }


            if (!(0 <= ny && ny < n && 0 <= nx && nx < m)) continue;
            if (dist[nx][ny] != -1) continue;

            if (map[nx][ny] == 'g')ng++;
            else if (map[nx][ny] == '.') {
                bool flg = false;
                for (int i = 0; i < 4; ++i)if (map[ny + dy[i]][nx + dx[i]] == 'g') {
                    flg = true;
                    break;
                }
                if (flg)ngg += 1;
            }
            pq.push(Cell{nx, ny,ng, ngg});
            dist[nx][ny] = dist[x][y] + 1;
        }

        if (end) break;
    }

    cout << ans1 << " " << ans2 << "\n";
    return 0;
}
