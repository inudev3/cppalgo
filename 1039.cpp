#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>

//
// Created by 정인우 on 2023/05/24.
//
int n,k;
using namespace std;
int main(){
    string num;
    cin>>num>>k;
    // i<<j<<m, swap(i,j) k번
    int m = num.length();
    queue<pair<string,int>> q;
    unordered_set<string> visited;
    q.push({num,0});
    visited.insert(num);
    string ans = num;
    while(q.empty()){
        pair<string,int> curr =q.front();
        q.pop();
        if(curr.second==k){
            ans= max(ans,num);
            continue;
        }
        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<m;j++){
                if(i==0&&curr.first[j]=='0')continue;
                swap(curr.first[i],curr.first[j]);
                if(visited.find(curr.first)!=visited.end()){
                    visited.insert(curr.first);
                    q.push({curr.first, curr.second+1});
                }
                swap(curr.first[i],curr.first[j]);
            }
        }

    }
    if (ans[0] == '0') cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}