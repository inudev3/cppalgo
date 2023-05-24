//
// Created by 정인우 on 2023/05/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    vector<int> build_time(n+1);
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    vector<int> dp(n+1, 0);


    for(int i = 1; i <= n; ++i) {
        cin >> build_time[i];
        dp[i] = build_time[i];
        while(true) {
            int prev;
            cin >> prev;
            if(prev == -1) break;
            graph[prev].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr = q.front();
        for(int next : graph[curr]){
            dp[next] = max(dp[next],dp[curr]+build_time[next]);
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
            }

        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << '\n';
    }

    return 0;
}
