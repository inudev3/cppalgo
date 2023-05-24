//
// Created by 정인우 on 2023/05/24.
//
#include <iostream>
#include <vector>
using namespace std;
int n,k,s;
int main(){
    cin >> n>>k;
    int x,y;
    vector<vector<int>> graph(n);
    vector<int> indegree(n);
    for(int i=0;i<k;i++){
        cin>>x>>y;
        graph[x].emplace_back(y);
        indegree[y]++;
    }

    cin>>s;
    vector<pair<int,int>> queries(s);
    vector<int> res(s);
    for(int i=0;i<n;i++){
        if
    }
}
