//
// Created by 정인우 on 2023/05/24.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
int n,m, x;

struct State{
    int num;
    int dist;
};
auto cmp = [](const State& a, const State& b){
    return a.dist>b.dist;
};

vector<State> graph[1001];
void dijkstra(vector<int>&dist, int start){
    priority_queue<State,vector<State>, decltype(cmp)> pq(cmp);
    dist[start]=0;
    pq.push(State{start,0});
    while(!pq.empty()){
        int curr=pq.top().num;
        int curDist = pq.top().dist;
        pq.pop();
        if(dist[curr]<curDist)continue;
        for(State next:graph[curr]){
            int nextN = next.num;
            int nextDist = curDist+next.dist;
            if(dist[nextN]>nextDist){
                dist[nextN]=nextDist;
                pq.push(State{nextDist,nextN});
            }
        }
    }
}
int main(){
    cin>>n>>m>>x;
    int a,b,cost;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>cost;
        graph[a].emplace_back(State{b,cost});
    }

    vector<int> result(n + 1, 0);
    vector<int> tmp(n + 1);

    for (int i = 1; i <= n; i++) {
        if (i == x)
            continue;

        fill(tmp.begin(), tmp.end(), INT_MAX);
        dijkstra(tmp, i);
        result[i] += tmp[x];

        fill(tmp.begin(), tmp.end(), INT_MAX);
        dijkstra(tmp, x);
        result[i] += tmp[i];
    }
    cout << *max_element(result.begin(), result.end());
    return 0;
}