//
// Created by 정인우 on 2023/05/23.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n,INF));
    vector<vector<int>> first_path(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>> a >> b>> c ;
        a--; b--;
        graph[a][b] = c;
        graph[b][a] = c;
        first_path[a][b] = b+1;
        first_path[b][a] = a+1;
    }
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(i!=j && graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                    first_path[i][j] = first_path[i][k];
                }
            }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j){
                cout << first_path[i][j] << ' ';
            } else {
                cout << "- ";
            }
        }
        cout << '\n';
    }

    return 0;
}



int dp[1001][3][4];
int n;
int MOD= 1'000'000;
int solve(int day,int L, int A ){
    if(L>=2 || A>=3) return 0;
    if(day==n)return 1;

    int& ret = dp[day][L][A];
    if(ret!=-1)return ret;
    ret=solve(day+1,L+1,0)%MOD;
    ret=(ret+solve(day+1,L,A+1)%MOD)%MOD;
    ret = (ret+solve(day+1,L,0)%MOD)%MOD;
    return dp[day][L][A]=ret;
}
using namespace std;
int n;
int main(){
    //OLA 출 지 결
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    int room, starttime,endtime;
    vector<pair<int,int>> lects;
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=1;i<=n;i++){

        cin >> room >> starttime>> endtime;
        lects.emplace_back(pair<int,int>(starttime,endtime));
    }
    sort(begin(lects),end(lects));
    int ans=0;
    for(int i=0;i<lects.size();i++){
        int start= lects[i].first;
        int end = lects[i].second;
        if(pq.empty())pq.emplace(end);
        else{
            if(pq.top()>start)ans++;
            else{
                pq.pop();
            }
            pq.emplace(end);
        }
    }
    cout <<ans;
}

