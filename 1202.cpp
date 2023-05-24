//
// Created by 정인우 on 2023/05/24.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,k;
int main(){
    cin>>n>>k;
    int m,v;
    vector<int>bags(k);
    vector<pair<int,int>> jewels(n);
    for(int i=0;i<n;i++){
        cin>>m>>v;
        jewels[i] = {m,v}; //무게, 가격
    }
    for(int j=0;j<k;j++){
        cin>>bags[j];
    }
    sort(begin(jewels),end(jewels));
    sort(begin(bags),end(bags));
    priority_queue<int, vector<int>> pq;
    int j=0;
    int sum=0;
    for(int i=0;i<k;i++){
        while(j<n&&jewels[j].first<=bags[i])pq.push(jewels[j++].second);
        if(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
    }
}
