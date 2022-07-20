#include <bits/stdc++.h>
using namespace std;

int vis[200001];
int cnt1=-1;
int N,K;

int main(){
    cin >> N >> K;

    if(N == K || N * 2 == K){
        cout << 0;
        return 0;
    }
    queue<pair<int,int>> q;
    q.push({N,0});

    while(!q.empty()){
        pair<int,int> cur = q.front();q.pop();
        int num = cur.first;
        int level = cur.second;
        vis[num] = 1;

        if(level <= cnt1 && num == K) cnt1 = level;

        if(cnt1 == -1 && num == K) {
            cnt1 = level;
            continue;
        }

        for(auto cal: {num -1, num + 1}){
            if(cal >= 0 && cal <=100001 && vis[cal] == 0){
                q.push({cal,level+1});
            }
        }
        if(num * 2<=200001 && vis[num*2] == 0){
            q.push({num*2,level});
        }
    }
    cout << cnt1;
}