//
// Created by 정인우 on 2023/05/24.
//
#include <iostream>
#include <vector>
using namespace std;
int n;
bool flag;

int main(){
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(n == 1) cout << 'A';
}