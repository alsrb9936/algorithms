#include <bits/stdc++.h>
using namespace std;

int pos[100001];
int N,K;


int main(){
    cin >> N >> K;

    queue<int> q;
    pos[N] = 1;
    q.push(N);;

    while(!q.empty()){
        int cur = q.front();q.pop();

        if(pos[K] != 0) break;

        for(auto cal: {cur + 1, cur - 1, cur * 2 }){
            if(cal >= 0 && cal <=100001 && pos[cal] == 0 ){
                pos[cal] = pos[cur] + 1;
                q.push(cal);
            }
        }
    } 

    cout << pos[K] - 1;

}

