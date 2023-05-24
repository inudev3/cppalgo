#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int ans;
int n,m,k;
unordered_set<string> check[11];
void dfs(string S, int depth){
    string num= S;
    int x = stoi(S);
    if(depth == k){
        ans = max(ans,x);
        return;
    }
    for(int i=0; i<num.size(); i++){
        for(int j=i+1; j<num.size(); j++){
            if(i==0 && num[j]=='0') continue;
            swap(num[i], num[j]);
            if(check[depth].find(num) == check[depth].end()){
                check[depth].insert(num);
                dfs(num, depth+1);
            }
            swap(num[i], num[j]);
        }
    }
}
int main(){
    string S;
    cin >> S >> k;
    m = S.size(), n= stoi(S);


    if(m==1||(m==2&&S[1]=='0')){cout << "-1"; return 0;}
    dfs(S, 0);
    cout << ans << '\n';
    return 0;
}
