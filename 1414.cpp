//
// Created by 정인우 on 2023/05/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

class UnionFind {
public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 1);
        for(int i=0; i<size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if(rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
};
struct Edge {
    int u, v, w;
    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
};
int toInt(char ch) {
    if ('a' <= ch && ch <= 'z') return ch - 'a' + 1;
    if ('A' <= ch && ch <= 'Z') return ch - 'A' + 27;
    return 0;
}

int main(){
    cin>>n;
    UnionFind uf(n);
    vector<Edge> edges;
    int total_len = 0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        char ch;
        cin>>ch;
        int len = toInt(ch);
        if(i<j &&len>0){
            edges.emplace_back(Edge{i,j,len});
            total_len+=len;
        }
    }
    int res=0;
    sort(begin(edges), end(edges));
    for(const Edge& e:edges){
        if(uf.find(e.u)==uf.find(e.v))continue;
        uf.unite(e.u,e.v);
        res+=e.w;
    }
    int root = uf.find(0);
    for (int i = 1; i < n; ++i) {
        if (uf.find(i) != root) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << total_len-res << '\n';
    return 0;
}